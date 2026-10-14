#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const int N = 6;

int w[N], sum[1 << N];
bool vis[1 << N];

vector<pair<double, double> > dp[1 << N]; // 当前集合的合法情况(left, right)（当前最宽不一定是全局最宽，故存储所有的合法情况） 
void dfs(int mask, double r) {
	if(vis[mask]) return;
	vis[mask] = true;
	
	if(((mask - 1) & mask) == 0) { // 位运算的运算级别很低，务必加上括号 
		dp[mask].push_back({0.0, 0.0});
		return;
	}
	for(int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) { // 枚举子集 
		int lt = sub;
		int rt = sub ^ mask;
		
		dfs(lt, r); dfs(rt, r);
		
		int weight = sum[lt] + sum[rt];
		double left_len = (double)sum[rt] / weight;
		double right_len = (double)sum[lt] / weight;
		
		for(pair<double, double> &lp : dp[lt]) {
			for(pair<double, double> &rp : dp[rt]) {
				double lp_left = lp.first, lp_right = lp.second;
				double rp_left = rp.first, rp_right = rp.second;
				
				double left = max(lp_left + left_len, rp_left - right_len);
				double right = max(right_len + rp_right, lp_right - left_len);
				
				if(left + right <= r + eps) {
					dp[mask].push_back({left, right});
				}
			}
		}  
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		double r;
		int s;
		
		cin >> r >> s;
		for(int i = 0; i < s; i++) cin >> w[i];
		
		for(int mask = 1; mask < (1 << s); mask++) { // 二进制表示集合 
			sum[mask] = 0;
			for(int i = 0; i < s; i++)
			    if(mask & (1 << i)) sum[mask] += w[i];
			vis[mask] = false;
			dp[mask].clear();
		}
		
		dfs((1 << s) - 1, r);
		
		double ans = -1.0;
		
		for(pair<double, double> tree : dp[(1 << s) - 1]) {
			
			double width = tree.first + tree.second;
			ans = max(ans, width);
		}
		if(ans == -1.0) printf("-1\n");
		else printf("%.16f\n", ans);
	}
	return 0;
}

