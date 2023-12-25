// PHAN HOANG NAM - 20215434
/* Bài tập 5.7. Chia tiền
Sau đại dịch, thầy trò Đường Tăng muốn xin tiền của các nhà giàu để chia cho các nhà nghèo. 
Họ sẽ vào n thôn, thôn thứ i có ki nhà. Mỗi thôn họ sẽ quyết định xin tiền hay cho tiền, phụ thuộc vào đánh giá của họ về mức độ giàu nghèo ở đây. 
Nếu thôn i giàu, họ sẽ đi từng nhà trong số ki nhà này và xin ai,j tiền của nhà thứ j. Nếu thôn i nghèo, họ sẽ đi từng nhà trong số ki nhà này 
và phát ai,j tiền cho nhà thứ j. Hãy tính số tiền ít nhất họ phải mang theo để đảm bảo có thể phát đủ cho người nghèo (tức số tiền luôn không bị âm)
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "PHAN HOANG NAM - 20215434\n"; 

    int n; // Số lượng thôn
    cin >> n;

    int ans = 0, sum = 0; // Biến ans lưu giá trị số tiền ít nhất cần mang theo, sum lưu tổng số tiền trong quá trình di chuyển

    while (n--) {
        int k, t; // k: số lượng nhà trong thôn, t: trạng thái giàu nghèo của thôn
        cin >> k >> t;

        if (t == 1) { // Nếu thôn giàu, xin tiền từ nhà
            while (k--) {
                int a;
                cin >> a;
                sum += a; // Tăng tổng số tiền đã xin
                ans = max(ans, -sum); // Cập nhật giá trị ans nếu có giá trị mới lớn hơn
            }// PHAN HOANG NAM - 20215434
        } else { // Nếu thôn nghèo, phát tiền cho nhà
            while (k--) {
                int a;
                cin >> a;
                sum -= a; // Giảm tổng số tiền đã phát
                ans = max(ans, -sum); // Cập nhật giá trị ans nếu có giá trị mới lớn hơn
            }
        }
    }

    cout << ans; // In ra số tiền ít nhất cần mang theo
}
// PHAN HOANG NAM - 20215434
