    #include "bits/stdc++.h"
     
    using namespace std;
     
    int k, ans;
    string s;
     
    void cal(string pp) {
    		bool pos = true;
    		for (int j = 0; j < k/2; j++) {
    			if (pp[j] != pp[k - j - 1]) pos = false;
    		}
    		if (pos) ans++;
    	}
    int main() {
    	cin >> k;
    	cin >> s;
    	string ss = "";
    	for (int i = 0; i < k; i++) {
    		ss += s[i];
    	}
    	cal(ss);
    	for (int i = k; i < s.size(); i++) {
    		ss.erase(ss.begin());
    		ss += s[i];
    		cal(ss);
    	}
    	cout << ans;
    } 