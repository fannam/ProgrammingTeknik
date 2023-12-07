//PHAN HOANG NAM - 20215434
/*Bài 3.3. Một người xuất phát tại thành phố 1, muốn đi thăm tất cả các thành phố khác, mỗi thành phố đúng 1 lần và quay về 1. 
Chi phí để đi từ thành phố i sang thành phố j là cij. Hãy tìm tổng chi phí nhỏ nhất có thể */

#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];//nhập ma trận chi phí
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}//PHAN HOÀNG NAM - 20215434
//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        /*****************
        # YOUR CODE HERE #*/
        if(mark[i]==0){//nếu thành phố chưa đi qua 
            x[k]=i;//gán thành phố vừa đi vào x[k] lưu thứ tự đi 
            curr += c[x[k-1]][i]; //tổng chi phí mới 
            mark[i]=1;//đánh dấu thành phố đã qua 
            if(k==n) best = min(curr + c[i][1], best);//nếu đi đến thành phố cuối
            //best = min của best trước đó và tổng chi phí mới 
            else TRY(k+1);//nếu chưa thăm hết thì thăm thành phố tiếp theo 
            mark[i]=0;//đặt lại thành phố i là chưa thăm cho lần lặp tiếp theo 
            curr -= c[x[k-1]][i];//đặt lại giá trị curr cho lần lặp tiếp theo 
        }
        //PHAN HOÀNG NAM - 20215434
        /*****************/
    }
}

int main() {
    input();//gọi hàm input
    x[1] = 1;//đã thăm thành phố 1
    TRY(2);//gọi thủ tục quay lui từ thành phố thứ 2
    cout << best;//in ra giá trị best
    return 0;
}