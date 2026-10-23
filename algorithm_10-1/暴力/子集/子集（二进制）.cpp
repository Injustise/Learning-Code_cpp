#include<bits/stdc++.h>
using namespace std;

void print_subset(int s, int n) {
	for(int i = 0; i < n; i++)
		if(s & (1 << i)) cout << i + 1 << ' ';
	cout << '\n';
}

int main() {
	int n;
	while(cin >> n && n) {
		for(int i = 0; i < (1 << n) ; i++)
		    print_subset(i, n);
	} 
	return 0;
}

