    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    #define rep(i,n)	for(int i=0; i<n; i++)
    #define si(i)	scanf("%d",&i)
    #define sl(i)	scanf("%lld",&i)
    #define sc(c)	scanf("%c",&c)
    #define pi(i)	printf("%d\n",i)
    #define pl(i)	printf("%lld\n",i)
    #define loop(i,j,k)	for(int i=j; i<k; i++)
    typedef long long ll;
     
    int main(){
    	int n,k;
    	si(n),si(k);
    	vector<int> arr;
    	arr.resize(n);
    	rep(i,n)
    		si(arr[i]);
    	sort(arr.begin(),arr.end());
    	ll ans=0;
    	for(int i=0;i<n;i++){
    		if(arr[i]+k <= arr[n-1]){
    			typeof(arr.begin()) it = lower_bound(arr.begin()+i+1,arr.end(),arr[i]+k);
    			while(*it == arr[i]+k){
    				ans++;
    				it++;
    			}
    		}else
    			break;
    	}
    	pl(ans);
    } 