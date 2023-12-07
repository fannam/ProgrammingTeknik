#include<bits/stdc++.h>
using namespace std;

int n;
int X[100], Y[100];
bool mark[100][100];

const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void print_sol(){
	int dem = 0;
	for(int j=1; j<=n*n; ++j) printf("%d: (%d, %d)\n", ++dem, X[j], Y[j]);
	exit(0);
}

void TRY(int k){
	for(int i=0; i<8; i++){
		int xx = X[k-1] + hx[i];
		int yy = Y[k-1] + hy[i];
		if(!mark[xx][yy]&&xx>=1&&xx<=n&&yy>=1&&yy<=n){
			mark[xx][yy] = true;
			X[k]=xx;
			Y[k]=yy;
			if(k==n*n) print_sol();
			else TRY(k+1);
		}
		mark[xx][yy]=false;	
	}
}
int main(){
	cin>>n;
	mark[1][1]=true;
	X[1] = Y[1] = 1;
	TRY(2);
}