#include<bits/stdc++.h>
using namespace std;

const int N = 15;

bool vis[N];

void dfs(vector<int> &cur, int n) {
	if(cur.size() == n) {
		for(int x: cur) cout << x << ' ';
		cout << '\n';
		return;
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) {
			vis[i] = true;
			cur.push_back(i);
			dfs(cur, n);
			vis[i] = false;
			cur.pop_back();	
		}
}

void init() {
	for(int i = 0; i < N; i++) 
		vis[i] = false;
}

int main() {
	init(); 
	int n;
	while(cin >> n && n) {
		vector<int> cur;
		dfs(cur, n);
	} 
	return 0;
}

