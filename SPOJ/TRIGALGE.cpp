#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a,b,c;
double val(double x){
	return (a*x + b*sin(x)-c);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		double start = 0;
		double end;
		for(int i=1;;i++){
			if(a*i+b*sin(i)-c > 0){
				end = i;
				break;
			}
		}
		double demo;
		for(int i=0;i<=10000;i++){
			demo = (start+end)/2;
			if(val(demo) < 0)
				start = demo;
			else
				end = demo;
		}
		cout << fixed << setprecision(6) << start << "\n";
	}
}
