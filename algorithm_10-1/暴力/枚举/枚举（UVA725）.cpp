#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[10], tmp_vis[10], flag;
int p10[5] = {1, 10, 100, 1000, 10000}; 

void check(int num) {
	int tmp = num * n;
	
	for(int i = 0; i < 10; i++) tmp_vis[i] = vis[i];
	
	if(tmp > 99999) return;
	
	for(int i = 0; i < 5; i++) {
		int x = tmp % 10;
		
		if(tmp_vis[x]) return;
		
		tmp_vis[x] = true;
		tmp/=10;
	}
	
	cout << setw(5) << setfill('0') << num * n << " / " 
		 << setw(5) << setfill('0') << num << " = "
		 << n << '\n';
	flag = true;
}

void dfs(int k ,int num) {
	if(k < 0) {
		check(num);
		return;
	}
	for(int i = 0; i < 10; i++) if(!vis[i]) {
		vis[i] = true;
		dfs(k - 1, num + i * p10[k]);
		vis[i] = false; 
	}
}

int main() {
    bool first = true 
	while(cin >> n && n) {
		if(!first) cout << '\n';
		first = false;
		
		flag = false;
		for(int i = 0; i < 10; i++) vis[i] = false;
		
		dfs(4, 0);
		
		if(!flag) cout << "There are no solutions for " << n << ".\n"; 
	} 
	return 0;
}

