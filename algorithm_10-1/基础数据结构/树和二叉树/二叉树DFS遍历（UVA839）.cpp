#include<bits/stdc++.h>
using namespace std;

bool flag;

int dfs() {
	int lw, ld, rw, rd;
	cin >> lw >> ld >> rw >> rd;
	if(lw == 0) {
		lw = dfs();
	}
	if(rw == 0) {
		rw = dfs();
	}
	if(lw * ld != rw * rd) flag = false;
	return lw + rw;
	
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		flag = true;
		dfs();
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
		if(T) cout << endl; 
	} 
	return 0;
}
/*
1
0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2
*/
