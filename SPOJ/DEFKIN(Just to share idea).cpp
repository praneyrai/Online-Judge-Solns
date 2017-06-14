//THis is the graph approach to solve SPOJ problem DEFKIN.. 
// Just posted this to share the approach, it won't pass the time limit coz its O(n2) solution.
#include "bits/stdc++.h"

using namespace std;

bool vis[40010][40010];
int main() {
	int t; cin >> t;
	while (t--) {
		int w, h, n;
		cin >> w >> h >> n;
		for (int i = 1; i < w + 1; i++) for (int j = 1; j < h + 1; j++) vis[i][j] = 1;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			for (int i = 1; i <= w; i++) vis[i][b] = 0;
			for (int i = 1; i <= h; i++) vis[a][i] = 0;
		} 
		queue<pair<int, int> > q;
		int ans = 0;
		for (int x = 1; x <= w; x++) {
			for (int y = 1; y <= h; y++) {
				if (vis[x][y] == 1) {
					int cnt = 1;
					q.push({x, y});
					vis[x][y] = 0;
					while (!q.empty()) {
						int i = q.front().first;
						int j = q.front().second;
						q.pop();
						if (vis[i+1][j] == 1) {
							cnt++;
							vis[i+1][j] = 0;
							q.push({i+1, j});
						}
						if (vis[i-1][j] == 1) {
							cnt++;
							vis[i-1][j] = 0;
							q.push({i-1, j});
						}
						if (vis[i][j + 1] == 1) {
							cnt++;
							vis[i][j + 1] = 0;
							q.push({i, j + 1});
						}
						if (vis[i][j - 1] == 1) {
							cnt++;
							vis[i][j - 1] = 0;
							q.push({i, j - 1});
						}
					}
					ans = max(ans, cnt);
				}
			}
		}
		cout << ans << '\n';
	}
}