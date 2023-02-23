<<<<<<< HEAD
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Design01.cydsn/codegentemp/CyBootAsmIar.s
;-------------------------------------------------------------------------------
; \file CyBootAsmIar.s
; \version 5.82
;
; \brief Assembly routines for IAR Embedded Workbench IDE.
;
;-------------------------------------------------------------------------------
; Copyright 2013-2021, Cypress Semiconductor Corporation.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions,
; disclaimers, and limitations in the end user license agreement accompanying
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    SECTION .text:CODE:ROOT(4)
    PUBLIC CyDelayCycles
    PUBLIC CyEnterCriticalSection
    PUBLIC CyExitCriticalSection
    THUMB
    INCLUDE cyfitter.h


;-------------------------------------------------------------------------------
; Function Name: CyDelayCycles
;-------------------------------------------------------------------------------
;
; Summary:
;  Delays for the specified number of cycles.
;
; Parameters:
;  uint32 cycles: number of cycles to delay.
;
; Return:
;  None
;
;-------------------------------------------------------------------------------
; void CyDelayCycles(uint32 cycles)

CyDelayCycles:
    ADDS r0, r0, #2
    LSRS r0, r0, #2
    BEQ CyDelayCycles_done
    #ifdef CYIPBLOCK_m0s8cpuss_VERSION
        NOP                     ;    1    2    Loop alignment padding
    #else
        #ifdef CYIPBLOCK_s8srsslt_VERSION
            #ifdef CYIPBLOCK_m0s8cpussv2_VERSION
                #ifdef CYIPBLOCK_mxusbpd_VERSION
                    /* Do nothing */
                #else
                    #ifdef CYIPBLOCK_m0s8usbpd_VERSION
                        /* Do nothing */
                    #else
                        NOP             ;    1    2    Loop alignment padding
                    #endif
                #endif
            #endif
        #endif
        ;Leave loop unaligned
    #endif
CyDelayCycles_loop:
    #ifdef CYDEV_CM0P_BASE
        ADDS r0, r0, #1
        SUBS r0, r0, #2
        BNE CyDelayCycles_loop
        NOP
    #else
        SUBS r0, r0, #1
        BNE CyDelayCycles_loop
        NOP
        NOP
    #endif
CyDelayCycles_done:
    BX lr

;-------------------------------------------------------------------------------
; Function Name: CyEnterCriticalSection
;-------------------------------------------------------------------------------
;
; Summary:
;  CyEnterCriticalSection disables interrupts and returns a value indicating
;  whether interrupts were previously enabled.
;
;  Note Implementation of CyEnterCriticalSection manipulates the IRQ enable bit
;  with interrupts still enabled. The test and set of the interrupt bits is not
;  atomic. Therefore, to avoid corrupting processor state, it must be the policy
;  that all interrupt routines restore the interrupt enable bits as they were
;  found on entry.
;
; Parameters:
;  None
;
; Return:
;  uint8
;   Returns 0 if interrupts were previously enabled or 1 if interrupts
;   were previously disabled.
;
;-------------------------------------------------------------------------------
; uint8 CyEnterCriticalSection(void)

CyEnterCriticalSection:
    MRS r0, PRIMASK         ; Save and return interrupt state
    CPSID I                 ; Disable interrupts
    BX lr

;-------------------------------------------------------------------------------
; Function Name: CyExitCriticalSection
;-------------------------------------------------------------------------------
;
; Summary:
;  CyExitCriticalSection re-enables interrupts if they were enabled before
;  CyEnterCriticalSection was called. The argument should be the value returned
;  from CyEnterCriticalSection.
;
; Parameters:
;  uint8 savedIntrStatus:
;   Saved interrupt status returned by the CyEnterCriticalSection function.
;
; Return:
;  None
;
;-------------------------------------------------------------------------------
; void CyExitCriticalSection(uint8 savedIntrStatus)

CyExitCriticalSection:
    MSR PRIMASK, r0         ; Restore interrupt state
    BX lr

    END

