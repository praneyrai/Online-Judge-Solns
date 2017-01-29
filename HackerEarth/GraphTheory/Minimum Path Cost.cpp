#include <iostream>
#include <map>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	string arr[n+1];
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	map<string,map<string,int> > ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[arr[i]][arr[j]] = 999999;
		}
	}
	for(int i=0;i<m;i++){
		string s,s1;
		int val;
		cin >> s >> s1 >> val;
		ans[s][s1] = val;
		ans[s1][s] = val;
	}
	for(int i=1;i<=n;i++)
		ans[arr[i]][arr[i]]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[arr[i]][arr[j]] = min(ans[arr[i]][arr[j]] , ans[arr[i]][arr[k]] + ans[arr[k]][arr[j]]);
			}
		}
	}
	int query;
	cin >> query;
	while(query--){
		string s,s1;
		cin >> s >> s1;
		cout << ans[s][s1] << "\n";
	}
}
