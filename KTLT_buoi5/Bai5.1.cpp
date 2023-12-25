// PHAN HOANG NAM - 20215434
/* Bài tập 5.1: Tìm và sửa các lỗi cú pháp
Đoạn code sau liệt kê tất cả các hoán vị n số. Hãy tìm và sửa các lỗi cú pháp như hướng dẫn ở trên.
*/
#include <stdio.h>

int x[100], mark[100], n; // khởi tạo mảng x và mảng mark kiểu int để đánh dấu, khởi tạo n kiểu int

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]); // hàm print duyệt qua các số trong mảng x và in ra 
    printf("\n");
}

void process(int i) { // hàm process với tham số đầu vào i
    if (i > n){ // nếu i > n thì gọi hàm print
        print();
        return;
    }
    for (int j = 1; j <= n; ++j) // ngược lại duyệt qua các phần tử trong mảng mark
        if (!mark[j]){ // Kiểm tra xem phần tử thứ j trong mảng có chưa được sử dụng không
        mark[j] = 1; // Đánh dấu phần tử j đã được sử dụng
        x[i] = j;    // Gán giá trị j cho x[i], là một phần tử trong hoán vị
        process(i+1); // Gọi đệ quy hàm process với i tăng lên 1 để xử lý phần tử tiếp theo
        mark[j] = 0; // Trả lại giá trị của mark[j] về 0 để quay lại trạng thái ban đầu
        }

}

int main() {
    printf("\n");
    printf("PHAN HOANG NAM - 20215434\n");
    n = 5; 
    process(1);
    return 0;
}

