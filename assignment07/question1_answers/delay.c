#include "delay.h"
#include <stdint.h>
extern int counter_g;
void delay (uint32_t mscount) {
   counter_g=mscount;
   while(counter_g > 0){
   }  
}