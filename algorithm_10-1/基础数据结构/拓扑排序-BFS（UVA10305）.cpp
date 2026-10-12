#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int n, m;
vector<vector<int> > edge;
int indeg[MAXN + 10];

vector<int> topo;

priority_queue<int, vector<int>, greater<int> > q;

void bfs() {
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		
		topo.push_back(u);
		
		for(int v : edge[u]) {
			indeg[v]--;
			if(!indeg[v]) q.push(v);
		}
	}
}
 
void init() {
	topo.clear();
	edge.clear();
	memset(indeg, 0, sizeof(indeg));
	while(!q.empty()) 
		q.pop();
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
			indeg[y]++;
		}
		for(int u = 1; u <= n; u++) 
			if(!indeg[u]) q.push(u);
		bfs();
		for(int x : topo) 
		  	cout << x << ' ';
		cout << endl;
	} 
	return 0;
}

