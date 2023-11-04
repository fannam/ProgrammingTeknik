//PHAN HOÀNG NAM 20215434
/*Bài 1.5. Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double.
Nếu mảng rỗng hãy trả về NULL.
*/

#include<stdio.h>
double *maximum(double *a, int size){
    double *max; //khai báo con trỏ max
    max = a; //gán con trỏ max trỏ tới phần tử đầu tiên của mảng
    if(a==NULL) return NULL; //nếu mảng là NULL thì trả về NULL, kết thúc hàm 
//*****************
    /*YOUR CODE HERE - PHAN HOÀNG NAM - 20215434 */ 
    for(int i=0; i<size; i++){ 
        if(a[i]>*max) max=&a[i]; //duyệt mảng, nếu a[i]>giá trị con trỏ max trỏ tới  
                                // thì gán con trỏ max trỏ tới địa chỉ a[i]
    }
//***************** 
    return max; //trả về con trỏ max trỏ tới phần tử có giá trị lớn nhất của mảng 
}
//PHAN HOÀNG NAM - 20215434 
