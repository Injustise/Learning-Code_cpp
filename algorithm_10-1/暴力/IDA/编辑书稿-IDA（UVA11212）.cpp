#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int book[N];

int check(const int list[], int n) {
	int err = 0;
	for(int i = 0; i < n; i++) {
		if(list[i] == n) {
			if(list[i + 1] != 0) err++;
		}
		else if(list[i + 1] != (list[i] + 1)) err++;
	}	
	return err;
}

void edit(int list[], int n, int l, int r, int k) {
	int tmp[N], t = 0;
	for(int i = 0; i <= k; i++) {
		if(i >= l && i <= r) continue;
		tmp[t++] = list[i];	
	}
	for(int i = l; i <= r; i++) {
		tmp[t++] = list[i];
	} 
	for(int i = k + 1; i < n; i++) {
		if(i >= l && i <= r) continue;
		tmp[t++] = list[i];
	}
	tmp[t] = 0;
	memcpy(list, tmp, sizeof(tmp));
}

bool dfs(const int maxd, int d, int n, int list[]) {
	if(d == maxd) {
		for(int i = 0; i < n; i++) 
			if(list[i] != i + 1) return 0; 
		return 1;
	}
	
	if(3 * (maxd - d) < check(list, n)) return 0; // 启发性剪枝 

	int tmp[N];	
	for(int len = 1; len <= n - 1; len++) { // 枚举剪切长度 
		for(int i = 0; i <= n - len; i++) { // 枚举剪切起点 
			int j = i + len - 1;
		
			if(i == 0 && list[i] == 1) continue; // 剪枝，不破坏合法后继 
			else if(j == n - 1 && list[j] == n) continue;
			else if((i && list[i] == list[i - 1] + 1) || (j < n - 1 && list[j + 1] == list[j] + 1)) continue;
	
				
			for(int k = 0; k < i; k++) { // 枚举插入点 
				memcpy(tmp, list, (n + 1) * sizeof(int)); // 数组传参退化为指针 type(list) = int*，这里不能直接 sizeof(list) 
				edit(tmp, n, i, j, k);
				if(dfs(maxd, d + 1, n, tmp)) return true;
			}
			for(int k = j + 1; k < n; k++) {
				memcpy(tmp, list, (n + 1) * sizeof(int));
				edit(tmp, n, i, j, k);
				if(dfs(maxd, d + 1, n, tmp)) return true;
			}
		}
	}
	return false;
}

int main() {
	int n, T = 0;
	while(cin >> n && n) {
		memset(book, 0, sizeof(book));
		for(int i = 0; i < n; i++) cin >> book[i];
		for(int maxd = 0; maxd < n; maxd++) {
			if(dfs(maxd, 0, n, book)) {
				cout << "Case " << ++T << ": " << maxd << '\n';
				break;
			}
		}
	}
	return 0;
}

