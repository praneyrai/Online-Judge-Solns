    #include "bits/stdc++.h"
     
    using namespace std;
     
    int main() {
    	while (1) {
    		long long a, b;
    		cin >> a >> b;
    		if (a == 0 && b == 0) break;
    		vector<int> v1, v2;
    		while (a) {
    			v1.push_back(a%10);
    			a = a / 10;
    		}
    		while (b) {
    			v2.push_back(b%10);
    			b = b / 10;
    		}
    		if (v1.size() < v2.size()) {
    			while (1) {
    				if (v1.size() == v2.size()) break;
    				v1.push_back(0);
    			}
    		} else if (v1.size() > v2.size()) {
    			while (1) {
    				if (v2.size() == v1.size()) break;
    				v2.push_back(0);
    			}
    		}
    		int cr = 0, ans = 0;
    		for (int i = 0; i < v1.size(); i++) {
    			int sum = v1[i] + v2[i] + cr;
    			if (sum < 10) {
    				cr = 0;
    				continue;
    			}
    			cr = sum/10;
    			if (cr > 0) ans++;
    		}
    		if (ans == 0) {
    			cout << "No carry operation.\n";
    		} else if (ans == 1){
    			cout << ans << " carry operation.\n";
    		} else {
    			cout << ans << " carry operations.\n";
    		}
    	}
    } 