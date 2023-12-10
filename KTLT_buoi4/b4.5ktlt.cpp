/*Bài 4.5. Viết hàm void dfs(vector< list<int> > adj) thực hiện thuật toán DFS không sử dụng đệ quy 
trên đồ thị biểu diễn bằng danh sách kề. Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS 
xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. 
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).*/
//PHAN HOÀNG NAM - 20215434 
void dfs(vector<list<int>> adj) {
    stack<int> S;
    vector<bool> visited(adj.size(), false);
    S.push(1); // Start from vertex 1
    while (!S.empty()) {//lặp tới khi stack rỗng 
        int top = S.top();//gán phần tử trên cùng của stack vào top 
        if(!visited[top]){//kiểm tra để in 
            cout<<top<<endl;//nếu chưa từng duyệt qua thì in ra 
            visited[top]=true;//đánh dấu đã duyệt qua 
        }
        if(!adj[top].empty()){//kiểm tra danh sách kề rỗng 
            int v = adj[top].front();//v = node trái nhất trong ds kề 
            adj[top].pop_front();//xóa node trái nhất trong ds kề  
            if(!visited[v]){//nếu chưa từng duyệt qua v 
                S.push(v);//đẩy vào stack
            }
        }
        else S.pop();//xóa phần tử trên cùng của stack 
    }
}