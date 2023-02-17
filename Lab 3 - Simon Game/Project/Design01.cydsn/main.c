/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

static const int ROUNDS = 20;
volatile int timeout, pressed;

// This function implements a non-blocking polling loop.
// If neither of the buttons is pressed, it should return 0,
// otherwise it should return a value that corresponds
// to one of the colored buttons. To be consistent, this
// should match the color used in the sequence
int poll_button()
{
    int button = 0;
    
    // XXX: Polling loop for button goes here

    // For each iteration of polling loop, check value of BTN. If bit change (0,1,2,4,8)
    // Are on, change the button value based on this value
    switch(BTN_Read()){
    case 1: 
        button = 1;
        break;
    case 2: 
        button = 2;
        break;
    case 4: 
        button = 3;
        break;
    case 8: 
        button = 4;
        break;
    default: 
        button = 0;
        break;
    }

    return button;
}

// The play color function illuminates an led
// using a PWM at a duty cycle given by dc for
// a number of milliseconds equal to delay and
// plays the correpsonding note.
//
//  INPUTS:
//      color (int): A mapping to determine the
//                   LED to play.
//                  Suggested Colors and Notes are
//                  0: Red (310 Hz)
//                  1: Green (415 Hz)
//                  2: Blue (209 Hz)
//                  3: Yellow (252 Hz)
//
//      dc (int): The duty cycle of the chosen LED's
//                PWM. Only numbers 0-100 should be
//                valid.
//
//      delay (uint32): How long to play the LED and
//                      note, in milliseconds

void play_color(int color, int dc, uint32 delay)
{
    // Set period to initial value of 0
    int period = 0;
 
    switch(color){
    case 0:
        // Period = 3225 for Red
        // 1000000 / 310 = 3225
        period = 3225;
        break;
    case 1:
        // Period = 3174 for Green
        // 1000000 / 415 = 3174
        period = 3174;
        break;
    case 2:
        // Period = 4784 for Blue
        // 1000000 / 209 = 4784       
        period = 4784;
        break;
    case 3:
        // Period = 3968 for Yellow
        // 1000000 / 252 = 3968
        period = 3968;
        break;
    }
    // Write speaker frequency from switch statement
    SPEAKER_PWM_WritePeriod(period);
    // 50% duty cycle, period/2
    SPEAKER_PWM_WriteCompare((int) (period/2));
    // Write LED period to 1000 for easy math
    LED_PWM_WritePeriod(1000);
    // Compare is duty cycle% * 10
    LED_PWM_WriteCompare(dc * 10);
    // Start PWM's'
    LED_PWM_Start();
    SPEAKER_PWM_Start();
    // Select color
    LED_SEL_Write(color);
    // Delay the amount desired
    CyDelay(delay);
    // Stop PWM's'
    SPEAKER_PWM_Stop(); 
    LED_PWM_Stop();
    // Small delay
    CyDelay(100);
    
}

// This should play the start sequence of Simon, which is
// to turn all 4 LEDs on and play a 600Hz tone for 500 ms,
// then turn them off for 500ms, then repeat 2 more times
void play_start()
{
   
    // 50% duty cycle, 600 Hz
    
    /*
    How to calculate Hz
    Take clock rate (1MHz) and divide by frequency. (in microsec) - WritePeriod
    Duty cycle : multiply %duty cycle to the period - WriteCompare
    Period = (1000000/600) + 1
    Compare = .5 * Period
        
    
    
    */
    // Write period of 1667 for frequency of 600Hz (math above)
    SPEAKER_PWM_WritePeriod(1667);
    // 50% duty cycle
    SPEAKER_PWM_WriteCompare(833);
    // Basically DC voltage
    LED_PWM_WritePeriod(1000);
    LED_PWM_WriteCompare(999);
    for (int i = 0; i < 3; i++){
        // Half a second delay
        CyDelay(500);
        // Start PWM modules
        SPEAKER_PWM_Start();
        LED_PWM_Start();
        // 1 ms * 4 * 125 = 500 ms (time that LEDs are on)
        for(int i = 0; i < 125; i++){
            // Switch between LEDs and delay
            LED_SEL_Write(0);
            CyDelay(1);
            LED_SEL_Write(1);
            CyDelay(1);
            LED_SEL_Write(2);
            CyDelay(1);
            LED_SEL_Write(3);
            CyDelay(1);
        }
        // Stop PWM modules
        SPEAKER_PWM_Stop();
        LED_PWM_Stop();
    }
    // Not needed, but stopping Speaker PWM module again.
    SPEAKER_PWM_Stop();
}

