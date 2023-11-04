//PHAN HOÀNG NAM - 20215434 

/*Bài 1.1. Viết một chương trình C nhập vào 3 số nguyên. Thiết lập một con trỏ để lần 
lượt trỏ tới từng số nguyên và hiển thị kết quả giá trị tham chiếu ngược của con trỏ.

Lưu ý: Phép toán & trả về địa chỉ của biến.
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int x,y,z; //khai báo 3 biến nguyên x, y, z
    int *ptr; //khai báo con trỏ kiểu int 
    printf("Enter three integers:\n"); 
    scanf("%d %d %d", &x, &y, &z); //Nhập 3 biến x, y, z
    printf("The three integers are:\n");
    ptr = &x; //con trỏ trỏ đến địa chỉ của x
    printf("x = %d\n", *ptr); //In ra giá trị ô nhớ con trỏ trỏ đến 
    //******************
    /*YOUR CODE HERE - PHAN HOÀNG NAM - 20215434 */
    ptr = &y; //con trỏ trỏ đến địa chỉ của y
    printf("y = %d\n", *ptr); //In ra giá trị ô nhớ con trỏ trỏ đến
    ptr = &z; //con trỏ trỏ đến địa chỉ của z
    printf("z = %d\n", *ptr); //In ra giá trị ô nhớ con trỏ trỏ đến
    //******************
    return 0;
}
//PHAN HOÀNG NAM - 20215434 