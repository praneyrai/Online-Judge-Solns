#include<iostream>
#include<cmath>
using namespace std;
int count(int num){
	int dig=0;
	while(num){
		dig++;
		num/=2;
	}
	return dig;
}
int main(){
	int a,b;
	cin >> a >> b;
	a > b ? (cout << (long long)(pow(2,count(a)) - 1)) : (cout << (long long)(pow(2,count(b)) - 1));
}
