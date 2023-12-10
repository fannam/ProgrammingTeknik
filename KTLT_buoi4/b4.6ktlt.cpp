/*Bài 4.6. Viết hàm void bfs(vector< list<int> > adj) thực hiện thuật toán BFS không sử dụng đệ quy 
trên đồ thị biểu diễn bằng danh sách kề. Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán BFS
xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. 
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).*/
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    visited[1]=true;//đánh dấu đỉnh 1 đã được duyệt
    /***************** PHAN HOÀNG NAM - 20215434
    # YOUR CODE HERE #*/
    while(!Q.empty()){//lặp tới khi queue rỗng
        int s = Q.front();//s là phần tử đầu queue
        cout<<s<<endl;//in ra s
        Q.pop();//xóa phần tử đầu queue
        for(int v:adj[s]){//duyệt các đỉnh kề với s
            if(!visited[v]){//nếu chưa duyệt đỉnh nào
                Q.push(v);//đẩy vào cuối hàng đợi queue
                visited[v]=true;//đánh dấu đã duyệt qua 
            }
        }
    }
    /*****************/
}