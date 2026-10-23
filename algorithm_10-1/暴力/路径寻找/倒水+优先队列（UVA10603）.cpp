#include<bits/stdc++.h>
using namespace std;

const int N = 210;

int liter[3], d, all;
int Fill[N][N];

struct State {
	int w0, w1;
	int fill; 
};

struct mycmp {
	bool operator()(const State &a, const State &b) {
		return a.fill > b.fill;
	}
};

int best_d, best_fill;
void bfs() {
	memset(Fill, -1, sizeof(Fill));
	best_d = 0, best_fill = 0; 
	priority_queue<State, vector<State>, mycmp> q;
	q.push(State{0, 0, 0});
	
	while(!q.empty()) {
		State s = q.top();
		q.pop();
		
		int w[3] = {s.w0, s.w1, all - s.w0 - s.w1};
		for(int i = 0; i < 3; i++) {
			if(w[i] == d) {
				best_d = d;
				best_fill = s.fill;
				return;
			}
			if(w[i] < d && w[i] > best_d) {
				best_d = w[i];
				best_fill = s.fill;
			}
		}
		
		
		for(int i = 0; i < 3; i++) // i -> j
		 	for(int j = 0; j < 3; j++) {
		 		int water[3] = {s.w0, s.w1, all - s.w0 - s.w1};;
		 		
		 		if(water[i] == 0) break;
		 		if(i == j) continue;
		 		
				int fill = s.fill;
				if(water[i] <= liter[j] - water[j]) {
					fill += water[i];
					water[j] += water[i];
					water[i] = 0;
					
				} else {
					fill += (liter[j] - water[j]);
					water[i] -= (liter[j] - water[j]);
					water[j] = liter[j];
				}
				
				if(Fill[water[0]][water[1]] != -1) {
					if(fill < Fill[water[0]][water[1]]) {
						Fill[water[0]][water[1]] = fill;
						q.push(State{water[0], water[1], fill});
					}
				} else {
					Fill[water[0]][water[1]] = fill;
					q.push(State{water[0], water[1], fill});
				}
			}
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> liter[0] >> liter[1] >> liter[2] >> d;
		all = liter[2];
		
		bfs();
		cout << best_fill << ' ' << best_d << "\n";
	}
	return 0;
}

