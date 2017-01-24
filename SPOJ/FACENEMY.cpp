#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		double x1,y1,u1,v1,x2,y2,u2,v2;
		cin >> x1 >> y1 >> u1 >> v1 >> x2 >> y2 >> u2 >> v2;
		double s1=(v1-y1)/(u1-x1);
		double s2=(y2-y1)/(x2-x1);
		double s3=(v2-y2)/(u2-x2);
		double spl1=atan(fabs((s1-s2)/(1+s1*s2)));
		double spl2=atan(fabs((s2-s3)/(1+s2*s3)));
		if(spl1==spl2)
			cout << "0\n";
		else if(spl1 > spl2)
			cout << "Heroine\n";
		else
			cout << "Hero\n";
	}
}
