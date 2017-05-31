    #include "bits/stdc++.h"
    #define mp make_pair
    #define pb push_back
    #define xx first
    #define yy second
    using namespace std;
     
    char a[22][22];
    int vis[22][22];
     
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	int t;
    	cin >> t;
    	while (t--) {
    		int n, m;
    		cin >> n >> m;
    		for (int i = 0; i <= n+1; i++) {
    			for (int j = 0; j <= m+1; j++) {
    				if (i == 0 || j == 0 || i == n+1 || j == m+1) vis[i][j] = -1;
    				else vis[i][j] = 0;
    			}
    		}
    		vector<pair<int, int> > aa;
    		for (int i = 1; i <= n; i++) {
    			for (int j = 1; j <= m; j++) {
    				cin >> a[i][j];
    			}
    		}
    		if (n == 1) {
    			for (int i = 1; i <= m; i++) {
    				if (a[1][i] == '.') {
    					aa.pb({1, i});
    				}
    			}
    			if (aa.size() == 2) {
    				if (aa[0].yy + 1 == aa[1].yy) {
    					cout << "valid\n";
    				}
    				else {
    					cout << "invalid\n";
    				}
    			}
    			else {
    				cout << "invalid\n";
    			}
    			continue;
    		}
    		if (m == 1) {
    			for (int i = 1; i <= n; i++) {
    				if (a[i][1] == '.') {
    					aa.pb({i, 1});
    				}
    			}
    			if (aa.size() == 2) {
    				if (aa[0].xx + 1 == aa[1].xx) {
    					cout << "valid\n";
    				}
    				else {
    					cout << "invalid\n";
    				}
    			}
    			else {
    				cout << "invalid\n";
    			}
    			continue;
    		}
    		for (int i = 1; i <= n; i++) {
    			if (a[i][1] == '.') {
    				aa.pb({i, 1});
    			}
    			if (a[i][m] == '.') {
    				aa.pb({i, m});
    			}
    		}
    		for (int i = 2; i <= m-1; i++) {
    			if (a[1][i] == '.') {
    				aa.pb({1, i});
    			}
    			if (a[n][i] == '.') {
    				aa.pb({n, i});
    			}
    		}
    		if (aa.size() == 2) {
    			queue<pair<int, int> > q;
    			q.push({aa[0].xx, aa[0].yy});
    			vis[aa[0].xx][aa[0].yy] = 1;
    			while (!q.empty()) {
    				int x = q.front().xx;
    				int y = q.front().yy;
    				q.pop();
    				if (vis[x-1][y] == 0 && a[x-1][y] == '.') {
    					vis[x-1][y] = 1;
    					q.push({x-1, y});
    				}
    				if (vis[x+1][y] == 0 && a[x+1][y] == '.') {
    					vis[x+1][y] = 1;
    					q.push({x+1, y});
    				}
    				if (vis[x][y-1] == 0 && a[x][y-1] == '.') {
    					vis[x][y-1] = 1;
    					q.push({x, y-1});
    				}
    				if (vis[x][y+1] == 0 && a[x][y+1] == '.') {
    					vis[x][y+1] = 1;
    					q.push({x, y+1});
    				}
    			}
    			if (vis[aa[1].xx][aa[1].yy]) {
    				cout << "valid\n";
    			}
    			else {
    				cout << "invalid\n";
    			}
    		}
    		else {
    			cout << "invalid\n";
    		}
    	}	
    } 