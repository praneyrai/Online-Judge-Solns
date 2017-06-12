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
 
int main() {
	ll n = 0, m = 0, k = 0, lo = 0, hi = 0, mi = INF, mx = -INF, sum = 0, ans = 0, cnt=0, t = 0, v1 = 0, v2 = 0, x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, curr = 0;
	str s, s1, s2;
	char c, c1, c2, *ptr;
	db dub=0, dub2 = 0;
	/////////////////////////////////////////////////////////////////////////////////////////////
	t = in();
	while (t--) {
		queue<int> q;
		vi pq;
		map<int, int> mp;
		n = in(), k = in();
		rep (i, n) {
			lo = in();
			pq.pb(lo);
			q.push(i);
			mp[i] = lo;
		}
		sort(all(pq));
		reverse(all(pq));
		ans = 0;
		while (!q.empty()) {
			auto i = pq.begin();
			if (*i > mp[q.front()]) {
				q.push(q.front());
				q.pop();
			} else if (*i == mp[q.front()]) {
				ans++;
				if (q.front() == k) {
					putln(ans);
					break;
				}
				q.pop();
				pq.erase(pq.begin());
			}
		}
	}
	
} 