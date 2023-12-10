/*Bài tập 4.10: Search Engine Xây dựng một máy tìm kiếm (search engine) đơn giản. Cho N văn bản và Q truy vấn.
 Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất. Sử dụng phương pháp tính điểm TF-IDF:*/
 //PHAN HOANG NAM - 20215434 
#include<bits/stdc++.h>
using namespace std;
string s[1000];//khai báo mảng s kiểu string để nhập văn bản
string que[1000];//khai báo mảng que kiểu string để nhập query
unordered_map<string, int>m[1000];//khai báo map có key kiểu string, value kiểu int
unordered_map<string, int>query[1000];//khai báo map có key kiểu string, value kiểu int
unordered_map<string, int>df;//đếm từ xuất hiện trong bao nhiêu văn bản
int n, q;//số lượng văn bản và query
static int max_f[1000];//maxf
unordered_map<string, int> createWordMap(string document, int index, bool isDocument) {//f(t,d), index bắt đầu từ 1
    unordered_map<string, int> newMap;//khởi tạo newMap
    int start = 0;//chỉ số đánh dấu bắt đầu word
   	int end = document.find(',');//chỉ số đánh dấu kết thúc word
    while (end != string::npos) {//đọc đến hết chuỗi
        string word = document.substr(start, end - start);
		//lưu từ giữa các dấu phẩy vào biến word
        if (!word.empty()) {//nếu thực sự là 1 từ
            newMap[word]++;//thêm vào map, tăng value lên 1
            //if(max_f[index]<newMap[word]) max_f[index] = newMap[word];
        }//PHAN HOANG NAM - 20214534
        start = end + 1;//chỉ số bắt đầu cho từ tiếp theo
        end = document.find(',', start);//chỉ số kết thúc cho từ tiếp theo
    }
    string lastWord = document.substr(start);//từ cuối cùng (không có dấu phẩy ở cuối)
    if (!lastWord.empty()) {//nếu thực sự là 1 từ
        newMap[lastWord]++;//thêm vào map, tăng value lên 1
        //if(max_f[index]<newMap[lastWord]) max_f[index] = newMap[lastWord];
    }
    if(isDocument){//nếu là document 
    	for(auto e : newMap) {//duyệt qua các phần tử của map 
    		df[e.first]++;//tăng df 
    		if(max_f[index]<e.second) max_f[index] = e.second;//tính max_f của văn bản thứ index 
		}
	}
    return newMap;//trả về newMap
}

double TF(string word, unordered_map<string, int>wordMap, int index){//TF(t,d)
	int max_ftd = max_f[index];//lấy giá trị max_f 
	double result = 0.5 + 0.5 * (wordMap[word]*1.0)/max_ftd;//công thức tính TF(t,d)
	return result;//trả về result
}
double IDF(string word){//IDF(t)
	int d_ft = df[word];//df(word)
	double tmp = (n*1.0)/d_ft;//N/df(word)
	double result = log2(tmp);//log_2(x) = lnx/ln2
	return result;//trả về result
}
double score(string word, unordered_map<string, int>wordMap, int index){//score(t,d)
	if(wordMap[word]==0) return 0.0;//nếu không có word trong văn bản thì trả về 0
	return IDF(word) * TF(word, wordMap, index);//nếu có thì trả về IDF(t)*TF(t,d)
}
double doc_score(unordered_map<string, int>queryMap, unordered_map<string, int>documentMap, int index){//tổng điểm
	double sum = 0;//biến tổng = 0
	for(auto e : queryMap){//duyệt qua các phần tử của query
		double tmp = score(e.first, documentMap, index);//tính điểm của từ trong query
		sum += tmp * e.second;//cộng vào tổng điểm
	}
	return sum;//trả về tổng điểm
}
int main(){
	printf("PHAN HOANG NAM - 20215434\n");
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("input_test.txt", "r", stdin);
	cin>>n;//nhập n
	cin.ignore();//không đọc dấu enter ở chuỗi tiếp theo
	for(int i=0; i<n; i++){//nhập văn bản
		getline(cin, s[i]);
		m[i]=createWordMap(s[i], i+1, true);//tạo map từ văn bảnn>>q;//nhập q
	}
	cin>>q;
	cin.ignore();//không đọc dấu enter ở chuỗi tiếp theo
	for(int i=0; i<q; i++){//nhập query
		getline(cin, que[i]);
		query[i]=createWordMap(que[i], i+1, false);//tạo map từ query
	}//PHAN HOANG NAM - 20214534
	for(int i=0; i<q; i++){//duyệt từng query qua từng văn bản
		double res = -1;//điểm 
		int index = 0;//chỉ số văn bản
		for(int j=0; j<n; j++){
			double tmp = doc_score(query[i], m[j], j+1);//tính điểm của văn bản hiện tại
			if(tmp>res){//nếu lớn hơn điểm đã tính
				index = j+1;//lưu lại chỉ số văn bản (cộng thêm 1 do tính từ 0)
				res = tmp;//đặt lại điểm lớn nhất
			}
		}
		cout<<index<<endl;//in ra chỉ số văn bản 
	}
}
