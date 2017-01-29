#include<iostream>
using namespace std;

int main(){
	long long ans[1001];
	ans[1]=5;
	for(int i=2; i<=1000; i++){
		ans[i] = ans[i-1] + 3*(i-1) + 4;
	}
	while(1){
		int n;
		cin >> n;
		if(n==0)	break;
		cout << ans[n] << "\n";
	}
}

