#include<bits/stdc++.h>
using namespace std;

const int MAXN  = 10000 + 10;

int in_order[MAXN];
int post_order[MAXN];

int mp[MAXN];

int minn, minn_x;

void dfs(int l1, int r1, int l2, int r2, int sum) {
	if(l1 > r1) return;
	if(l1 == r1) {
		if(sum + in_order[l1] < minn || (sum + in_order[l1] == minn && in_order[l1] < minn_x)) {
			minn = sum + in_order[l1];
			minn_x = in_order[l1];
		}
		return;
	}
	
	int u_val = post_order[r2];
	int pos = mp[u_val];
	
	int len = pos - l1;
	
	// left tree
	dfs(l1, pos - 1, l2, l2 + len - 1, sum + u_val);
	// right tree
	dfs(pos + 1, r1, l2 + len, r2 - 1, sum + u_val);
		
}

int main() {
    string line;
    while(getline(cin, line)) {
    	stringstream s1(line);
    	int x, n = 0;
    	while(s1 >> x) {
    		in_order[++n] = x;
    		mp[x] = n;
		}
    	
    	getline(cin, line);
    	stringstream s2(line);
    	n = 0;
    	while(s2 >> x) post_order[++n] = x;
    	
    	minn = MAXN * MAXN;
    	minn_x = MAXN;
    	dfs(1, n, 1, n, 0);
    	
    	cout << minn_x << endl;
	}
	return 0;
}
/*
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255
*/
