#include<iostream>
using namespace std;
inline int input2(){int number=0;bool negative=false;register int c;number=0;c=getchar();if(c=='-'){negative=true;c=getchar();}for(;(c>47 && c<58);c=getchar())number=number*10+c-48;if(negative)number*= -1;return number;}
//inline ll input2(){ll number=0;bool negative=false;register int c;number=0;c=getchar_unlocked();if(c=='-'){negative=true;c=getchar_unlocked();}for(;(c>47 && c<58);c=getchar_unlocked())number=number*10+c-48;if(negative)number*= -1;return number;}
int main(){
	ios_base::sync_with_stdio(false);
	int wtt,n;
	wtt = input2();
	n = input2();
	long long dp[2][wtt+1];
	int val[n],wt[n];
	for(int i=0;i<n;i++){
		val[i] = input2();
		wt[i] = input2();
	}
	for(int i=0;i<=wtt;i++)
		dp[0][i] = 0;
	for(int i=1;i<=n;i++){
		if(i%2 != 0){
			dp[1][0] = 0;
			for(int j=1;j<=wtt;j++){
				if(wt[i-1] <= j){
					dp[1][j] = max(dp[0][j],val[i-1]+dp[0][j-wt[i-1]]);
				}else
					dp[1][j] = dp[0][j];
			}
		}else{
			dp[0][0] = 0;
			for(int j=1;j<=wtt;j++){
				if(wt[i-1] <= j){
					dp[0][j] = max(dp[1][j],val[i-1]+dp[1][j-wt[i-1]]);
				}else
					dp[0][j] = dp[1][j];
			}
		}
	}
	cout << max(dp[1][wtt],dp[0][wtt]);
}
