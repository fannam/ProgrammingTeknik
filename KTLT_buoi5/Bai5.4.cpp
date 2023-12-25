// PHAN HOANG NAM - 20215434
/* Bài tập 5.4: Bài toán người du lịch
Một người xuất phát tại thành phố 1, muốn đi thăm tất cả các thành phố khác, mỗi thành phố đúng 1 lần và quay về 1. 
Chi phí để đi từ thành phố 𝑖 sang thành phố 𝑗 là  ci,j. Hãy tìm tổng chi phí nhỏ nhất có thể
*/

#include <bits/stdc++.h>
using namespace std;
//khai báo các biến sử dụng 
int m, n, Smin = INT_MAX;
long long S = 0;
int cmin = 100000000;
int x[100];
int c[100][100];
vector<int> flag(100, false);

// Hàm thử tất cả các khả năng để tìm đường đi ngắn nhất
void TRY(int k) {
    for (int i = 2; i <= n; i++) {
        // Nếu thành phố i chưa được thăm và có đường đi từ thành phố trước đó đến i
        if (flag[i] == false && c[x[k - 1]][i] != -1) {
            flag[i] = true;
            x[k] = i;//lưu lại thành phố vừa thăm vào vị trí thứ k
            S = S + c[x[k - 1]][i];//tính tổng đường đi mới

            // Nếu đã thăm hết các thành phố
            if (k == n) {
                // Cập nhật chi phí nhỏ nhất nếu có đường đi mới tốt hơn
                if (S + c[i][1] < Smin && c[i][1] != -1)
                    Smin = S + c[i][1];
            }
            // Nếu chưa thăm hết và có khả năng có đường đi ngắn hơn
            else if (S + cmin * (n - k + 1) < Smin) {
                TRY(k + 1);//backtrack
            }

            // Quay lui
            flag[i] = false;//đặt lại flag
            S = S - c[x[k - 1]][i];//đặt lại S
        }
    }
}

int main() {
    int a, b;
    cout << "PHAN HOANG NAM - 20215434\n";
    cin >> n >> m;

    // Khởi tạo ma trận chi phí với giá trị mặc định là -1
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                c[i][j] = 0;
            else
                c[i][j] = -1;
        }

    // Nhập chi phí từ thành phố a đến b
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cin >> c[a][b];

        // Cập nhật chi phí nhỏ nhất
        if (c[a][b] < cmin)
            cmin = c[a][b];
    }

    x[1] = 1;
    flag[1] = true;

    // Thực hiện hàm thử các khả năng để tìm đường đi ngắn nhất
    TRY(2);

    // In ra chi phí ngắn nhất
    cout << Smin;
}
// PHAN HOANG NAM - 20215434
