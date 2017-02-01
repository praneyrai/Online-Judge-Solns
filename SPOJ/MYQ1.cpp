#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long n;
		n = input();
		if(n==1){
			cout << "poor conductor\n";
			continue;
		}
		long long row = ceil((double)(n-1)/5);
		cout << row << " ";
		int demo = n%5;
		if(row%2 == 0){
			if(demo == 0){
				cout << "A L\n";
			}else if(demo == 1){
				cout << "W L\n";
			}else if(demo == 2){
				cout << "W R\n";
			}else if(demo ==3){
				cout << "M R\n";
			}else{
				cout << "A R\n";
			}
		}else{
			if(demo == 0){
				cout << "M R\n";
			}else if(demo == 1){
				cout << "W R\n";
			}else if(demo == 2){
				cout << "W L\n";
			}else if(demo ==3){
				cout << "A L\n";
			}else{
				cout << "A R\n";
			}
		}
	}
}