;Undefine temporary defines
#undef CYIPBLOCK_m0s8cpussv2_VERSION
#undef CYIPBLOCK_m0s8srssv2_VERSION
=======
=======
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/CyBootAsmIar.s
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
;-------------------------------------------------------------------------------
; \file CyBootAsmIar.s
; \version 6.10
;
; \brief Assembly routines for IAR Embedded Workbench IDE.
;
;-------------------------------------------------------------------------------
; Copyright 2013-2021, Cypress Semiconductor Corporation.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions,
; disclaimers, and limitations in the end user license agreement accompanying
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    SECTION .text:CODE:ROOT(4)
    PUBLIC CyDelayCycles
    PUBLIC CyEnterCriticalSection
    PUBLIC CyExitCriticalSection
    THUMB
    INCLUDE cyfitter.h


;-------------------------------------------------------------------------------
; Function Name: CyDelayCycles
;-------------------------------------------------------------------------------
;
; Summary:
;  Delays for the specified number of cycles.
;
; Parameters:
;  uint32 cycles: number of cycles to delay.
;
; Return:
;  None
;
;-------------------------------------------------------------------------------
; void CyDelayCycles(uint32 cycles)

CyDelayCycles:
    ADDS r0, r0, #2
    LSRS r0, r0, #2
    BEQ CyDelayCycles_done
    #ifdef CYIPBLOCK_m0s8cpuss_VERSION
        NOP                     ;    1    2    Loop alignment padding
    #else
        #ifdef CYIPBLOCK_s8srsslt_VERSION
            #ifdef CYIPBLOCK_m0s8cpussv2_VERSION
                #ifdef CYIPBLOCK_mxusbpd_VERSION
                    /* Do nothing */
                #else
                    #ifdef CYIPBLOCK_m0s8usbpd_VERSION
                        /* Do nothing */
                    #else
                        NOP             ;    1    2    Loop alignment padding
                    #endif
                #endif
            #endif
        #endif
        ;Leave loop unaligned
    #endif
CyDelayCycles_loop:
    #ifdef CYDEV_CM0P_BASE
        ADDS r0, r0, #1
        SUBS r0, r0, #2
        BNE CyDelayCycles_loop
        NOP
    #else
        SUBS r0, r0, #1
        BNE CyDelayCycles_loop
        NOP
        NOP
    #endif
CyDelayCycles_done:
    BX lr

;-------------------------------------------------------------------------------
; Function Name: CyEnterCriticalSection
;-------------------------------------------------------------------------------
;
; Summary:
;  CyEnterCriticalSection disables interrupts and returns a value indicating
;  whether interrupts were previously enabled.
;
;  Note Implementation of CyEnterCriticalSection manipulates the IRQ enable bit
;  with interrupts still enabled. The test and set of the interrupt bits is not
;  atomic. Therefore, to avoid corrupting processor state, it must be the policy
;  that all interrupt routines restore the interrupt enable bits as they were
;  found on entry.
;
; Parameters:
;  None
;
; Return:
;  uint8
;   Returns 0 if interrupts were previously enabled or 1 if interrupts
;   were previously disabled.
;
;-------------------------------------------------------------------------------
; uint8 CyEnterCriticalSection(void)

CyEnterCriticalSection:
    MRS r0, PRIMASK         ; Save and return interrupt state
    CPSID I                 ; Disable interrupts
    BX lr

;-------------------------------------------------------------------------------
; Function Name: CyExitCriticalSection
;-------------------------------------------------------------------------------
;
; Summary:
;  CyExitCriticalSection re-enables interrupts if they were enabled before
;  CyEnterCriticalSection was called. The argument should be the value returned
;  from CyEnterCriticalSection.
;
; Parameters:
;  uint8 savedIntrStatus:
;   Saved interrupt status returned by the CyEnterCriticalSection function.
;
; Return:
;  None
;
;-------------------------------------------------------------------------------
; void CyExitCriticalSection(uint8 savedIntrStatus)

CyExitCriticalSection:
    MSR PRIMASK, r0         ; Restore interrupt state
    BX lr

    END

