/*Bài tập 10 (bonus): Tính tích hai ma trận vuông Dưới đây cung cấp đoạn code đơn giản để tính tích của hai ma trận cỡ  NxN 
theo công thức trực tiếp. Hãy viết hàm tính tích hai ma trận nhưng có tốc độ nhanh hơn ít nhất 10% so với code đơn giản. 
Gợi ý: hãy để ý đến thứ tự truy cập các phần tử trong ma trận, tối ưu cache hoặc sử dụng thuật toán tốt hơn  O(N3) .*/
#include<bits/stdc++.h>
//PHAN HOÀNG NAM - 20215434 
using namespace std;

const int N = 128;

typedef struct Matrix {//khai báo kiểu dữ liệu Matrix 
    unsigned int mat[N][N]; //khai báo mảng mat NxN kiểu int 

    Matrix() {//constructor 
        memset(mat, 0, sizeof mat);//đặt các giá trị ban đầu của mat = 0 
    }
}Matrix;

bool operator == (const Matrix &a, const Matrix &b) {//đa năng hóa toán tử so sánh 2 ma trận 
    for (int i = 0; i < N; ++i) { //duyệt mọi phần tử của ma trận 
        for (int j = 0; j < N; ++j) {
            if (a.mat[i][j] != b.mat[i][j]) return false;//nếu tồn tại một phần tử khác nhau, trả về false 
        }
    }
    return true;//trường hợp còn lại trả về true 
}
//PHAN HOÀNG NAM - 20215434 
Matrix operator + (const Matrix &a, const Matrix &b){//đa năng hóa toán tử +
	Matrix c;//khai báo ma trận c 
	for (int i = 0; i < N; ++i) {//cộng theo quy tắc cộng ma trận 
        for (int j = 0; j < N; ++j) {
            c.mat[i][j] = a.mat[i][j] + b.mat[i][j];//gán vào c 
        }
    }
    return c;//trả về ma trận c 
}

Matrix operator - (const Matrix &a, const Matrix &b){//đa năng hóa toán tử -
	Matrix c;//khai báo ma trận c
	for (int i = 0; i < N; ++i) {//trừ theo quy tắc trừ ma trận 
        for (int j = 0; j < N; ++j) {
            c.mat[i][j] = a.mat[i][j] - b.mat[i][j];//gán vào c 
        }
    }
    return c;//trả về ma trận c 
}
//PHAN HOÀNG NAM - 20215434 
Matrix multiply_naive(const Matrix &a, const Matrix &b, int size) {
//hàm nhân ma trận thông thường, nhận vào tham số là ma trận a, b và kích thước ma trận sizexsize 
    Matrix c;//khai báo ma trận c 
    for (int i = 0; i < size; ++i) {//thực hiện phép nhân ma trận thông thường 
        for (int j = 0; j < size; ++j) {//từng phần tử trên 1 hàng của ma trận 1 
            for (int k = 0; k < size; ++k) {//nhân với từng phần tử trên cột của ma trận 2 
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];//một cách tương ứng, gán vào c 
            }
        }
    }
    return c;//trả về ma trận c 
}
//PHAN HOÀNG NAM - 20215434 
//thuật toán Strassens 
Matrix multiply_fast(const Matrix &a, const Matrix &b, int size) {
//hàm nhân ma trận theo thuật toán strassen 
//nhận vào tham số là 2 ma trận a, b và kích thước 2 ma trận size 
    if (size <= 64) return multiply_naive(a, b, size);
	//nếu kích thước ma trận <=64 thì thực hiện nhân ma trận thông thường 
    int halfSize = size / 2;//khai báo và khởi tạo biến halfSize = size/2
	//thực hiện chia để trị  
    Matrix a11, a12, a21, a22, b11, b12, b21, b22;
    //khai báo các ma trận a_ij và b_ij 
    for (int i = 0; i < halfSize; ++i) {//khởi tạo giá trị cho các ma trận a_ij, b_ij 
        for (int j = 0; j < halfSize; ++j) {
            a11.mat[i][j] = a.mat[i][j];//ma trận a11 ứng với góc trái-trên của a 
            a12.mat[i][j] = a.mat[i][j + halfSize];//ma trận a12 ứng với góc phải-trên của a
            a21.mat[i][j] = a.mat[i + halfSize][j];//ma trận a21 ứng với góc trái-dưới của a
            a22.mat[i][j] = a.mat[i + halfSize][j + halfSize];//ma trận a22 ứng với góc phải-dưới của a  
			//tương tự với ma trận b 
            b11.mat[i][j] = b.mat[i][j];
            b12.mat[i][j] = b.mat[i][j + halfSize];
            b21.mat[i][j] = b.mat[i + halfSize][j];
            b22.mat[i][j] = b.mat[i + halfSize][j + halfSize];
        }
    }
	//PHAN HOÀNG NAM - 20215434 
	//khai báo và khởi tạo giá trị ma trận Mi 
	//gọi đệ quy tính Mi theo thuật toán Strassen một cách đệ quy
	//với kích thước của ma trận bằng 1 nửa  
	Matrix M1 = multiply_fast(a11+a22, b11+b22, halfSize);
	Matrix M2 = multiply_fast(a21+a22, b11, halfSize);
	Matrix M3 = multiply_fast(a11, b12-b22, halfSize);
	Matrix M4 = multiply_fast(a22, b21-b11, halfSize);
	Matrix M5 = multiply_fast(a11+a12, b22, halfSize);
	Matrix M6 = multiply_fast(a21-a11, b11+b12, halfSize);
	Matrix M7 = multiply_fast(a12-a22, b21+b22, halfSize);
	//tính toán các thành phần của ma trận c sau khi nhân ma trận 
	//theo thuật toán Strassen 
	Matrix c11 = M1 + M4 - M5 + M7; 
	Matrix c12 = M3 + M5;
	Matrix c21 = M2 + M4;
	Matrix c22 = M1 - M2 + M3 + M6;
	//PHAN HOÀNG NAM - 20215434 
    Matrix c;//khai báo ma trận c 
    for (int i = 0; i < halfSize; ++i) {//thực hiện gán ma trận c_ij vào ma trận c 
        for (int j = 0; j < halfSize; ++j) {
            c.mat[i][j] = c11.mat[i][j];//c11 ứng với góc trái-trên của c 
            c.mat[i][j + halfSize] = c12.mat[i][j];//c12 ứng với góc phải-trên của c 
            c.mat[i + halfSize][j] = c21.mat[i][j];//c21 ứng với góc trái-dưới của c 
            c.mat[i + halfSize][j + halfSize] = c22.mat[i][j];//c22 ứng với góc phải-dưới của c  
        }
    }
    return c;//trả về ma trận c 
}
//PHAN HOÀNG NAM - 20215434 
Matrix gen_random_matrix() {//hàm sinh ma trận 
    Matrix a;//khai báo ma trận a 
    for (int i = 0; i < N; ++i) {//duyệt qua từng phần tử của ma trận a
        for (int j = 0; j < N; ++j) {
            a.mat[i][j] = rand();//gán các phần tử của a bằng 1 giá trị ngẫu nhiên 
        }
    }
    return a;//trả về ma trận a 
}

