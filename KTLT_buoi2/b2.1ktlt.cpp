/*Bài tập 1: Truyền tham trị
Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.*/

#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    /*****************
    # YOUR CODE HERE #*/
    return sqrt(x*x+y*y); //trả về căn bậc 2 của x^2+y^2 
    /*****************/
}

int main(){
    float x, y; //Khai báo biến x, y
    scanf("%f%f", &x, &y); //Nhập vào x và y
    
    float z = get_hypotenuse(x, y); //khai báo và khởi tạo z = giá trị trả về của hàm get_hypotenuse
    printf("z = %.2f\n", z); //in ra z với 2 chữ số thập phân sau dấu phẩy 
    
    return 0;
}