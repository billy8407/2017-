#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>                                                           
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        fork();
        printf("-");
   }
   wait(NULL); wait(NULL); wait(NULL);/*等完所有的子程序才會結束*/ 
   return 0;
}
/* 
迴圈從 parent開始, i == 0
Parent fork()s, 生成 child 1  現在有兩個程序
迴圈重新開始 現在i==1 
Parent and child 1 fork(), 生成 children 2 and 3.
Parent fork()s, 生成 child 1  現在有四個程序
迴圈重新開始 現在i==2
Parent and children 1 ~ 3 fork(), 生成 children 4 ~ 7.
每個程序的迴圈重新開始 現在i==3
現在有八個程序 
i < 3 不成立  迴圈停止
總共印出24個  -(8個程序  每個印出三次(i=0,i=1,i=2)) 
*/
