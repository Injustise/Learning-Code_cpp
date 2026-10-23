#include<bits/stdc++.h>
using namespace std;

const int N = 20;

int w, h, n;
char grid[N][N];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int id[N][N], cnt;
vector<int> adj[N * N]; // 邻接表 

void build_graph() { // 建立临界表。本质预处理状态转移的情况，避免不合法转移的开销 
	memset(id, -1, sizeof(id));
	cnt = 0;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) 
			if(grid[i][j] != '#') id[i][j] = cnt++;
			
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) {
			for(int k = 0; k < 5; k++) {
				if(id[i][j] == -1) continue;
				
				int nx = i + dx[k];
				int ny = j + dy[k];
				
				if(nx >= 0 && nx < h && ny >= 0 && ny < w && id[nx][ny] != -1) {
					adj[id[i][j]].push_back(id[nx][ny]);
				}
			}
		}
}
 
struct State {
	int u[3];
	int tim;
	
	State() {
		u[0] = u[1] = u[2] = -1;
		tim = 0;
	}
	
	bool operator==(const State &o) const {
		return u[0] == o.u[0] && u[1] == o.u[1] && u[2] == o.u[2]; }
}; 
 
bool vis[256 * 256 * 256]; 
bool check(State &s) {
	int h = 0;
	for(int i = 0; i < n; i++) h = h * 256 + s.u[i];
	if(vis[h]) return false;
	return vis[h] = true;
}
 
void dfs(queue<State> &q, const State &s, vector<int> &actions, int k) {
	if(k == n) {
		State nt;
		for(int i = 0; i < n; i++) 
		  	nt.u[i] = actions[i];
		nt.tim = s.tim + 1;
	
		bool is_valid = true; // 字母本质是动态障碍，考虑这部分的不合法转移 
		for(int i = 0; i < n ; i++)
		    for(int j = i + 1 ; j < n; j++) {
		    	if(nt.u[i] == nt.u[j] || // 防重叠 
				s.u[i] == nt.u[j] && s.u[j] == nt.u[i]) { // 防对穿 
					is_valid = false; 
				}
			}
	
		if(is_valid && check(nt)) q.push(nt);
		
		return; 
	}
	
	for(int v : adj[s.u[k]]) {
		actions.push_back(v);
		dfs(q, s, actions, k + 1);
		actions.pop_back();
	}
} 

void bfs(State &st, State &ed) {
	queue<State> q;
	q.push(st);
	
	while(!q.empty()) {
		State s = q.front();
		q.pop();
		
		if(s == ed) {
			cout << s.tim << '\n';
			return;
		}
		
		vector<int> actions;
		dfs(q, s, actions, 0);		
	}
}
 
void init() {
	for(int i = 0; i < N * N; i++) adj[i].clear();
	memset(vis, 0, sizeof(vis));
} 
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	while(cin >> w >> h >> n && w && h && n) {
		cin.ignore(100, '\n'); // 先吃掉换行符 
		for(int i = 0; i < h; i++) cin.getline(grid[i], N);
		
		init(); 
		
		build_graph();
		State st, ed;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++) {
			if(grid[i][j] >= 'a' && grid[i][j] <= 'c') {
				int ch = grid[i][j] - 'a';
				st.u[ch] = id[i][j];
			}
			if(grid[i][j] >= 'A' && grid[i][j] <= 'C') {
				int ch = grid[i][j] - 'A';
				ed.u[ch] = id[i][j];
			}
		}
		bfs(st, ed);
	}
	return 0;
}
/*
5 5 2
#####
#A#B#
#   #
#b#a#
#####
0 0 0
*/
