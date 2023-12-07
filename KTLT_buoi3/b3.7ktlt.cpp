//PHAN HOÀNG NAM - 20215434
/*Bài 3.7. Sử dụng phương pháp khử đệ quy bằng stack, hãy liệt kê các xâu nhị phân độ dài n
không có k bit 1 nào liên tiếp*/

#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
    //i là vị trí đang xét, j là bit tại vị trí i, old_L là số số 1 liên tiếp trước đó 
};
//PHAN HOÀNG NAM - 20215434
int main() {
    int n, k;//khai báo n, k
    cin >> n >> k;//nhập n, k
    int x[n+1];//khai báo mảng x có n+1 phần tử
    stack<state> s;//khai báo stack s chứa các phần tử có kiểu state
    //# number of consecutive suffix 1
    int L = 0;//khởi tạo L=0
    s.push(state(1, 0));//i=1, j=0
    while (!s.empty()){//nếu s không rỗng thì lặp
        state &top = s.top();//top là phần tử trên cùng của stack s
        //# if a new binary sequence is found
        if (top.i > n){//nếu index vượt quá n thì in ra mảng x
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];//nếu i==n thì xuống dòng, nếu không thì space 
            s.pop();//xóa phần tử trên cùng của stack s
            continue;//chuyển sang lần lặp tiếp theo
        }//PHAN HOÀNG NAM - 20215434
        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #*/
        if(top.j > 1){//nếu bit > 1 thì xóa phần tử trên cùng của stack s
            s.pop();
            continue;//chuyển sang lần lặp tiếp theo
        }
        if(top.j == 1){//nếu bit = 1
            L = top.old_L;//cập nhật giá trị của L
        }
        if(L+1<k || top.j==0){//nếu L+1<k hoặc bit = 0 thì bit tiếp theo có thể là 1
            x[top.i] = top.j;//gán x[index] = bit
            s.push(state(top.i + 1, 0));//xét index tiếp theo
            top.old_L = L;//cập nhật giá trị top.old_L
            if(top.j==0) L = 0;//nếu bit = 0 thì đặt lại L=0
            else L+=1;//nếu không thì tăng L lên 1 để xét cho lần lặp tiếp theo
        }//PHAN HOÀNG NAM - 20215434
        top.j += 1;//tăng bit lên 1
        /*****************/
    }
    return 0;
}