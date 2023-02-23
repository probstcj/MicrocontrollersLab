# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 3 - Simon Game\Project\Design01.cydsn\Design01.cyprj
# Date: Thu, 23 Feb 2023 18:16:52 GMT
#set_units -time ns
create_clock -name {PWM_CLK(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_11}] [get_pins {ClockBlock/ff_div_13}]]
create_clock -name {TIMER_CLK(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_12}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {PWM_CLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 49 97} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {TIMER_CLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list]


# Component constraints for C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 3 - Simon Game\Project\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 3 - Simon Game\Project\Design01.cydsn\Design01.cyprj
# Date: Thu, 23 Feb 2023 18:16:47 GMT
