//PHAN HOÀNG NAM - 20215434 
#include<bits/stdc++.h>
using namespace std;
typedef struct element{//khai báo kiểu dữ liệu element 
	int key; //thành phần key kiểu int 
	int value; //thành phần value kiểu int 
}element;

vector<element>m;//khai báo vector m kiểu element 

int main(){
	//PHAN HOÀNG NAM - 20215434 
	//printf("PHAN HOANG NAM - 20215434\n");
	int a,b;//khai báo biến int a, b 
	freopen("input.txt", "r", stdin);
	while(cin>>a>>b){//vòng lặp //nhập vào a, b 
		m.push_back({a, b});//đẩy phần tử element có key = a và value = b vào vector m 	
	}
	sort(m.begin(), m.end(), [](element x, element y){ //hàm sắp xếp của C++
	//sắp xếp các phần tử trên vector m 
	//với tham số là kết quả trả về của hàm nặc danh 
	//nếu tham số là true thì sắp xếp giảm dần, ngược lại tăng dần  
	//hàm nặc danh này có tham số truyền vào là biến x,y kiểu element 
		if(x.value > y.value) return true;//nếu x.value > y.value trả về true 
		else if(x.value == y.value){//nếu x.value = y.value 
			if(x.key > y.key) return true;//so sánh key của chúng 
			//trả về true nếu x.key > y.key 
			return false;//còn lại trả về false 
		}//PHAN HOÀNG NAM - 20215434 	
		return false;//trả về false trong các trường hợp còn lại 
	});
	for(auto e : m){//for each 
		printf("%d %d\n", e.key, e.value);//in ra các giá trị key và value của các phần tử 
	}
}//PHAN HOÀNG NAM - 20215434 