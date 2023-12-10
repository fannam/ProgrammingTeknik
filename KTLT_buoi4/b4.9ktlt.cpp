/*Bài 4.9. Cài đặt thuật toán Dijkstra trên đồ thị vô hướng được biểu diễn bằng danh sách kề 
sử dụng std::priority_queue
Cụ thể, bạn cần cài đặt hàm vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj)
nhận đầu vào là danh sách kề chứa các cặp pair<int, int> biểu diễn đỉnh kề và trọng số tương ứng
của cạnh. Đồ thị gồm n đỉnh được đánh số từ 0 tới n-1. Hàm cần trả `vector<int>` chứa n phần tử 
lần lượt là khoảng cách đường đi ngắn nhất từ đỉnh 0 tới các đỉnh 0, 1, 2, ..., n-1.*/
//PHAN HOÀNG NAM - 20215434
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************
    # YOUR CODE HERE #*/
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //Khai báo hàng chờ ưu tiên sắp xếp tăng dần
    vector<int>dist(adj.size(), INT_MAX);
    //khai báo vector dist kiểu int, kích thước ban đầu = kích thước vector adj
    //giá trị ban đầu = INT_MAX
    vector<bool>visited(adj.size(), false);
    //khai báo vector visited kiểu bool, kích thước ban đầu = kích thước vector adj
    //giá trị ban đầu = false
    dist[0]=0;//khởi tạo dist[0]=0 là khoảng cách từ 0 đến chính nó
    pq.push({dist[0], 0});//đẩy vào hàng chờ
    visited[0]=true;//đánh dấu đã thăm
    while(!pq.empty()){//lặp tới khi hàng chờ rỗng
        int v = pq.top().second;//v = thành phần đỉnh của phần tử đầu hàng chờ 
        visited[v]=true;//đánh dấu đã thăm v
        pq.pop();//xóa phần tử đầu hàng chờ
        for(auto e : adj[v]){//duyệt qua các đỉnh kề v
            int s = e.first;//s là thành phần đỉnh
            int weight = e.second;//weight là thành phần trọng số
            if(!visited[s]){//nếu chưa từng thăm s
                if(dist[s] > dist[v] + weight){//kiểm tra độ dài đường đi ngắn nhất hiện tại
                    dist[s] = dist[v] + weight;//cập nhật độ dài đường đi 
                    pq.push({dist[s], s});//đẩy vào hàng chờ
                }
            }
        }//PHAN HOÀNG NAM - 20215434
    }
    return dist;//trả về vector dist
    /*****************/
}
