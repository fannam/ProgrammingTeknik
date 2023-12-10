/*Bài 4.8. Viết các hàm thực hiện các phép giao và hợp của hai tập hợp mờ được biểu diễn bằng map.

Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1] biểu thị độ thuộc của phần tử trong 
tập hợp, với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp và ngược lại độ thuộc bằng 
0 nghĩa là phần tử chắc chắn không thuộc trong tập hợp.

Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp, với độ
thuộc mới được tính bằng phép toán min và max của hai độ thuộc.*/
//PHAN HOÀNG NAM - 20215434
template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #*/
    map<T, double>result = a;//Khai báo result có key kiểu T, value kiểu double và gán a vào result
    for(const auto &element : b){//duyệt qua các phần tử của map b
        if(result.count(element.first)){//nếu trong result có ít nhất 1 phần tử = key của element
            result[element.first]=max(result[element.first], element.second);
            //gán value của element key = max (a_value, b_value) tương ứng
        }
        else result.insert(element);//nếu không thì thêm element vào result
    }
    return result;//trả về result
    /*****************/
}//PHAN HOÀNG NAM - 20215434

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #*/
    map<T, double> result;//Khai báo result có key kiểu T, value kiểu double
    
    for (const auto &element : a) {//duyệt qua các phần tử của a
        if (b.count(element.first)) {//nếu trong b tồn tại ít nhất 1 phần tử = key của element
            result[element.first] = min(element.second, b.at(element.first));
            //gán value của element key = min (a_value, b_value) tương ứng
        }
    }//PHAN HOÀNG NAM - 20215434

    return result;//trả về result
    /*****************/
}