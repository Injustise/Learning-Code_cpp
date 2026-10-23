#include<bits/stdc++.h>
using namespace std;

int n;
int indeg[30], outdeg[30];
bool vis[30];
int parent[30];

int get_int(char ch) { return ch - 'a'; }

int find(int x) {
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]); // 路径压缩 
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) parent[a] = b; 
}

void print() {
	int root = -1;
	for(int i = 0; i < 26; i++) if(vis[i]) { // 是否连通 
		if(root == -1) root = find(i);
		else if(find(i) != root) {
			cout << "The door cannot be opened." << endl;
			return;
		} 
	}
	int st = 0, ed = 0;
	for(int u = 0; u < 26; u++) {
		int diff = indeg[u] - outdeg[u];
		if(diff == -1) st++;
		else if(diff == 1) ed++;
		else if(diff != 0) {
			cout << "The door cannot be opened." << endl;
			return;
		}
	}
	if((st == 1 && ed == 1) || (!st && !ed)) cout << "Ordering is possible." << endl;
	else cout << "The door cannot be opened." << endl;
}

void init() {
	for(int i = 0; i < 26; i++) {
		parent[i] = i;
		indeg[i] = outdeg[i] = 0;
		vis[i] = false;
	}	
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		init();
		cin >> n;
		for(int i = 0; i < n; i++) {
			string word;
    		cin >> word;
    	  	int u = get_int(word.front()), v = get_int(word.back());
    	  	
    	  	vis[u] = vis[v] = true;
    	  	indeg[v]++, outdeg[u]++;
    	  	
    	  	unite(u, v);
		}
		print();
	} 
	return 0;
}

