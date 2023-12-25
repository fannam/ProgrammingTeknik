// PHAN HOANG NAM - 20215434
/* Bài tập 5.6. Tổng kết
Một lớp có n sinh viên. Sinh viên thứ i có điểm tổng kết là ai theo thang điểm 10. Để đánh giá chất lượng dạy học, 
giảng viên muốn biết có bao nhiêu bạn đạt điểm A, B, C, D, F. Quy đổi thang điểm được cho như sau:
a<4: F
4≤a<5.5: D
5.5≤a<7: C
7≤a<8.5: B
8.5≤a: A
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <bits/stdc++.h>
using namespace std;
// Hàm đánh giá chất lượng dạy học dựa trên điểm tổng kết
char cal(double a){
    if (a < 4) return 'F';
    if (4 <= a && a < 5.5) return 'D';
    if (5.5 <= a && a < 7) return 'C';
    if (7 <= a && a < 8.5) return 'B';
    if (8.5 <= a) return 'A';
}

int main(){
    cout<<"PHAN HOANG NAM - 20215434\n";
    int n;
    cin >> n;
     // Khởi tạo biến đếm cho từng loại điểm
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        int a;
        cin >> a;
        char symbol = cal(a);//tính cal(a) và gán vào symbol
         // Tăng giá trị của biến đếm tương ứng với loại điểm của sinh viên
        if (symbol == 'A') ++A;
        if (symbol == 'B') ++B;
        if (symbol == 'C') ++C;
        if (symbol == 'D') ++D;
        if (symbol == 'F') ++F;
    }
    // In ra số lượng sinh viên đạt từng loại điểm
    cout << A << " " << B << " " << C << " " << D << " " << F;
}
// PHAN HOANG NAM - 20215434