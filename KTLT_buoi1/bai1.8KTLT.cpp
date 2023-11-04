#include <stdio.h>
#include<stdlib.h>
void allocate_mem(int ***mt, int m, int n){
    //#Allocate memory for the matrix
    *mt = (int**)malloc(m*sizeof(int*)); //cap phat hang cho mang mt
    if(*mt == NULL){ //neu mt = NULL, giai phong mt va ket thuc ham
        printf("memory allocation error\n");
        free(*mt);
        return;
    }
    for(int i=0; i<m; i++){ 
        (*mt)[i]=(int*)malloc(n*sizeof(int)); //cap phat cot cho mang mt
        if((*mt)[i]==NULL){ //neu ton tai 1 cot = NULL
            for(int j=0; j<i; j++) free((*mt)[j]); //giai phong cac cot da cap phat truoc do
            free(*mt); //giai phong mt
            return; //ket thuc ham
        }
    }
    /*****************
    # YOUR CODE HERE #
    *****************/
}


void input(int **mt, int m, int n){
    //#Input elements of the matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", &mt[i][j]); //nhap du lieu cho mang
        }
    }
    /*****************
    # YOUR CODE HERE #
    
    *****************/
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", mt[i][j]); //in ra cac phan tu cua mang
        }
        printf("\n");
    }
    /*****************
    # YOUR CODE HERE #
    *****************/ 
    
}

int process(int **mt, int m, int n){
    int tong = 0;
    //# Calculate the sum of all even elements in the matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mt[i][j]%2==0) tong+=mt[i][j]; //neu phan tu vua nhap chia het cho 2, cong vao sum_even
        }
    }
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    return tong;
}

void free_mem(int **mt, int m, int n){
    //# Free memory
    for(int i=0; i<m; i++){
    	free(mt[i]);
	}
	free(mt);
    /*****************
    # YOUR CODE HERE #
    *****************/
}

int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}