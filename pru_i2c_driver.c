/*
 * pru_i2c_driver.c
 *
 *  Created on: 04 mar 2018
 *      Author: andrea
 */
#include "include/pru_i2c.h"
#include "include/pru_i2c_driver.h"

#define CLKACTIVITY_I2C_FCLK            24
#define CLKACTIVITY_L4LS_GCLK           8
#define MAX_CYCLES_WAITING              200000

volatile pruI2c* CT_I2C[2] = { &CT_I2C1, &CT_I2C2};
uint32_t* CM_PER_I2C_CLKCTRL[2] = {(uint32_t*) 0x44E00048, (uint32_t*) 0x44E00044};

uint8_t initialized[2] = {0,0};

void pru_i2c_driver_DelayMicros(uint8_t micros)
{
    uint16_t cycles = micros * 100;
    uint16_t i = 0;
    for (i = 0; i < cycles; i++)
    {
    };
}

uint8_t pru_i2c_driver_WaitBB(uint8_t i2cDevice)
{
    uint32_t ticks = 0;
    while (CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_BB)
    {
        ticks++;
        if (ticks > MAX_CYCLES_WAITING)
        {
            return 0;
        }
    }
    return 1;
}
uint8_t pru_i2c_driver_WaitBF(uint8_t i2cDevice)
{
    uint32_t ticks = 0;
    while (!CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_BF)
    {
        ticks++;
        if (ticks > MAX_CYCLES_WAITING)
        {
            return 0;
        }
    }
    return 1;
}
uint8_t pru_i2c_driver_WaitXRDY(uint8_t i2cDevice)
{
    uint32_t ticks = 0;
    while (!CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_XRDY)
    {
        ticks++;
        if (ticks > MAX_CYCLES_WAITING)
        {
            return 0;
        }
    }
    return 1;
}
uint8_t pru_i2c_driver_WaitRRDY(uint8_t i2cDevice)
{
    uint32_t ticks = 0;
    while (!CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_RRDY)
    {
        ticks++;
        if (ticks > MAX_CYCLES_WAITING)
        {
            return 0;
        }
    }
    return 1;
}
uint8_t pru_i2c_driver_WaitARDY(uint8_t i2cDevice)
{
    uint32_t ticks = 0;
    while (!CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_ARDY)
    {
        ticks++;
        if (ticks > MAX_CYCLES_WAITING)
        {
            return 0;
        }
    }
    return 1;
}

uint8_t pru_i2c_driver_WaitRDONE(uint8_t i2cDevice)
{
    uint32_t ticks = 0;
    while (!CT_I2C[i2cDevice-1]->I2C_SYSS_bit.I2C_SYSS_RDONE)
    {
        ticks++;
        if (ticks > MAX_CYCLES_WAITING)
        {
            return 0;
        }
    }
    return 1;
}

