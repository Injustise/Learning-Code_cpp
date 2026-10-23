#include<bits/stdc++.h>
using namespace std;

const int N = 100;

bool is_prime[N], vis[N];

void dfs(vector<int> cur, int n) {
	if(cur.size() == n) {
		if(is_prime[cur[0] + cur[n - 1]]) {
			cout << cur[0];
    		for(int i = 1; i < cur.size(); i++) cout << ' ' << cur[i];
    		cout << '\n';
		}
		return;
	}
	for(int i = 2; i <= n; i++) {
		if(vis[i] || (!cur.empty() && !is_prime[i + cur[cur.size() - 1]])) 
			continue;
		vis[i] = true;
		cur.push_back(i);
		dfs(cur, n);
		vis[i] = false;
		cur.pop_back();
	}
}

void primes() {
	is_prime[1] = false;
	for(int i = 2; i < N; i++) {
		bool flag = true;
		for(int j = 2; j <= sqrt(i); j++) {
			if(i % j == 0) {
				is_prime[i] = false;
				flag = false;
				break;
			}
		}
		if(flag) is_prime[i] = true;
	}
} 

int main() {
	int n; 
	primes();
	memset(vis, 0, sizeof(vis));
	
	int tim = 1;
	bool fir = true;
	while(cin >> n) {
		if(!fir) cout << '\n';
		fir = false;
		vector<int> cur;
		cur.push_back(1); // 强制第一个位置放 1，保证字典序最小的同时，不重不漏地遍历每一个环（n!/n = (n - 1)!） 
		
		cout << "Case " << tim++ << ":\n";
		dfs(cur, n);
	}
	
	return 0;
}

