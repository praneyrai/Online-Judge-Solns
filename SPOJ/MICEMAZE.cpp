        #include "bits/stdc++.h"
        #define ll long long
        #define pb push_back
        #define mp make_pair
        #define xx first
        #define yy second
        using namespace std;
        const int Inf = 1e6;
        int cst[110][110];
        list<int> add[110];
        int dist[110];
        int main() {
        	ios_base::sync_with_stdio(false);
        	cin.tie(0);
        	set<pair<ll, ll> > pq;
        	int n, s, t, m;
        	cin >> n >> s >> t >> m;
        	for (int i = 0; i < m; i++) {
        		int a, b, c;
        		cin >> a >> b >> c;
        		add[b].pb(a);
        		cst[b][a] = c;
        	}
        	dist[s] = 0;
        	pq.insert(mp(dist[s], s));
        	for (int i = 1; i <= n; i++) {
        		if (i != s) {
        			dist[i] = Inf;
        			pq.insert(mp(dist[i], i));
        		}
        	}
        	int vis[110] = {0};
        	while (!pq.empty()) {
        		auto i = pq.begin();
        		vis[(*i).yy] = 1;
        		pq.erase(pq.begin());
        		for (auto x : add[(*i).yy]) {
        			if (vis[x] == 0 && dist[x] > (*i).xx + cst[(*i).yy][x]) {
        				pq.erase(mp(dist[x], x));
        				dist[x] = (*i).xx + cst[(*i).yy][x];
        				pq.insert(mp(dist[x], x));
        			}
        		}
        	}
        	int ans = 0;
        	for (int i = 0; i < n; i++) {
        		if (dist[i+1] <= t) ans++;
        	}
        	cout << ans;
        }  