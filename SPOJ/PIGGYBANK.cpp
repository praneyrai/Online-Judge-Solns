#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

#define rep(i , n)	for(ll i=0 ; i<n ; ++i)
#define loop(i , a , b)	for(ll i=a ; i<b ; ++i)
#define loopi(i , a) for(auto i = a.begin() ; i != a.end() ; ++i)
#define Max(a , b)	(a > b ? a : b)
#define Min(a , b)	(a > b ? b : a)
#define Mid(a , b)	((a+b)/2)
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
typedef pair<ll , ll> pll;
typedef vector<ll> vi;
typedef vector<pll> vpll;
typedef vector<vi> matrix;

const int N = 100100;
const int MOD = int(1e9) + 7;
const ll INF = ll(1e18);
const db DELTA = 0.000000001;

ll dp[10100];

int main(){
//	fio;
	ll n=0 , lo=0 , t=0 , sum=0 , sum1=0 , mid=0 , hi=0 , k=0 , m=0 , i=0 , j=0 , maxx=-INF , minn=INF;
	ll x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0;
	str s="" , s1="" , s2="" , s3="";
	char ch , ch1 , *ch2 , *ch3;
	db a=0 , b=0;
	////////////////////////////////////////////////////////////////////
	cin >> t;
	while(t--){
		cin >> lo >> hi >> k;
		vpll arr;
		bool flag = true;
		arr.resize(k);
		rep(i , k){
			cin >> arr[i].xx >> arr[i].yy;
		}
		rep(i , 10100)	dp[i] = 100000000;
		rep(i , k)	dp[arr[i].yy] = arr[i].xx;
		dp[0] = 0;
		rep(i , k){
			loop(j , 1 , hi-lo+1){
				if(arr[i].yy <= j)	dp[j] = Min(arr[i].xx + dp[j-arr[i].yy], dp[j]);
			}
		//	rep(j , hi-lo+1)	cout << j << " " << dp[j] << "\n";
		}
		if(dp[hi-lo] == 100000000)	cout << "This is impossible.\n";
		else	cout << "The minimum amount of money in the piggy-bank is " << dp[hi-lo] << ".\n";
	}	
}