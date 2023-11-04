/*Bài tập 7: Khái quát hóa hàm
Viết hàm tính tổng các phần tử trong hai mảng.
Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.*/

#include <iostream>
using namespace std;

//# viết hàm arr_sum
/*****************
# YOUR CODE HERE #*/
template<typename T> //Khai báo kiểu template T 
T arr_sum(T *arr1, int size1, T *arr2, int size2){ //Hàm arr_sum trả về giá trị kiểu T
//nhận tham số là con trỏ kiểu T trỏ tới 1 mảng 1 chiều, biến nguyên là kích thước của mảng 
    T sum=0; //khai báo và khởi tạo biến sum = 0 có kiểu T 
    for(int i=0; i<size1; i++) sum+=arr1[i]; //cộng các phần tử của arr1 vào sum
    for(int i=0; i<size2; i++) sum+=arr2[i]; //cộng các phần tử của arr2 vào sum  
    return sum;
}
/*****************/

int main() {
    int val;
    cin >> val; //Nhạp vào biến val
    
    {
        int a[] = {3, 2, 0, val}; //Khởi tạo các phần tử của mảng a
        int b[] = {5, 6, 1, 2, 7};//Khởi tạo các phần tử của mảng b  
        cout << arr_sum(a, 4, b, 5) << endl; //in ra giá trị trả về của hàm arr_sum
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};//Khởi tạo các phần tử của mảng a
        double b[] = {5, 6.1, 1, 2.3, 7};//Khởi tạo các phần tử của mảng b  
        cout << arr_sum(a, 4, b, 5) << endl;//in ra giá trị trả về của hàm arr_sum
    }

    return 0;
}