# THIS FILE IS AUTOMATICALLY GENERATED
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Sun, 29 Jan 2023 23:31:12 GMT
=======
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Thu, 23 Feb 2023 18:12:31 GMT
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
=======
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Thu, 23 Feb 2023 18:12:31 GMT
=======
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Sun, 29 Jan 2023 23:31:12 GMT
>>>>>>> e6b66f492be45cb54e7efb6d0f687a534db08ab8:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
<<<<<<< HEAD
=======
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Sun, 29 Jan 2023 23:31:12 GMT
=======
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Thu, 23 Feb 2023 18:12:31 GMT
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
=======
>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
#set_units -time ns
create_clock -name {CLK(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {CLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list]


<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
# Component constraints for C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Sun, 29 Jan 2023 23:30:47 GMT
=======
# Component constraints for C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Thu, 23 Feb 2023 18:12:27 GMT
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
=======
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
# Component constraints for C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Thu, 23 Feb 2023 18:12:27 GMT
=======
# Component constraints for C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Sun, 29 Jan 2023 23:30:47 GMT
>>>>>>> e6b66f492be45cb54e7efb6d0f687a534db08ab8:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
<<<<<<< HEAD
=======
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
# Component constraints for C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Leo Tejkowski\Desktop\ece381\Lab 2 - Interrupts\Project\Zip File\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Sun, 29 Jan 2023 23:30:47 GMT
=======
# Component constraints for C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Hello Kitty\Desktop\MicrocontrollersLab\Lab 2 - Interrupts\Project\Lab02 - Interrupts.cydsn\Lab02 - Interrupts.cyprj
# Date: Thu, 23 Feb 2023 18:12:27 GMT
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/Lab02 - Interrupts.sdc
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
=======
>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
