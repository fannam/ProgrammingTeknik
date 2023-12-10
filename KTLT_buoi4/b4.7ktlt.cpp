/*Bài 4.7. Viết các hàm thực hiện các phép giao và hợp của hai tập hợp được biểu diễn bằng set*/
//PHAN HOANG NAM - 20215434
template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #*/
    set<T> result = a;//khai báo set result kiểu T và gán a vào result 
    result.insert(b.begin(), b.end());//thêm các phần tử của b vào result
    //vì tính chất duy nhất của set nên set không thêm các phần tử đã tồn tại trong result
    return result;//trả về result
    /*****************/
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #*/
    set<T> result;//khai báo set result kiểu T
    for(auto element : a){//duyệt qua từng phần tử của set a
        if(b.find(element)!=b.end()){//nếu tìm thấy phần tử element trong b
            result.insert(element);//thêm element vào result
        }//PHAN HOANG NAM - 20215434
    }
    return result;//trả về result
    /*****************/
}

