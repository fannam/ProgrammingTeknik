/*Bài tập 12. Lược đồ
Cho một lược đồ gồm  n cột chữ nhật liên tiếp nhau có chiều rộng bằng 1 và chiều 
cao lần lượt là các số nguyên không âm  h1,h2,…,hn .Hãy xác định hình chữ nhật 
có diện tích lớn nhất có thể tạo thành từ các cột liên tiếp.*/
//PHAN HOÀNG NAM - 20215434
#include<bits/stdc++.h>
using namespace std;

long long findLargestRectArea(int n, int heights[]){
	stack<int>S;//stack để lưu chỉ số của hcn
	int maxArea = 0;//diện tích lớn nhất 
	int top;//biến lưu đỉnh stack
	int area_top_as_smallest;//diện tích lớn nhất của hcn với chiều cao là heights[top]
	int i=0;//index hcn
	while(i<n){//lặp
		if(S.empty()||heights[i]>=heights[S.top()]){
			//nếu stack rỗng hoặc gặp hcn thấp hơn hcn có chỉ số ở đỉnh stack
			S.push(i++);//đẩy vào stack
		}//PHAN HOÀNG NAM - 20215434
		else{
			top = S.top();//top = chỉ số hcn đỉnh stack
			S.pop();//xóa phần tử đỉnh stack
			int width = (S.empty()?i:i-S.top()-1);
			//chiều rộng của hcn là i nếu stack rỗng
			//là i-S.top()-1 nếu stack không rỗng
			//i là chỉ số hiện tại (bên phải nhất)
			//S.top() là chỉ số bên trái nhất 
			area_top_as_smallest = heights[top]*width;//tính diện tích hcn
			maxArea = max(maxArea, area_top_as_smallest);//cập nhật diện tích max
		}
	}//PHAN HOÀNG NAM - 20215434
	while(!S.empty()){//nếu stack chưa rỗng thì lặp lại các bước ở else
		top = S.top();
		S.pop();
		int width = (S.empty()?i:i-S.top()-1);
		area_top_as_smallest = heights[top]*width;
		maxArea = max(maxArea, area_top_as_smallest);
	}
	return maxArea;
}//PHAN HOÀNG NAM - 20215434
int main(){
	printf("PHAN HOANG NAM - 20215434\n");
	freopen("input.txt", "r", stdin);
	int n;
	cin>>n;//nhập số hcn
	int heights[n];//mảng chiều cao hcn
	for(int i=0; i<n; i++){
		cin>>heights[i];//nhập chiều cao hcn
	}
	long long result = findLargestRectArea(n, heights);//result lưu kết quả trả về
	cout<<result;//in ra result
}