#include<bits/stdc++.h>
#define LL long long

using namespace std;

int n;
map<char, pair<int, int>> mat;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		mat[ch] = make_pair(x, y);
	}
	string str;
	while(cin >> str) {
		LL ans = 0;
		bool flag = true;
		stack<pair<int, int>> st;
		
		for(int i = 0; i < str.size(); i++) {
			
			if(str[i] == ')') {
				pair<int, int> tmp = st.top();
				st.pop();	
				while(!st.empty()) {
					if(st.top().first == -1) {
						st.pop();
						st.push(tmp);
						break;
					}
					else {
						if(st.top().second == tmp.first) {
							ans += st.top().first * st.top().second * tmp.second;
							tmp.first = st.top().first;
					        st.pop();
						}
						else {
							flag = false;
							break;
						}
					}
				}
			}
			else {
				if(str[i] == '(') st.push(make_pair(-1, 0));
				else st.push(mat[str[i]]);
			}
			if(!flag) {
				cout << "error" << endl;
				break;
			}
		}
		if(flag) {
			cout << ans << endl;
		}
	}
	return 0;
}
