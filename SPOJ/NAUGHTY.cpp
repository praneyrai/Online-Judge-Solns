#include<iostream>
#include<map>
#include<set>
using namespace std;
set<int> st;
map<int,int> top;
map<int,int> bot;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		if(x != y){
			top[x]++;
			bot[y]++;
		}else
			top[x]++;
		st.insert(x);
		st.insert(y);
	}
	int min=1e6;
	if(n%2 != 0){
		n++;
	}
	for(auto it = st.begin(); it!= st.end(); it++){
		if(top[*it] + bot[*it] >= n/2){
			int xx = bot[*it];
			while(top[*it]+xx > n/2 && xx>0){
				xx--;
			}
			if(xx < min)
				min = xx;
		}
	}
	if(min != 1e6)
		cout << min;
	else	cout << "Impossible";
}
