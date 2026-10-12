#include<bits/stdc++.h>
using namespace std;
const int MAXD = 20;
bool s[1 << MAXD];
int main() {
    int T, D, I;
    cin >> T;
	while(T--) {
		cin >> D >> I;
		memset(s, 0, sizeof(s));
//		for(int i = 1; i <= I; i++) { // O(2^19 * 19) + 多组数据 = TLE 
//			k = 1, d = 1;
//			while(d < D) {
//				s[k] = !s[k];
//				k = s[k] ? k * 2 : k * 2 + 1; // 完全二叉树的左右节点编号 
//				d++; 
//			} 
//		}
		int k = 1; 
		for(int i = 1; i < D; i++) {
			if(I & 1) {
				k = k * 2;
				I = I / 2 + 1;
			} else {
				k = k * 2 + 1;
				I = I / 2; 
			}	  
		}
		cout << k << endl;
	} 
	cin >> T;
	return 0;
}
/*
5
4 2
3 4
10 1
2 2
8 128
-1
*/
