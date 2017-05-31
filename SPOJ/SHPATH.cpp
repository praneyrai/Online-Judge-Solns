    #include "bits/stdc++.h"
    #define pb push_back
    #define xx first
    #define yy second
    #define gc getchar_unlocked
    #define str string
    #define rtn return
    using namespace std;
    typedef long long ll;
    const int Inf = 1e5;
    inline void putln(ll x){int i = 20;char buf[21];buf[20]='\n';do{buf[--i] = x % 10 + '0';x/= 10;}while(x);do{putchar(buf[i]);}while(buf[i++]!='\n');}
    inline str sin(){str s="";while (1){char c = gc();if(c==' '||c=='\n')break;s+=c;}rtn s;}
    inline ll in(){ll n=0,s=1;char p=gc();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=gc();if(p=='-')s=-1,p=gc();while(p>='0'&&p<='9'){n=(n<< 3)+(n<< 1)+(p - '0');p=gc();}return n*s;}
    int main() {
    	ll t = in();
    	while (t--) {
    		vector<pair<ll, ll> > add[10010];
    		unordered_map<string, ll> mp;
    		ll n = in();
    		for (ll i = 1; i <= n; i++) {
    			string s = sin();
    			mp[s] = i;
    			ll m = in();
    			while (m--) {
    				int a = in(), c = in();
    				add[a].pb({i, c});
    				add[i].pb({a, c});
    			}
    		}
    		ll tt = in();
    		while (tt--) {
    			string s = sin(), s1 = sin();
    			int sr = mp[s];
    			int vis[10010] = {0};
    			int dist[10010] = {0};
    			dist[sr] = 0;
    			set<pair<int, int> > pq;
    			pq.insert({0, sr});
    			for (int i = 1; i <= n; i++) {
    				if (i != sr) {
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
    			putln(dist[mp[s1]]);
    		}
    	}
    } 