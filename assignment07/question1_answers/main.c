#include "stm32l475xx.h"
#include "delay.h"
//void delay (uint32_t mscount);
void SysTick_Initialize();
int counter_g;

int main()
{
  //warmup code to see if LED works
  /*
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
  GPIOB->MODER |= GPIO_MODER_MODE14_0;
  GPIOB->ODR ^= GPIO_ODR_OD14;
  */
  
  //setup LED registers
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
   
  //SysTick_Initialize
  SysTick_Initialize();
  
  while(1){
      delay(5000);
      GPIOA->ODR ^= GPIO_ODR_OD5;
  }
}

void SysTick_Initialize(void){
    SysTick->LOAD = 4000;// 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;// 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;// 0xE000E010 - Enable interrupts
}

void SysTick_Handler (void) {
   __disable_irq();
   counter_g--;
   __enable_irq();
}
