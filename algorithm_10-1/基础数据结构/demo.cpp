#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10;

const char *dirs = "NESW";
const char *turns = "FLR";

int dir_id(char dir) { return strchr(dirs, dir) - dirs; }
int turn_id(char turn) { return strchr(turns, turn) - turns; }

// NESW
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

string case_name;
int stx, sty, edx, edy, ntx, nty;
char stdr;

struct Node {
	int x, y;
	int dir; 
};

bool edge[MAXN][MAXN][4][3];
bool vis[MAXN][MAXN][4];
bool mp[MAXN][MAXN];
Node fa[MAXN][MAXN][4];

Node walk(Node u, int turn) {
	int dir = u.dir;
	if(turn == 1) dir = (dir + 3) % 4; // 左转，逆时针 
	if(turn == 2) dir = (dir + 1) % 4; // 右转，顺时针 
	return Node{u.x + dx[dir], u.y + dy[dir], dir};
}

void print_ans(Node u) {
	vector<Node> path;
	for(;;) {
		path.push_back(u);
		if(u.x == stx && u.y == sty) break;
		u = fa[u.x][u.y][u.dir];
	}
	
	int cnt = 1;
	for(int i = path.size() - 1; i >= 0; i--, cnt++) {
		if(cnt % 10 == 1) printf("  ");
		if(cnt % 10 == 0 || i == 0) printf("(%d,%d)\n", path[i].x, path[i].y);
		else printf("(%d,%d) ", path[i].x, path[i].y);
	}
}

void bfs() {
	int dir = dir_id(stdr);
	
	queue<Node> q;
	q.push(Node{stx, sty, dir});
	vis[stx][sty][dir] = true;
	edge[stx][sty][dir][0] = true;
	
	while(!q.empty()) {
		Node u = q.front();
		q.pop();
		
		if(u.x == edx && u.y == edy) {
			print_ans(u);
			return;
		}
		
		for(int i = 0; i < 3; i++) {
			if(edge[u.x][u.y][u.dir][i]) {
				Node v = walk(u, i);
				if(mp[v.x][v.y] && !vis[v.x][v.y][v.dir]) {
					q.push(v);
					vis[v.x][v.y][v.dir] = true;
					fa[v.x][v.y][v.dir] = u;
				}
			}
			
		}
	}
	cout << "  No Solution Possible" << endl;	
}

void init() {
	memset(edge, 0, sizeof(edge));
	memset(vis, 0, sizeof(vis));
	memset(mp, 0, sizeof(mp));
}

int main() {
	while(cin >> case_name && case_name != "END") {
		init(); 
		cin >> stx >> sty >> stdr >> edx >> edy;
		mp[stx][sty] = mp[edx][edy] = true;
		int x, y;
		while(cin >> x && x) {
			cin >> y;
		    mp[x][y] = true;
			char dir_turn[10];
			while(cin >> dir_turn && strcmp(dir_turn, "*") != 0) {
				int dir = dir_id(dir_turn[0]);
				for(int i = 1; i < strlen(dir_turn); i++) {
					int turn = turn_id(dir_turn[i]);
					edge[x][y][dir][turn] = true;
				}
			} 
		}
		cout << case_name << endl;
		bfs();
	} 
	return 0;
}

