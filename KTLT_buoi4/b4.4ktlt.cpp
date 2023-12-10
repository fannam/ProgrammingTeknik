/*Bài 4.4. Cho hai std::vector, hãy xóa hết các phần tử chẵn, sắp xếp giảm dần các số trong cả 2 
vector và trộn lại thành một vector cũng được sắp xếp giảm dần.*/
//PHAN HOÀNG NAM - 20215434 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #*/
    a.erase(remove_if(a.begin(), a.end(), [](int v) { return v % 2 == 0; }), a.end());
    //hàm xóa phần tử sử dụng lambda 
    /*****************/
}
//PHAN HOÀNG NAM - 20215434 
void sort_decrease(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #*/
    sort(a.begin(), a.end(), greater<int>());//hàm sắp xếp theo thứ tự giảm dần 
    /*****************/
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    # YOUR CODE HERE #*/
    vector<int>result;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result), greater<int>());
    //hàm trộn, thêm vào vector result theo thứ tự giảm dần 
    /*****************/
    return result;//trả về vector result 
}
//PHAN HOÀNG NAM - 20215434 
int main() {
    int m, n, u;//khai báo biên 
    std::vector<int> a, b;//khai báo vector 
    
    std::cin >> m >> n;//nhập m, n 
    for(int i = 0; i < m; i++){//nhập vector a
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){//nhập vector b
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a); //gọi hàm xóa số chẵn trên vector a 
    cout << "Odd elements of a: ";
    print_vector(a);//in vector a 

    delete_even(b);//gọi hàm xóa số chẵn trên vetor b 
    cout << "Odd elements of b: ";
    print_vector(b);//in vector b 
//PHAN HOÀNG NAM - 20215434 
    sort_decrease(a);//xếp phần tử trên vector a giảm dần 
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);//xếp phần tử trên vector b giảm dần
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);//trộn vector a và b, lưu kết quả vào vector c
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}//PHAN HOÀNG NAM - 20215434 