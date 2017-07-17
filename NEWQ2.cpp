#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sx1(int ,int );
int  pc(int ,int );	 
uint32_t half_add(uint32_t a, uint32_t b) {
    if (b == 0) return a;
    uint32_t sum = a ^ b;             /* 相加但不進位 */
    uint32_t carry = (a & b) << 1;    /* 進位但不相加 */
    return half_add(sum, carry);
}
int sx1(int a,int b)
{
   int x,z,cc,sum,i;
   cc=0;
   sum=0;  
   while(a!=0&&b!=0) /*當兩數某一位元數字為零  就不需計算*/ 
   {
        x=a%10;/*分離出數字1的每一個位元(1)*/ 
        if(cc>=1)/*c>=1表示數字1是十位數以上  數字1分離出來的數字必須乘上該數字相對應10的次方乘積*/
    	{
       		for(i=1;i<=cc;i++)
           		x=x*10;
   		}
   		z=pc(x,b);/*把數字1的某一個位元和數字2的某一個位元丟去pc function處理*/
   		a=a/10;/*分離出數字1的每一個位元(2)*/ 
    	sum=sum+z;  /*把回傳回來的數字做加總*/
  	  		cc++;
}
    return sum;
} 
int pc(int a,int b)
{
	
	int i,x;
	 if(b==1) /*數字2的某一位元數字為1時，數字1和數字2某位元相乘為該數字1，故不需做計算，直接回傳該值*/ 
	 {
		x=a;
	 }
 	 for(i=1;i<=b-1;i++)/*利用半加器計算相乘乘積*/ 
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
	int l,s,sx2,a,z,sum,carry,x,f,fa,c,i,j,k;
	
	int x1;
	int x2;
	printf("請輸入2個數，利用半加器求出兩數相乘之值\n");
   
   for(j=1;j<=999;j++)
   {
   	for(k=1;k<=999;k++)
   {
   	
   x1=j;
   x2=k;
   sum=0;
	c=0;
	f=0;
	printf("j=%d\n",j);
	printf("k=%d\n",k);
    while(x2!=0)/*當數字2不等於0時進入迴圈*/ 
    {
    	l=x2%10; /*分離出數字2的每一個位元(1)*/  
    	if(c>=1)/*c>=1表示數字2是十位數以上  數字2分離出來的數字必須乘上該數字相對應10的次方乘積*/
    	{
    		for(i=1;i<=c;i++)
    			l=l*10;
		}
    	z=sx1(x1,l);/*把數字1和數字2的某一個位元丟去sx1 function處理*/
    	f=f+z;/*把回傳回來的數字做加總*/
		x2=x2/10;/*分離出數字2的每一個位元(2)*/
    	c++;
	}
	if(f!=j*k)
	{
	

	 printf("程式不正常");
	 return 0;
	  
}
	}
    }
 printf("程式正常");
 return 0;
}