Matrix base;//khai báo ma trận base 
//PHAN HOÀNG NAM - 20215434 
double benchmark(Matrix (*multiply) (const Matrix&, const Matrix&, int), Matrix &result) {
	//hàm benchmark tính toán thời gian 
	//nhận vào tham số là con trỏ hàm kiểu Matrix nhận vào tham số là địa chỉ 2 ma trận và 1 số nguyên
	//và địa chỉ của 1 ma trận kết quả 
    const int NUM_TEST = 10;//số test = 10 
    const int NUM_ITER = 64;//số vòng lặp = 64 

    Matrix a = base;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t) {//thực hiện tính 10 lần 
        clock_t start = clock();//bắt đầu tính giờ 
        for (int i = 0; i < NUM_ITER; ++i) {//lặp 64 lần 
            a = multiply(a, result, N); //a = a*result
            result = multiply(result, a, N); //result = result*a
        }
        clock_t finish = clock();//kết thúc tính giờ 
        taken += (double)(finish - start);//tính tổng thời gian thực hiện đoạn code 
    }
    taken /= NUM_TEST;//tính thời gian trung bình 
	//PHAN HOÀNG NAM - 20215434 
    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);//in ra thời gian trung bình 
    return taken;//trả về thời gian trung bình 
}

int main() {
    base = gen_random_matrix();//khởi tạo ma trận base = ma trận ngẫu nhiên 
	//printf("PHAN HOANG NAM - 20215434\n");
    Matrix a, b;//khai báo ma trận a, b 
    printf("Slow version\n");//in ra slow version 
    double slow = benchmark(multiply_naive, a);//khởi tạo slow = giá trị trả về của hàm tính với thời gian 
    //và in ra thời gian trên console 
    printf("Fast version\n");//in ra fast version 
    double fast = benchmark(multiply_fast, b);//khởi tạo fast = giá trị trả về của hàm tính với thời gian 
    //và in ra thời gian trên console 
	//PHAN HOÀNG NAM - 20215434 
    if (a == b) {//nếu ma trận tính theo 2 cách bằng nhau 
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
        //in ra dòng đáp án đúng và thời gian nhanh hơn của thuật toán nhân nhanh so với nhân chậm 
    } else {//nếu a khác b tức là thuật toán sai 
        printf("Wrong answer!\n");//in ra thông báo đáp án sai  
    }
    return 0;
}