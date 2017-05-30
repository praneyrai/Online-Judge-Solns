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
         
        ll vis[100100];
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
        		list<int> add[100005];
        		cin >> n;
        		for (int i = 0; i < n; i++) vis[i] = 0;
        		rep (i, n-1) {
        			cin >> lo >> hi;
        			add[lo].pb(hi);
        			add[hi].pb(lo);
        		}
        		queue<int> q;
        		q.push(0);
        		int x;
        		vis[0] = 1;
        		while (!q.empty()) {
        			x = q.front();
        			q.pop();
        			for (auto i : add[x]) {
        				if (!vis[i]) {
        					vis[i] = 1;
        					q.push(i);
        				} 
        			}
        		}
        		q.push(x);
        		for (int i = 0; i < n; i++) vis[i] = 0;
        		vis[x] = 1;
        		while (!q.empty()) {
        			x = q.front();
        			q.pop();
        			for (auto i : add[x]) {
        				if (!vis[i]) {
        					vis[i] = vis[x] + 1;
        					q.push(i);
        				}
        			}
        		}
        		mx = -INF;
        		for (int i = 0; i < n; i++) {
        			mx = Max(mx, vis[i]-1);
        		}
        		cout << mx/2 + mx%2 << '\n';
        	}
        	
        	
        }  