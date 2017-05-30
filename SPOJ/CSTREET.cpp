    #include "bits/stdc++.h"
    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define xx first
    #define yy second
    using namespace std;
    typedef pair<ll, pair<ll, ll> > plll; 
    typedef priority_queue<plll, vector<plll>, greater<plll> > pq;
    ll ran[1010];
    ll par[1010];
    ll find(ll x){
    	if(x != par[x])	par[x] = find(par[x]);
    		return par[x];
    }
    void merge(ll x, ll y){
    	int i = find(x);
    	int j = find(y);
    	if(ran[i] > ran[j])	par[j] = i;
    	else	par[i] = j;
    	if(ran[i] == ran[j])	ran[j] += 1;
    }
    bool isC(ll x, ll y){
    	return find(x) == find(y);
    }
    int main() {
    	int t;
    	cin >> t;
    	while (t--) {
    		memset(ran, 0, 1009);
    		for (int i = 0; i < 1010; i++) par[i] = i;
    		pq queue;
    		ll pr, n, m;
    		cin >> pr >> n >> m;
    		for (int i = 0; i < m; i++) {
    			int a, b, c;
    			cin >> a >> b >> c;
    			queue.push(mp(c, mp(a, b)));
    		}
    		int cnt = 0, ans = 0;
    		for (int i = 0; ; i++) {
    			if (cnt == n-1) break;
    			auto it = queue.top();
    			queue.pop();
    			if (!isC((it).yy.xx, (it).yy.yy)) {
    				cnt++;
    				merge(it.yy.xx, it.yy.yy);
    				ans += it.xx;
    			}
    		}
    		cout << (long long)ans*pr << '\n';
    	}
    } 