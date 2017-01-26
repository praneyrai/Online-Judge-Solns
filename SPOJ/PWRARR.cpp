/*-----praney_rai-----
----IIT(ISM) Dhanbad----*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define loop(i,a,b) for(ll i=(a); i<(n); i++)
#define rep(i,b) for(ll i=(0); i<(b); i++)
#define rev(i,b,a) for(ll i=(b-1); i>=(a); i--)
#define push_back(x) pb(x)
#define pop_back() ppb()
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define pin(x)	printf("%d\n",x)
#define pi(x)	printf("%d",x)
#define pl(x)	printf("%lld",x)
#define pln(x)	printf("%lld\n",x)

typedef long long ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr;
		set<int> st;
		arr.resize(n);
		rep(i,n){
			cin >> arr[i];
			st.insert(arr[i]);
		}
		sort(arr.begin(),arr.end());
		map<int,int> mp;
		ll ans=0,count=0,prev=0;
		for(set<int>::iterator it = st.begin(); it!=st.end();it++){
			for(int i=prev;i<n;i++){
				if(arr[i] == (*it)){
					count++;
				}else{
					prev=i;
					break;
				}
			}
			mp[*it]=count;
		}
		for(int i=0;i<n;i++){
			ans += mp[arr[i]];
		}
		cout << ans << "\n";
	}
	
}
