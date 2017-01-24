#include<iostream>
#include<cmath>
#include<iomanip>
#define eumac 0.5772156649
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		double ans=0;
		for(int i=1;i<=n;i++){
			ans+=(double)n/i;
		}
		cout << fixed << setprecision(2) << ans << "\n";
	}
}
