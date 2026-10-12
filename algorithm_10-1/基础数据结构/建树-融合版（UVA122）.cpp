#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300;

struct Node {
	bool have_val;
	int val;
	Node *lt, *rt;
}node[MAXN];

/*
内存池 + 空闲列表
- 兼具两者之长：既有数组的内存连续（速度快），又有指针的语法支持真正的内存回收（避免了 cnt 无限膨胀的问题） 
*/

Node* root;
bool flag;

void deletenode(Node *u);

void clear_tree(Node *u) {
	if(u == nullptr) return;
	clear_tree(u->lt);
	clear_tree(u->rt);
	deletenode(u);
}

queue<Node*> freenodes;
void init_nodes() {
	for(int i = 0; i < MAXN; i++) {
		freenodes.push(&node[i]);
	}
} 
Node *newnode() {
	Node *u = freenodes.front();
	freenodes.pop();
	u->have_val = false;
	u->lt = u->rt = nullptr;
	return u; 
}
void deletenode(Node *u) {
	freenodes.push(u);
}

void add_node(char *path, int val) {
	Node *u = root;
	for(; *path != ')'; path++) {
		if(*path == 'L') {
			if(u->lt == nullptr) u->lt = newnode();
			u = u->lt;
		} else {
			if(u->rt == nullptr) u->rt = newnode();
			u = u->rt;
		}
	}
	if(u->have_val) {
		flag = false;
		return;
	}
	u->val = val;
	u->have_val = true;
}

void bfs() {
	if(!flag) {
		cout << "not complete" << endl;
		return;
	}
	queue<Node*> q;
	q.push(root);
	bool first = true;
	while(!q.empty()) {
		Node *u = q.front();
		q.pop();
		if(!u->have_val) {
			cout << "not complete" << endl;
			return;
		}
		if(first) {
			cout << u->val;
			first = false;
		} else cout << ' ' << u->val;
		if(u->lt != nullptr) q.push(u->lt);
		if(u->rt != nullptr) q.push(u->rt);
	} 
	cout << endl;
}

int main() {
	char str[MAXN];
	init_nodes();
	root = newnode();
	flag = true;
	while(cin >> str) {
		if(!strcmp(str, "()")) {
			bfs();
			clear_tree(root);
			root = newnode();
			flag = true;
			continue;
		}
		int val;
		sscanf(str + 1, "%d", &val);
		add_node(strchr(str, ',') + 1, val);
	}	
	return 0;
}

