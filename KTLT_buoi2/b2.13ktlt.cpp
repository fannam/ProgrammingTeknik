/*Bài tập 13: Big Integer
Số nguyên lớn là các số nguyên có giá trị rất lớn và không thể 
biểu diễn bằng các kiểu dữ liệu nguyên cơ bản*/
//PHAN HOÀNG NAM - 20215434
#include<bits/stdc++.h>
using namespace std;

typedef struct bigNum{
	char sign;
	string num;
}bigNum;//khai báo kiểu dữ liệu bigNum gồm sign kiểu char và num kiểu string

void initialize(string &num1, string &num2){
	//hàm khởi tạo nhận vào tham số là địa chỉ 2 biến kiểu bigNum
	int len1 = num1.length();//len1 = độ dài xâu num1
	int len2 = num2.length();//len2 = độ dài xâu num2
	int len = (len1>len2)?len1:len2;//biến len = max(len1,len2)
	while(num1.length()!=len) num1 = "0"+num1;//thêm số 0 vào đầu xâu để có độ dài bằng nhau
	while(num2.length()!=len) num2 = "0"+num2;
}//PHAN HOÀNG NAM - 20215434

string add(string &num1, string &num2){
	//hàm cộng nhận vào tham số là địa chỉ 2 biến kiểu string
    string result;//khai báo biến string result
    initialize(num1, num2);//thêm số 0 vào đầu xâu ngắn hơn
    int carryOut = 0;//khởi tạo biến carryOut = 0
    int len = num1.length();//khởi tạo len = độ dài 2 xâu
    for(int i=len-1; i>=0; i--){//cộng 
        int temp1 = num1[i] - '0';//chuyển từ char về int
        int temp2 = num2[i] - '0';//chuyển từ char về int
        int tempResult = temp1 + temp2 + carryOut;
		//thực hiện phép cộng thông thường, lưu vào biến tempResult
	//PHAN HOÀNG NAM - 20215434
		carryOut = tempResult/10;
		//nếu tempResult>10 thì carryOut=1, <10 thì carryOut=0
		tempResult %= 10;//lấy phần dư để lưu lại
		result = char(tempResult + '0') + result;
		//chuyển về char và tempResult vào result
    }
    if(carryOut>0){//nếu đến cuối mà carryOut = 1
        result = '1' + result;//thêm 1 vào đầu xâu result
    }
    return result;//trả về xâu result
}//PHAN HOÀNG NAM - 20215434

string sub(string &num1, string &num2){
	////hàm trừ nhận vào tham số là địa chỉ 2 biến kiểu string
    string result;//khai báo biến string result
    int borrow = 0;//khởi tạo biến borrow = 0
    initialize(num1, num2);//thêm số 0 vào đầu xâu ngắn hơn
    int len = num1.length();//khởi tạo len = độ dài 2 xâu
    for(int i = len - 1; i >= 0; i--){//trừ
        int temp1 = num1[i] - '0';//chuyển từ char về int
        int temp2 = num2[i] - '0';//chuyển từ char về int
        int tempResult = temp1 - temp2 - borrow;
		//thực hiện phép trừ thông thường, lưu vào biến tempResult
        if(tempResult >= 0){//nếu tempResult >= 0
            result = char(tempResult + '0') + result;
            //chuyển về char và lưu vào result
            borrow = 0;//đặt lại borrow = 0
        }//PHAN HOÀNG NAM - 20215434
        else{//nếu tempResult < 0
            tempResult += 10;//cộng thêm 10 vào tempResult
            result = char(tempResult + '0') + result;
            //chuyển về char và lưu vào result
            borrow = 1;//đặt borrow = 1
        }
    }
    size_t firstNonZero = 0;
	//khai báo biến firstNonZero kiểu size_t (đề phòng số quá dài)
    while (firstNonZero < result.length() && result[firstNonZero] == '0') {
    	//duyệt tới khi index = độ dài của result hoặc gặp kí tự '0'
        firstNonZero++;//tăng biến index
    }//PHAN HOÀNG NAM - 20215434
    if (firstNonZero == result.length()) {
    	//nếu tất cả phần tử đều là '0'
        return "0";//trả về '0'
    }
    return result.substr(firstNonZero);
	//trả về chuỗi con sau khi loại bỏ '0' ở đầu
}

