//PHAN HOANG NAM - 20215434
/*Bài 3.5. Tính hệ số tổ hợp C(n, k)*/

#include <iostream>
using namespace std;

int binom(int n, int k) {//hàm tính C(k,n) bằng đệ quy
    if (k > n) return 0;//trường hợp k>n trả về 0
    if (k == 0) return 1;//trường hợp k=0 thì trả về 1
    return binom(n-1, k) + binom(n-1, k-1); //công thức C(k,n)=C(k,n-1)+C(k-1,n-1)
}
int C[1000][1000];
int binom2(int n, int k){
    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #*/
    for(int i=0; i<=n; i++){//quy hoạch động, lặp qua tất cả các phần tử C(j,i) với 0<=j<=i<=n
		for(int j=0; j<=i; j++){
			if(j==0) C[j][i]=1;//nếu j=0 thì C[j][i]=1
			else if(i==j) C[j][i]=1;//nếu j=i thì C[i][j]=1
			else
				C[j][i] = (C[j][i-1] + C[j-1][i-1]);//công thức C(k,n)=C(k,n-1)+C(k-1,n-1)
		}//PHAN HOÀNG NAM - 20215434
    }
    /*****************/
    return C[k][n];//trả về giá trị C[k][n]
}

int main() {
    int m;//khai báo biến m
    cin >> m;//nhập m
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));//tính C(k,n) kiểu đệ quy
        printf("\n");
    }//PHAN HOÀNG NAM - 20215434
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));//tính C(k,n) kiểu không đệ quy
        printf("\n");
    }
    return 0;
}