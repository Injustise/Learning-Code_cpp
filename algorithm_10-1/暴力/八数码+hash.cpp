#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

struct State { int arr[9]; };

State st[MAXN], ed;
int dist[MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

const int H = 1000003; // 哈希（散列表） 
int head[H], nt[H];
int cnt = 0;

int _Hash(State s) {
	int num = 0;
	for(int i = 0; i < 9; i++) num = num * 10 + s.arr[i];
	return num % H; 
}

int Hash(State s) {
	int h = _Hash(s);
	int u = head[h];
	for(; u; u = nt[u]) {
		if(memcmp(st[u].arr, s.arr, sizeof(s.arr)) == 0) return 0;
	}
		
	memcpy(&st[++cnt].arr, &s.arr, sizeof(s.arr));
		
	nt[cnt] = head[h]; //头插法 
	head[h] = cnt;
	 
	return cnt;
}


int bfs() {
	dist[Hash(st[1])] = 0;
	
	queue<int> q; // 存放哈希编号 
	q.push(1);
	while(!q.empty()) {
		int s = q.front();
		q.pop();
		
		if(memcmp(ed.arr, st[s].arr, sizeof(st[s].arr)) == 0) return dist[s];
		
		int id, x, y;
		for(int i = 0; i < 9; i++) if(!st[s].arr[i]) id = i;
		x = id / 3;
		y = id % 3;
		
		for(int i = 0; i < 4 ; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
			
			int nid = nx * 3 + ny;
			
			State tmp;
			memcpy(&tmp.arr, &st[s].arr, sizeof(st[s].arr));
			
			swap(tmp.arr[id], tmp.arr[nid]);
			
			int n_hash = Hash(tmp);
			if(n_hash) { // 剪枝（跳过已经计算过的状态） 
				dist[n_hash] = dist[s] + 1;
				q.push(n_hash);
			} 
		}
	}
	return -1;
}

int main() {
	for(int i = 0; i < 9; i++) cin >> st[1].arr[i];
	for(int i = 0; i < 9; i++) cin >> ed.arr[i];
	
	memset(head, 0, sizeof(head));
	memset(dist, 0, sizeof(dist));
	
	cout << bfs();
	return 0;
}
/*
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
*/
