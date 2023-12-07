//PHAN HOANG NAM - 20215434
/*Bài tập 11: Lịch trình chụp ảnh
Superior là một hòn đảo tuyệt đẹp với  n
  địa điểm chụp ảnh và các đường một chiều nối các điểm chụp ảnh với nhau. Đoàn khách tham quan có  r
  người với sở thích chụp ảnh khác nhau. Theo đó, mỗi người sẽ đưa ra danh sách các địa điểm mà họ 
  muốn chụp. Bạn cần giúp mỗi người trong đoàn lập lịch di chuyển sao cho đi qua các điểm họ yêu cầu
   đúng một lần, không đi qua điểm nào khác, bắt đầu tại điểm đầu tiên và kết thúc tại điểm cuối cùng 
   trong danh sách mà họ đưa ra, và có tổng khoảng cách đi lại là nhỏ nhất.*/
#include<bits/stdc++.h>
using namespace std;
int c[100][100];//ma trận chi phí
bool visited[100];//mảng đánh dấu các điểm đã đi qua
int x[100];//mảng lưu lại thành phố vừa đi 
int curr = 0;//biến tính chi phí hiện tại
int best = 1e8;//biến lưu chi phí nhỏ nhất
int n, r;//khai báo n, r
void reset(){//hàm đặt lại giá trị để tìm đường cho người khác
	for(int i=0; i<100; i++){
		visited[i]=false;
		x[i]=0;
	}//PHAN HOANG NAM - 20215434
	curr = 0;
	best = 1e8;
}
bool check(int v, int k){//hàm kiểm tra điều kiện
	if(visited[v]) return false;//nếu thành phố đã đi qua trả về false
	if(c[x[k-1]][v]==0) return false;//nếu thành phố không thể đi tới trả về false
	return true;//còn lại trả về true
}
void TRY(int k, vector<int>&path){//hàm backtrack
	visited[path[0]]=true;//đặt thành phố đầu tiên là đã thăm
	for(int v:path){//với mỗi thành phố sẽ đi
		if(check(v, k)){//nếu đi được
			x[k]=v;//gán thành phố đó vào x[k]
			curr += c[x[k-1]][v];//tính chi phí mới
			visited[v]=true;//đánh dấu thành phố đã thăm
			if(k==path.size()){//nếu đi đến thành phố cuối
				if(v==path.back()){//nếu thành phố cuối là thành phố kết thúc
					best = min(curr, best);//tính lại best mới
				}//PHAN HOANG NAM - 20215434
			}
			else TRY(k+1, path);//nếu chưa đi đến cuối thì thử tiếp thành phố tiếp theo
			visited[v]=false;//backtrack
			curr -= c[x[k-1]][v];//backtrack
		}
	}
}

int main(){
	printf("PHAN HOANG NAM - 20215434\n");
	freopen("input.txt", "r", stdin);
	cin>>n>>r;//nhập vào giá trị n, r
	for(int i=1; i<=n; i++){//nhập ma trận chi phí
		for(int j=1; j<=n; j++){
			cin>>c[i][j];
		}
	}//PHAN HOANG NAM - 20215434
	int cnt = 0;//đặt biến đếm = 0
	while(cnt<=r){//nhập vào r dòng
		++cnt;//tăng biến đếm
		string s;//khai báo chuỗi s
		getline(cin, s);//nhập chuỗi
		istringstream stream(s);
		vector<int> path;//khai báo vector path
		int number;//khai báo biến int number
	    while (stream >> number) {//nếu nhập số
	        path.push_back(number);//đẩy vào vector path
	    }
		if(!path.empty()){//nếu path không rỗng
			x[1]=path[0];//đặt thành phố hiện tại (đầu tiên) là x[1]
			visited[path[0]]=true;//đánh dấu 
			TRY(2, path);//back track từ thành phố thứ 2
			if(best == 1e8) cout<<0<<endl;//nếu không có đường đi thì in 0
			else cout<<best<<endl;//nếu có đường đi thì in ra best
			reset();//đặt lại các giá trị cho người tiếp theo
		}//PHAN HOANG NAM - 20215434	
	}
}