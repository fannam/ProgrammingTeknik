/*Bài tập 6: Con trỏ hàm
Giả thuyết Collatz: bắt đầu từ số dương  n
  bất kỳ, nếu  n
  chẵn thì chia 2, nếu lẻ thì nhân 3 cộng 1, giả thuyết cho rằng ta luôn đi đến  n=1
 .

Hãy viết chương trình mô phỏng lại quá trình biến đổi để kiếm chứng giả thuyết với giá trị của  n
  nhập từ bàn phím.*/
#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n); //hàm in ra giá trị n được truyền vào
}

int mul3plus1(int n) {
    return n * 3 + 1; //hàm trả về 3n+1 với n là gia trị truyền vào
}

int div2(int n) {
    return n / 2; //hàm trả về n/2 với n là giá trị truyền vào 
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int), int (*even)(int), void(*output)(int)){
    (*output)(n); //gọi tới hàm con trỏ output trỏ tới 
    if (n == 1) return; //nếu n=1, kết thúc hàm 
    if (n % 2 == 0) { 
        n = (*even)(n); //nếu n chia hết cho 2 gọi hàm con trỏ even trỏ tới 
    } else {
        n = (*odd)(n); //nếu n chia 2 dư 1 gọi hàm con trỏ odd trỏ tới 
    }
    simulate(n, odd, even, output); //gọi đệ quy hàm 
}

int main() {
    int (*odd)(int) = NULL; //khai báo con trỏ hàm tên là odd có kiểu trả về là int, tham số truyền vào là int
    int (*even)(int) = NULL;//khai báo con trỏ hàm tên là even có kiểu trả về là int, tham số truyền vào là int

    /*****************
    # YOUR CODE HERE #*/
    odd = mul3plus1;//gán con trỏ odd trỏ tới hàm mul3plus1
    even = div2;//gán con trỏ even trỏ tới hàm div2
    /*****************/

    int n;//khai báo biến n kiểu int
    scanf("%d", &n); //nhập vào n
    simulate(n, odd, even, print);//gọi hàm simulate với tham số là n, con trỏ odd trỏ tới hàm mul3plus1
    //con trỏ even trỏ tới hàm div2, hàm print  

    return 0;
}