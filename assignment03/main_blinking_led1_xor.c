/*
KIT   : B-L475E-IOT01A1
PART  : STM32L475VGT6

1. Enable clock
   RCC_BASE = 0x40021000
   RCC_AHB2ENR_offset = 0x4C
   set bit[1] to 1

2. Set GPIOB to Output mode
   GPIO_BASE = 0x48000400
   GPIOx_MODER = 0x00 //enable port mode as in,out
   set bit[29:28] to 0x01 to enable PB14 as output

3. Write to GPIO Data Register to toggle LED
   GPIO_BASE = 0x48000400
   GPIOx_ODR = 0x14
   set bit[14] to 1 -> 0x4000 //turn led on
   set bit[14] to 0 -> 0x0 //turn led off
*/

//base address and offset address
//define <replace this> <with this> //pre processing part
#define RCC_BASE (0x40021000)
#define GPIOB_BASE (0x48000400)
#define GPIOA_BASE (0x48000000)
#define RCC_AHB2ENR_OFFSET (0x4C)
#define GPIO_MODER_OFFSET (0x00)
#define GPIO_ODR_OFFSET (0x14)

//register access macros
#define REG_RCC_AHB2ENR (*(unsigned int*)(RCC_BASE + RCC_AHB2ENR_OFFSET))

#define REG_GPIOB_MODE (*(unsigned int*)(GPIOB_BASE + GPIO_MODER_OFFSET))
#define REG_GPIOB_ODR (*(unsigned int*)(GPIOB_BASE + GPIO_ODR_OFFSET))

#define REG_GPIOA_MODE (*(unsigned int*)(GPIOA_BASE + GPIO_MODER_OFFSET))
#define REG_GPIOA_ODR (*(unsigned int*)(GPIOA_BASE + GPIO_ODR_OFFSET))

//application specific macros
#define ORD14 (1 << 14)
#define ORD5 (1 << 5)
#define GPIOB_EN (1 << 1)
#define GPIOA_EN (1 << 0)

#if 1

int main()
{
   int counter=1;
   REG_RCC_AHB2ENR = GPIOA_EN;
   REG_GPIOA_MODE &= 0xFFFFF7FF;
   
   while(1) {
      while(counter < 500000) {
         counter++;
      }
      counter=1;
   
      REG_GPIOA_ODR |= ORD5;
   
      while(counter < 500000) {
         counter++;
      }
      counter=1;
      
      //0000_0000_0001_0000 : ORD5
      //1111_1111_1110_1111 : ~ORD5
      REG_GPIOA_ODR ^= ORD5;
      
      
   }
  
}
#endif

