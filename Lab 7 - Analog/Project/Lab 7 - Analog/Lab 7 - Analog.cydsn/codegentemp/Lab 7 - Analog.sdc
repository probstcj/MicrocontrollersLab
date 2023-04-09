# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 7 - Analog\Project\Lab 7 - Analog\Lab 7 - Analog.cydsn\Lab 7 - Analog.cyprj
# Date: Sat, 08 Apr 2023 17:33:53 GMT
#set_units -time ns
create_clock -name {ADC_intClock(FFB)} -period 166.66666666666666 -waveform {0 83.3333333333333} [list [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {PWM_CLK(FFB)} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 9 17} [list]
create_generated_clock -name {PWM_CLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 481 961} [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\Leo Tejkowski\Desktop\ece381\Lab 7 - Analog\Project\Lab 7 - Analog\Lab 7 - Analog.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 7 - Analog\Project\Lab 7 - Analog\Lab 7 - Analog.cydsn\Lab 7 - Analog.cyprj
# Date: Sat, 08 Apr 2023 17:33:47 GMT