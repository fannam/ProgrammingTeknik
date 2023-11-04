/*Bài 1.10. Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, trong đó n nhập từ bàn phím. 
Sau đó tính tổng và tích của hai ma trận đó và đưa kết quả ra màn hình.
Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.
*/
//PHAN HOANG NAM - 20215434
#include<stdio.h>
#include<stdlib.h>

void allocate_mem(int ***mt, int n){
    *mt = (int**)malloc(n*sizeof(int*)); //cap phat hang cho mang mt
    if(*mt == NULL){ //neu mt = NULL, giai phong mt va ket thuc ham
        printf("memory allocation error\n");
        free(*mt);
        return;
    }
    for(int i=0; i<n; i++){ 
        (*mt)[i]=(int*)malloc(n*sizeof(int)); //cap phat cot cho mang mt
        if((*mt)[i]==NULL){ //neu ton tai 1 cot = NULL
            for(int j=0; j<i; j++) free((*mt)[j]); //giai phong cac cot da cap phat truoc do
            free(*mt); //giai phong mt
            return; //ket thuc ham
        }
    }
}
//PHAN HOANG NAM - 20215434
int **plusMatrix(int **matrix1, int **matrix2, int n){
	int **newMatrix = NULL; //khoi tao con tro cap 2
	allocate_mem(&newMatrix, n); //cap phat bo nho cho mang newMatrix
	for(int i=0; i<n; i++){ //cong hai ma tran
		for(int j=0; j<n; j++){
			newMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return newMatrix; //tra ve con tro tro toi dau ma tran da cong
}
//PHAN HOANG NAM - 20215434
int **multiplyMatrix(int **matrix1, int **matrix2, int n){
	int **newMatrix = NULL; //khoi tao con tro cap 2
	allocate_mem(&newMatrix, n); //cap phat bo nho cho mang newMatrix
	for(int i=0;i<n;++i){ //nhan 2 ma tran
        for(int j=0;j<n;++j)
        {
            newMatrix[i][j]=0;
            for(int k=0;k<n;++k)
                newMatrix[i][j]=newMatrix[i][j]+(matrix1[i][k]*matrix2[k][j]);
        }
    }
    return newMatrix;
}
//PHAN HOANG NAM - 20215434
void free_mem(int **mt, int n){
	for(int i=0; i<n; i++){
		free(mt[i]);
	}
	free(mt);
}
//PHAN HOANG NAM - 20215434
int main(){
	int n;
	printf("PHAN HOANG NAM - 20215434\n");
	scanf("%d", &n);
	int **matrix1 = NULL; //khoi tao 2 ma tran
	int **matrix2 = NULL;
	allocate_mem(&matrix1, n); //cap phat bo nho cho 2 ma tran
	allocate_mem(&matrix2, n);	
	//printf("Nhap ma tran 1: ");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//printf("mt1[%d][%d] = ", i, j);
			scanf("%d", &matrix1[i][j]);
		}
	}
	//printf("Nhap ma tran 2: ");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//printf("mt1[%d][%d] = ", i ,j);
			scanf("%d", &matrix2[i][j]);
		}
	}
	int **plus_matrix = plusMatrix(matrix1, matrix2, n); //luu ket qua cong ma tran vao plus_maxtrix
	//plus_matrix la ket qua cong ma tran
	int **multiply_matrix = multiplyMatrix(matrix1, matrix2, n);//luu ket qua nhan ma tran vao multiply_matrix 
	//multiply_matrix la ket qua nhan ma tran
	for(int i=0; i<n; i++){ //in ra ma tran cong
		for(int j=0; j<n; j++){
			printf("%d ", plus_matrix[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<n; i++){ //in ra ma tran nhan
		for(int j=0; j<n; j++){
			printf("%d ", multiply_matrix[i][j]);
		}
		printf("\n");
	}
	free_mem(matrix1, n); //giai phong bo nho cac ma tran da cap phat bo nho
	free_mem(matrix2, n);
	free_mem(plus_matrix, n);
	free_mem(multiply_matrix, n);
}
//PHAN HOANG NAM - 20215434