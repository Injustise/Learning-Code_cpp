#include<bits/stdc++.h>
using namespace std;

int n;

vector<vector<int> > edge;
int indeg[30], outdeg[30];
bool vis[30];

int get_int(char ch) { return ch - 97; }

void init() {
	edge.clear();
	memset(indeg, 0, sizeof(indeg));
	memset(outdeg, 0, sizeof(outdeg));
	memset(vis, 0, sizeof(vis));
	edge.resize(30);
}

void dfs(int u) {
	vis[u] = false;
	for(int v : edge[u]) if(vis[v])
		dfs(v);
}

void print() {
	for(int u = 0; u < 26; u++) if(vis[u]) {
		cout << "The door cannot be opened." << endl;
		return;
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

int main() {
    int T;
    cin >> T;
    while(T--) {
    	init();
    	cin >> n;
    	for(int i = 1; i <= n; i++) {
    		string word;
    		cin >> word;
    	  	int u = get_int(word[0]), v = get_int(word[word.size() - 1]);
    		edge[u].push_back(v);
    		edge[v].push_back(u);
    		vis[u] = vis[v] = true; 
    		indeg[v]++, outdeg[u]++;
		}
		for(int u = 0; u < 26; u++) 
			if(vis[u]) {
				dfs(u);
				break; 
			}
		print();
	}
 	return 0;
}

