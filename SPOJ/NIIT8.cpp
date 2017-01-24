    #include<iostream>
    #include<algorithm>
    #include<cmath>
    using namespace std;
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	int t;
    	cin >> t;
    	while(t--){
    		int n;
    		cin >> n;
    		long long arr[n];
    		for(int i=0;i<n;i++)
    			cin >> arr[i];
    		int start=0,end=n-1;
    		long long max=-99,val;
    		while(start < end){
    			if(arr[start] > arr[end]){
    				val = (end-start)*arr[end];
    				end--;
    			}else{
    				val = (end-start)*arr[start];
    				start++;
    			}
    			if(val > max)
    				max = val;
    		}
    		cout << max << "\n";
    	}
    } 