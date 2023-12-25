// PHAN HOANG NAM - 20215434
/* Bài tập 3: Dãy ngoặc đúng
Viết một chương trình nhận vào một dãy dấu ngoặc và kiểu tra xem dãy dấu ngoặc đóng mở đúng chưa.
Đề bài: http://codeforces.com/group/Ir5CI6f3FD/contest/269186/problem/H
Mã nguồn dưới đây là của một sinh viên, khi submit bị lỗi runtime (Exit code is -1073741819). 
Sử dụng công cụ debug ở trên, hãy tìm và sửa các lỗi trong mã nguồn
*/

#include <iostream>
using namespace std;
#include <string.h>
#include <stack>

// Hàm kiểm tra dãy ngoặc đóng mở có đúng không
int par(string str) {
    int a = str.length();  // Độ dài của chuỗi
    stack<char> S;  // Sử dụng stack để kiểm tra cặp ngoặc

    char x, y;
    for (int i = 0; i < a; i++) {
        x = str[i];
        if (x == '(' || x == '[' || x == '{') {
            S.push(x);  // Nếu là dấu mở ngoặc, đẩy vào stack
        } else {// PHAN HOANG NAM - 20215434
            if (S.empty()) return 0;  // Nếu stack rỗng mà gặp dấu đóng, trả về 0
            if (x == ')') {
                if (S.top() == '(') {
                    S.pop();  // Nếu là dấu đóng đúng cặp, loại bỏ dấu mở từ stack
                } else return 0;
            } else if (x == ']') {
                if (S.top() == '[') {
                    S.pop();  // Tương tự với dấu ngoặc vuông
                } else return 0;
            } else if (x == '}') {
                if (S.top() == '{') {
                    S.pop();  // Tương tự với dấu ngoặc nhọn
                } else return 0;
            }
        }
    }
// PHAN HOANG NAM - 20215434
    if (!S.empty()) {
        return 0;  // Nếu sau khi duyệt hết chuỗi mà stack vẫn còn phần tử, trả về 0
    } else
        return 1;  // Ngược lại, trả về 1 nếu dãy ngoặc đúng
}

int main() {
    int n;
    string str;
	printf("PHAN HOANG NAM - 20215434\n");
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        cout << par(str) << endl;  // In kết quả của hàm kiểm tra dãy ngoặc
    }

    return 0;
}
// PHAN HOANG NAM - 20215434
