/*Đa năng hóa toán tử
Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức.*/

#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

typedef struct Complex { //Tạo kiểu dữ liệu Complex có 2 thành phần real và imag 
    double real; 
    double imag;
}Complex;

Complex operator + (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #*/
    Complex result; //khai báo biến Complex trung gian tên là result 
    result.real = a.real + b.real; //gán thành phần real của biến result = tổng 2 thành phần real của tham số a và b  
    result.imag = a.imag + b.imag;//gán thành phần imag của biến result = tổng 2 thành phần imag của tham số a và b  
    return result;//trả về biến result đã được tính 
    /*****************/
}

Complex operator - (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #*/
    Complex result; //khai báo biến Complex trung gian tên là result 
    result.real = a.real - b.real; //gán thành phần real của biến result = hiệu 2 thành phần real của tham số a và b  
    result.imag = a.imag - b.imag;//gán thành phần imag của biến result = hiệu 2 thành phần imag của tham số a và b  
    return result;//trả về biến result đã được tính 
    /*****************/
}

Complex operator * (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #*/
    //(a+bi)(c+di) = ac+adi+bci-bd = (ac-bd)+(ad+bc)i
    //a = a.real, b=a.imag, c=b.real, d=c.imag 
    Complex result; //khai báo biến Complex trung gian tên là result 
    result.real = a.real * b.real - a.imag * b.imag; //gán thành phần real của biến result bằng kết quả theo công thức
    result.imag = a.real * b.imag + a.imag * b.real;//gán thành phần imag của biến result bằng kết quả theo công thức 
    return result;//trả về biến result đã được tính 
    /*****************/
}

Complex operator / (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #*/
    //(a+bi)/(c+di)=(a+bi)(c-di)/(c^2+d^2) 
    // = (ac-adi+bci+bd)/(c^2+d^2) = (ac+bd)/(c^2+d^2) + (bc-ad)i/(c^2+d^2)
    //a = a.real, b=a.imag, c=b.real, d=c.imag 
    Complex result; //Khai báo biến Complex tên là result
    Complex temp; //Khai báo biến Complex trung gian tên là temp
    temp.real = b.real; //gán temp.real = b.real
    temp.imag = -b.imag; //gán temp.imag = b.imag
    result = a*temp; //Dùng trực tiếp phép nhân đã đa năng hóa cho kiểu Complex
    result.real = result.real/(b.real*b.real + b.imag*b.imag); //Chia kết quả cho c^2+d^2
    result.imag = result.imag/(b.real*b.real + b.imag*b.imag); //Chia kết quả cho c^2+d^2
    return result;//trả về biến Complex result đã được tính 
    /*****************/
}

ostream& operator << (ostream& out, const Complex &a) { //đa năng hóa toán tử <<
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    //output mặc định lấy tối đa 2 chữ số thập phân sau dấu phẩy 
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b; //khởi tạo các biến 
    cin >> real_a >> img_a; //nhập vào các giá trị trung gian 
    cin >> real_b >> img_b; //nhập vào các giá trị trung gian 
    
    Complex a{real_a, img_a}; //gán vào biến Complex a
    Complex b{real_b, img_b}; //gán vào biến Complex b 
    
    cout << a << " + " << b << " = " << a + b << endl; //in ra a+b
    cout << a << " - " << b << " = " << a - b << endl; //in ra a-b
    cout << a << " * " << b << " = " << a * b << endl; //in ra a*b
    cout << a << " / " << b << " = " << a / b << endl; //in ra a/b 
    
    return 0;
}