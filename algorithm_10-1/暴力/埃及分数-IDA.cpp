#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const int N = 100005;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } 

ll get_c(ll a, ll b) { // 1/c <= a/b --> b <= ac
	for(ll c = b / a; ; c++) 
		if(b <= a * c) return c;
}

ll best[N],ans[N];

bool cmp(int n) {
	for(int i = n; i >= 0; i--) {
		if(best[i] == -1) return 1;
		if(ans[i] != best[i]) return ans[i] < best[i]; 
	} 
	return 0;
}
bool dfs(const int maxd, int d, ll a, ll b, ll c) {
	if(d == maxd) {
		if(b % a) return 0;
		ans[d] = b / a;
		if(ans[d] < c) return 0;
		if(cmp(maxd)) memcpy(best, ans, sizeof(ans));
		return 1;
	}
	
	c = max(c, get_c(a, b));
	bool flag = false;
	
	for(; ; c++) { 
		// 1/c * (maxd - d) <= a/b Æô·¢ÐÔ¼ôÖ¦ 
		if((__int128)b * (maxd - d + 1) <= (__int128)a * c) break;
		// a/b - 1/c
		ll aa = a * c - b;
		ll bb = b * c;
		ll g = gcd(aa, bb);
		ans[d] = c;
		if(dfs(maxd, d + 1, aa / g, bb / g, c + 1)) flag = true;
	}
	return flag;
}

int main() {
	ll a, b;
	cin >> a >> b;
	
	ll g = gcd(a, b);
	a = a / g;
	b = b / g; 
	
	for(int maxd = 0; ; maxd++) {
		memset(best, -1, sizeof(best));
		if(dfs(maxd, 0, a, b, get_c(a, b))) {
			for(int i = 0; i <= maxd; i++)
			    cout << best[i] << ' ';
			return 0;		
		}
	}
}

