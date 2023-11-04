/*Bài tập 11: Tính tích hai đa thức
Cho 2 đa thức A(x) và B(x) tương ứng có bậc N và  M
Hãy tính ma trận tích C(x) = A(x) * B(x) có bậc N+M−1
*/
//PHAN HOÀNG NAM - 20215434
#include<iostream>
#include<vector>
#include<cmath>
#include<complex>
using namespace std;
using Complex = complex<double>;//dùng kiểu Complex thay cho complex<double> 
typedef struct polynomial{ //khai báo kiểu dữ liệu polynomial 
	int deg; //bậc của đa thức 
	vector<int>coeffecient;	//các hệ số của đa thức 
}polynomial;
//PHAN HOÀNG NAM - 20215434
//thuật toán FFT và IFFT với tham số bool isInverted để phân biệt 
void fastFourierTransform(vector<Complex> &A, bool isInverted){
	int n = A.size(); //khai báo và khởi tạo n = kích thước vector A 
	if(n<=1) return; //điều kiện để kết thúc hàm đệ quy 
	
	vector<Complex>A0(n/2); //Khai báo vector A0 có kích thước n/2 
	vector<Complex>A1(n/2); //Khai báo vector A1 có kích thước n/2 
	for(int i=0; 2*i<n; i++){//chia 2 mỗi lần đệ quy
		A0[i] = A[2*i];//để trả về ma trận nghịch đảo khi kết thúc đệ quy
		A1[i] = A[2*i+1];
	}
	//gán các giá trị cho vector A0 và A1 theo thuật toán FFT 
	fastFourierTransform(A0, isInverted); //gọi đệ quy với vector A0  
	fastFourierTransform(A1, isInverted); //gọi đệ quy với vector A1 
//PHAN HOÀNG NAM - 20215434
	double angle = (2 * M_PI)/n * (isInverted? -1 : 1);
	//khai báo biến angle là góc của nghiệm phức trên vòng tròn lượng giác, có định hướng  
	//M_PI là số pi lấy từ thư viện cmath 
	//Nếu isInverted = false thì trả trả về -1 ngược lại trả về 1 
	Complex w(1), w_n(cos(angle), sin(angle));; //Khởi tạo biến w và w_n kiểu Complex 
	//w=1+0i, w_n = cos + isin
	for(int i=0; 2 * i < n ; i++){
		A[i] = A0[i] + w * A1[i]; //y_k = y0_k + (w_n)^k * y1_k (k=0,1,...,n/2-1)
		A[i + n/2] = A0[i] - w * A1[i]; //y_k+n/2 = y0_k - (w_n)^k * y1_k (k=0,1,...,n/2-1)
		if(isInverted){
			A[i]/=2;
			A[i+n/2]/=2;
		}
		w = w * w_n; //quay w thêm góc angle trong hệ tọa độ phức (dạng argument) 
		//r1(cos(a) + isin(a)) * r2(cos(b) + isin(b)) = r1r2(cos(a+b)+isin(a+b)) 
	}
}//PHAN HOÀNG NAM - 20215434
//hàm multiply nhận tham số đầu vào là 2 vector và 2 số mũ của đa thức 
void multiply(vector<int>&coeff1, vector<int>&coeff2, int deg1, int deg2){ 
	int n=1; //khởi tại biến tạm n=1 
	while(n<coeff1.size() + coeff2.size()) n<<=1; //n=2^k nhỏ nhất > tổng kích thước coeff1 và coeff2 
	vector<Complex>a(n), b(n);//khai báo vector a, b có kích thước n 
	for(int i=0; i<coeff1.size(); i++) a[i]=coeff1[i]; //gán vector a = vector coeff1 
	for(int i=0; i<coeff2.size(); i++) b[i]=coeff2[i]; //gán vector b = vector coeff2 
	fastFourierTransform(a, false); //gọi hàm FFT thuận (DFT) với vector hệ số a  
	fastFourierTransform(b, false); //gọi hàm FFT thuận (DFT) với vector hệ số b 
	for(int i=0; i<n; i++) a[i] = a[i] * b[i];//DiscreteFT(A.B) = DiscreteFT(A).DFT(B)
	//lưu lại vào vector a 
	fastFourierTransform(a, true); //gọi hàm FFT ngược (IDFT) với vector hệ số a sau khi tính toán 
	vector<int>result(deg1+deg2+1); //khởi tạo vector có kích thước deg1+deg2+1 
	for(int i=0; i<deg1+deg2+1; i++){
		result[i] = round(a[i].real()); //làm tròn phần thực lên theo thuật toán FFT 
	}//PHAN HOÀNG NAM - 20215434
	int p=0;//khởi tạo giá trị tạm p = 0;
	for(int r : result) p=p^r; //tính 0 xor r 
	cout<<p; //in ra p 
}

int main(){
	//printf("PHAN HOANG NAM - 20215434\n");
	//freopen("input.txt", "r", stdin);
	polynomial P1, P2;//khai báo 2 biến kiểu polynomial 
	cin>>P1.deg;//nhập vào bậc đa thức 1 
	for(int i=0; i<=P1.deg; i++){ //nhập vào hệ số đa thức 1 
		int coef;//khai báo biến coef 
		cin>>coef;
		P1.coeffecient.push_back(coef); //lưu ở vector P1.coeffecient
	}//PHAN HOÀNG NAM - 20215434
	cin>>P2.deg;//nhập vào bậc đa thức 2 
	for(int i=0; i<=P2.deg; i++){//nhập vào hệ số đa thức 1 
		int coef;//khai báo biến coef 
		cin>>coef;
		P2.coeffecient.push_back(coef);	//lưu ở vector P2.coeffecient
	}
	multiply(P1.coeffecient, P2.coeffecient, P1.deg, P2.deg);//gọi hàm nhân đa thức 
}