/*Bài tập 2: Truyền tham chiếu
Viết hàm hoán vị vòng tròn 3 biến a, b, c. Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.*/

#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    /*****************
    # YOUR CODE HERE #*/
    int temp; //khai báo biến tạm 
    temp = x; //gán x vào temp 
    x = y; //gán y vào x
    y = z; //gán z vào y
    z = temp; //gán temp vào z
    //->Đổi chỗ (a,b,c) thành (b,c,a)
    /*****************/
}

int main() {
    int x, y, z;
    
    //# Nhập 3 số nguyên
    /*****************
    # YOUR CODE HERE #*/
    scanf("%d %d %d", &x, &y, &z);
    /*****************/
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}