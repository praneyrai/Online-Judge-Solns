#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
long long power(int base,int power){
	long long sum=1;
	for(int i=0;i<power;i++){
		sum = sum*base;
	}
	return sum;
}
int main(){
	int t;
	cin >> t;
	string s = "manku";
	while(t--){
		long long n;
		cin >> n;
		if(n==0)	continue;
		if(n == 1 || n == 2 || n==3 || n==4 || n==5){
			cout << s[n-1] << "\n";
			continue;
		}
		long long sum=0;
		int count=1;
		for(int i=1; i<=64; i++){
			long long demo = power(5,i);
			if(sum + demo >= n){
				break;
			}
			sum += demo;
			count++;
		}
		n = n - sum;
		n--;
		if(n==0){
			while(count--){
				cout << s[0];
			}
			cout << "\n";
			continue;
		}
		stack<int> st;
		int cc=0;
		while(n){
			st.push(n%5);
			n/=5;
			cc++;
		}
		if(cc < count){
			while(count != cc){
				count--;
				cout << s[0];
			}
		}
		while(!st.empty()){
			cout << s[st.top()];
			st.pop();
		}
		cout << "\n";
	}
}
