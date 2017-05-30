    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	int t;
    	cin >> t;
    	while (t--) {
    		map<string, bool> mp;
    		int n;
    		cin >> n;
    		vector<string> ss(n);
    		for (int i = 0; i < n; i++) {
    			cin >> ss[i];
    		}
    		sort(ss.begin(), ss.end());
    		bool flag = true;
    		for (int i = 0; i < n; i++) {
    			string s1 = "";
    			for (int j = 0; j < ss[i].size()&&flag; j++) {
    				s1 += ss[i][j];
    				if(mp.find(s1) != mp.end()) {
    					flag = false;
    				}
    			}
    			mp[ss[i]] = 1;
    		}
    		if (flag) cout << "YES\n";
    		else cout << "NO\n";
    	}
    } 