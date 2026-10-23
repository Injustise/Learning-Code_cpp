#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1024;

void skip(char *&tree, int depth) {
	if(*tree == 'p') 
		for(int i = 0; i < 4; i++) 
			skip(++tree, depth + 1);
}

int count(char *&tree, int depth) {
	int area = MAXN >> (depth * 2);
	int Fill = 0; 
	if(*tree == 'e') return 0;
	if(*tree == 'f') return area;
	for(int i = 0; i < 4; i++) 
		Fill += count(++tree, depth + 1);
	return Fill;
	
}

int merge(char *&tree1, char *&tree2, int depth) {
	int area = MAXN >> (depth * 2);
	int Fill = 0;
	
	if(*tree1 == 'p' && *tree2 == 'p') {
		for(int i = 0; i < 4; i++) 
			Fill += merge(++tree1, ++tree2, depth + 1);
		return Fill;
	}
		
	if(*tree1 == 'f' || *tree2 == 'f') {
		if(*tree1 == 'p') skip(tree1, depth);
		if(*tree2 == 'p') skip(tree2, depth);
		return area;
	}
	
	if(*tree1 == 'e' && *tree2 == 'p') 
	    return count(tree2, depth);
	if(*tree1 == 'p' && *tree2 == 'e')
	  	return count(tree1, depth);
	if(*tree1 == 'e' && *tree2 == 'e')
	    return 0; 
}

int main() {
	int T;
	char tree1[MAXN * 4], tree2[MAXN * 4];
	
	cin >> T;
	while(T--) {
		cin >> tree1 >> tree2;
		char *p1 = tree1;
		char *p2 = tree2;
		cout << "There are " << merge(p1, p2, 0) << " black pixels.\n";	
	}
	return 0;
}
/*
3
ppeeefpffeefe
pefepeefe
peeef
peefe
peeef
peepefefe
*/
