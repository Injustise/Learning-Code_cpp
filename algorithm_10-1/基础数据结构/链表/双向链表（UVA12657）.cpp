#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int MAXN = 100000 + 10;
struct ListNode {
	int id;
	int pre, nxt;
}node[MAXN];

void init(int n) {
	for(int i = 0; i <= n + 1; i++) {
		node[i].id = i;
		node[i].pre = i - 1;
		node[i].nxt = i + 1;
	}
}

void Link(int L, int R) {
	node[L].nxt = R;
	node[R].pre = L;
}

void Insert_left(int x, int y) {
	// ¶Ï x  
	Link(node[x].pre, node[x].nxt);
	
	// ¶Ï y ²å x
	Link(node[y].pre, x);
	Link(x, y);
}

void Insert_right(int x, int y) {
	// ¶Ï x 
	Link(node[x].pre, node[x].nxt);
	
	// ¶Ï y ²å x
	Link(x, node[y].nxt);
	Link(y, x);
}

void Swap(int x, int y) {
	int x_pre = node[x].pre, x_nxt = node[x].nxt;
	int y_pre = node[y].pre, y_nxt = node[y].nxt;
	if(node[x].nxt == y) {
		Link(x_pre, y);
		Link(y, x);
		Link(x, y_nxt);
	} 
	else if(node[y].nxt == x) {
		Link(y_pre, x);
		Link(x, y); 
		Link(y, x_nxt);
	}
	else {
		Link(x_pre, y); Link(y, x_nxt);
		Link(y_pre, x); Link(x, y_nxt);
	}
}

int main() {
	int n, m, tim = 1;
	while(cin >> n >> m) {
		init(n);
		bool flag = true;
		for(int i = 1; i <= m; i++) {
			int op;
			cin >> op;
			switch(op) {
				case 1: {
					int x, y;
					cin >> x >> y;
					if(flag) Insert_left(x, y);
					else Insert_right(x, y);
					break;
				}
				case 2: {
					int x, y;
					cin >> x >> y;
					if(flag) Insert_right(x, y);
					else Insert_left(x, y);
					break;
				}
				case 3: {
					int x, y;
					cin >> x >> y;
					Swap(x, y);
					break;
				}
				case 4: {
					flag = !flag; 
					break;
				}
			}
		}
		int pos = 1;
		LL ans = 0;
		if(flag) {
			for(int i = node[0].nxt; i != n + 1; i = node[i].nxt, pos++)
				if(pos & 1) ans += node[i].id;
		} else {
			for(int i = node[n + 1].pre; i != 0; i = node[i].pre, pos++)
			    if(pos & 1) ans += node[i].id;
		}
		cout << "Case " << tim++ << ": " << ans << endl;
	}
	return 0;
}
/*
6 4
1 1 4
2 3 5
3 1 6
4
6 3
1 1 4
2 3 5
3 1 6
100000 1
4
*/
