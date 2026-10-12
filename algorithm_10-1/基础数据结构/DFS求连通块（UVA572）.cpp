#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int m, n;

char pic[MAXN + 10][MAXN + 10];
bool vis[MAXN + 10][MAXN + 10];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void dfs(int x, int y) {
	if(x < 1 || y < 1 || x > m || y > n || pic[x][y] == '*') return;
	vis[x][y] = true;
	for(int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(!vis[xx][yy]) dfs(xx, yy);
	} 
}

int main() {
	while(cin >> m >> n && m != 0 && n != 0) {
		for(int i = 1; i <= m; i++)
		    for(int j = 1; j <= n; j++) {
		    	cin >> pic[i][j];
		    	vis[i][j] = false;
			} 
		int ans = 0;   	
		for(int i = 1;  i <= m; i++) 
		 	for(int j = 1; j <= n; j++) 
		 		if(pic[i][j] == '@' && !vis[i][j]) {
		 			ans++;
		 			dfs(i, j);
				 }
		cout << ans << endl;	
	} 
	return 0;
}

