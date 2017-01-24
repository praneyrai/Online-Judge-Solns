    #include<iostream>
    using namespace std;
    long long gcd(long long a,long long b){
    	if(a==0)
    		return b;
    	return gcd(b%a,a);
    }
    int main(){
    	ios_base::sync_with_stdio(false);
    	while(1){
    		int n;
    		cin >> n;
    		if(n == 0)
    			break;
    		long long gc[n],prod[n];
    		for(int i=0;i<n;i++){
    			int a,b,c;
    			cin >> a >> b >> c;
    			long long g1=gcd(a,b);
    			g1=gcd(g1,c);
    			gc[i]=g1;
    			prod[i]=a*b*c;
    		}
    		long long gcc=gc[0];
    		for(int i=1;i<n;i++){
    			gcc=gcd(gcc,gc[i]);
    		}
    		long long ans=0;
    		for(int i=0;i<n;i++){
    			ans+=prod[i]/(gcc*gcc*gcc);
    		}
    		cout << ans << "\n";
    	}
    } 