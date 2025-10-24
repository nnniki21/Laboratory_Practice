 #include "../Inc/init.h";
 
 void GPIO_Init_with_Myself_Macros(void){
    BIT_SET(RCC_AHB1ENR, RCC_GPIOB_EN||RCC_GPIOC_EN);
 }