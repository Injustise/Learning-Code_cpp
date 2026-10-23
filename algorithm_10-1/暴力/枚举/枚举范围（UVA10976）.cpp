/*
1/k = 1/x + 1/y

x >= y 
-> 1/x <= 1/y
-> 1/k = 1/x + 1/y <= 1/y + 1/y = 2/y
-> y <= 2k
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int k;
	while(cin >> k) {
		vector<pair<int, int> > vec;
		for(int y = k + 1; y <= 2 * k; y++) {
			if((k * y) % (y - k) == 0) {
				int x = (k * y) / (y - k);
				vec.push_back(make_pair(x, y));
			}
		}
		printf("%d\n", vec.size());
		for(pair<int, int> p : vec) {
			printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
		}
	} 
	return 0;
}

