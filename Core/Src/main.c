#include "init.c";
#include <stdint.h>

uint8_t flag_PC10 = 0; //для кнопки 2 по умолчанию 0-вход 1-выход
uint8_t flag_PC11 = 0; //для кнопки 3
uint8_t flag_PC12 = 0; //для кнопки 4
uint8_t flag_PC13 = 0; //флаг для кнопки на плате (1)
uint32_t count_PC13 = 0; //счетчик для кол-ва нажатий 

int main(void)
{
    
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN); // включение тактирования портов C и B
    // порты на выход
    GPIOC10_Set_Output();
    GPIOC11_Set_Output();
    GPIOC12_Set_Output();
    Green_LED_ON();
    Blue_LED_ON();
    Red_LED_ON();

    while (1)
    {
        //для кнопки 1 (на плате) управление режимами портов 
        while(count_PC13 <= 5){
            if(READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_13)!=0){
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
                count_PC13++;
                if(count_PC13 == 1){
                    GPIOC10_Set_Outtput();
                    flag_PC10 = 1;
                    continue;
                }
                if(count_PC13 == 2){
                    GPIOC11_Set_Outtput();
                    flag_PC11 = 1;
                    continue;
                }
                if(count_PC13 == 3){
                    GPIOC12_Set_Outtput();
                    flag_PC12 = 1;
                    continue;
                }
                if(count_PC13 == 4){
                    GPIOC10_Set_Input();
                    GPIOC11_Set_Input();
                    GPIOC12_Set_Input();
                    flag_PC10 = 0;
                    flag_PC11 = 0;
                    flag_PC12 = 0;
                    continue;
                }
                if(count_PC13 == 5){
                    GPIOC10_Set_Output();
                    GPIOC11_Set_Output();
                    GPIOC12_Set_Output();
                    flag_PC10 = 1;
                    flag_PC11 = 1;
                    flag_PC12 = 1;
                    count_PC13 = 0;
                    break;
                }
            }
            else{
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR7);
            }
        }

        //для кнопки 2 (зеленый светодиод PB0)
        if(flag_PC10 == 1){
           if(READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_10)){
                SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS10);
            }
            else{
                SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR10);
            }
        }
        else{
            if(READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_10)){
                
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0);
            }
            else{
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0);
            }
        }

        //кнопка 3 (Синий PB7)
        if(flag_PC11 == 1){
           if(READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_11)){
                SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS11);
            }
            else{
                SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR11);
            }
        }
        else{
            if(READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_11)){
                
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
            }
            else{
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
            }
        }

        //кнопка 3(красный PB14)
        if(flag_PC12 == 1){
           if(READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_12)){
                SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS12);
            }
            else{
                SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR12);
            }
        }
        else{
            if(READ_BIT(GPIOC->IDR, GPIO_IDR_IDR_12)){
                
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14);
            }
            else{
                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14);
            }
        }

        
    }
}