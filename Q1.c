
/*²Ä¤@ÃD*/ 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdint.h>

uint16_t func(uint16_t x) {
   uint16_t n = x;
   int i,a;
   for(i=1;i<=4;i++)
   {
   	  if(i==1)
   	 {
	    n = ((n & 0xff00) >> 8) | ((n & 0x00ff) << 8);
	 }
      if(i==2)
     {
        n = ((a & 0xf0f0) >>  4) | ((a & 0x0f0f) <<  4);
     }
	  if(i==3)
	 {
	 	 n = ((a & 0xcccc) >>  2) | ((a & 0x3333) <<  2);
	 }
      if(i==4)
     {
     	n = ((a & 0xaaaa) >>  1) | ((a & 0x5555) <<  1);    
	    return n; 
	 }	
	 a=n;
   }
   
	

    
}
int main(int argc, char *argv[]) {
	int n;
	n=func(0x00ff);
	printf("%x",n);
	return 0;         
}
