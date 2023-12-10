/*Bài tập 4.13: Đếm xâu con Cho một xâu nhị phân độ dài  n . Hãy viết chương trình đếm số
 lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.*/
#include<bits/stdc++.h>
using namespace std;
long long countEqualSubstrings(string binaryString) {
    long long len = binaryString.length();//độ dài chuỗi nhập vào
    long long counter = 0;//số chuỗi con có số 0 bằng 1
    map<long long, long long>frequency;//map để lưu số lần xuất hiện của giá trị prefixSum
    long long prefixSum = 0;//nếu gặp 1 thì tăng thêm 1, nếu gặp 0 thì trừ đi 1
    //nếu ở vị trí i prefixSum = k và ở vị trí j<i prefixSum = k 
	//thì chuỗi [j+1, i] là chuỗi con thỏa mãn
    for(int i=0; i<len; i++){
    	if(binaryString[i]=='1'){
    		prefixSum++;
		}//PHAN HOANG NAM - 20215434
		else prefixSum--;
		counter+=frequency[prefixSum];//đếm số chuỗi con thỏa mãn mới đc tìm thấy
		frequency[prefixSum]++;//tăng số lần xuất hiện của giá trị prefixSum thêm 1
		if(prefixSum==0) counter++;//trường hợp prefixSum = 0 thì lấy thêm cả từ index 0
	}
	return counter;//trả về số lượng dãy con thỏa mãn 
}
int main() {
	printf("PHAN HOANG NAM - 20215434\n");
	freopen("input4.13.txt", "r", stdin);
    string binaryString;//khai báo chuỗi 
    cin >> binaryString;//nhập chuỗi
    long long result = countEqualSubstrings(binaryString);//lưu kết quả vào result
    cout << result << endl;//in 
    return 0;
    //PHAN HOANG NAM - 20215434
}