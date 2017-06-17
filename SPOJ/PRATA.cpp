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
    #ifdef _WIN32
    	#define pc putchar
    	#define gc getchar
    #else
    	#define pc putchar_unlocked
    	#define gc getchar_unlocked
    #endif
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef string str;
    typedef double db;
    typedef vector<ll> vi;
    typedef pair<ll, ll> pll;
     
    const int N = 100100;
    const int MOD = int(1e9) + 7;
    const ll INF = 0x7FFFFFFFFFFFFFFF;
    const db PI = 3.1415926535897932384626433832795;
     
    ll in() {int n=0;ll x=0;char c=gc();if(c=='-')n=1;while(c<'0'||c>'9'){c=gc();if(c=='-')n=1;}while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=gc();}if(n)x=-x; rtn x;}
    void put(ll a) {int n=(a<0?1:0);if(n)a=-a;char b[20];int i=0;do{b[i++]=a%10+'0';a/=10;}while(a);if(n)pc('-');i--;while(i>=0)pc(b[i--]);pc(' ');}
    void putln(ll a) {int n=(a<0?1:0);if(n)a=-a;char b[20];int i=0;do{b[i++]=a%10+'0';a/=10;}while(a);if(n)pc('-');i--;while(i>=0)pc(b[i--]);pc('\n');}
     
    ll p, n, a[75];
     
    bool f(int mid) {
    	ll pr = 0;
    	for (int i = 0; i < n; i++) {
    		ll cnt = 0;
    		ll cr = 1;
    		while (1) {
    			if (cnt + cr * a[i] > mid) break;
    			cnt += cr*a[i];
    			cr++;
    		}
    		pr += cr - 1;
    	}	
    	if (pr >= p) return true;
    	return false;
    }
     
    void bs() {
    	int lo = 0, hi = 1e7;
    	while (lo < hi) {
    		int mid = (lo + hi) / 2;
    		if (f(mid)) hi = mid;
    		else lo = mid + 1;
    	}
    	putln(lo);
    }
    int main() {
    	int t = in();
    	while (t--) {
    		p = in(), n = in();
    		for (int i = 0; i < n; i++) a[i] = in();
    		bs();
    	}
    } 