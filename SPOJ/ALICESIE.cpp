#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
inline ll input1(){ll number=0;bool negative=false;register int c;number=0;c=getchar();if(c=='-'){negative=true;c=getchar();}for(;(c>47 && c<58);c=getchar())number=number*10+c-48;if(negative)number*= -1;return number;}
int main(){
	ll t;
	t = input1();
	while(t--){
		double n;
		n = input1();
		if(n==1)
			cout << 0 << "\n";
		else
			cout << ceil(n/2) << "\n";
	}
}