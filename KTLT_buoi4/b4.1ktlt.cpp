/*Bài 4.1: Đảo ngược một danh sách liên kết đơn

Hãy hoàn thiện các hàm thao tác trên một danh sách liên kết:

Thêm một phần tử vào đầu danh sách liên kết
In danh sách
Đảo ngược danh sách liên kết (yêu cầu độ phức tạp thời gian O(N) và chi phí bộ nhớ dùng thêm O(1))*/
//PHAN HOANG NAM - 20215434
#include <iostream> 
using namespace std;
struct Node {//kiểu dữ liệu Node 
    int data; 
    Node* next;

    Node(int data) {//constructor
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /***************** PHAN HOÀNG NAM - 20215434 
    # YOUR CODE HERE #*/
    Node *newNode = new Node(data);//tạo node mới 
   	//gán node mới lên đầu danh sách 
   	newNode->next = head->next;
   	head->next = newNode;
    return head;//trả về head 
    /*****************/
}
//PHAN HOÀNG NAM - 20215434 
// print the list content on a line
void print(Node* head) {
    /*****************
    # YOUR CODE HERE #*/
    Node *p = head->next;//khai báo node tạm p = node tiếp theo của head 
    while(p!=NULL){//lặp tới cuối danh sách 
        printf("%d ", p->data);//in ra giá trị node p 
        p=p->next;//gán p = node tiếp theo 
    }
    printf("\n");//xuống dòng 
    /*****************/
}
//PHAN HOÀNG NAM - 20215434 
// return the new head of the reversed list
Node* reverse(Node* h) {
    /*****************PHAN HOÀNG NAM - 20215434 
    # YOUR CODE HERE #*/
    if (h->next == NULL || h->next->next == NULL) {
        return h;//nếu danh sách rỗng thì trả về head 
    }
    Node* prev = NULL;//khai báo node tạm prev là node trước đó 
    Node* current = h->next;//khai báo node tạm current là node hiện tại 
    Node* nextNode = NULL;//khai báo node tạm nextNode là node tiếp theo 
//PHAN HOÀNG NAM - 20215434 
    while (current != NULL) {//lặp tới cuối danh sách 
        nextNode = current->next;//gán giá trị cho node tiếp theo 
        current->next = prev;//gán giá trị mới cho node tiếp theo sau khi đảo danh sách (là node trước)
        prev = current;//gán node hiện tại vào node trước 
        current = nextNode;//gán node sau và node hiện tại
    }

    h->next = prev;//trỏ node tiếp theo của head tới đầu danh sách mới 
    return h;//trả về con trỏ head 
    /*****************/
}//PHAN HOÀNG NAM - 20215434 
  
int main() {
    int n, u;
    cin >> n;
    Node* head = new Node(1e9);//tạo node head 
    for (int i = 0; i < n; ++i){//nhập danh sách 
        cin >> u;//nhập data
        head = prepend(head, u);//thêm vào đầu danh sách 
    } 
    
    cout << "Original list: ";
    print(head);//in 

    head = reverse(head);//đảo danh sách 
//PHAN HOÀNG NAM - 20215434     
    cout << "Reversed list: ";
    print(head);//in 

    return 0; 
}