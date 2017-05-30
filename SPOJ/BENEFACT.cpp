    // Praney Rai
    // Welcome (:
    #include <stdio.h>
    #include <bits/stdc++.h>
    using namespace std;
     
    #define rep(i , n)	for(ll i=0 ; i<n ; ++i)
    #define loop(i , a , b)	for(ll i=a ; i<b ; ++i)
    #define loopi(i , a) for(auto i = a.begin() ; i != a.end() ; ++i)
    #define io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #define Max(a, b)	(a > b ? a : b)
    #define Min(a, b)	(a > b ? b : a)
    #define Mid(a, b)	((a+b)/2)
    #define all(x) x.begin(), x.end()
    #define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define rtn return
    #define xx first
    #define yy second
    #define pb push_back
    #define mp make_pair
    #define eb emplace_back
    #define fill(a , x) memset(a , x , sizeof(a))
     
    typedef long long ll;
    typedef string str;
    typedef double db;
    typedef vector<ll> vi;
     
    const int N = 100100;
    const int MOD = int(1e9) + 7;
    const ll INF = 1e18;
    const db PI = 3.1415926536;
     
    ll vis[50050];
     
    int main() {
    	std::ios_base::sync_with_stdio(false);
    	std::cin.tie(NULL);
    	std::cout.tie(NULL);
    	ll n = 0, m = 0, k = 0, lo = 0, hi = 0, mi = INF, mx = -INF, sum = 0, ans = 0, cnt=0, t = 0, v1 = 0, v2 = 0;
    	str s, s1, s2;
    	char c, c1, c2, *ptr;
    	db dub=0;
    	/////////////////////////////////////////////////////////////////////////////////////////////
    	cin >> t;
    	while (t--) {
    		cin >> n;
    		list<int> add[50050];
    		map<ll, map<ll, ll> > cst;
    		for (int i = 0; i < n - 1; i++) {
    			int a, b, c;
    			cin >> a >> b >> c;
    			add[a].pb(b);
    			add[b].pb(a);
    			if (a < b) {
    				cst[a][b] = c;
    			}
    			else {
    				cst[b][a] = c;
    			}
    		}
    		queue<int> q;
    		q.push(1);
    		fill(vis, 0);
    		vis[1] = 0;
    		while (!q.empty()) {
    			int x  = q.front();
    			q.pop();
    			for (auto i : add[x]) {
    				if (vis[i] == 0) {
    					if (x < i) {
    						vis[i] = vis[x] + cst[x][i];
    					}
    					else {
    						vis[i] = vis[x] + cst[i][x];
    					}
    					q.push(i);
    				}
    			}
    		}
    		mx = -INF, v1 = 0;
    		loop (i, 1, n+1) {
    			if (vis[i] > mx) {
    				mx = vis[i];
    				v1 = i;
    			}
    		}
    		q.push(v1);
    		fill(vis, 0);
    		vis[v1] = 0;
    		while (!q.empty()) {
    			int x  = q.front();
    			q.pop();
    			for (auto i : add[x]) {
    				if (vis[i] == 0) {
    					if (x < i) {
    						vis[i] = vis[x] + cst[x][i];
    					}
    					else {
    						vis[i] = vis[x] + cst[i][x];
    					}
    					q.push(i);
    				}
    			}
    		}
    		mx = -INF;
    		loop (i, 1, n+1) {
    			if (vis[i] > mx) {
    				mx = vis[i];
    			}
    		}
    		cout << mx << '\n';
    	}
    	
    	
    } 