bigNum operator + (bigNum num1, bigNum num2){
	//đa năng hóa toán tử + kiểu bigNum + bigNum
	bigNum result;//khai báo biến result kiểu bigNum
	if(num1.sign==num2.sign){//nếu 2 số cùng dấu
		result.sign = num1.sign;//giữ nguyên dấu
		result.num = add(num1.num, num2.num);//thực hiện cộng gttd 2 số
	}//PHAN HOÀNG NAM - 20215434
	else{//nếu 2 số khác dấu
		if(num1.num>num2.num){//nếu gttd số thứ nhất lớn hơn
			result.sign = num1.sign;//dấu kết quả giống dấu số thứ nhất
			result.num = sub(num1.num, num2.num);
			//thực hiện lấy gttd số thứ nhất trừ gttd số thứ hai
		}
		else if(num1.num<num2.num){//nếu gttd số thứ hai lớn hơn
			result.sign = num2.sign;//dấu kết quả giống dấu số thứ hai
			result.num = sub(num2.num, num1.num);
			//thực hiện lấy gttd số thứ hai trừ gttd số thứ nhất
		}
		else{//nếu 2 số bằng nhau, kết quả là +0
			result.sign = '1';
			result.num = '0';
		}//PHAN HOÀNG NAM - 20215434
	}
	return result;//trả về biến result
}

bigNum operator - (bigNum num1, bigNum num2){
	//đa năng hóa toán tử - kiểu bigNum - bigNum
	bigNum result;//khai báo biến result kiểu bigNum
	if(num1.sign!=num2.sign){//nếu 2 số khác dấu
		result.sign = num1.sign;//dấu kết quả giống dấu số thứ nhất
		result.num = add(num1.num, num2.num);//thực hiện cộng gttd 2 số
	}
	else{//nếu 2 số cùng dấu
		if(num1.num>num2.num){//nếu gttd số thứ nhất lớn hơn
			result.sign = num1.sign;//dấu kết quả giống dấu số thứ nhất
			result.num = sub(num1.num, num2.num);
			//thực hiện trừ gttd số thứ nhất cho gttd số thứ 2
		}//PHAN HOÀNG NAM - 20215434
		else if(num1.num<num2.num){//nếu gttd số thứ hai lớn hơn
			result.sign = num2.sign;//dấu kết quả giống dấu số thứ hai
			result.num = sub(num2.num, num1.num);
			//thực hiện trừ gttd số thứ nhất cho gttd số thứ 2
		}
		else{//nếu 2 số bằng nhau thì kết quả là +0
			result.sign = '1';
			result.num = '0';
		}
	}
	return result;//trả về biến result
}
//PHAN HOÀNG NAM - 20215434
bigNum operator * (bigNum num1, bigNum num2){
	//đa năng hóa toán tử * kiểu bigNum * bigNum
    bigNum result;//khai báo biến result kiểu bigNum
    result.sign = ((num1.sign == num2.sign) ? '1' : '0');
    //nếu 2 số cùng dấu thì kết quả có dấu dương
    //ngược lại kết quả có dấu âm
    int len1 = num1.num.length();//khởi tạo len1 = độ dài sâu num1.num
    int len2 = num2.num.length();//khởi tạo len2 = độ dài sâu num2.num
    for(int i = len1 - 1; i >= 0; i--){//thực hiện nhân theo quy tắc thông thường
        int carryOut = 0;//khởi tạo biến carryOut = 0
        string tempResult = "";//khởi tạo xâu rỗng tempResult
        for(int j = len2 - 1; j >= 0; j--){//thực hiện nhân theo quy tắc thông thường
            int temp1 = num1.num[i] - '0';//chuyển về kiểu int
            int temp2 = num2.num[j] - '0';//chuyển về kiểu int

            int product = (temp1 * temp2) + carryOut;
            //biến product = kết quả phép nhân 2 số nguyên + phần nhớ cũ
            carryOut = product / 10;//phần nhớ mới 
            tempResult = char(product % 10 + '0') + tempResult;
            //chuyển phần đơn vị về char và thêm vào tempResult
        }//PHAN HOÀNG NAM - 20215434
        if(carryOut > 0){//nếu đến cuối carryOut>0
            tempResult = char(carryOut + '0') + tempResult;
            //chuyển carryOut sang char và thêm vào tempResult
            //tương đương số cuối cùng thực hiện nhân rồi thêm thằng vào tempResult
        }
        for(int k = 0; k < len1 - 1 - i; k++){//dịch sang trái mỗi lần nhân
            tempResult += "0";//thêm số 0 vào cuối tempResult
        }
        result.num = add(result.num, tempResult);//cộng vào result
    }
    return result;//trả về result
}
//PHAN HOÀNG NAM - 20215434
int main(){
	printf("PHAN HOANG NAM - 20215434\n");
	bigNum a, b;//khai báo biến a, b kiểu bigNum
	bigNum number3, number4;//khai báo biến number3, number4 kiểu bigNum
	number3.sign = '1';//khởi tạo number3 = +3
	number3.num = '3';
	number4.sign = '1';//khởi tạo number4 = +4
	number4.num = '4';
	cin>>a.sign>>a.num;//nhập vào a
	cin>>b.sign>>b.num;//nhập vào b
	bigNum res = a*b - number3*a + number4*b;//res = ab-3a+4b
	cout<<res.sign<<res.num;//in ra res
}