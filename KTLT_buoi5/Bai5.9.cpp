// PHAN HOANG NAM - 20215434
/* Bài tập 9: Xây tháp
Perhaps you have heard of the legend of the Tower of Babylon. Nowadays many details of 
this tale have been forgotten. So now, in line with the educational nature of this contest,
 we will tell you the whole story:
The babylonians had n types of blocks, and an unlimited supply of blocks of each type. Each type-i
 block was a rectangular solid with linear dimensions (xi,yi,zi). A block could be reoriented so
that any two of its three dimensions determined the dimensions of the base and the other dimension 
was the height. They wanted to construct the tallest tower possible by stacking blocks. 
The problem was that, in building a tower, one block could only be placed on top of another
 block as long as the two base dimensions of the upper block were both strictly smaller than
  the corresponding base dimensions of the lower block. This meant, for example,
that blocks oriented to have equal-sized bases couldn't be stacked.
Your job is to write a program that determines the height of the tallest tower the babylonians can 
build with a given set of blocks.
*/

#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x, y, z;
} block;
int n;
block a[100];
int maxh[100];

void input(){
    cin >> n;
    if (n == 0) exit(0);
    int x, y, z;
    for (int i = 1; i <= n; i++){//nhập dữ liệu
        cin >> x >> y >> z;
        a[3 * i - 2].x = x;
        a[3 * i - 2].y = y;
        a[3 * i - 2].z = z;
        a[3 * i - 1].x = y;
        a[3 * i - 1].y = z;
        a[3 * i - 1].z = x;
        a[3 * i].x = z;
        a[3 * i].y = x;
        a[3 * i].z = y;
    }
// PHAN HOANG NAM - 20215434
    for(int i=0; i<100; i++) maxh[i] = 0;//khởi tạo
}

int dp(int i){//Tim chieu cao cua toa thap voi dinh la vien i
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;
    for(int j = 1; j <= 3*n; j++){
        if (a[i].x < a[j].x && a[i].y < a[j].y ||
            a[i].x < a[j].y && a[i].y < a[j].x){
            maxh[i] = max (maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}

int main(){
    printf("PHAN HOANG NAM - 20215434\n");
    int cnt = 1;
    while(1){
        int res = 0;
        input();
        for(int i = 1; i <= 3 * n; i++){
            res = max(res, dp(i));
        }
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}
// PHAN HOANG NAM - 20215434