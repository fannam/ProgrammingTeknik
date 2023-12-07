//PHAN HOANG NAM - 20215434
/*Bài tập 10: Khoảng cách Hamming
Khoảng cách Hamming giữa hai xâu cùng độ dài là số vị trí mà ký tự tại vị 
trí đó là khác nhau trên hai xâu. Cho  S
  là xâu gồm  n
  ký tự 0. Hãy liệt kê tất cả các xâu nhị phân độ dài  n
 , có khoảng cách Hamming với  S bằng  H
 . Các xâu phải được liệt kê theo thứ tự từ điển*/

#include<bits/stdc++.h>
using namespace std;
//hàm kiểm tra khoảng cách hamming
bool isHammingDistance(int x[], int size, int distance){
	int counter = 0;//biến đếm
	for(int i=0; i<size; i++){
		if(x[i]==1) counter++;//nếu có bit khác 0 tăng biến đếm lên 1
	}
	return (counter==distance);//nếu có số bit 1 bằng distance thì trả về true
	//ngược lại trả về false
}
void solution(int x[], int size, int distance){//hàm in kết quả
	if(isHammingDistance(x, size, distance)){//in nếu thỏa mãn khoảng cách hamming
		for(int i=0; i<size; i++){
			cout<<x[i];
		}
		cout<<endl;
	}//PHAN HOÀNG NAM - 20215434

}
void TRY(int x[], int k, int size, int distance){//hàm backtrack
	for(int v=0; v<=1; v++){//xét 2 bit 0 và 1
		x[k]=v;//gán bit xét vào x[k] lưu kết quả
		if(k==size-1) solution(x, size, distance);//nếu xét hết độ dài thì in ra kết quả
		else TRY(x, k+1, size, distance);//nếu không thử vị trí tiếp theo
	}
}
int main(){
	int t, n, h;//khai báo biến t, n, h
	printf("PHAN HOANG NAM - 20215434\n");
	cin>>t;//nhập t
	int cnt=1;//khai báo biến đếm
	while(cnt<=t){//nhập t testcase
		cin>>n>>h;//nhập độ dài n và khoảng cách h
		int x[20];//khai báo bảng x gồm 20 phần tử
		TRY(x, 0, n, h);//thử vị trí đầu tiên
		cnt++;//tăng biến đếm lên 1
	}//PHAN HOÀNG NAM - 20215434
}
