    #include "bits/stdc++.h"
     
    using namespace std;
     
    int main() {
    	int t;
    	cin >> t;
    	while (t--) {
    		int s;
    		cin >> s;
    		list<int> add[330];
    		set<int> st;
    		while (1) {
    			int a, b; cin >> a >> b;
    			if (a == -1 && b == -1) break;
    			add[a].push_back(b);
    			add[b].push_back(a);
    			st.insert(a); st.insert(b);
    		}
    		bool pos = true;
    		for (set<int>::iterator i = st.begin(); i != st.end(); i++) {
    			if (add[*i].size()%2) pos = false;
    		}
    		if (pos) cout << "YES\n";
    		else cout << "NO\n";
    	}
    } 