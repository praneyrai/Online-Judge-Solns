#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int tt=0;
	while(t--){
		int n,r;
		cin >> n >> r;
		set<int> st;
		bool flag = false;
		map<int,map<int,int> > mp;
		for(int i=0;i<r;i++){
			int id,code;
			cin >> id >> code;
			st.insert(code);
			if(mp[id][code]){
				flag = true;
			}
			mp[id][code]++;
		}
		if(flag)	cout << "Scenario #" << ++tt << ": impossible\n";
		else	cout << "Scenario #" << ++tt << ": possible\n";
	}
}
