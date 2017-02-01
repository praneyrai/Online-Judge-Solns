#include <iostream>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
//inline ll input2(){ll number=0;bool negative=false;register int c;number=0;c=getchar_unlocked();if(c=='-'){negative=true;c=getchar_unlocked();}for(;(c>47 && c<58);c=getchar_unlocked())number=number*10+c-48;if(negative)number*= -1;return number;}
inline ll input(){ll number=0;bool negative=false;register int c;number=0;c=getchar();if(c=='-'){negative=true;c=getchar();}for(;(c>47 && c<58);c=getchar())number=number*10+c-48;if(negative)number*= -1;return number;}
int main(){
	ios_base::sync_with_stdio(false);
	while(1){
		int n,m;
		n = input();
		m = input();
		if(n==0 && m==0)	break;
		set<string> st;
		map<string,int> mp;
		for(int i=0;i<n-1;i++){
			string s;
			cin >> s;
			st.insert(s);
			mp[s]++;
		}
		int no[n]={0};
		for(set<string>::iterator it = st.begin(); it!=st.end(); it++){
			if(mp[*it] == 1){
				no[mp[*it]-1]++;
			}else{
				no[mp[*it]-1]++;
			}
		}
		for(int i=0;i<n;i++){
			cout << no[i] << "\n";
		}
	}
}
