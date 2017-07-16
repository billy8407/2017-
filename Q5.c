#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>                                                           
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        fork();
        printf("-");
   }
   wait(NULL); wait(NULL); wait(NULL);/*�����Ҧ����l�{�Ǥ~�|����*/ 
   return 0;
}
/* 
�j��q parent�}�l, i == 0
Parent fork()s, �ͦ� child 1  �{�b����ӵ{��
�j�魫�s�}�l �{�bi==1 
Parent and child 1 fork(), �ͦ� children 2 and 3.
Parent fork()s, �ͦ� child 1  �{�b���|�ӵ{��
�j�魫�s�}�l �{�bi==2
Parent and children 1 ~ 3 fork(), �ͦ� children 4 ~ 7.
�C�ӵ{�Ǫ��j�魫�s�}�l �{�bi==3
�{�b���K�ӵ{�� 
i < 3 ������  �j�鰱��
�`�@�L�X24��  -(8�ӵ{��  �C�ӦL�X�T��(i=0,i=1,i=2)) 
*/