;Undefine temporary defines
#undef CYIPBLOCK_m0s8cpussv2_VERSION
#undef CYIPBLOCK_m0s8srssv2_VERSION
<<<<<<< HEAD
>>>>>>> e6b66f492be45cb54e7efb6d0f687a534db08ab8:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/CyBootAsmIar.s
=======
=======
;-------------------------------------------------------------------------------
; \file CyBootAsmIar.s
; \version 5.82
;
; \brief Assembly routines for IAR Embedded Workbench IDE.
;
;-------------------------------------------------------------------------------
; Copyright 2013-2021, Cypress Semiconductor Corporation.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions,
; disclaimers, and limitations in the end user license agreement accompanying
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    SECTION .text:CODE:ROOT(4)
    PUBLIC CyDelayCycles
    PUBLIC CyEnterCriticalSection
    PUBLIC CyExitCriticalSection
    THUMB
    INCLUDE cyfitter.h


;-------------------------------------------------------------------------------
; Function Name: CyDelayCycles
;-------------------------------------------------------------------------------
;
; Summary:
;  Delays for the specified number of cycles.
;
; Parameters:
;  uint32 cycles: number of cycles to delay.
;
; Return:
;  None
;
;-------------------------------------------------------------------------------
; void CyDelayCycles(uint32 cycles)

CyDelayCycles:
    ADDS r0, r0, #2
    LSRS r0, r0, #2
    BEQ CyDelayCycles_done
    #ifdef CYIPBLOCK_m0s8cpuss_VERSION
        NOP                     ;    1    2    Loop alignment padding
    #else
        #ifdef CYIPBLOCK_s8srsslt_VERSION
            #ifdef CYIPBLOCK_m0s8cpussv2_VERSION
                #ifdef CYIPBLOCK_mxusbpd_VERSION
                    /* Do nothing */
                #else
                    #ifdef CYIPBLOCK_m0s8usbpd_VERSION
                        /* Do nothing */
                    #else
                        NOP             ;    1    2    Loop alignment padding
                    #endif
                #endif
            #endif
        #endif
        ;Leave loop unaligned
    #endif
CyDelayCycles_loop:
    #ifdef CYDEV_CM0P_BASE
        ADDS r0, r0, #1
        SUBS r0, r0, #2
        BNE CyDelayCycles_loop
        NOP
    #else
        SUBS r0, r0, #1
        BNE CyDelayCycles_loop
        NOP
        NOP
    #endif
CyDelayCycles_done:
    BX lr

;-------------------------------------------------------------------------------
; Function Name: CyEnterCriticalSection
;-------------------------------------------------------------------------------
;
; Summary:
;  CyEnterCriticalSection disables interrupts and returns a value indicating
;  whether interrupts were previously enabled.
;
;  Note Implementation of CyEnterCriticalSection manipulates the IRQ enable bit
;  with interrupts still enabled. The test and set of the interrupt bits is not
;  atomic. Therefore, to avoid corrupting processor state, it must be the policy
;  that all interrupt routines restore the interrupt enable bits as they were
;  found on entry.
;
; Parameters:
;  None
;
; Return:
;  uint8
;   Returns 0 if interrupts were previously enabled or 1 if interrupts
;   were previously disabled.
;
;-------------------------------------------------------------------------------
; uint8 CyEnterCriticalSection(void)

CyEnterCriticalSection:
    MRS r0, PRIMASK         ; Save and return interrupt state
    CPSID I                 ; Disable interrupts
    BX lr

;-------------------------------------------------------------------------------
; Function Name: CyExitCriticalSection
;-------------------------------------------------------------------------------
;
; Summary:
;  CyExitCriticalSection re-enables interrupts if they were enabled before
;  CyEnterCriticalSection was called. The argument should be the value returned
;  from CyEnterCriticalSection.
;
; Parameters:
;  uint8 savedIntrStatus:
;   Saved interrupt status returned by the CyEnterCriticalSection function.
;
; Return:
;  None
;
;-------------------------------------------------------------------------------
; void CyExitCriticalSection(uint8 savedIntrStatus)

CyExitCriticalSection:
    MSR PRIMASK, r0         ; Restore interrupt state
    BX lr

    END

;Undefine temporary defines
#undef CYIPBLOCK_m0s8cpussv2_VERSION
#undef CYIPBLOCK_m0s8srssv2_VERSION
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 3 - Simon Game/Project/Design01.cydsn/codegentemp/CyBootAsmIar.s
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
