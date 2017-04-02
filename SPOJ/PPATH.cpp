#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define rtn return 
bool isPrime[10010];
void seive(){
	memset(isPrime , 1 , sizeof(isPrime));
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(int i=2;i*i<=10010;i++){
		if(isPrime[i]){
			for(int j=2*i;j<10010;j+=i)	isPrime[j] = 0;
		}
	}
}
inline str srev(str s){str demo="";for(int i=s.length()-1;i>=0;i--)demo+=s[i];rtn demo;}
inline str ts(ll i){str s="",nm="0123456789";if(i==0){s="0";}while(i){s+=nm[i%10];i/=10;}rtn srev(s);}
ll tn(string s){
	ll ans=0;
	for(int i=0;i<4;i++)	ans = ans*10 + s[i]-'0';
	return ans;
}
int main(){
	seive();
	int t;
	cin >> t;
	while(t--){
		int beg,end;
		cin >> beg >> end;
		queue<int> qq;
		qq.push(beg);
		map<ll,ll> mp;
		bool visited[10010]={0};
		visited[beg] = 1;
		mp[beg] = 0;
		while(!qq.empty()){
			int xx = qq.front();
			qq.pop();
			if(xx == end)	break;
			string s = ts(xx);
			//check by changing first number
			for(char i='1';i<='9';i++){
				s[0] = i;
				ll x = tn(s);
				if(isPrime[x] && visited[x] == 0){
					qq.push(x);
					mp[x] = mp[xx] + 1;
					visited[x] = 1;
				}
			}
			s = ts(xx);
			//check by changing second number
			for(char i='0';i<='9';i++){
				s[1] = i;
				ll x = tn(s);
				if(isPrime[x] && visited[x] == 0){
					qq.push(x);
					mp[x] = mp[xx] + 1;
					visited[x] = 1;
				}
			}
			s = ts(xx);
			//check by changing third number
			for(char i='0' ; i<='9';i++){
				s[2] = i;
				ll x = tn(s);
				if(isPrime[x] && visited[x] == 0){
					qq.push(x);
					mp[x] = mp[xx] + 1;
					visited[x] = 1;
				}
			}
			s = ts(xx);
			//check by fourth number
			for(char i= '0' ; i<='9' ; i++){
				s[3] = i;
				ll x = tn(s);
				if(isPrime[x] && visited[x] == 0){
					qq.push(x);
					mp[x] = mp[xx] + 1;
					visited[x] = 1;
				}
			}
		}
		cout << mp[end] << "\n";
	}
}