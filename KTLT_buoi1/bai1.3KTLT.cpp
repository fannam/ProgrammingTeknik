//PHAN HOÀNG NAM - 20215434 

/*Bài 1.3. Viết chương trình yêu cầu nhập giá trị cho 3 biến số nguyên x, y, z kiểu int.
Sau đó sử dụng duy nhất một con trỏ để cộng giá trị của mỗi biến thêm 100.
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int x,y,z;
    int *ptr;
    scanf("%d %d %d\n", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
//*********************
//YOUR CODE HERE - PHAN HOÀNG NAM 20215434 
    ptr = &x;
    *ptr += 100;
    ptr = &y;
    *ptr += 100;
    ptr = &z;
    *ptr +=100;
//*********************
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}
//PHAN HOÀNG NAM 20215434 