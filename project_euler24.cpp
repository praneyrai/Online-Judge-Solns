#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rtn return
#define rep(i , n)	for(ll i=0;i<n;i++) 
#define loop(i , a , b)	for(ll i=a;i<b;i++)
#define str string
bool isPrime[1000100];
void seive(){
	isPrime[0] = 0;
	isPrime[1] = 0;
	memset(isPrime , 1 , sizeof(isPrime));
	for(ll i=2;i*i<=1000100;i++){
		if(isPrime[i]){
			for(ll j=2*i;j<1000100;j+=i)	isPrime[j] = 0;
		}
	}
}
ll pow(ll x , ll y){
	ll c=1;
	rep(i , y)	c*=x;
	rtn c;
}
bool f(ll x){
	ll in = x , c = 0;
	while(x){
		c += pow(x%10 , 5);
		x/=10;
	}
	if(c == in)	rtn true;
	rtn false;
}
ll fact[10];
void init(){
	fact[0] = 0;
	fact[1] = 1;
	loop(i , 2 , 10)	fact[i] = i*fact[i-1];
}
bool g(ll x){
	ll in = x , s=0;
	while(x){
		s+=fact[x%10];
		x/=10;
	}
	return s == in;
}
inline str srev(str s){str demo="";for(int i=s.length()-1;i>=0;i--)demo+=s[i];rtn demo;}
inline str ts(ll i){str s="",nm="0123456789";if(i==0){s="0";}while(i){s+=nm[i%10];i/=10;}rtn srev(s);}
inline ll ti(str s,int size){
	ll ans=0;
	rep(i , size){
		ans = ans*10 + s[i]-'0';
	}
	rtn ans;
}
inline ll count(ll x){
	int cc=0;
	while(x){
		cc++;
		x/=10;
	}
	rtn cc;
}
bool poss(ll x){
	ll cc=count(x);
	int arr[cc];
	for(int i=cc-1;i>=0;i--){
		arr[i]=x%10;
	//	cout << arr[i];
		x/=10;
	}
//	cout << "\n";
	int temp[cc];
	for(int i=0;i<cc;i++){
		for(int j=0;j<cc;j++){
			temp[j]=arr[(i+j)%cc];
		}
		str s="";
		for(int j=0;j<cc;j++)	s+=ts(temp[j]);
		
		if(!isPrime[ti(s,cc)])	rtn false;
	}
	rtn true;
}
ll power(ll x , ll y){
	ll ans=1;
	rep(i , y)	ans=ans*x;
	rtn ans;
}
ll arr[10];
void compute(ll start,ll &cnt){
	if(start == 10){
		cnt++;
		if(cnt == 1000000){
			rep(i , 10)	cout << arr[i] << " ";
			cout << "\n";
		}
		return;
	}
	if(start == 0){
		for(int i=0;i<10;i++){
			arr[start]=i;
			compute(start+1,cnt);	
		}
	}else{
		for(int i=0;i<10;i++){
			bool flag=false;
			for(int j=0;j<start;j++){
				if(arr[j] == i){
					flag = true;
					break;
				}
			}
			if(!flag){
				arr[start] = i;
				compute(start+1 , cnt);
			}
		}
	}
}
int main(){
	ll cnt=0;
	compute(0 , cnt);
}
