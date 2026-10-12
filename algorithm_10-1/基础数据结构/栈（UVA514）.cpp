#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
int main() {
    int n, target[N];
	while(cin >> n && n) {
		while(cin >> target[1] && target[1]) {
			for(int i = 2; i <= n; i++) cin >> target[i];
			stack<int> C;
			int A = 1, B = 1;
			while(A <= n) {
				C.push(A++); 
				while(!C.empty() && C.top() == target[B]) {
					C.pop();
					B++;
				}
			}
			if(C.empty()) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	} 
	return 0;
}

