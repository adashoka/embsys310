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

/*
//morse code notes
- symbol1                                    = dot (one unit)
- symbol2                                    = dash (3 x the duration of dot)
- inter symbol space in a character(iss)     = 1 x the duration of the dot
- inter letter space in a word(ils)          = 3 x the duration of a dot
- inter word space in a sentence             = 7 x the duratoin of a dot

aditya
a:dot,iss,dash
ils

d:dash,iss,dot,iss,dot
ils

i:dot,iss,dot
ils

t:dash
ils

y:dash,iss,dot,iss,dash,iss,dash
ils



*/

#if 1
void symbol_delay(int time_unit,int multiplier)
{
   int counter=multiplier*time_unit;
   while(counter > 0)
   {
      counter--;
   }
}

void dot(int time_unit) {
   REG_GPIOA_ODR |= ORD5;//on
   symbol_delay(time_unit,1);
   REG_GPIOA_ODR &= ~ORD5;//off
}

void dash(int time_unit) {
   REG_GPIOA_ODR |= ORD5;//on
   symbol_delay(time_unit,3);
   REG_GPIOA_ODR &= ~ORD5;//off
}

void inter_symbol_interval(int time_unit){
   symbol_delay(time_unit,1);
}
void inter_letter_interval(int time_unit){
   symbol_delay(time_unit,3);
}

void character_a(int time_unit)
{
   //a:dot,iss,dash   
   dot(time_unit);
   inter_symbol_interval(time_unit);
   dash(time_unit);
}

void character_d(int time_unit)
{
   //d:dash,iss,dot,iss,dot
   dash(time_unit);
   inter_symbol_interval(time_unit);
   dot(time_unit);
   inter_symbol_interval(time_unit);
   dot(time_unit);
}

void character_i(int time_unit)
{
   //i:dot,iss,dot
   dot(time_unit);
   inter_symbol_interval(time_unit);
   dot(time_unit);
}

void character_t(int time_unit)
{
   //t:dash
   dash(time_unit);
}

void character_y(int time_unit)
{
   //y:dash,iss,dot,iss,dash,iss,dash
   dash(time_unit);
   inter_symbol_interval(time_unit);
   dot(time_unit);
   inter_symbol_interval(time_unit);
   dash(time_unit);
   inter_symbol_interval(time_unit);
   dash(time_unit);
}

int main()
{ 
   int time_unit=500000;
   REG_RCC_AHB2ENR = GPIOA_EN;
   REG_GPIOA_MODE &= 0xFFFFF7FF;
   char first_name[] = {'a','d','i','t','y','a','\0'};
   //enhancement use generic terminal count (while and null character)
   for (int i = 0; i < 6; i++){
      if(first_name[i] == 'a') {
         character_a(time_unit);
      }
      else if(first_name[i] == 'd') {
         character_d(time_unit);
      }
      else if(first_name[i] == 'i') {
         character_i(time_unit);
      }
      else if(first_name[i] == 't') {
         character_t(time_unit);
      }
      else if(first_name[i] == 'y') {
         character_y(time_unit);
      }
      inter_letter_interval(time_unit);
   }
   
      

  
}


#endif

