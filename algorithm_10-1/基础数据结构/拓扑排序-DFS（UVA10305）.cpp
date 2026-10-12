#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int n, m;
bool flag;

int vis[MAXN + 10];
vector<vector<int>> edge;

vector<int> topo;

void dfs(int u) {
	vis[u] = -1;
	for(int v : edge[u]) {
		if(vis[v] < 0) {
			flag = false;
			return;
		}
		if(!vis[v]) dfs(v);
	}
	vis[u] = 1;
	topo.push_back(u);
}

void topo_sort(){
	for(int u = 1; u <= n; u++) 
		if(flag && !vis[u]) dfs(u);
}

void init() {
	flag = true;
	memset(vis, 0, sizeof(vis));
	edge.clear();
	topo.clear();
}

int main() {
   	while(cin >> n >> m) {
   		if(!n && !m) break; 
   		init();
   		edge.resize(n + 1);
   		while(m--) {
   			int x, y;
			cin >> x >> y;
			edge[x].push_back(y);	
		}	
		topo_sort();
		if(!flag) cout << -1 << endl;
		else {
			reverse(topo.begin(), topo.end());
			for(int x : topo) 
				cout << x << ' ';
			cout << endl;
		}
		
	}
	return 0;
}

