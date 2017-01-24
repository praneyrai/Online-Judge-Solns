    #include<iostream>
    #include<algorithm>
    #include<vector>
     
    using namespace std;
     
    #define rep(i,n)	for(int i=0; i<n; i++)
    #define si(i)	scanf("%d",&i)
    #define sl(i)	scanf("%lld",&i)
    #define pi(i)	printf("%d\n",i)
    #define pl(i)	printf("%lld\n",i)
    #define loop(i,j,k)	for(int i=j; i<k; i++)
     
    typedef long long ll;
     
    int main(){
    	while(1){
    		int n;
    		si(n);
    		if(n==0)	break;
    		vector<int> arr;
    		arr.resize(n);
    		rep(i,n)
    			cin >> arr[i];
    		sort(arr.begin(),arr.end());
    		ll ans=0;
    		rep(i,n-2){
    			loop(j,i+1,n-1){
    				typeof(arr.begin()) it = upper_bound(arr.begin()+j+1,arr.end(),arr[i]+arr[j]);
    				ans+=arr.end()-it;
    			}
    		}
    		pl(ans);
    	}
    } 