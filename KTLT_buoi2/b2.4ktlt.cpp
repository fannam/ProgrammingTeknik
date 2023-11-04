/*Bài tập 4: Đa năng hóa hàm
Viết các hàm tính lập phương của số nguyên và số thực.*/

#include <stdio.h>

int cube(int x) {//hàm cube trả về kiểu int, nhận vào tham số kiểu int 
    /*****************
    # YOUR CODE HERE #*/
    return x*x*x; //trả về lập phương của x
    /*****************/
}

//# viết hàm tính lập phương của một số kiểu double
/*****************
# YOUR CODE HERE #*/
double cube(double x){//hàm cube trả về kiểu double, nhận vào tham số kiểu double 
    return x*x*x;//trả về lập phương của xx
}
/*****************/

int main() {
    int n; //khai báo biến n
    double f;//khai báo biến f
    scanf("%d %lf", &n, &f); //nhập vào n và f 
    
    printf("Int: %d\n", cube(n)); //in ra giá trị trả về của cube(n)
    printf("Double: %.2lf\n", cube(f));//in ra giá trị trả về của cube(f)
    
    return 0;
}