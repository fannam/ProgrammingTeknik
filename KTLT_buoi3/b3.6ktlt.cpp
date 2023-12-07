//PHAN HOANG NAM - 20215434
//Bài 3.6. Tìm ước chung lớn nhất của hai số nguyên a, b cho trước.
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b){//tính ucln theo cách đệ quy
    if (b == 0) return a;//nếu b=0 thì trả về a
    return gcd(b, a % b);//nếu không thì gọi đệ quy 
}

int gcd2(int a, int b){
    
    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #*/
    while(a!=b){//lặp tới khi a=b
        if(a>b) a = a - b;//lấy số lớn trừ số nhỏ liên tục
        else b = b - a;
    }//PHAN HOANG NAM - 20215434
    return a;//trả về ucln
    /*****************/
}

int main() {
    int a, b;//khai báo a, b
    cin >> a >> b;//nhập a, b
    cout << gcd(a, b) << endl << gcd2(a, b);//in ra ucln theo 2 cách tính
    return 0;
}