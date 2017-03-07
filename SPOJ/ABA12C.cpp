#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int arr[k];
		for(int i=0;i<k;i++)	cin >> arr[i];
		int dp[k+1];
		dp[0] = 0;
		for(int i=1;i<=k;i++){
			int q = 1e9;
			for(int j=1;j<=i;j++){
				q = min(q , arr[j-1]+dp[i-j]);
			}
			dp[i] = q;
		}
		if(dp[k] <=0) cout << -1 << "\n";
		else
			cout << dp[k] << "\n";
	}
}