#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		if(n==1){
			string s;
			cin >> s;
			cout << s;
			continue;
		}
		for(int i=0;i<n;i++){
			string s;
			cin >> s;
			if(s=="lxh")
				arr[i] = 0;
			else
				arr[i] = 1;
		}
		int val = (arr[0]^arr[1]);
		if(val == 0)
			val = 1;
		else
			val = 0;
		for(int i=2;i<n;i++){
			val = val^arr[i];
			if(val == 0)
				val = 1;
			else
				val = 0;
		}
		if(val == 0)
			cout << "lxh\n";
		else
			cout << "hhb\n";
	}
}
