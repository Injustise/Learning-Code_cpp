#include<bits/stdc++.h>
using namespace std;

struct Node {
	int weight;
	double left, right;
	Node(int weight, double left, double right) : weight(weight), left(left), right(right) {}
};

const double eps = 1e-8;
double ans;

const int N = 100;
bool vis[N];

void dfs(vector<Node> &nodes, int k, double rr, int ss) {
	if(k == ss - 1) {
		double width = nodes.back().left + nodes.back().right;
		if(width - rr < eps) 
			ans = max(ans, width);
		return;
	}
	for(int l = 0; l < nodes.size(); l++) {
		if(vis[l]) continue;
		for(int r = 0; r < nodes.size(); r++) {
	 		if(l == r || vis[r]) continue;
	 		int weight = nodes[l].weight + nodes[r].weight;
	 		double left_len = (double)nodes[r].weight / weight;
	 		double right_len = (double)nodes[l].weight / weight;
	 		
			Node newnode(weight, 
						max(nodes[l].left + left_len, nodes[r].left - right_len), 
						max(right_len + nodes[r].right, nodes[l].right - left_len));
			
			vis[l] = vis[r] = true;
			nodes.push_back(newnode);
			
			dfs(nodes, k + 1, rr, ss);
			
			vis[l] = vis[r] = false;
			nodes.pop_back();	
		}
	}
	 	
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		double r;
		int s;
		cin >> r >> s;
		
		vector<Node> nodes;
		for(int w, i = 0; i < s; i++) {
			cin >> w;
			nodes.push_back(Node(w, 0.0, 0.0));
		}
		
		ans = -1.0;
		dfs(nodes, 0, r, s);
		
		if(ans == -1.0) printf("-1\n");
		else printf("%.16f\n", ans); 
	} 
	return 0;
}

