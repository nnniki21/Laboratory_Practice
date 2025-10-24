#ifndef INIT_H
#define INIT_H

#include<stdint.h>

#define RCC_AHB1ENR                 *(uint32_t *)(0x40023800UL + 0x30UL)
#define RCC_GPIOB_EN                0x02UL
#define RCC_GPIOC_EN                0x04UL

#define GPIOB_MODER                 *(uint32_t *)(0x40020400UL + 0x00UL)
#define GPIOB_OTYPER                *(uint32_t *)(0x40020400UL + 0x04UL)
#define GPIOB_OSPEEDR               *(uint32_t *)(0x40020400UL + 0x08UL)
#define GPIOB_BSRR                  *(uint32_t *)(0x40020400UL + 0x18UL)

#define GPIOC_IDR                   *(uint32_t *)(0x40020800UL + 0x10UL)


#define GPIO_OUTPUT_MEDIUM_PIN_7    0x4000U
#define GPIO_OUTPUT_MODE_PIN_7      0x4000UL
#define GPIO_PIN_RESET_7            0x800000UL
#define GPIO_PIN_SET_7              0x80UL
#define GPIO_PP_PIN_7               0x80UL
#define GPIO_PIN_PC12               0x1000UL


  


#define BIT_SET(REG, BIT)       ((REG) |= (BIT))
#define BIT_READ(REG, BIT)      ((REG) & (BIT))
#define BIT_CLEAR(REG, BIT)     ((REG) &= ~(BIT))

#endif