# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\hElLo KiTtY 2.1\Desktop\ECE381\Lab 5 - I2C\Project\Lab 5 - I2C.cydsn\Lab 5 - I2C.cyprj
# Date: Wed, 15 Mar 2023 01:54:30 GMT
#set_units -time ns
create_clock -name {I2C_SCBCLK(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {I2C_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 31 61} [list]


# Component constraints for C:\Users\hElLo KiTtY 2.1\Desktop\ECE381\Lab 5 - I2C\Project\Lab 5 - I2C.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\hElLo KiTtY 2.1\Desktop\ECE381\Lab 5 - I2C\Project\Lab 5 - I2C.cydsn\Lab 5 - I2C.cyprj
# Date: Wed, 15 Mar 2023 01:54:29 GMT
