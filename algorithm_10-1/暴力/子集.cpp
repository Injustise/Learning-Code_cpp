#include<bits/stdc++.h>
using namespace std;

const int N = 15;

bool vis[N];

void dfs(int k, int n) {
	if(k > n) {
		for(int i = 1; i <= n; i++) if(vis[i])
			cout << i << ' ';
		cout << '\n';
		return;
	}
	
	vis[k] = true;
	dfs(k + 1, n);
	vis[k] = false;
	dfs(k + 1, n);
}


int main() {
	int n;
	while(cin >> n && n) {
		dfs(1, n);
	} 
	return 0;
}

