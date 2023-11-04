//PHAN HOÀNG NAM - 20215434 
//Bài 1.6. Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.
#include<stdio.h>
void reversearray(int arr[], int size){
    int l=0, r=size-1, tmp; //l = vị trí đầu tiên của mảng, r = vị trí cuối cùng của mảng 
//*********************
//YOUR CODE HERE - PHAN HOÀNG NAM - 20215434 
    while(l<r){ 
        tmp = arr[l];
        arr[l] = arr[r];  //hoán đổi giá trị 2 phần tử của mảng
        arr[r] = tmp;  
        l++; //tăng biến l lên 1 đơn vị 
        r--; //giảm biến r đi 1 đơn vị 
    }
//*********************
}
void ptr_reversearray(int *arr, int size){
    int l=0, r=size-1, tmp; //l = vị trí đầu tiên của mảng, r = vị trí cuối cùng của mảng 
//*********************
//YOUR CODE HERE - PHAN HOÀNG NAM - 20215434 
    while(l<r){
        tmp = arr[l];
        arr[l] = arr[r]; //hoán đổi giá trị 2 phần tử của mảng
        arr[r] = tmp;
        l++; //tăng biến l lên 1 đơn vị
        r--; //giảm biến r đi 1 đơn vị
    }
//********************
}
//PHAN HOÀNG NAM - 20215434 