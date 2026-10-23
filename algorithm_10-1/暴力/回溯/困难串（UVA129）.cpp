#include<bits/stdc++.h>
using namespace std;

int num; 
bool have_found; 

void dfs(vector<char> &cur, int n, int L) {
	if(have_found) return;
	
	if(num == n) {
		for(int i = 0; i < cur.size(); i++) {
			if (i == 64) cout << '\n';
			else if(i && i % 4 == 0) cout << ' ';
			cout << cur[i];
		}
		cout << '\n' << cur.size() << '\n';
		have_found = true;
		return;
	}
	
	for(char ch = 'A'; ch < char('A' + L); ch++) {
		cur.push_back(ch);
		int max_len = cur.size() / 2;
		
		bool valid = true;
		for(int len = 1; len <= max_len; len++) {
			bool same = true;
			
			for(int i = 1; i <= len; i++) 
				if(cur[cur.size() - i] != cur[cur.size() - len - i]) { same = false; break; }
			
			if(same) { valid = false; break; }
		}
		if(valid) {
			num++;
			dfs(cur, n, L);
			if(have_found) return;
		}
		cur.pop_back();
	}
}

int main() {
	int n, L;
	while(cin >> n >> L) {
		if(!n && !L) break;
		vector<char> cur;
		have_found = false; 
		num = 0;
		dfs(cur, n, L);
	}
	return 0;
}

