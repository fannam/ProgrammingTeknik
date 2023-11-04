//PHAN HOANG NAM - 20215434
/*Viết chương trình in ra tất cả các dãy con của một dãy cho trước. 
*/
#include<stdio.h>
#include<stdlib.h>
void allocate_mem(int **arr, int n){
	*arr = (int*)malloc(n*sizeof(int)); //cap phat bo nho cho mang
	if(arr==NULL) { //neu arr = NULL thi in ra thong bao loi cap phat va ket thuc ham
		printf("memory allocation error\n");
		return;
	}
}
int main(){
	int n; //khai bao bien n la kich thuoc mang
	int *arr; //khai bao con tro kieu int
	printf("PHAN HOANG NAM - 20215434\n");
	scanf("%d", &n); //nhap n
	allocate_mem(&arr, n); //cap phat bo nho cho mang
	for(int i=0; i<n; i++) scanf("%d", &arr[i]); //nhap du lieu cho mang
	
	for(int i=0; i<n; i++){ //in ra cac day con
		for(int j=i; j<n; j++){ 
			for(int k=i; k<=j; k++){
				printf("%d ", arr[k]);
			}
			printf("\n");
		}
	}
}//PHAN HOANG NAM - 20215434