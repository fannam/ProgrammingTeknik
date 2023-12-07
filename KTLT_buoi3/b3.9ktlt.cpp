//PHAN HOANG NAM - 20215434
/*Bài tập 9: Lập lịch cho y tá
Một y tá cần lập lịch làm việc trong  N
  ngày, mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi. Một lịch làm việc là tốt nếu không có hai ngày nghỉ
   nào liên tiếp và mọi chuỗi ngày tối đại làm việc liên tiếp đều có số ngày thuộc đoạn  [K1,K2]
 . Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch in ra trên một dòng một xâu nhị phân độ dài  n
  với bit 0/1 tương ứng là nghỉ/làm việc. Các xâu phải được in ra theo thứ tự từ điển*/
#include<bits/stdc++.h>
using namespace std;
int consecutive1 = 0;//số số 1 liên tiếp
int k1, k2, n;//khai báo k1, k2, n
int x[205];//khai báo mảng x lưu lại kết quả 
bool check(int  v, int  k){//hàm kiểm tra điều kiện
	if(k==0) return true;//nếu là ngày đầu tiên đi làm thì nghỉ hay đi đều được
	else{//nếu không phải ngày đầu tiên
		if(v==0){//nếu ngày đang xét nghỉ
			if(x[k-1]==0) return false;//nếu ngày trước đó nghỉ thì trả về false
			else if(consecutive1 < k1) return false;//nếu ngày trước đó đi làm
			//mà chưa đủ ít nhất k1 ngày thì trả về false
		}//PHAN HOANG NAM - 20215434
		else{//nếu ngày đang xét đi làm
			if(x[k-1]==1){//nếu ngày trước đó đi làm
				if(consecutive1>=k2) return false;//kiểm tra 
				//xem có đi liên tiếp k2 ngày hay không
			}
			else{ //nếu ngày trước đó nghỉ
				if(n-k+1<k1) return false;//kiểm tra
				//từ đó đến ngày cuối có đủ ít nhất k1 ngày đi làm liên tục không
			}
		}
		return true;//các trường hợp còn lại trả về true
	}
}
//PHAN HOANG NAM - 20215434
void solution(){//hàm in ra các giá trị của mảng x
	for(int i=0; i<n; i++){
		cout<<x[i];
	}
	cout<<endl;
}

void TRY(int k){//hàm back track
	for(int v=0; v<=1; v++){//xét giá trị hiện tại là 1 hoặc 0
		if(check(v, k)){//nếu thỏa mãn điều kiện
			x[k] = v;//gán v vào x[k]
			int old_consec1 = consecutive1;//lưu lại số ngày đi làm liên tục liên tiếp
			if(v==1){//nếu đi làm
				if(x[k-1]==1) consecutive1++;//nếu ngày trước đó cũng đi làm
				//tăng số ngày đi làm liên tục thêm 1				              
				else consecutive1 = 1;//nếu không đặt lại số ngày đi làm liên tục thành 1
			}//PHAN HOANG NAM - 20215434
			else consecutive1 = 0;//nếu nghỉ thì đặt số ngày đi làm liên tục thành 0
			
			if(k==n) solution();//nếu xét hết số ngày thì in ra kết quả
			else TRY(k+1);//nếu không thì thử với ngày tiếp theo
			consecutive1 = old_consec1;//đặt lại giá trị số ngày đi làm liên tục cũ để quay lui
		}
	}
}

int main(){
	cout<<"PHAN HOANG NAM - 20215434\n";
	cin>>n>>k1>>k2;//nhập n, k1, k2
	TRY(0);//gọi thủ tục quay lui từ vị trí đầu tiên
}