uint8_t pru_i2c_driver_ReadBytes(uint8_t i2cDevice, uint8_t address, uint8_t reg, uint8_t bytes, uint8_t* buffer)
{
    if(!initialized[i2cDevice-1]) {
        if(!pru_i2c_driver_Init(i2cDevice)) {
            return 0;
        }
    }

    if (!pru_i2c_driver_WaitBB(i2cDevice))
    {
        return 0;
    }

    CT_I2C[i2cDevice-1]->I2C_SA_bit.I2C_SA_SA = address; // 7 bit address
    CT_I2C[i2cDevice-1]->I2C_CNT_bit.I2C_CNT_DCOUNT = 1; // 1 byte to transmit
    CT_I2C[i2cDevice-1]->I2C_CON = 0x8601; // MST/TRX/STT
    pru_i2c_driver_DelayMicros(7);

    if (!pru_i2c_driver_WaitXRDY(i2cDevice))
    {
        return 0;
    }
    // write register to read
    CT_I2C[i2cDevice-1]->I2C_DATA = reg;
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_XRDY = 0b1;

    // wait access to registers
    if (!pru_i2c_driver_WaitARDY(i2cDevice))
    {
        return 0;
    }
    pru_i2c_driver_DelayMicros(6);

    if (CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_AERR
            | CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_NACK)
    {
        return 0;
    }

    // read data
    CT_I2C[i2cDevice-1]->I2C_CNT_bit.I2C_CNT_DCOUNT = bytes; // bytes to reveive
    CT_I2C[i2cDevice-1]->I2C_CON = 0x8403; // MST/STP/STT
    pru_i2c_driver_DelayMicros(24);
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_ARDY = 0b1;

    // wait data
    if (!pru_i2c_driver_WaitRRDY(i2cDevice))
    {
        return 0;
    }

    uint8_t count;
    for (count = 0; count < bytes; count++)
    {
        // read byte
        buffer[count] = CT_I2C[i2cDevice-1]->I2C_DATA;

        // require next data
        CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_RRDY = 0b1;

        // wait data
        if (!pru_i2c_driver_WaitRRDY(i2cDevice))
        {
            return 0;
        }
        pru_i2c_driver_DelayMicros(1);

        if (CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_AERR
                | CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_NACK)
        {
            return 0;
        }
    }

    // wait for access ready
    if (!pru_i2c_driver_WaitARDY(i2cDevice))
    {
        return 0;
    }
    pru_i2c_driver_DelayMicros(6);

    // wait for bus free
    // wait data
    if (!pru_i2c_driver_WaitBF(i2cDevice))
    {
        return 0;
    }

    // serve?
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_ARDY = 0b1;
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_XRDY = 1;
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_RRDY = 1;
    return count;
}

uint8_t pru_i2c_driver_WriteBytes(uint8_t i2cDevice, uint8_t address, uint8_t reg, uint8_t bytes, uint8_t* buffer)
{
    if(!initialized[i2cDevice-1]) {
        if(!pru_i2c_driver_Init(i2cDevice)) {
            return 0;
        }
    }
    if (!pru_i2c_driver_WaitBB(i2cDevice))
    {
        return 0;
    }

    CT_I2C[i2cDevice-1]->I2C_SA_bit.I2C_SA_SA = address; // 7 bit address
    CT_I2C[i2cDevice-1]->I2C_CNT_bit.I2C_CNT_DCOUNT = bytes + 1; // 1 byte to transmit
    CT_I2C[i2cDevice-1]->I2C_CON = 0x8603; // MST/TRX/STT/STP
    pru_i2c_driver_DelayMicros(7);

    if (!pru_i2c_driver_WaitXRDY(i2cDevice))
    {
        return 0;
    }
    // write register to read
    CT_I2C[i2cDevice-1]->I2C_DATA = reg;
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_XRDY = 0b1;
    pru_i2c_driver_DelayMicros(1);
    if (CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_AERR
            | CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_NACK)
    {
        return 0;
    }

    uint8_t count;
    for (count = 0; count < bytes; count++)
    {
        pru_i2c_driver_WaitXRDY(i2cDevice);
        CT_I2C[i2cDevice-1]->I2C_DATA = buffer[count];
        CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_XRDY = 0b1;
        pru_i2c_driver_DelayMicros(1);
        if (CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_AERR
                | CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_NACK)
        {
            return 0;
        }
    }

    // wait for access ready
    if (!pru_i2c_driver_WaitARDY(i2cDevice))
    {
        return 0;
    }
    pru_i2c_driver_DelayMicros(6);

    // wait for bus free
    // wait data
    if (!pru_i2c_driver_WaitBF(i2cDevice))
    {
        return 0;
    }

    // serve?
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_ARDY = 0b1;
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_XRDY = 1;
    CT_I2C[i2cDevice-1]->I2C_IRQSTATUS_RAW_bit.I2C_IRQSTATUS_RAW_RRDY = 1;
    return count;
}

uint8_t pru_i2c_driver_ReadReg(uint8_t i2cDevice, uint8_t address, uint8_t reg, uint8_t* buffer)
{
    return pru_i2c_driver_ReadBytes(i2cDevice, address, reg, 1, buffer);
}
uint8_t pru_i2c_driver_WriteReg(uint8_t i2cDevice, uint8_t address, uint8_t reg, uint8_t value)
{
    return pru_i2c_driver_WriteBytes(i2cDevice, address, reg, 1, &value);
}


