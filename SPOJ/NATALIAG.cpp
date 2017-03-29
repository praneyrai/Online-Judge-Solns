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
typedef vector<vi> matrix;

const int N = 100100;
const int MOD = int(1e9) + 7;
const ll INF = ll(1e18);
const db DELTA = 0.000000001;

int main(){
	fio;
	ll n=0 , lo=0 , t=0 , sum=0 , sum1=0 , mid=0 , hi=0 , k=0 , m=0 , i=0 , j=0 , maxx=-INF , minn=INF;
	ll x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0;
	str s="" , s1="" , s2="" , s3="";
	char ch , ch1 , *ch2 , *ch3;
	db a=0 , b=0;
	////////////////////////////////////////////////////////////////////
	cin >> t;
	while(t--){
		cin >> n >> m;
		char arr[n+2][m+2];
		queue<pll> qq;
		loop(i , 1 , n+1)	loop(j , 1 , m+1){
			cin >> arr[i][j];
			if(arr[i][j] == '$')	qq.push(mp(i , j));
			if(arr[i][j] == '#')	x1 = i , y1 = j;
		}
		int visited[n+2][m+2];
		rep(i , n+2)	rep(j , m+2){
			if(i == 0 || j == 0 || i == n+1 || j == m+1)	visited[i][j] = -1;
			else	visited[i][j] = 0;
		}
		visited[qq.front().xx][qq.front().yy] = 1;
		while(!qq.empty()){
			lo = qq.front().xx;
			hi = qq.front().yy;
			qq.pop();
			if(visited[lo-1][hi] == 0 && (arr[lo-1][hi] == 'O' || arr[lo-1][hi] == '#')){
				visited[lo-1][hi] = visited[lo][hi] + 1;
				qq.push(mp(lo-1 , hi));
			}
			if(visited[lo+1][hi] == 0 && (arr[lo+1][hi] == 'O' || arr[lo+1][hi] == '#')){
				visited[lo+1][hi] = visited[lo][hi] + 1;
				qq.push(mp(lo+1 , hi));
			}
			if(visited[lo][hi-1] == 0 && (arr[lo][hi-1] == 'O' || arr[lo][hi-1] == '#')){
				visited[lo][hi-1] = visited[lo][hi] + 1;
				qq.push(mp(lo , hi-1));
			}
			if(visited[lo][hi+1] == 0 && (arr[lo][hi+1] == 'O' || arr[lo][hi+1] == '#')){
				visited[lo][hi+1] = visited[lo][hi] + 1;
				qq.push(mp(lo , hi+1));
			}
		}
	/*	rep(i , n+2){
			rep(j , m+2)	cout << visited[i][j] << " ";
			cout << "\n";
		}*/
		if(visited[x1][y1] == 0)	cout << -1 << "\n";
		else	cout << visited[x1][y1]-1 << "\n";
	}
	
	
}