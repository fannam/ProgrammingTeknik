// PHAN HOANG NAM - 20215434
/*Bài tập 2: Tìm và sửa các lỗi cú pháp
Bài toán cái túi: Cho một cái túi có sức chứa M và n đồ vật. Đồ vật thứ i có khối lượng mi và giá trị vi. 
Cần chọn ra một số đồ vật để bỏ vào túi sao cho tổng khối lượng không quá M và tổng giá trị là lớn nhất có thể. 
Đoạn code sau đây giải bài toán cái túi bằng phương pháp duyệt nhánh cận. Hãy tìm và sửa các lỗi cú pháp
*/
#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, All[100];

// Hàm khởi tạo giá trị cho mảng All
void init() {
    for (int i = n; i >= 1; --i) {
        All[i] = All[i + 1] + v[i];
    }
}

// Hàm in ra giá trị tốt nhất
void print() {
    cout << best;
}// PHAN HOANG NAM - 20215434

// Hàm xử lý việc chọn đồ vật và cập nhật giá trị tốt nhất
void process(int i) {
    // Kiểm tra điều kiện cận để loại bỏ các trường hợp không tiềm năng
    if (sumV + All[i] <= best || sumM > M) return;

    // Nếu đã xét hết tất cả đồ vật
    if (i > n) {
        best = sumV;  // Cập nhật giá trị tốt nhất nếu tìm thấy giá trị mới tốt hơn
        return;
    }

    // Không chọn đồ vật thứ i
    process(i + 1);

    // Chọn đồ vật thứ i
    sumM += m[i];
    sumV += v[i];
    process(i + 1);

    // Hủy bỏ lựa chọn đồ vật thứ i
    sumM -= m[i];
    sumV -= v[i];
}// PHAN HOANG NAM - 20215434

int main() {
	printf("PHAN HOANG NAM - 20215434\n");
    // Nhập số lượng đồ vật n và sức chứa túi M
    cin >> n >> M;
    // Nhập khối lượng và giá trị của từng đồ vật
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    // Khởi tạo giá trị của mảng All
    init();
    // Thực hiện quá trình chọn đồ vật
    process(1);
    // In ra giá trị tốt nhất
    print();
    return 0;
}
