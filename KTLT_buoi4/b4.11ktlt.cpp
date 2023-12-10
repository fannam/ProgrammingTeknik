//PHAN HOANG NAM - 20214534
/*Bài tập 4.11. Bảo vệ lâu đài Bức tường bao quanh một lâu đài nọ được cấu thành từ  n đoạn tường được
 đánh số từ 1 đến  n . Quân giặc lên kế hoạch tấn công lâu đài bằng cách gửi  ai tên giặc đánh vào đoạn 
 tường thứ  i . Để bảo vệ lâu đài có tất cả  s lính. Do các đoạn tường có chất lượng khác nhau nên khả 
 năng bảo vệ tại các đoạn tường cũng khác nhau. Cụ thể tại đoạn tường thứ  i , mỗi lính có thể đẩy lùi 
 tấn công của  ki tên giặc. Giả sử đoạn tường thứ  i có  xi lính. Khi đó nếu số tên giặc không vượt quá  
 xi×ki thì không có tên giặc nào lọt vào được qua đoạn tường này. Ngược lại sẽ có  ai−xi×ki tên giặc lọt 
 vào lâu đài qua đoạn tường này. Yêu cầu hãy viết chương trình phân bố lính đứng ở các đoạn tường sao cho
  tổng số lính là  s và tổng số lượng tên giặc lọt vào lâu đài là nhỏ nhất.*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>>pq;//hàng chờ ưu tiên giảm dần theo khả năng phòng ngự
int main(){
	int n, s;//số bức tường và tổng số lính
	printf("PHAN HOANG NAM - 20215434\n");
	freopen("input.txt", "r", stdin);
	cin>>n>>s;//nhập
	int remain_enemy = 0;//số lính còn lại của địch
	for(int i=0; i<n; i++){
		int a, k;//số lính địch a và khả năng phòng ngự k
		cin>>a>>k;//nhập
		pq.push({k, a});//đẩy vào hàng chờ ưu tiên
		remain_enemy += a;//tính tổng số lính địch
	}//PHAN HOANG NAM - 20214534
	while(!pq.empty()&&s>0){//lặp tới khi hàng chờ rỗng hoặc hết lính
		int strength = pq.top().first;//khả năng phòng ngự tại bức tường 
		int enemy = pq.top().second;//số lính địch tại bức tường
		pq.pop();//xóa phần tử trên cùng
		int soldier = min(s, enemy/strength);//số lính phân cho bức tường 
		//là gtnn (s, [enemy/strength]) 
		s -= soldier;//giảm tổng số lính
		remain_enemy -= soldier * strength;//tính số lính địch còn lại
		if(enemy%strength!=0){//nếu số lính địch còn dư
			pq.push({enemy%strength, enemy%strength});//đẩy vào hàng chờ
			//để đảm bảo dùng thêm 1 lính phòng ngự thì sẽ hết lính địch
		}	
	}//PHAN HOANG NAM - 20214534
	cout<<remain_enemy;//in
}//PHAN HOANG NAM - 20214534