#include "stm32l475xx.h"
#include "delay.h"
#include "delay.c"
//objective: blink LED1 (PA5; GPIO BANKA) using CIPS

int main()
{
   //enable clock for GPIO bank A
   RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
   
   //mode:01
   GPIOA->MODER |= GPIO_MODER_MODE5_0;
   GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
   
   while(1) {
      //drive GPIO to blink(on) the LED
      GPIOA->ODR |= GPIO_ODR_OD5;
      delay(1000000);
      //drive GPIO to blink(off) the LED
      GPIOA->ODR &= ~GPIO_ODR_OD5;
      delay(1000000);
   }
  return 0;
}
