#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long test;
		cin >> test;
		long long dis = pow(1+8*test,0.5);
		if(dis*dis == 1+8*test){
			long long tt1 = (-1+dis)/2;
			if(tt1%2 == 0){
				long long prev = (tt1-1)*(tt1)/2;
				long long more = test - prev;
				cout << "TERM " << test << " IS " << more << "/" << tt1-more+1 << "\n";
			}else{
				long long prev = (tt1-1)*(tt1)/2;
				long long more = test - prev;
				cout << "TERM " << test << " IS " << tt1-more+1 << "/" << more << "\n";
			}
		}else{
			long long tt1 = (-1+dis)/2;
			if(tt1%2 == 0){
				long long prev = (tt1)*(tt1+1)/2;
				long long more = test - prev;
				cout << "TERM " << test << " IS " << tt1-more+2 << "/" << more << "\n";
			}else{
				long long prev = (tt1)*(tt1+1)/2;
				long long more = test - prev;
				cout << "TERM " << test << " IS " << more << "/" << tt1-more+2 << "\n";
			}
		}
	}
}
