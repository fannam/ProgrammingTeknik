//PHAN HOÀNG NAM - 20215434
/*Bài 1.7. Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím. Sau đó sắp xếp mảng theo thứ tự tăng dần.
Hiển thị danh sách mảng trước và sau khi sắp xếp.
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n; //khai báo biến n là kích thước của mảng 
    printf("Enter the number of elements: ");
    scanf("%d", &n); //nhập n 
    int *arr; //khai báo con trỏ kiểu int
    arr = (int*)malloc(n*sizeof(int)); //cấp phát bộ nhớ cho mảng 
    for(int i=0; i<n; i++) scanf("%d", arr+i ); //nhập dữ liệu cho mảng  
    printf("The input array is:\n");
    for(int i=0; i<n; i++) printf("%d ", *(arr+i)); //in ra mảng vừa nhập 
//*****************
//YOUR CODE HERE - PHAN HOÀNG NAM - 20215434
    for(int i=0; i<n; i++){ //sắp xếp mảng 
        for(int j=i; j<n; j++){
            if(*(arr+i)>*(arr+j)){
                int tmp = *(arr+i); //gán arr[i] cho tmp
                *(arr+i) = *(arr+j); //gán arr[j] cho arr[i] 
                *(arr+j) = tmp; //gán tmp cho arr[j]
            }
        }
    }
//*****************
    printf("\nThe sorted array is:\n");
    for(int i=0; i<n; i++) printf("%d ", *(arr+i)); //in ra mảng đã sắp xếp 
}
//PHAN HOÀNG NAM - 20215434 