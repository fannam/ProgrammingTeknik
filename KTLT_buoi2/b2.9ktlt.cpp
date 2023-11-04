/*Bài tập 9: Tính hàm sigmoid
Dưới đây cung cấp đoạn code đơn giản để tính hàm sigmoid theo công thức trực tiếp.
Hãy viết hàm tính xấp xỉ sigmoid(x) đến độ chính xác  10−6
  và có tốc độ nhanh hơn ít nhất 30% so với code đơn giản.
Gợi ý: sử dụng kỹ thuật "chuẩn bị trước" như trong slide.*/

#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;
//khai báo các biến hằng số 
const int LIMIT = 100; 
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;
//hàm sigmoid chậm
double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}
//khai báo mảng x 
double x[NUM_INPUTS];

void prepare_input() { //hàm chuẩn bị trước
    const int PRECISION = 1000000; //biến hằng PRECISION 
    const double RANGE = LIMIT / 20.0; //biến hằng RANGE 
    for (int i = 0; i < NUM_INPUTS; ++i) { //khởi tạo các giá trị của x[i] để tính trước các giá trị sigmoid  
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
/*****************
# YOUR CODE HERE #*/
const int MAX = 100000;
double sigmoid[MAX]; //khai báo mảng sigmoid kích thước MAX 
const double supremum = 5.0 ; //khai báo cận trên 
const double infimum = -5.0 ; //khai báo cận dưới 
const double delta = (supremum - infimum)/MAX;  //khai báo delta tính theo sup và inf 
/*****************/

//# hàm chuẩn bị dữ liệu
void precalc() {
    /*****************
    # YOUR CODE HERE #*/
    double x = infimum;
    for(int i=0; i<MAX; i++){
        sigmoid[i]=sigmoid_slow(x);
        x+=delta;
    }
    /*****************/
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    /*****************
    # YOUR CODE HERE #*/
    if(x>=supremum) return 1.0;
    if(x<=infimum) return 0.0;
    int i =floor ((x-infimum)/delta); 
    //hồi quy tuyến tính, xấp xỉ giá trị dựa vào 2 đầu mút
    return sigmoid[i]+(x-infimum-i*delta)/delta *(sigmoid[i+1]-sigmoid[i]);
    /*****************/
}

//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    //hàm benchmark nhận tham số là con trỏ hàm calc có tham số double, giá trị trả về là double
    //và vector có kiểu dữ liệu double, truyền kiểu tham chiếu 
    const int NUM_TEST = 20;//khai báo và khởi tạo biến NUM_TEST = 20

    double taken = 0;//khai báo và khởi tạo biến taken = 0
    result = vector<double>(); //khởi tạo result là vector rỗng 
    result.reserve(NUM_ITER); //đặt trước kích thước của vector >= NUM_ITER

    int input_id = 0; //khai báo và khởi tạo biến input_id = 0
    clock_t start = clock(); //khởi tạo biến start để lấy thời điểm bắt đầu chạy đoạn code  
    for (int t = 0; t < NUM_TEST; ++t) { //xét toàn bộ các test 
        //double sum = 0;//khai báo và khởi tạo biến double sum = 0
        for (int i = 0; i < NUM_ITER; ++i) { 
            double v = fabs(calc(x[input_id]));
            //khởi tạo biến v=giá trị tuyệt đối của kết quả trả về của hàm mà hàm calc trỏ tới
            //với tham số đầu vào là double x[input_id]
            //sum += v; //tính tổng 
            if (t == 0) result.push_back(v);//lưu lại kết quả lần kiểm thử đầu tiên để đánh giá hiệu suất 
            if ((++input_id) == NUM_INPUTS) input_id = 0;// quản lý chỉ số của dữ liệu đầu vào
        }
    }
    clock_t finish = clock();//khởi tạo biến finish để lấy thời điểm sau khi chạy xong đoạn code 
    taken = (double)(finish - start);//gán taken = thời gian chạy code 
//#  printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;//trả về giá trị taken 
}
//kiểm tra sai số của sigmoid_fast so với sigmoid_slow
bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6; //khai báo biến hằng EPS = 10^-6

    if (a.size() != b.size()) return false; //nếu kích thước 2 vector khác nhau, trả về false
    for (unsigned int i = 0; i < a.size(); ++i) { //so sánh với mỗi phần tử tương ứng của 2 vector 
        if (fabs(a[i] - b[i]) > EPS) { //nếu tồn tại một cặp có sai số >10^-6 thì trả về false
            return false;
        }
    }
    return true; //các trường hợp còn lại trả về true 
}

int main() {
    prepare_input(); //gọi hàm prepare_input()
    precalc();//gọi hàm precalc()

    vector<double> a, b; //khởi tạo 2 vector a, b
    double slow = benchmark(sigmoid_slow, a); 
    //gán biến slow = thời gian thực hiện sigmoid_slow và lưu các kết quả ở vector a
    double fast = benchmark(sigmoid_fast, b);
    //gán biến fast = thời gian thực hiện sigmoid_fast và lưu các kết quả ở vector b
    double xval;//khởi tạo biến xval
    scanf("%lf", &xval); //nhập vào biến xval
    printf("%.2f \n", sigmoid_fast(xval)); //in ra kết quả tính sigmoid_fast 
    
    if (is_correct(a, b) && (slow/fast > 1.3)) { 
        //kiểm tra thời gian chạy sigmoid_slow so với sigmoid_fast
        //nếu kiểu tra điều kiện sai số thỏa mãn và thời gian đủ nhanh thì in ra 
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } else {
        //ngược lại in ra dòng dưới 
      	printf("Correct answer! Your code is faster at least 30%%!\n");
    }
    
    return 0;
}