<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/cyutils.c
=======
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Design01.cydsn/Generated_Source/PSoC4/cyutils.c
/***************************************************************************//**
* \file cyutils.c
* \version 5.82
*
* \brief Provides a function to handle 24-bit value writes.
*
********************************************************************************
* \copyright
* Copyright 2008-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"

#if (!CY_PSOC3)

    /***************************************************************************
    * Function Name: CySetReg24
    ************************************************************************//**
    *
    * Writes a 24-bit value to the specified register.
    *
    * \param addr The address where data must be written.
    * \param value The data that must be written.
    *
    * \reentrant No
    *
    ***************************************************************************/
    void CySetReg24(uint32 volatile * addr, uint32 value)
    {
        uint8 volatile *tmpAddr;

        tmpAddr = (uint8 volatile *) addr;

        tmpAddr[0u] = (uint8) value;
        tmpAddr[1u] = (uint8) (value >> 8u);
        tmpAddr[2u] = (uint8) (value >> 16u);
    }


    #if(CY_PSOC4)

        /***************************************************************************
        * Function Name: CyGetReg24
        ************************************************************************//**
        *
        * Reads the 24-bit value from the specified register.
        *
        * \param addr The address where data must be read.
        *
        * \reentrant No
        *
        ***************************************************************************/
        uint32 CyGetReg24(uint32 const volatile * addr)
        {
            uint8 const volatile *tmpAddr;
            uint32 value;

            tmpAddr = (uint8 const volatile *) addr;

            value  =  (uint32) tmpAddr[0u];
            value |= ((uint32) tmpAddr[1u] << 8u );
            value |= ((uint32) tmpAddr[2u] << 16u);

            return(value);
        }

    #endif  /*(CY_PSOC4)*/

#endif  /* (!CY_PSOC3) */


/* [] END OF FILE */
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/cyutils.c
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
=======
>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
/***************************************************************************//**
* \file cyutils.c
* \version 6.10
*
* \brief Provides a function to handle 24-bit value writes.
*
********************************************************************************
* \copyright
* Copyright 2008-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"

#if (!CY_PSOC3)

    /***************************************************************************
    * Function Name: CySetReg24
    ************************************************************************//**
    *
    * Writes a 24-bit value to the specified register.
    *
    * \param addr The address where data must be written.
    * \param value The data that must be written.
    *
    * \reentrant No
    *
    ***************************************************************************/
    void CySetReg24(uint32 volatile * addr, uint32 value)
    {
        uint8 volatile *tmpAddr;

        tmpAddr = (uint8 volatile *) addr;

        tmpAddr[0u] = (uint8) value;
        tmpAddr[1u] = (uint8) (value >> 8u);
        tmpAddr[2u] = (uint8) (value >> 16u);
    }


    #if(CY_PSOC4)

        /***************************************************************************
        * Function Name: CyGetReg24
        ************************************************************************//**
        *
        * Reads the 24-bit value from the specified register.
        *
        * \param addr The address where data must be read.
        *
        * \reentrant No
        *
        ***************************************************************************/
        uint32 CyGetReg24(uint32 const volatile * addr)
        {
            uint8 const volatile *tmpAddr;
            uint32 value;

            tmpAddr = (uint8 const volatile *) addr;

            value  =  (uint32) tmpAddr[0u];
            value |= ((uint32) tmpAddr[1u] << 8u );
            value |= ((uint32) tmpAddr[2u] << 16u);

            return(value);
        }

    #endif  /*(CY_PSOC4)*/

#endif  /* (!CY_PSOC3) */


/* [] END OF FILE */
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> e6b66f492be45cb54e7efb6d0f687a534db08ab8:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/cyutils.c
=======
=======
/***************************************************************************//**
* \file cyutils.c
* \version 5.82
*
* \brief Provides a function to handle 24-bit value writes.
*
********************************************************************************
* \copyright
* Copyright 2008-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"

#if (!CY_PSOC3)

    /***************************************************************************
    * Function Name: CySetReg24
    ************************************************************************//**
    *
    * Writes a 24-bit value to the specified register.
    *
    * \param addr The address where data must be written.
    * \param value The data that must be written.
    *
    * \reentrant No
    *
    ***************************************************************************/
    void CySetReg24(uint32 volatile * addr, uint32 value)
    {
        uint8 volatile *tmpAddr;

        tmpAddr = (uint8 volatile *) addr;

        tmpAddr[0u] = (uint8) value;
        tmpAddr[1u] = (uint8) (value >> 8u);
        tmpAddr[2u] = (uint8) (value >> 16u);
    }


    #if(CY_PSOC4)

        /***************************************************************************
        * Function Name: CyGetReg24
        ************************************************************************//**
        *
        * Reads the 24-bit value from the specified register.
        *
        * \param addr The address where data must be read.
        *
        * \reentrant No
        *
        ***************************************************************************/
        uint32 CyGetReg24(uint32 const volatile * addr)
        {
            uint8 const volatile *tmpAddr;
            uint32 value;

            tmpAddr = (uint8 const volatile *) addr;

            value  =  (uint32) tmpAddr[0u];
            value |= ((uint32) tmpAddr[1u] << 8u );
            value |= ((uint32) tmpAddr[2u] << 16u);

            return(value);
        }

    #endif  /*(CY_PSOC4)*/

#endif  /* (!CY_PSOC3) */


/* [] END OF FILE */
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 3 - Simon Game/Project/Design01.cydsn/Generated_Source/PSoC4/cyutils.c
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
=======
=======
/***************************************************************************//**
* \file cyutils.c
* \version 5.82
*
* \brief Provides a function to handle 24-bit value writes.
*
********************************************************************************
* \copyright
* Copyright 2008-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"

#if (!CY_PSOC3)

    /***************************************************************************
    * Function Name: CySetReg24
    ************************************************************************//**
    *
    * Writes a 24-bit value to the specified register.
    *
    * \param addr The address where data must be written.
    * \param value The data that must be written.
    *
    * \reentrant No
    *
    ***************************************************************************/
    void CySetReg24(uint32 volatile * addr, uint32 value)
    {
        uint8 volatile *tmpAddr;

        tmpAddr = (uint8 volatile *) addr;

        tmpAddr[0u] = (uint8) value;
        tmpAddr[1u] = (uint8) (value >> 8u);
        tmpAddr[2u] = (uint8) (value >> 16u);
    }


    #if(CY_PSOC4)

        /***************************************************************************
        * Function Name: CyGetReg24
        ************************************************************************//**
        *
        * Reads the 24-bit value from the specified register.
        *
        * \param addr The address where data must be read.
        *
        * \reentrant No
        *
        ***************************************************************************/
        uint32 CyGetReg24(uint32 const volatile * addr)
        {
            uint8 const volatile *tmpAddr;
            uint32 value;

            tmpAddr = (uint8 const volatile *) addr;

            value  =  (uint32) tmpAddr[0u];
            value |= ((uint32) tmpAddr[1u] << 8u );
            value |= ((uint32) tmpAddr[2u] << 16u);

            return(value);
        }

    #endif  /*(CY_PSOC4)*/

#endif  /* (!CY_PSOC3) */


/* [] END OF FILE */
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 3 - Simon Game/Project/Design01.cydsn/Generated_Source/PSoC4/cyutils.c
=======
>>>>>>> e6b66f492be45cb54e7efb6d0f687a534db08ab8:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/cyutils.c
>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
