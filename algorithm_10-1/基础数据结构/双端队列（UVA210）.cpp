#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;

int T, n, t[5], Q; 
int Val[26];
bool Lock;

deque<int> wait_que, block_que;

struct Program { 
	int num, index; // 语句个数， 当前语句索引 
	int str[110][3]; // 每个语句 
}pro[N]; // 每个程序 

void init() {
	memset(Val, 0, sizeof(Val)); // 多组数据，一定记得即时清空 
	Lock = false;
	wait_que.clear();
	block_que.clear();
	
	
	cin >> n >> t[0] >> t[1] >> t[2] >> t[3] >> t[4] >> Q;
	
	for(int i = 1; i <= n; i++) {
		pro[i].num = 0, pro[i].index = 1;
		
		string line;
		while(getline(cin, line)) { // 读入一整行（含空格） 
		    if(line.empty()) continue; // 防止读入空行，掉入 else 语句，引发报错
		    
			stringstream lineSS(line); // 通过字符流读取词元 
			string token1;
			lineSS >> token1; 
		
			if(token1 == "print") {
				string letter;
				lineSS >> letter;
				pro[i].str[++pro[i].num][0] = 1;
				pro[i].str[pro[i].num][1] = int(letter[0]) - 97;
			}
			else if(token1 == "lock") {
				pro[i].str[++pro[i].num][0] = 2;
			}
			else if(token1 == "unlock") {
				pro[i].str[++pro[i].num][0] = 3;
			}
			else if(token1 == "end") {
				pro[i].str[++pro[i].num][0] = 4;
				break;
			}
			else {
				string eq, val;
				lineSS >> eq >> val;
				pro[i].str[++pro[i].num][0] = 0;
				pro[i].str[pro[i].num][1] = int(token1[0]) - 97;
				pro[i].str[pro[i].num][2] = stoi(val);
			}
		}
		wait_que.push_back(i);
	}
}

int main() {
	cin >> T;
	while(T--) {
		init();
		
		while(!wait_que.empty()) {
			int now = wait_que.front();
			wait_que.pop_front();
			
			int tim = 0;
			bool flag = false;
			while(tim < Q) {
				if(pro[now].str[pro[now].index][0] == 4) {
					flag = true;
					break;
				}
				
				else if(pro[now].str[pro[now].index][0] == 1) {
					int id = pro[now].str[pro[now].index][1];
					
					cout << now << ": " << Val[id] << endl;
					
					tim += t[1];
					pro[now].index++;
				}
				else if(pro[now].str[pro[now].index][0] == 2) {
					if(!Lock) Lock = true;
					else {
						block_que.push_back(now);
						flag = true;
						break;
					}
					
					tim += t[2];
					pro[now].index++;
				}
				else if(pro[now].str[pro[now].index][0] == 3) {
					Lock = false;
					if(!block_que.empty()) {
						wait_que.push_front(block_que.front());
						block_que.pop_front();
					}
					
					tim += t[3];
					pro[now].index++;
				}
				else if(pro[now].str[pro[now].index][0] == 0){
					int id = pro[now].str[pro[now].index][1];
					int val = pro[now].str[pro[now].index][2];
					
					Val[id] = val;
					
					tim += t[0];
					pro[now].index++;
				}
			}
			if(!flag) wait_que.push_back(now);
	 	}
	 	if(T > 0) cout << endl;
	}
	return 0;
}
