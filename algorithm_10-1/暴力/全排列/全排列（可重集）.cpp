#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int nums[N]; 
bool vis[N];

void dfs(vector<int> &cur, int n) {
	if(cur.size() == n) {
		for(int x: cur) cout << x << ' ';
		cout << '\n';
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(i > 1 && nums[i] == nums[i - 1] && !vis[i - 1]) continue; // eg: [1, 1, 1] 保证不重复 
		if(!vis[i]) {
			vis[i] = true;
			cur.push_back(nums[i]);
			dfs(cur, n);
			vis[i] = false;
			cur.pop_back();	
		}
	}
}

void init() {
	memset(vis, 0, sizeof(vis));
}

int main() {
	init(); 
	int n;
	while(cin >> n && n) {
		for(int i = 1; i <= n; i++) cin >> nums[i];
		sort(nums + 1, nums + n + 1);
		vector<int> cur;
		dfs(cur, n);
	} 
	return 0;
}