void pru_i2c_driver_Set400KHz(uint8_t i2cDevice)
{
    // prescaler
    CT_I2C[i2cDevice-1]->I2C_PSC = 0x02; // 24MHz
    /*
     * tLow = (SCLL +7)*42ns
     * 42ns is the time period at 24MHz,
     * tLow = (1000000000ns/400000Hz)/2) is the time period (in ns) at low signal on SCL
     * SCLL = tLow/42ns -7
     * SCLL = 1250/42 -7
     * SCLL is like 23 (rounded)
     */
    CT_I2C[i2cDevice-1]->I2C_SCLL = 0x17;
    /*
     * tHigh = (SCLH +5)*42ns
     * 42ns is the time period at 24MHz,
     * tHigh = (1000000000ns/400000Hz)/2) is the time period (in ns) at high signal on SCL
     * SCLH = tHigh/42ns -5
     * SCLH = 1250/42 -5
     * SCLH is like 25 (rounded)
     */
    CT_I2C[i2cDevice-1]->I2C_SCLH = 0x19;
}

void pru_i2c_driver_Set100KHz(uint8_t i2cDevice)
{
    // prescaler
    CT_I2C[i2cDevice-1]->I2C_PSC = 0x04; // 12MHz
    /*
     * tLow = (SCLL +7)*83ns
     * 83ns is the time period at 12MHz,
     * tLow = (1000000000ns/100000Hz)/2) is the time period (in ns) at low signal on SCL
     * SCLL = tLow/83ns -7 = 53,241
     * SCLL = 1250/83 -7
     * SCLL is like 53 (rounded)
     */
    CT_I2C[i2cDevice-1]->I2C_SCLL = 53;
    /*
     * tHigh = (SCLH +5)*83ns
     * 83ns is the time period at 12MHz,
     * tHigh = (1000000000ns/100000Hz)/2) is the time period (in ns) at high signal on SCL
     * SCLH = tHigh/83ns - 5 = 55,25
     * SCLH = 1250/83 - 5
     * SCLH is like 55 (rounded)
     */
    CT_I2C[i2cDevice-1]->I2C_SCLH = 55;
}

/*******************************************************************
 * C O N F I G U R A T I O N   O F   I 2 C 2   A N D   C L O C K S *
 *******************************************************************/
uint8_t pru_i2c_driver_Init(uint8_t i2cDevice) {
    uint32_t * CM_PER_L4LS_CLKSTCTRL = (uint32_t *) 0x44E00000;
    (*CM_PER_L4LS_CLKSTCTRL) = ((*CM_PER_L4LS_CLKSTCTRL)
            | (1 << CLKACTIVITY_I2C_FCLK) | (1 << CLKACTIVITY_L4LS_GCLK))
            & 0xFFFFFFFC; // CLKTRCTRL = 0x00

    /*
     * FROM: https://e2e.ti.com/support/arm/sitara_arm/f/791/p/458311/1659097
     * CM_PER_I2C2_CLKCTRL must enabled;
     */
    (*CM_PER_I2C_CLKCTRL[i2cDevice-1]) = 2;

    // SYSC system control register
    CT_I2C[i2cDevice-1]->I2C_SYSC_bit.I2C_SYSC_AUTOIDLE = 0b0; // AutoIdle disabled
    CT_I2C[i2cDevice-1]->I2C_SYSC_bit.I2C_SYSC_ENAWAKEUP = 0b0; // wakeup disabled
    CT_I2C[i2cDevice-1]->I2C_SYSC_bit.I2C_SYSC_IDLEMODE = 0b01; // no idleMode
    CT_I2C[i2cDevice-1]->I2C_SYSC_bit.I2C_SYSC_CLKACTIVITY = 0b00; // cutoff interface ocp clock and functional system clock

    pru_i2c_driver_Set400KHz(i2cDevice);

    // I2C_BUF as default: DMA disabled and buffer tx/rx lenght = 1

    // enable i2c2
    CT_I2C[i2cDevice-1]->I2C_CON_bit.I2C_CON_I2C_EN = 0b1;
    if(pru_i2c_driver_WaitRDONE(i2cDevice)) {
        initialized[i2cDevice-1]=1;
        return 1;
    }
    return 0;
}