// This should play the fail sequence, which is to turn on
// all 4 LEDs and play a 42Hz tone for 1.5 seconds
void play_fail()
{
    // Set speaker frequency to 42 Hz
    // 1000000 / 42 = 23810
    SPEAKER_PWM_WritePeriod(23810);
    // 50% duty cycle
    SPEAKER_PWM_WriteCompare(11904);
    // Basically DC voltage
    LED_PWM_WritePeriod(1000);
    LED_PWM_WriteCompare(999);
    // Non needed for loop, only runs once, but is copied from play_start
    for (int i = 0; i < 1; i++){
        // Start PWM modules
        SPEAKER_PWM_Start();
        LED_PWM_Start();
        // Play LEDs for 1.5 seconds
        // 1ms * 4 * 375 = 1500 ms
        for(int i = 0; i < 375; i++){
            LED_SEL_Write(0);
            CyDelay(1);
            LED_SEL_Write(1);
            CyDelay(1);
            LED_SEL_Write(2);
            CyDelay(1);
            LED_SEL_Write(3);
            CyDelay(1);
        }
        // Stop PWM modules'
        SPEAKER_PWM_Stop();
        LED_PWM_Stop();
    }
    // Not needed, copied from the last.
    SPEAKER_PWM_Stop();  
}

// This should play back the victory sequence. In the original
// Simon, that plays:
// R, Y, B, G in sequence 0.1s apart, 3 times
// then RY, 
// then play failure tone for 0.8s, while the lights then
// continually flash R Y B G 0.1s apart.
//
// You can implement whatever victory sequence you want if
// you don't feel like doing the original one.
void play_win()
{
    // Basically DC voltage
    LED_PWM_WritePeriod(1000);
    LED_PWM_WriteCompare(999);
    // Repeat this sequence 3 times
    for(int i = 0; i < 3; i++){
        // Repeat this inner sequence 4 times (per color)
        for(int j = 0; j < 4; j++){
            // Write the correct LED
            LED_SEL_Write(j);
            // Blink LED and play speaker at 600Hz with 100ms delay between blinks
            for(int k = 0; k < 3; k++){
                SPEAKER_PWM_WritePeriod(1667);
                SPEAKER_PWM_WriteCompare(833);
                LED_PWM_Start();
                SPEAKER_PWM_Start();
                CyDelay(100);
                LED_PWM_Stop();
                SPEAKER_PWM_Stop();
                CyDelay(100);
            }
            // Blink LED and play speaker at 540Hz with 100ms delay
            SPEAKER_PWM_WritePeriod(1852);
            SPEAKER_PWM_WriteCompare(926);
            SPEAKER_PWM_Start();
            LED_PWM_Start();
            CyDelay(100);
            SPEAKER_PWM_Stop();
            LED_PWM_Stop();
            CyDelay(100);
        }
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Variables */
    int ix = 0, num_correct = 0, errors = 0, seq_ctr = 0;
    int simon_sequence[ROUNDS];
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PRS_Start();
    SPEAKER_PWM_Start();
    SPEAKER_PWM_Stop();
    LED_PWM_Start();
    LED_PWM_Stop();
    INPUT_TIMER_Start();
    INPUT_TIMER_Stop();
    INPUT_TIMER_ISR_Start();
    
    for(;;)
    {
        /* Place your application code here. */
        
        // Wait for any button press  
        while (poll_button() == 0);
        
        // Play the start sequence
        play_start();
        
        // Generate random sequnce of 20 rounds. Store it
        // in simon_sequence
        
        // Use the PRS module to generate random numbers.
        // % 4 will create numbers 0 - 3
        for(int i = 0; i < ROUNDS; i++){
            simon_sequence[i] = PRS_Read() % 4;
            // Delay for PRS module
            CyDelay(1);
        }
        
       
        
        // Zero the sequence counter. We use this variable to keep
        // track of how far along we are in the game        
        seq_ctr = 1;
        
        // These variables keep track of how many are correct each round and
        // if any errors are input.
        num_correct = 0, errors = 0;

        // Start the counter at 1 (Why not zero? Due to the nature of
        // for loops bounds checking! See below)
        seq_ctr = 1;        
        
        
        // The main game begins here. As long as there are no errors,
        // and we haven't gone through all rounds, we are stuck in here        
        while (seq_ctr < ROUNDS + 1 && errors == 0)
        {
            
            // For each round of the game, we start with having no
            // correct buttons pressed            
            num_correct = 0;
            
            // Playback current sequence. The LED should get
            // progressively dimmer for each color in the sequence
            for (ix = 0; ix < seq_ctr; ix++)
            {
                play_color(simon_sequence[ix], (100/ROUNDS)*(ROUNDS - seq_ctr + 1), 420); 
            }
            
            // Since seq_ctr keeps track of the current number we have
            // gotten correct so far, for each round we have to keep looping
            // until we get all correct (or break if an error)
            while (num_correct < seq_ctr)
            {
                // Pressed keeps track of the current (if any) button that
                // was pressed. Timeout starts at 0 and gets set from
                // INPUT_TIMER_ISR if a button hasn't been pressed in
                // 3s
                pressed = 0;
                timeout = 0;
                
                
                // This is the main input loop. When poll_button returns
                // something non-zero, that means a button is pressed.
                // If timeout gets set to 1, that means 3s have elapsed
                // without a button press
                
                // Before button poll *initialize* the Timer (restarts the timer)
                INPUT_TIMER_Init();
                INPUT_TIMER_Start();
                // Start ISR for timeout
                INPUT_TIMER_ISR_Start();
                // 3 second timer
                INPUT_TIMER_WritePeriod(3000);
                // Poll button
                while(pressed == 0 && timeout == 0)
                {
                    pressed = poll_button();
                }         
                // Wait for button release       
                while(BTN_Read()!=0 && timeout==0);
                // Stop timer and ISR
                INPUT_TIMER_Stop();
                // Not needed, but here anyway
                INPUT_TIMER_WritePeriod(3000);
                INPUT_TIMER_ISR_Stop();
                
                
                // If the main input loop breaks due a timeout, then 
                if (timeout == 1)
                {
                    // Play the fail sequence
                    
                    play_fail();

                    // Set the error counter
                    errors = 1;

                    // Break out of the loop for the current round.
                    // This combined with setting errors should get
                    // back to start of the gam
                    break;
                }
                // otherwise, the main input loop broke due to a button press.
                else
                {
                    // Whether right or wrong, playback the correct color
                    play_color(pressed - 1, (100/ROUNDS)*(ROUNDS - seq_ctr + 1), 420);

                    // Check here to see pressed button is correct
                    if (pressed == simon_sequence[num_correct] + 1)
                    {
                        // Increment the number of correctly input
                        // buttons for the sequence
                        num_correct++;
                    }
                    // Otherwise, the button pressed didn't match the current sequence color
                    else
                    {
                        // Play the fail sequence
                        play_fail();

                        // Set the error counter
                        errors = 1;

                        // Break out of the loop for the current round.
                        // This combined with setting errors should get
                        // back to start of the game
                        break;
                    }
                }                
                
            }
            
            // If we get here, all the buttons entered for the current round
            // matched the sequence! We can increment the sequence counter
            // and go on to the next round. The original Simon delayed 0.8s
            // between rounds.
            if (errors == 0)
            {
                seq_ctr++;
                CyDelay(800);
            }            
        }
        
        // If we get here, we have completed the game! Play a celebration!
        if (errors == 0)
        {
            play_win();
        }        
    }
}

/* [] END OF FILE */

