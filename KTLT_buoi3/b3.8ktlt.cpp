//PHAN HOÀNG NAM - 20215434
/*Bài tập 8: Cân đĩa Bạn đang muốn kiểm tra xem một vật cho trước có đúng nặng  
M như người ta nói hay không. Có một cân thăng bằng và  n quả cân. Quả thứ  i nặng 
 mi . Hãy chỉ ra một cách cân thỏa mãn. Quy cách in ra đã được tích hợp trong
  mã nguồn dưới.*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}//constructor
};//i là vị trí đang xét, j thuộc {-1; 0; 1} là giá trị của x[i]

int main() {
    int n, M;//khai báo n, M
    printf("PHAN HOANG NAM - 20215434\n");
    cin >> n >> M;//nhập n, M
    int m[n+1];//khai báo mảng n+1 phần tử, chứa giá trị các quả cân
    for (int i = 1; i <= n; ++i) cin >> m[i];//nhập giá trị cho mảng m
    int x[n+1];//khai báo mảng n+1 phần tử
    stack<state> s;//khai báo stack s chứa các phần tử có kiểu state
    //# sum of selected weights
    int sum = 0;//khởi tạo sum = 0
    s.push(state(1, -1));//đẩy phần tử đầu tiên vào stack
    while (!s.empty()){//lặp tới khi s rỗng
        state &top = s.top();//top = phần tử trên cùng của stack
        if (top.i > n){//nếu xét hết tất cả quả cân
            if (sum == M){//nếu sum = M
                for (int i = 1; i <= n; ++i){//in ra
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }//PHAN HOANG NAM - 20215434
                cout << "=" << M;
                exit(0);//dừng chương trình
            }
            s.pop();//xóa phần tử trên cùng của stack
            continue;//chuyển sang vòng lặp tiếp theo
        }
        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #*/
        if(top.j > -1){//nếu x[i]>-1 (backtrack)
			sum = sum - m[top.i] * x[top.i];//đặt lại sum cho lần lặp tiếp theo
		}//PHAN HOANG NAM - 20215434
        if(top.j > 1){//nếu x[i]>1
        	s.pop();//xóa phần tử trên cùng của stack
        	continue;//chuyển sang vòng lặp tiếp theo
		}		
		x[top.i] = top.j;//gán x[i] = {-1, 0, 1} để thử
		sum = sum + m[top.i] * x[top.i];//tính sum
		s.push(state(top.i+1, -1));//thử quả cân tiếp theo
		top.j = top.j + 1;//tăng x[i] lên 1 
        /*****************/
    }
    cout << -1;//nếu không có cách cân thì in ra -1
//PHAN HOANG NAM - 20215434
    return 0;
}