/*Vi?t chuong trình in ra d?a ch? c?a 5 ph?n t? d?u tiên trong m?ng du?c d?nh nghia sau dây:
 int a[7]= {13, -355, 235, 47, 67, 943, 1222};
*/
//PHAN HOANG NAM - 20215434
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[7]={13, -355, 235, 47, 67, 943, 1222};
	int *ptr;
	printf("\nPhan Hoang Nam - 20215434\n");
	printf("address of first five elements in memory.\n");
	for(int i=0; i<5; i++) printf("\t\t\ta[%d] ", i);
	printf("\n");
	for(int i=0; i<5; i++) printf("\t    %p", &a[i]);
	printf("\n");
	return 0;
}