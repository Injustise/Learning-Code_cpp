#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void dfs(vector<int> cur, int n) {
	if(cur.size() == n) {
		ans++;
		if(ans <= 3) {
			for(int col : cur) cout << col + 1 << ' ';
			cout << '\n';
		}
		return;
	}
	for(int col = 0; col < n; col++) {
		int dif = cur.size();
		bool flag = true;
		for(int i = 0; i < cur.size(); i++) {
			if(col == cur[i] || col == cur[i] + dif || col == cur[i] - dif) {
				flag = false;
				break;
			}
			dif--;
		}
		if(flag) {
			cur.push_back(col);
			dfs(cur, n);
			cur.pop_back();	
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> cur;
	dfs(cur, n);
	cout << ans;
	return 0;
}

