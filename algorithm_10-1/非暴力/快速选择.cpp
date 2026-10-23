#include<bits/stdc++.h>
using namespace std;
const int N = 10000005;

int n, k, a[N];

void quick_sort(int l, int r, int a[]) {
	if(l == r) {
		cout << a[l]; 
		return;
	}
	
	int ref = a[r]; // 时间复杂读取决于基准值的选择 
	int i = l - 1;
	for(int j = l; j <= r; j++) {
		if(a[j] >= ref) {
			i++;
			swap(a[i], a[j]);
		}
	}
	
	if(i == k) {
		cout << a[k];
		return;
	} 
	if(i > k) quick_sort(l, i - 1, a); // 每次只递归一半，期望时间复杂度 O(n)，最坏情况O(n^2)。 
	else quick_sort(i + 1, r, a);
}

int main() {
	cin >> n >> k;
	for(int i = 1 ; i <= n; i++) cin >> a[i];
	quick_sort(1, n, a);
	return 0;
}

