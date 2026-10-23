#include<bits/stdc++.h>
using namespace std;

const int root = 1;

struct Node {
	bool have_val;
	int val;
	int lt, rt;
}node[300];
int cnt;

/*
纯数组模拟（竞赛环境推荐）
- 简约，高效 
- 已知最大节点数、不需要频繁删除节点的题目中的最优解 
*/

bool flag;

void new_tree() {
	node[root].lt = node[root].rt = 0;
	node[root].have_val = false;
	cnt = root;
	flag = true;
}

int newnode() {
	int u = ++cnt;
	node[u].lt = node[u].rt = 0;
	node[u].have_val = false;
	return u;
}


void add_node(string path, int val) {
	int n = path.size();
	int u = root;
	for(int i = 0; i < n; i++) {
		if(path[i] == 'L') {
			if(!node[u].lt) node[u].lt = newnode();
			u = node[u].lt;
		} else {
			if(!node[u].rt) node[u].rt = newnode();
			u = node[u].rt;
		}
	}
	if(node[u].have_val) {
		flag = false;
		return;
	}
	node[u].val = val;
	node[u].have_val = true;
}


void bfs() {
	if(!flag) {
		cout << "not complete" << endl;
		return;
	}
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(!node[u].have_val) {
			cout << "not complete" << endl;
			return;
		}
		if(u == root) cout << node[u].val;
		else cout << ' ' << node[u].val;
		if(node[u].lt) q.push(node[u].lt);
		if(node[u].rt) q.push(node[u].rt);
	}
	cout << endl;
}

int main() {
	string str;
	new_tree();
	while(cin >> str) {
		if(str ==  "()") {
			bfs();
			new_tree();
			continue;
		}
		int pos = str.find(',');
		int val = stoi(str.substr(1, pos - 1));
		string path = str.substr(pos + 1, str.size() - pos - 2);
		add_node(path, val);
	} 
	return 0;
}
/*
(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()
*/
