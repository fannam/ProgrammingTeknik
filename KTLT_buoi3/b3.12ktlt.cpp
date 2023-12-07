//PHAN HOANG NAM - 20215434
/*Bài tập 12: Đếm đường đi
Cho đồ thị vô hướng  G
 , hãy đếm số đường đi đi qua  k
  cạnh và không đi qua đỉnh nào quá một lần.*/
#include<bits/stdc++.h>
using namespace std;

bool visited[35];//mảng đánh dấu
vector<int>adj[35];//vector danh sách kề
int cnt = 0;//biến đếm

void reset(){//hàm đặt lại giá trị 
	for(int i=0; i<35; i++) visited[i]=false;
}
void search(int src, int depth, int current=0){//hàm tìm đường đi
//src là đỉnh đang xét, depth là độ sâu cần tới, current là độ sâu hiện tại
	visited[src] = true;//đánh dấu đỉnh đang xét 
	if(depth==current){//nếu độ sâu hiện tại = độ sâu cần tới
		cnt++;//tăng biến đếm thêm 1
		return;//dừng tìm kiếm sâu hơn
	}//PHAN HOANG NAM - 20215434
	for(int v:adj[src]){//với mỗi đỉnh kề đỉnh đang xét
		if(!visited[v]){//nếu đỉnh đó chưa được thăm
			search(v, depth, current+1);//duyệt đỉnh đó với độ sâu tăng 1
			visited[v] = false;//đặt lại để backtrack
		}
	}
}

int main(){
	printf("PHAN HOANG NAM - 20215434\n");
	freopen("input.txt", "r", stdin);
	int n, k, m;//khai báo biến
	cin>>n>>k>>m;//nhập
	//PHAN HOANG NAM - 20215434
	for(int i=1; i<=m; i++){//nhập danh sách cạnh
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);//tạo danh sách kề
		adj[v].push_back(u);//tạo danh sách kề
	}
	for(int i=1; i<=n; i++){
		search(i, k);
		reset();
	}
	cout<<cnt/2;//in ra số đường đi
	//phải chia 2 vì nếu có đường đi a->b thì đường b->a cũng tồn tại
	//do đồ thị là undirected
}//PHAN HOANG NAM - 20215434