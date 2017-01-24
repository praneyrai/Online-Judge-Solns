/*-----praney_rai-----
----IIT(ISM) Dhanbad----*/
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef std::string str;
typedef double db;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<str> VS;
typedef vector<ll> VL;
typedef vector<db> VD;
typedef set<int> ST;
typedef set<char> SC;
typedef set<str> SS;
typedef map<int,int> MII;
typedef map<str,int> MSI;
typedef map<ll,ll> MLL;
typedef map<ll,map<ll,ll> > MMLL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef set<ll>::iterator SLLI;

#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define loop(i,a,b) for(ll i=(a); i<(n); i++)
#define rep(i,b) for(ll i=(0); i<(b); i++)
#define rev(i,b,a) for(ll i=(b-1); i>=(a); i--)
#define push_back() pb
#define pop_back() ppb

//const. list
const int MOD = int(1e9) + 7;
const db PI = acos(-1.0);

//inline ll input2(){ll number=0;bool negative=false;register int c;number=0;c=getchar_unlocked();if(c=='-'){negative=true;c=getchar_unlocked();}for(;(c>47 && c<58);c=getchar_unlocked())number=number*10+c-48;if(negative)number*= -1;return number;}
inline ll input1(){ll number=0;bool negative=false;register int c;number=0;c=getchar();if(c=='-'){negative=true;c=getchar();}for(;(c>47 && c<58);c=getchar())number=number*10+c-48;if(negative)number*= -1;return number;}
inline ll fme(ll a, ll b,ll MOD){ll res=1;a%=MOD;while(b){if(b%2){res*=a;res%=MOD;}a*=a;a%=MOD;b/=2;}return res%MOD;}
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}
template<class T> T lcm(T a, T b){return (a*b)/gcd(a,b);}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	ll t,count=1;
	t = input1();
	while(t--){
		ll n = input1();
		if(n==0){
			cout << "Case " << count << ": " << 0 << "\n";
			count++;
			continue;
		}
		ll arr[n];
		rep(i,n)
			arr[i] = input1();
		ll dp[n]={0};
		dp[0]=arr[0];
		dp[1]=max(arr[0],arr[1]);
		loop(i,2,n){
			dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
		}
	/*	rep(i,n)
			cout << dp[i] << " ";
		cout << "\n";*/
		cout << "Case " << count << ": " << dp[n-1] << "\n";
		count++;
	}

}

