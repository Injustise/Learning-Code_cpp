#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int nums[N];

int main() {
	int n;
	while(cin >> n && n) {
		for(int i = 1; i <= n; i++) cin >> nums[i];
		
		sort(nums + 1, nums + n + 1); // 必须先 sort，保证不遗漏 
		
		do {
			for(int i = 1; i <= n; i++) cout << nums[i] << ' ';
			cout << '\n';
		} while(next_permutation(nums + 1, nums + n + 1)); // 也适用于字符串（可重集） 
	} 
	return 0;
}

