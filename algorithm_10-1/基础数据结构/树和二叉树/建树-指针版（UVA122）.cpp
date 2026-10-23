#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300;

struct Node {
	bool have_val;
	int val;
	Node *lt, *rt;	
	Node(): have_val(false), lt(nullptr), rt(nullptr) {}
};

/*
指针 + 动态内存分配（工程开发环境推荐）
- 不需要预估节点总数，来多少分配多少 

- 速度慢：new 内存地址在堆区不连续，CPU 缓存命中率低（Cache Miss）
- 内存管理麻烦：必须手动 delete
*/

Node *root;
bool flag;

void clear_tree(Node *u) {
	if(u == nullptr) return;
	clear_tree(u->lt);
	clear_tree(u->rt);
	delete u;
}

Node* newnode() {
	return new Node();
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

