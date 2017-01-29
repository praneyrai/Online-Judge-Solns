#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		string s,s1;
		cin >> s >> s1;
		int sl = s.length();
		int s1l = s1.length();
		int dp[sl+1][s1l+1];
		for(int i=0;i<=sl;i++){
			dp[i][0] = i;
		}
		for(int i=0;i<=s1l;i++){
			dp[0][i] = i;
		}
		for(int i=1;i<=sl;i++){
			for(int j=1;j<=s1l;j++){
				if(s[i-1] == s1[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		}
		cout << dp[sl][s1l] << "\n"; 
	}
	return 0;
}
