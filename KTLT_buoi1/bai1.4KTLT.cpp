//PHAN HOÀNG NAM - 20215434
/*Bài 1.4. Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng,
trả về số lượng số chẵn trong mảng???
*/
#include<stdio.h>
int counteven(int *arr, int size){
    int dem=0; //đặt biến đếm = 0
    for(int i=0; i<size; i++){ 
        if(arr[i]%2==0) dem++; //nếu a[i] chia hết cho 2 thì tăng biến đếm thêm 1 
    }
    return dem; //trả về biến đếm 
}
//PHAN HOÀNG NAM - 20215434