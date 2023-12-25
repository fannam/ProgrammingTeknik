// PHAN HOANG NAM - 20215434
/* Bài tập 8: Cắt hình chữ nhật
Phong là một nhà điêu khắc, ông có một tấm đá cẩm thạch hình chữ nhật kích thước W×H
. Ông ta muốn cắt tấm đá thành các miếng hình chữ nhật kích thước W1×H1,W2×H2,…,WN×HN
. Ông ta muốn cắt đến tối đa các mẫu kích thước có thể. Tấm đá có những vân đá cho nên 
không thể xoay khi sử dụng, có nghĩa là không thể cắt ra miếng B×A
 thay cho miếng A×B
 trừ khi A=B
. Các miếng phải được cắt tại các điểm nguyên trên hàng cột và mỗi nhát cắt phải cắt 
đến hết hàng hoặc hết cột. Sau khi cắt sẽ còn lại những mẩu đá còn thừa bỏ đi, nghĩa 
là những mẩu đá không thể cắt thành miếng kích thước cho trước nào.
Yêu cầu: Hãy tìm cách cắt sao cho còn ít nhất diện tích đá thừa bỏ đi.
*/
#include <bits/stdc++.h>
using namespace std;

int w, h;
int table[601][601];

void init() {
    // Khởi tạo bảng với giá trị là tích của chỉ số hàng và cột
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            table[i][j] = i * j;
        }
    }
}

int main() {
    cout << "PHAN HOANG NAM - 20215434\n";
    ios::sync_with_stdio(false);
    cin.tie();

    int m;
    cin >> w >> h;
    cin >> m;

    init(); // Khởi tạo bảng

    // Đánh dấu các ô bị cắt
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0;
    }
// PHAN HOANG NAM - 20215434
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int minWaste = table[i][j];

            // horizontal cut
            for (int k = 1; k <= i; k++) {
                minWaste = min(minWaste, table[k][j] + table[i - k][j]);
            }
            // vertical cut
            for (int k = 1; k <= j; k++) {
                minWaste = min(minWaste, table[i][k] + table[i][j - k]);
            }

            table[i][j] = minWaste; // Lưu giá trị tối ưu vào bảng
        }
    }

    cout << table[h][w] << endl; // In ra giá trị tối ưu
}
// PHAN HOANG NAM - 20215434
