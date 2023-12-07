//PHAN HOANG NAM - 20215434
/*Bài 3.4. Cho dãy a có  n phần tử. Một dãy con của  a là dãy thu được bằng cách xóa đi một số phần tử của
a và giữ nguyên thứ tự các phần tử còn lại (có thể không xóa phần tử nào). Hãy tìm dãy con tăng dài nhất của a.*/
#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải

void init(){
    memset(mem, -1, sizeof(mem));//khởi tạo tất cả phần tử mảng mem bằng -1
}

//# Quy hoạch động, 
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    /*****************
    # YOUR CODE HERE #*/
    int res = 1;//khởi tạo giá trị mặc định cho trường hợp i=1
    for(int j=0; j<i; j++){//lặp
        if(a[i]>a[j]){//nếu số thứ i lớn hơn một trong các số thuộc dãy con
            res = max(res, lis(j)+1); //cập nhật res và tính giá trị dãy con kết thúc tại a[j]
        }//đồng thời cập nhật mem[j]
    }//PHAN HOÀNG NAM - 20215434
    mem[i] = res;//cập nhật giá trị mới cho mem[i]
    return res;
    /*****************/
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){//với mỗi giá trị j < i
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){//nếu a[j]<a[i] và thỏa mãn 
        //độ dài dãy con kết thúc tại a[i] = 1 + độ dài dãy con kết thúc tại a[j]
            trace(j);//gọi đệ quy với j để in ra dãy
            break;
        }//PHAN HOÀNG NAM - 20215434
    }
    cout << a[i] << " ";//in ra a[i]
}

int main(){
    init();//gọi hàm khởi tạo giá trị mảng mem
    cin >> n;//nhập n
    for(int i = 0; i < n; i++) cin >> a[i];//nhập giá trị cho mảng a
    int res = 1, pos = 0;//khởi tạo res = 1 và pos = 0
    for(int i = 1; i < n; i++){//PHAN HOÀNG NAM - 20215434
        if (res < lis(i)){//nếu res < độ dài dãy con kết thúc tại a[i]
            res = lis(i);//cập nhật độ dài lớn nhất
            pos = i;//lưu lại vị trí của phần tử
        }
    }
    cout << res << endl;//in ra kết quả
    trace(pos);//in ra dãy con
    return 0;
}