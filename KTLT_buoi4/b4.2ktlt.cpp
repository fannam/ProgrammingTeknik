/*Bài tập 2: Tính diện tích tam giác
Một điểm trong không gian 2 chiều được biểu diễn bằng pair. Hãy viết hàm double area(Point a, Point b,
Point c) tính diện tích tam giác theo tọa độ 3 đỉnh. Trong đó, Point là kiểu được định nghĩa sẵn trong 
trình chấm như sau: using Point = pair<double, double>;*/
//PHAN HOÀNG NAM - 20215434 

double area(Point a, Point b, Point c) {
    /*****************
    # YOUR CODE HERE #
    PHAN HOÀNG NAM - 20215434 */
    double area = fabs((b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second)) / 2;
    //công thức tính diện tích tam giác bằng định thức ma trận 2x2 
    return area;
    /*****************/
}
