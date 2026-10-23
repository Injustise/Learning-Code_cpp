#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
char str[MAXN];
int nxt[MAXN]; 

int main() {
	while(scanf("%s", str + 1)) {
		int n = strlen(str + 1);
		int cur = 0, last = 0;
		memset(nxt, 0, sizeof(nxt));
		nxt[0] = 0;
		for(int i = 1; i <= n; i++) {
			if(str[i] == '[') {
				cur = 0;
			}
			else if(str[i] == ']') {
				cur = last;
			}
			else {
				nxt[i] = nxt[cur]; // cursor 本质是链表插入操作 
				nxt[cur] = i;
				if(cur == last) last = i; 
				cur = i;
			}
		} 
		for(int i = nxt[0]; i != 0; i = nxt[i]) 
			cout << str[i];
		cout << endl;
	} 
	return 0;
}

