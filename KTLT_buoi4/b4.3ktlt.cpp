/*Bài tập 3: Tính tích có hướng của 2 vector
Một vector trong không gian 3 chiều được biểu diễn bằng tuple<double, double, double>. 
Hãy viết hàm Vector cross_product(Vector a, Vector b) tính tích có hướng của 2 vector. 
Trong đó Vector là kiểu dữ liệu được định nghĩa sẵn trong trình chấm như sau: 
using Vector = tuple<double, double, double>;*/
//PHAN HOÀNG NAM - 20215434 
Vector cross_product(Vector a, Vector b) {
    /*****************
    # YOUR CODE HERE #*/
    double x = get<1>(a) * get<2>(b) - get<2>(a) * get<1>(b);//x=a_y*b_z - a_z*b_y
    double y = get<2>(a) * get<0>(b) - get<0>(a) * get<2>(b);//y=a_z*b_x - a_x*b_z
    double z = get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b);//z=a_x*b_y - a_y*b_x 
    Vector res{x, y, z};//khởi tạo vector res với bộ giá trị (x, y, z)
    return res;//trả về vector res 
    /*****************/
}