
//base address
#define BASE_GPIOA (0x48000000)
#define BASE_RCC (0x40021000)

//register offsets
#define OFFSET_RCC_AHB2ENR (0x4C)
#define OFFSET_GPIOx_MODER (0x00)
#define OFFSET_GPIOx_ODR (0x14)

//registers
#define REG_RCC_AHB2ENR (*(unsigned int*)(BASE_RCC+OFFSET_RCC_AHB2ENR))
#define REG_GPIOA_MODER (*(unsigned int*)(BASE_GPIOA+OFFSET_GPIOx_MODER))
#define REG_GPIOA_ODR (*(unsigned int*)(BASE_GPIOA+OFFSET_GPIOx_ODR))

//setbit
#define SET5 (1 << 5);
int main()
{
   int counter=0;
   
   //without bitband
   REG_RCC_AHB2ENR |= 0x1;
   
   //with bitband
   //*((unsigned int*)((0x42000000)+(0x2104C * 32)+(0*4))) = 0x1;
   
 
   
   
   REG_GPIOA_MODER &= 0xFFFFF7FF;
   //ODR:XXXX_
   // 0000 = 0 
   // 0000 = 0
   // 0010 = 2
   // 0000 = 0
   //LED1@PA5
   while(1) {
      
      counter=0;
      while(counter < 100000) {
         counter++;
      }
      REG_GPIOA_ODR ^= SET5;
      
      counter=0;
      while(counter < 100000) {
         counter++;
      }
      REG_GPIOA_ODR ^= SET5;
   }

}