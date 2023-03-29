# Automatic pet feeder

Inspiration: https://www.thingiverse.com/thing:4815584

## PSoC Creator Steps

### Here are the steps we need to take in order to get this project working.

1) Start printing stuff on I2C LCD
2) Get encoder interrupt working
3) Get button interrupt working
4) Settings for LCD
- If nothing, show the following per line:
    - Time and Date(will be set by RTC)
    - "Time of next feed:"
    - Time and Date of next feed
- If button is pressed, enter settings
    - Cycle through settings to show when encoder turns clockwise or counter-clockwise:
        - Set clock time
        - Set feed time(s)
        - Set amount of food/feed
        - Turn on/off Tone
        - Turn on/off Lights
- Per setting:
    - Set clock time:
        - Allow user to change RTC time
        - Use encoder to change hour, press button
        - Use encoder to change minute, press button
    - Set feed time(s)
        - First prompt for amount of times, use encoder to cyle through numbers up to 10 per day (if they try anymore, call their cat fat)
        - Once confirmed, cycle through amount, change hour and minute, same as clock time.
        - Set RTC to interrupt at these times.
    - Set amount of food/feed
        - Use horizontal bar, starting from zero
        - Per encoder turn, turn motor for testing
        - Move horizontal bar over
        - Once button is pressed, set number of steps for motor.
    - Turn on/off Tone
        - Either turn on or off the speakers when feed time
    - Turn on/off Lights
        - Either turn on or off the lights when feed time
5) Get RTC working
    - Needs to interrupt on a specific time
    - Needs to have correct real world time.
    - Do we need COT_IN?
    - Look in datasheets
6) On RTC interrupt
    - Turn motor specific amount of steps
    - Turn on speakers, if wanted
    - Turn on lights, if wanted
7) Setup UART?

# 5) Get web app working??
