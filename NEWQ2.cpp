#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sx1(int ,int );
int  pc(int ,int );	 
uint32_t half_add(uint32_t a, uint32_t b) {
    if (b == 0) return a;
    uint32_t sum = a ^ b;             /* �ۥ[�����i�� */
    uint32_t carry = (a & b) << 1;    /* �i������ۥ[ */
    return half_add(sum, carry);
}
int sx1(int a,int b)
{
   int x,z,cc,sum,i;
   cc=0;
   sum=0;  
   while(a!=0&&b!=0) /*���ƬY�@�줸�Ʀr���s  �N���ݭp��*/ 
   {
        x=a%10;/*�����X�Ʀr1���C�@�Ӧ줸(1)*/ 
        if(cc>=1)/*c>=1��ܼƦr1�O�Q��ƥH�W  �Ʀr1�����X�Ӫ��Ʀr�������W�ӼƦr�۹���10�����譼�n*/
    	{
       		for(i=1;i<=cc;i++)
           		x=x*10;
   		}
   		z=pc(x,b);/*��Ʀr1���Y�@�Ӧ줸�M�Ʀr2���Y�@�Ӧ줸��hpc function�B�z*/
   		a=a/10;/*�����X�Ʀr1���C�@�Ӧ줸(2)*/ 
    	sum=sum+z;  /*��^�Ǧ^�Ӫ��Ʀr���[�`*/
  	  		cc++;
}
    return sum;
} 
int pc(int a,int b)
{
	
	int i,x;
	 if(b==1) /*�Ʀr2���Y�@�줸�Ʀr��1�ɡA�Ʀr1�M�Ʀr2�Y�줸�ۭ����ӼƦr1�A�G���ݰ��p��A�����^�Ǹӭ�*/ 
	 {
		x=a;
	 }
 	 for(i=1;i<=b-1;i++)/*�Q�Υb�[���p��ۭ����n*/ 
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
	printf("�п�J2�ӼơA�Q�Υb�[���D�X��Ƭۭ�����\n");
   
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
    while(x2!=0)/*��Ʀr2������0�ɶi�J�j��*/ 
    {
    	l=x2%10; /*�����X�Ʀr2���C�@�Ӧ줸(1)*/  
    	if(c>=1)/*c>=1��ܼƦr2�O�Q��ƥH�W  �Ʀr2�����X�Ӫ��Ʀr�������W�ӼƦr�۹���10�����譼�n*/
    	{
    		for(i=1;i<=c;i++)
    			l=l*10;
		}
    	z=sx1(x1,l);/*��Ʀr1�M�Ʀr2���Y�@�Ӧ줸��hsx1 function�B�z*/
    	f=f+z;/*��^�Ǧ^�Ӫ��Ʀr���[�`*/
		x2=x2/10;/*�����X�Ʀr2���C�@�Ӧ줸(2)*/
    	c++;
	}
	if(f!=j*k)
	{
	

	 printf("�{�������`");
	 return 0;
	  
}
	}
    }
 printf("�{�����`");
 return 0;
}
