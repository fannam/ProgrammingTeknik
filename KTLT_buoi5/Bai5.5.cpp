// PHAN HOANG NAM - 20215434
/* Bài tập 5: Năm nhuận
Một năm được coi là nhuận nếu hoặc nó chia hết cho 4 nhưng không chia hết cho 100, hoặc nó chia hết cho 400.
Cho một danh sách các năm, kiểm tra xem có tồn tại năm nhuận trong danh sách đó hay không.
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	printf("PHAN HOANG NAM - 20215434\n");
    int n; // Khởi tạo n kiểu int
    cin >> n; // Nhập vào n từ bàn phím
    bool found = false; // khởi tạo biến found kiểu bool và gán là false
    while(n--){ 
        int a; // Khởi tạo a
        cin >> a; // Nhập vào năm đang cần kiểm tra
        // Kiểm tra điều kiện năm nhuận
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
        	found = true;
            // Nếu tìm thấy năm nhuận, in "Yes" và kết thúc chương trình
            cout<<"Yes";
            return 0;
		}
    }
    // Nếu không tìm thấy năm nhuận, in "No"
    cout << "No";
}
// PHAN HOANG NAM - 20215434