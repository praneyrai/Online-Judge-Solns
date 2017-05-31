    #include "bits/stdc++.h"
    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define xx first
    #define yy second
    using namespace std;
    typedef pair<ll, ll> pll;
     
    const int Inf = 1e6;
    ll vis[100005];
    list<pll> add[100005];
    ll dist[100005];
     
    int main() {
    	int t;
    	cin >> t;
    	while (t--) {
    		int n, m, s, d;
    		cin >> n >> m >> s >> d;
    		for (int i = 1; i <= n; i++) vis[i] = 0, add[i].clear(), dist[i] = 0;
    		for (int i = 0; i < m; i++) {
    			int a, b, c;
    			cin >> a >> b >> c;
    			add[a].pb({b, c});
    			add[b].pb({a, c});
    		} 
    		set<pll> pq;
    		dist[s] = 0;
    		pq.insert({0, s});
    		for (int i = 1; i <= n; i++) {
    			if (i != s) {
    				dist[i] = Inf;
    				pq.insert({dist[i], i});
    			}
    		}
    		while (!pq.empty()) {
    			auto ii = pq.begin();
    			ll d = (*ii).xx;
    			ll x = (*ii).yy;
    			vis[x] = 1;
    			pq.erase(pq.begin());
    			for (auto i : add[x]) {
    				if (vis[i.xx] == 0 && dist[i.xx] > d + i.yy) {
    					pq.erase({dist[i.xx], i.xx});
    					dist[i.xx] = d + i.yy;
    					pq.insert({dist[i.xx], i.xx});
    				}
    			}
    		}
    		if (dist[d] == Inf) {
    			cout << "NONE\n";
    		}
    		else {
    			cout << dist[d] << '\n';
    		}
    	}
    } 