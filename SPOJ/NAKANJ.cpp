#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define mp make_pair
#define xx first
#define yy second
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		char c1, c2;
		int a, b;
		cin >> c1 >> a >> c2 >> b;
		a++, b++;
		queue<pair<int, int> > qq;
		map<char, int> hs;
		hs['a'] = 2, hs['b'] = 3, hs['c'] = 4, hs['d'] = 5, hs['e'] = 6, hs['f'] = 7, hs['g'] = 8, hs['h'] = 9;
		qq.push(mp(hs[c1], a));
		int vis[12][12];
		for(int i=0;i<12;i++) {
			for(int j=0;j<12;j++) {
				if(i == 0 || i == 11 || j == 0 || j == 11 || i == 1 || i == 10 || j == 1 || j == 10)	vis[i][j] = -1;
				else	vis[i][j] = 0;
			}
		}
	/*	for(int i=0;i<12;i++){
			for(int j=0;j<12;j++)	cout << vis[i][j] << " ";
			cout << "\n";
		}*/
		vis[hs[c1]][a] = 1;
		while(!qq.empty()) {
			int x = qq.front().xx;
			int y = qq.front().yy;
			qq.pop();
			if(x == hs[c2] && y == b)	break;
			// 2 left 1 up
			if(vis[x-2][y+1] == 0) {
				vis[x-2][y+1] = vis[x][y] + 1;
				qq.push(mp(x-2, y+1));
			}
			// 2 up 1 left
			if(vis[x-1][y+2] == 0) {
				vis[x-1][y+2] = vis[x][y] + 1;
				qq.push(mp(x-1, y+2));
			}
			// 2 up 1 right
			if(vis[x+1][y+2] == 0) {
				vis[x+1][y+2] = vis[x][y] + 1;
				qq.push(mp(x+1, y+2));
			}
			// 2 right 1 up
			if(vis[x+2][y+1] == 0) {
				vis[x+2][y+1] = vis[x][y] + 1;
				qq.push(mp(x+2, y+1));
			}
			// 2 right 1 down
			if(vis[x+2][y-1] == 0) {
				vis[x+2][y-1] = vis[x][y] + 1;
				qq.push(mp(x+2, y-1));
			}
			// 2 down 1 right
			if(vis[x+1][y-2] == 0) {
				vis[x+1][y-2] = vis[x][y] + 1;
				qq.push(mp(x+1, y-2));
			}
			// 2 down 1 left
			if(vis[x-1][y-2] == 0) {
				vis[x-1][y-2] = vis[x][y] + 1;
				qq.push(mp(x-1, y-2));
			}
			// 2 left 1 down
			if(vis[x-2][y-1] == 0) {
				vis[x-2][y-1] = vis[x][y] + 1;
				qq.push(mp(x-2, y-1));
			}
		}
	/*	for(int i=0;i<12;i++){
			for(int j=0;j<12;j++)	cout << vis[i][j] << " ";
			cout << "\n";
		}*/
		cout << vis[hs[c2]][b] - 1 << "\n";
	}
}