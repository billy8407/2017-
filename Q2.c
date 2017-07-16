#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sx1(int ,int );
int  pc(int ,int );	 
uint32_t half_add(uint32_t a, uint32_t b) {
    if (b == 0) return a;
    uint32_t sum = a ^ b;             /* ぃ秈 */
    uint32_t carry = (a & b) << 1;    /* 秈ぃ */
    return half_add(sum, carry);
}
int sx1(int a,int b)
{
   int x,z,cc,sum,i;
   cc=0;
   sum=0;  
   while(a!=0&&b!=0) /*讽ㄢ计琘じ计箂  碞ぃ惠璸衡*/ 
   {
        x=a%10;/*だ瞒计1–じ(1)*/ 
        if(cc>=1)/*c>=1ボ计1琌计  计1だ瞒ㄓ计ゲ斗赣计癸莱10Ωよ縩*/
    	{
       		for(i=1;i<=cc;i++)
           		x=x*10;
   		}
   		z=pc(x,b);/*р计1琘じ㎝计2琘じメpc function矪瞶*/
   		a=a/10;/*だ瞒计1–じ(2)*/ 
    	sum=sum+z;  /*р肚ㄓ计暗羆*/
  	  		cc++;
}
    return sum;
} 
int pc(int a,int b)
{
	
	int i,x;
	 if(b==1) /*计2琘じ计1计1㎝计2琘じ赣计1珿ぃ惠暗璸衡钡肚赣*/ 
	 {
		x=a;
	 }
 	 for(i=1;i<=b-1;i++)/*ノ竟璸衡縩*/ 
     {
  		if(i==1)
	     {
	  		x=0;
  		x=half_add(a,a);
     	}
		else{
			x=half_add(x,a); 
     		}  
    } 
   return x;
} 
 
int main(int argc, char *argv[]) {
	int l,s,sx2,a,z,sum,carry,x,f,fa,c,i;
	sum=0;
	c=0;
	f=0;
	int x1;
	int x2;
	printf("叫块2计ノ竟―ㄢ计ぇ\n");
    printf("计1:");
	scanf("%d",&x1); /*块计1*/ 
	printf("计2:");
	scanf("%d",&x2);/*块计2*/ 
    while(x2!=0)/*讽计2ぃ单0秈癹伴*/ 
    {
    	l=x2%10; /*だ瞒计2–じ(1)*/  
    	if(c>=1)/*c>=1ボ计2琌计  计2だ瞒ㄓ计ゲ斗赣计癸莱10Ωよ縩*/
    	{
    		for(i=1;i<=c;i++)
    			l=l*10;
		}
    	z=sx1(x1,l);/*р计1㎝计2琘じメsx1 function矪瞶*/
    	f=f+z;/*р肚ㄓ计暗羆*/
		x2=x2/10;/*だ瞒计2–じ(2)*/
    	c++;
	}
	printf("氮=%d\n",f);/*氮*/ 
		return 0;
}
