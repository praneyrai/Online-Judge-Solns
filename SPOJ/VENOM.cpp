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

long long h, p, a;

bool f(long long mid) {
	long long aa;
	long long tt = mid / 2 + mid % 2;
	aa = h + (mid/2)*a - (tt * (tt + 1) / 2)*p;
	if (aa > 0) return true;
	return false;
}
void t_search() {
	long long lo = 0, hi = 1e9;
	while (lo < hi) {
		long long mid = (lo + hi) / 2;
		if (f(mid)) lo = mid + 1;
		else hi = mid;
	}
	hi = lo, lo = 0;
	while (lo < hi) {
		long long mid = (lo + hi) / 2;
		if (f(mid)) lo = mid + 1;
		else hi = mid;
	}
	for (ll i = lo - 100; i < lo + 100; i++) {
		if (f(i - 1) == 1 && f(i + 1) == 0) {
			putln(i+1);
			break;
		}
	}
}
int main() {
	int t; t = in();
	while (t--) {
		h = in(), p = in(), a = in();
		t_search();		
	}
}