#include<iostream>
using namespace std;
int main(){
	while(1){
		int bug,par;
		cin >> bug >> par;
		if(bug == 0 && par == 0)
			break;
		int val[par],fun[par];
		for(int i=0;i<par;i++){
			cin >> val[i] >> fun[i];
		}
		int dp[par+1][bug+1];
		for(int i=0;i<=par;i++){
			for(int j=0;j<=bug;j++){
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(val[i-1] <= j)
					dp[i][j] = max(fun[i-1]+dp[i-1][j-val[i-1]],dp[i-1][j]);
				else
					dp[i][j] = dp[i-1][j];
			}
		}
	/*	for(int i=0;i<=par;i++){
			for(int j=0;j<=bug;j++){
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}*/
		int i=par,j=bug,sum=0;
		while(i!=0 && j!=0){
			while(dp[i][j]==dp[i][j-1])
				j--;
			if(dp[i][j] != dp[i-1][j]){
				sum+=val[i-1];
				j = j - val[i-1];
			}
			i--;
		}
		cout << sum << " " << dp[par][bug] << "\n";
	}
}
