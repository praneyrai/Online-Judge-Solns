#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
inline ll input(){ll number=0;bool negative=false;register int c;number=0;c=getchar();if(c=='-'){negative=true;c=getchar();}for(;(c>47 && c<58);c=getchar())number=number*10+c-48;if(negative)number*= -1;return number;}
int main(){
	ios_base::sync_with_stdio(false);
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
