/*Bài tập 3: Tham số ngầm định
Viết chương trình yêu cầu nhập giá trị cho số nguyên x nhỏ hơn 100. In ra giá trị  ax2+bx+c
  với a, b, c định sẵn.*/
  
#include <stdio.h>

//# Viết hàm get_value
/*****************
# YOUR CODE HERE #*/
int get_value(int x, int a=2, int b=1, int c=0){//hàm có tham số với giá trị mặc định a=2, b=1, c=0 
    return a*x*x + b*x + c; //trả về giá trị ax2+bx+c 
}
/*****************/

int main(){
    int x;
    scanf("%d", &x);//Nhập xx
    
    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c
    
    //# Nhập 3 số nguyên a, b, c từ bàn phím
    /*****************
    # YOUR CODE HERE #*/
    scanf("%d %d %d", &a, &b, &c);
    /*****************/
    
    printf("a=2, b=1, c=0: %d\n", get_value(x)); //in ra hàm với 1 tham số x và 3 tham số mặc định a,b,c
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a)); //in ra hàm với tham số x, a và 2 tham số mặc định b,c 
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b)); //in ra hàm với tham số x, a, b và tham số mặc định b
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));//in ra hàm với tham số x, a, b, c
    
    return 0;
}