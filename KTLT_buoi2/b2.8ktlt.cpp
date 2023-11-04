/*Bài tập 8: Sắp xếp
Viết hàm so sánh cho thuật toán sắp xếp.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2; //khai báo biến int có tên val1 và val2
    cin >> val1 >> val2; //nhập vào biến val1, val2
    vector< vector<int> > a = {//khai báo và khởi tạo vector a có các thành phần là vector 
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*****************
    # YOUR CODE HERE #*/
    sort(a.begin(), a.end(), [](vector<int>x, vector<int>y){//hàm lambda nhận tham số là 2 vector x và y 
        //hàm sort thực hiện sắp xếp các vector từ a.begin() đến a.end()
        //với tham số điều kiện là hàm lambda 
        int sum1 = 0, sum2=0; //khai báo và khởi tạo biến sum1 và sum2 bằng 0
        for(int v:x) sum1+=v; //sum1 = tổng các phần tử vector x 
        for(int v:y) sum2+=v; //sum2 = tổng các phần tử vector y
        return sum1>sum2;//trả về sum1>sum2 (sắp xếp giảm dần)
    });
    /*****************/

    for (const auto &v : a) { //với mỗi thành phần vector v thuộc a
        for (int it : v) { //với mỗi thành phần int it thuộc v 
            cout << it << ' '; //in ra it 
        }
        cout << endl;
    }
    return 0;
}