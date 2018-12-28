/*
 * pru_i2c.h
 *
 *  Created on: 20 feb 2018
 *      Author: andrea
 */

#ifndef PRU_I2C_H_
#define PRU_I2C_H_

#include <stdint.h>

typedef struct {

    /* PRU_I2C_REVNB_LO register bit field */
    union {
        volatile uint32_t I2C_REVNB_LO;

        volatile struct {
            unsigned I2C_REVNB_LO  : 32;       //31:0
        } I2C_REVNB_LO_bit;
    };  // 0x0 - 0x03

    /* PRU_I2C_REVNB_HI register bit field */
    union {
        volatile uint32_t I2C_REVNB_HI;

        volatile struct {
            unsigned I2C_REVNB_HI  : 32;       //31:0
        } I2C_REVNB_HI_bit;
    };  // 0x04 - 0x07

    uint32_t rsvd08[2];        // 0x08 - 0x0F

    /* PRU_I2C_SYSC register bit field */
    union {
        volatile uint32_t I2C_SYSC;

        volatile struct {
            unsigned I2C_SYSC_AUTOIDLE     : 1;        //0:0
            unsigned I2C_SYSC_SRST         : 1;        //1:1
            unsigned I2C_SYSC_ENAWAKEUP    : 1;        //2:2
            unsigned I2C_SYSC_IDLEMODE     : 2;        //4:3
            unsigned I2C_SYSC_RSRVD1       : 3;        //7:5
            unsigned I2C_SYSC_CLKACTIVITY  : 2;        //9:8
            unsigned I2C_SYSC_RSRVD2       : 22;       //31:10
        } I2C_SYSC_bit;
    };  // 0x10 - 0x13

    uint32_t rsvd14[4];        // 0x14 - 0x23

    /* PRU_I2C_IRQSTATUS_RAW register bit field */
    union {
        volatile uint32_t I2C_IRQSTATUS_RAW;

        volatile struct {
            unsigned I2C_IRQSTATUS_RAW_AL    : 1;        //0:0
            unsigned I2C_IRQSTATUS_RAW_NACK  : 1;        //1:1
            unsigned I2C_IRQSTATUS_RAW_ARDY  : 1;        //2:2
            unsigned I2C_IRQSTATUS_RAW_RRDY  : 1;        //3:3
            unsigned I2C_IRQSTATUS_RAW_XRDY  : 1;        //4:4
            unsigned I2C_IRQSTATUS_RAW_GC    : 1;        //5:5
            unsigned I2C_IRQSTATUS_RAW_STC   : 1;        //6:6
            unsigned I2C_IRQSTATUS_RAW_AERR  : 1;        //7:7
            unsigned I2C_IRQSTATUS_RAW_BF    : 1;        //8:8
            unsigned I2C_IRQSTATUS_RAW_AAS   : 1;        //9:9
            unsigned I2C_IRQSTATUS_RAW_XUDF  : 1;        //10:10
            unsigned I2C_IRQSTATUS_RAW_ROVR  : 1;        //11:11
            unsigned I2C_IRQSTATUS_RAW_BB    : 1;        //12:12
            unsigned I2C_IRQSTATUS_RAW_RDR   : 1;        //13:13
            unsigned I2C_IRQSTATUS_RAW_XDR   : 1;        //14:14
            unsigned I2C_IRQSTATUS_RAW_RSRVD : 17;       //31:15
        } I2C_IRQSTATUS_RAW_bit;
    };  // 0x24 - 0x27

    /* PRU_I2C_IRQSTATUS_RAW register bit field */
    union {
        volatile uint32_t I2C_IRQSTATUS;

        volatile struct {
            unsigned I2C_IRQSTATUS_AL    : 1;        //0:0
            unsigned I2C_IRQSTATUS_NACK  : 1;        //1:1
            unsigned I2C_IRQSTATUS_ARDY  : 1;        //2:2
            unsigned I2C_IRQSTATUS_RRDY  : 1;        //3:3
            unsigned I2C_IRQSTATUS_XRDY  : 1;        //4:4
            unsigned I2C_IRQSTATUS_GC    : 1;        //5:5
            unsigned I2C_IRQSTATUS_STC   : 1;        //6:6
            unsigned I2C_IRQSTATUS_AERR  : 1;        //7:7
            unsigned I2C_IRQSTATUS_BF    : 1;        //8:8
            unsigned I2C_IRQSTATUS_AAS   : 1;        //9:9
            unsigned I2C_IRQSTATUS_XUDF  : 1;        //10:10
            unsigned I2C_IRQSTATUS_ROVR  : 1;        //11:11
            unsigned I2C_IRQSTATUS_BB    : 1;        //12:12
            unsigned I2C_IRQSTATUS_RDR   : 1;        //13:13
            unsigned I2C_IRQSTATUS_XDR   : 1;        //14:14
            unsigned I2C_IRQSTATUS_RSRVD : 17;       //31:15
        } I2C_IRQSTATUS_bit;
    };  // 0x28 - 0x2B

    /* PRU_I2C_IRQENABLE_SET register bit field */
    union {
        volatile uint32_t I2C_IRQENABLE_SET;

        volatile struct {
            unsigned I2C_IRQENABLE_SET_AL_IE    : 1;        //0:0
            unsigned I2C_IRQENABLE_SET_NACK_IE  : 1;        //1:1
            unsigned I2C_IRQENABLE_SET_ARDY_IE  : 1;        //2:2
            unsigned I2C_IRQENABLE_SET_RRDY_IE  : 1;        //3:3
            unsigned I2C_IRQENABLE_SET_XRDY_IE  : 1;        //4:4
            unsigned I2C_IRQENABLE_SET_GC_IE    : 1;        //5:5
            unsigned I2C_IRQENABLE_SET_STC_IE   : 1;        //6:6
            unsigned I2C_IRQENABLE_SET_AERR_IE  : 1;        //7:7
            unsigned I2C_IRQENABLE_SET_BF_IE    : 1;        //8:8
            unsigned I2C_IRQENABLE_SET_AAS_IE   : 1;        //9:9
            unsigned I2C_IRQENABLE_SET_XUDF_IE  : 1;        //10:10
            unsigned I2C_IRQENABLE_SET_ROVR_IE  : 1;        //11:11
            unsigned I2C_IRQENABLE_SET_RSRVD1   : 1;        //12:12
            unsigned I2C_IRQENABLE_SET_RDR_IE   : 1;        //13:13
            unsigned I2C_IRQENABLE_SET_XDR_IE   : 1;        //14:14
            unsigned I2C_IRQENABLE_SET_RSRVD2   : 17;       //31:15
        } I2C_IRQENABLE_SET_bit;
    };  // 0x2C - 0x2F

    /* PRU_I2C_IRQENABLE_CLR register bit field */
    union {
        volatile uint32_t I2C_IRQENABLE_CLR;

        volatile struct {
            unsigned I2C_IRQENABLE_CLR_AL_IE    : 1;        //0:0
            unsigned I2C_IRQENABLE_CLR_NACK_IE  : 1;        //1:1
            unsigned I2C_IRQENABLE_CLR_ARDY_IE  : 1;        //2:2
            unsigned I2C_IRQENABLE_CLR_RRDY_IE  : 1;        //3:3
            unsigned I2C_IRQENABLE_CLR_XRDY_IE  : 1;        //4:4
            unsigned I2C_IRQENABLE_CLR_GC_IE    : 1;        //5:5
            unsigned I2C_IRQENABLE_CLR_STC_IE   : 1;        //6:6
            unsigned I2C_IRQENABLE_CLR_AERR_IE  : 1;        //7:7
            unsigned I2C_IRQENABLE_CLR_BF_IE    : 1;        //8:8
            unsigned I2C_IRQENABLE_CLR_AAS_IE   : 1;        //9:9
            unsigned I2C_IRQENABLE_CLR_XUDF_IE  : 1;        //10:10
            unsigned I2C_IRQENABLE_CLR_ROVR_IE  : 1;        //11:11
            unsigned I2C_IRQENABLE_CLR_RSRVD1   : 1;        //12:12
            unsigned I2C_IRQENABLE_CLR_RDR_IE   : 1;        //13:13
            unsigned I2C_IRQENABLE_CLR_XDR_IE   : 1;        //14:14
            unsigned I2C_IRQENABLE_CLR_RSRVD2   : 17;       //31:15
        } I2C_IRQENABLE_CLR_bit;
    };  // 0x30 - 0x33

    /* PRU_I2C_WE register bit field */
    union {
        volatile uint32_t I2C_WE;

        volatile struct {
            unsigned I2C_WE_AL_IE    : 1;        //0:0
            unsigned I2C_WE_NACK_IE  : 1;        //1:1
            unsigned I2C_WE_ARDY_IE  : 1;        //2:2
            unsigned I2C_WE_RRDY_IE  : 1;        //3:3
            unsigned I2C_WE_XRDY_IE  : 1;        //4:4
            unsigned I2C_WE_GC_IE    : 1;        //5:5
            unsigned I2C_WE_STC_IE   : 1;        //6:6
            unsigned I2C_WE_AERR_IE  : 1;        //7:7
            unsigned I2C_WE_BF_IE    : 1;        //8:8
            unsigned I2C_WE_AAS_IE   : 1;        //9:9
            unsigned I2C_WE_XUDF_IE  : 1;        //10:10
            unsigned I2C_WE_ROVR_IE  : 1;        //11:11
            unsigned I2C_WE_RSRVD1   : 1;        //12:12
            unsigned I2C_WE_RDR_IE   : 1;        //13:13
            unsigned I2C_WE_XDR_IE   : 1;        //14:14
            unsigned I2C_WE_RSRVD2   : 17;       //31:15
        } I2C_WE_bit;
    };  // 0x34 - 0x37

    /* PRU_I2C_DMARXENABLE_SET register bit field */
    union {
        volatile uint32_t I2C_DMARXENABLE_SET;

        volatile struct {
            unsigned I2C_DMARXENABLE_SET_ENABLE : 1;       //0:0
            unsigned I2C_DMARXENABLE_SET_RSRVD  : 31;       //31:1
        } I2C_DMARXENABLE_SET_bit;
    };  // 0x38 - 0x3B

    /* PRU_I2C_DMATXENABLE_SET register bit field */
    union {
        volatile uint32_t I2C_DMATXENABLE_SET;

        volatile struct {
            unsigned I2C_DMATXENABLE_SET_ENABLE : 1;       //0:0
            unsigned I2C_DMATXENABLE_SET_RSRVD  : 31;       //31:1
        } I2C_DMATXENABLE_SET_bit;
    };  // 0x3C - 0x3F

    /* PRU_I2C_DMARXENABLE_CLR register bit field */
    union {
        volatile uint32_t I2C_DMARXENABLE_CLR;

        volatile struct {
            unsigned I2C_DMARXENABLE_CLR_CLEAR  : 1;       //0:0
            unsigned I2C_DMARXENABLE_CLR_RSRVD  : 31;       //31:1
        } I2C_DMARXENABLE_CLR_bit;
    };  // 0x40 - 0x43

    /* PRU_I2C_DMATXENABLE_CLR register bit field */
    union {
        volatile uint32_t I2C_DMATXENABLE_CLR;

        volatile struct {
            unsigned I2C_DMATXENABLE_CLR_CLEAR  : 1;       //0:0
            unsigned I2C_DMATXENABLE_CLR_RSRVD  : 31;       //31:1
        } I2C_DMATXENABLE_CLR_bit;
    };  // 0x44 - 0x47

    /* PRU_I2C_DMARXWAKE_EN register bit field */
    union {
        volatile uint32_t I2C_DMARXWAKE_EN;

        volatile struct {
            unsigned I2C_DMARXWAKE_EN_AL     : 1;        //0:0
            unsigned I2C_DMARXWAKE_EN_NACK   : 1;        //1:1
            unsigned I2C_DMARXWAKE_EN_ARDY   : 1;        //2:2
            unsigned I2C_DMARXWAKE_EN_RRDY   : 1;        //3:3
            unsigned I2C_DMARXWAKE_EN_XRDY   : 1;        //4:4
            unsigned I2C_DMARXWAKE_EN_GC     : 1;        //5:5
            unsigned I2C_DMARXWAKE_EN_STC    : 1;        //6:6
            unsigned I2C_DMARXWAKE_EN_AERR   : 1;        //7:7
            unsigned I2C_DMARXWAKE_EN_BF     : 1;        //8:8
            unsigned I2C_DMARXWAKE_EN_AAS    : 1;        //9:9
            unsigned I2C_DMARXWAKE_EN_XUDF   : 1;        //10:10
            unsigned I2C_DMARXWAKE_EN_ROVR   : 1;        //11:11
            unsigned I2C_DMARXWAKE_EN_RSRVD1 : 1;        //12:12
            unsigned I2C_DMARXWAKE_EN_RDR    : 1;        //13:13
            unsigned I2C_DMARXWAKE_EN_XDR    : 1;        //14:14
            unsigned I2C_DMARXWAKE_EN_RSRVD2 : 17;       //31:15
        } I2C_DMARXWAKE_EN_bit;
    };  // 0x48 - 0x4B

    /* PRU_I2C_DMATXWAKE_EN register bit field */
    union {
        volatile uint32_t I2C_DMATXWAKE_EN;

        volatile struct {
            unsigned I2C_DMATXWAKE_EN_AL     : 1;        //0:0
            unsigned I2C_DMATXWAKE_EN_NACK   : 1;        //1:1
            unsigned I2C_DMATXWAKE_EN_ARDY   : 1;        //2:2
            unsigned I2C_DMATXWAKE_EN_RRDY   : 1;        //3:3
            unsigned I2C_DMATXWAKE_EN_XRDY   : 1;        //4:4
            unsigned I2C_DMATXWAKE_EN_GC     : 1;        //5:5
            unsigned I2C_DMATXWAKE_EN_STC    : 1;        //6:6
            unsigned I2C_DMATXWAKE_EN_AERR   : 1;        //7:7
            unsigned I2C_DMATXWAKE_EN_BF     : 1;        //8:8
            unsigned I2C_DMATXWAKE_EN_AAS    : 1;        //9:9
            unsigned I2C_DMATXWAKE_EN_XUDF   : 1;        //10:10
            unsigned I2C_DMATXWAKE_EN_ROVR   : 1;        //11:11
            unsigned I2C_DMATXWAKE_EN_RSRVD1 : 1;        //12:12
            unsigned I2C_DMATXWAKE_EN_RDR    : 1;        //13:13
            unsigned I2C_DMATXWAKE_EN_XDR    : 1;        //14:14
            unsigned I2C_DMATXWAKE_EN_RSRVD2 : 17;       //31:15
        } I2C_DMATXWAKE_EN_bit;
    };  // 0x4C - 0x4F

    uint32_t rsvd50[16];        // 0x50 - 0x8F

    /* PRU_I2C_SYSS register bit field */
    union {
        volatile uint32_t I2C_SYSS;

        volatile struct {
            unsigned I2C_SYSS_RDONE  : 1;        //0:0
            unsigned I2C_SYSS_RSRVD  : 31;       //31:1
        } I2C_SYSS_bit;
    };  // 0x90 - 0x93

    /* PRU_I2C_BUF register bit field */
    union {
        volatile uint32_t I2C_BUF;

        volatile struct {
            unsigned I2C_BUF_TXTHRS       : 6;        //5:0
            unsigned I2C_BUF_TXFIFO_CLR   : 1;        //6:6
            unsigned I2C_BUF_XDMA_EN      : 1;        //7:7
            unsigned I2C_BUF_RXTHRS       : 6;        //13:8
            unsigned I2C_BUF_RXFIFO_CLR   : 1;        //14:14
            unsigned I2C_BUF_RDMA_EN      : 1;        //15:15
            unsigned I2C_BUF_RSRVD        : 16;       //31:16
        } I2C_BUF_bit;
    };  // 0x94 - 0x97

    /* PRU_I2C_CNT register bit field */
    union {
        volatile uint32_t I2C_CNT;

        volatile struct {
            unsigned I2C_CNT_DCOUNT : 16;       //15:0
            unsigned I2C_CNT_RSRVD  : 16;       //31:16
        } I2C_CNT_bit;
    };  // 0x98 - 0x9B

    /* PRU_I2C_DATA register bit field */
    union {
        volatile uint32_t I2C_DATA;

        volatile struct {
            unsigned I2C_DATA_DATA   : 8;        //7:0
            unsigned I2C_DATA_RSRVD  : 24;       //31:8
        } I2C_DATA_bit;
    };  // 0x9C - 0x9F

    uint32_t rsvdA0[1];        // 0xA0 - 0xA3

    /* PRU_I2C_CON register bit field */
    union {
        volatile uint32_t I2C_CON;

        volatile struct {
            unsigned I2C_CON_STT    : 1;        //0:0
            unsigned I2C_CON_STP    : 1;        //1:1
            unsigned I2C_CON_RSRVD1 : 2;        //3:2
            unsigned I2C_CON_XOA3   : 1;        //4:4
            unsigned I2C_CON_XOA2   : 1;        //5:5
            unsigned I2C_CON_XOA1   : 1;        //6:6
            unsigned I2C_CON_XOA0   : 1;        //7:7
            unsigned I2C_CON_XSA    : 1;        //8:8
            unsigned I2C_CON_TRX    : 1;        //9:9
            unsigned I2C_CON_MST    : 1;        //10:10
            unsigned I2C_CON_STB    : 1;        //11:11
            unsigned I2C_CON_OPMODE : 2;        //13:12
            unsigned I2C_CON_RSRVD2 : 1;        //14:14
            unsigned I2C_CON_I2C_EN : 1;        //15:15
            unsigned I2C_CON_RSRVD3 : 16;       //31:16
        } I2C_CON_bit;
    };  // 0xA4 - 0xA7

    /* PRU_I2C_OA register bit field */
    union {
        volatile uint32_t I2C_OA;

        volatile struct {
            unsigned I2C_OA_OA     : 10;        //9:0
            unsigned I2C_OA_RSRVD  : 22;        //31:10
        } I2C_OA_bit;
    };  // 0xA8 - 0xAB

    /* PRU_I2C_SA register bit field */
    union {
        volatile uint32_t I2C_SA;

        volatile struct {
            unsigned I2C_SA_SA     : 10;        //9:0
            unsigned I2C_SA_RSRVD  : 22;        //31:10
        } I2C_SA_bit;
    };  // 0xAC - 0xAF

    /* PRU_I2C_PSC register bit field */
    union {
        volatile uint32_t I2C_PSC;

        volatile struct {
            unsigned I2C_PSC_PSC    : 8;        //7:0
            unsigned I2C_PSC_RSRVD  : 24;        //31:8
        } I2C_PSC_bit;
    };  // 0xB0 - 0xB3

    /* PRU_I2C_SCLL register bit field */
    union {
        volatile uint32_t I2C_SCLL;

        volatile struct {
            unsigned I2C_SCLL_SCLL    : 8;        //7:0
            unsigned I2C_SCLL_RSRVD   : 24;       //31:8
        } I2C_SCLL_bit;
    };  // 0xB4 - 0xB7

    /* PRU_I2C_SCLH register bit field */
    union {
        volatile uint32_t I2C_SCLH;

        volatile struct {
            unsigned I2C_SCLH_SCLH    : 8;        //7:0
            unsigned I2C_SCLH_RSRVD   : 24;       //31:8
        } I2C_SCLH_bit;
    };  // 0xB8 - 0xBB

    /* PRU_I2C_SYSTEST register bit field */
    union {
        volatile uint32_t I2C_SYSTEST;

        volatile struct {
            unsigned I2C_SYSTEST_SDA_O        : 1;        //0:0
            unsigned I2C_SYSTEST_SDA_I        : 1;        //1:1
            unsigned I2C_SYSTEST_SCL_O        : 1;        //2:2
            unsigned I2C_SYSTEST_SCL_I        : 1;        //3:3
            unsigned I2C_SYSTEST_RSRVD1       : 1;        //4:4
            unsigned I2C_SYSTEST_SDA_O_FUNC   : 1;        //5:5
            unsigned I2C_SYSTEST_SDA_I_FUNC   : 1;        //6:6
            unsigned I2C_SYSTEST_SCL_O_FUNC   : 1;        //7:7
            unsigned I2C_SYSTEST_SCL_I_FUNC   : 1;        //8:8
            unsigned I2C_SYSTEST_RSRVD2       : 2;        //10:9
            unsigned I2C_SYSTEST_SSB          : 1;        //11:11
            unsigned I2C_SYSTEST_TMODE        : 2;        //13:12
            unsigned I2C_SYSTEST_FREE         : 1;        //14:14
            unsigned I2C_SYSTEST_ST_EN        : 1;        //15:15
            unsigned I2C_SYSTEST_RSRVD3       : 16;       //31:16
        } I2C_SYSTEST_bit;
    };  // 0xBC - 0xBF

    /* PRU_I2C_BUFSTAT register bit field */
    union {
        volatile uint32_t I2C_BUFSTAT;

        volatile struct {
            unsigned I2C_BUFSTAT_TXSTAT     : 6;        //5:0
            unsigned I2C_BUFSTAT_RSRVD1     : 2;        //7:6
            unsigned I2C_BUFSTAT_RXSTAT     : 6;        //13:8
            unsigned I2C_BUFSTAT_FIFODEPTH  : 2;        //15:14
            unsigned I2C_BUFSTAT_RSRVD2     : 16;       //31:16
        } I2C_BUFSTAT_bit;
    };  // 0xC0 - 0xC3

    /* PRU_I2C_OA1 register bit field */
    union {
        volatile uint32_t I2C_OA1;

        volatile struct {
            unsigned I2C_OA1_OA1        : 10;       //9:0
            unsigned I2C_OA1_RSRVD      : 22;       //31:10
        } I2C_OA1_bit;
    };  // 0xC4 - 0xC7

    /* PRU_I2C_OA2 register bit field */
    union {
        volatile uint32_t I2C_OA2;

        volatile struct {
            unsigned I2C_OA2_OA2        : 10;       //9:0
            unsigned I2C_OA2_RSRVD      : 22;       //31:10
        } I2C_OA2_bit;
    };  // 0xC8 - 0xCB

    /* PRU_I2C_OA3 register bit field */
    union {
        volatile uint32_t I2C_OA3;

        volatile struct {
            unsigned I2C_OA3_OA3        : 10;       //9:0
            unsigned I2C_OA3_RSRVD      : 22;       //31:10
        } I2C_OA3_bit;
    };  // 0xCC - 0xCF

    /* PRU_I2C_ACTOA register bit field */
    union {
        volatile uint32_t I2C_ACTOA;

        volatile struct {
            unsigned I2C_ACTOA_OA0_ACT    : 1;       //0:0
            unsigned I2C_ACTOA_OA1_ACT    : 1;       //1:1
            unsigned I2C_ACTOA_OA2_ACT    : 1;       //2:2
            unsigned I2C_ACTOA_OA3_ACT    : 1;       //3:3
            unsigned I2C_ACTOA_RSRVD      : 28;      //31:4
        } I2C_ACTOA_bit;
    };  // 0xD0 - 0xD3

    /* PRU_I2C_SBLOCK register bit field */
    union {
        volatile uint32_t I2C_SBLOCK;

        volatile struct {
            unsigned I2C_SBLOCK_OA0_EN     : 1;       //0:0
            unsigned I2C_SBLOCK_OA1_EN     : 1;       //1:1
            unsigned I2C_SBLOCK_OA2_EN     : 1;       //2:2
            unsigned I2C_SBLOCK_OA3_EN     : 1;       //3:3
            unsigned I2C_SBLOCK_RSRVD      : 28;      //31:4
        } I2C_SBLOCK_bit;
    };  // 0xD4 - 0xD7

} pruI2c;

volatile __far pruI2c CT_I2C1 __attribute__((cregister("I2C1", near), peripheral));
volatile __far pruI2c CT_I2C2 __attribute__((cregister("I2C2", near), peripheral));

#endif /* PRU_I2C_H_ */
