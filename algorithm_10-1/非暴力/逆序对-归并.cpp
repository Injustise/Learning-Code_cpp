#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;

int n, a[N];
long long ans = 0;

void merge_sort(int l, int r, int a[]) {
	if(l >= r) return;
	
	int mid = (l + r) >> 1;
	merge_sort(l, mid, a);
	merge_sort(mid + 1, r, a);
	
	int tmp[n + 1], t = l;
	int i = l, j = mid + 1; 
	while(i <= mid && j <= r) {
		if(a[i] <= a[j]) {
			tmp[t++] = a[i];
			i++;
		} else {
			tmp[t++] = a[j];
			ans += (mid - i + 1);
			j++;
		}
	}
	for(; i <= mid; i++) tmp[t++] = a[i];
	for(; j <= r; j++) tmp[t++] = a[j];
	for(int k = l; k <= r; k++) a[k] = tmp[k];
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	merge_sort(1, n, a);
	cout << ans;
	return 0;
}

