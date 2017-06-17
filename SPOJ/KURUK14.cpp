    #include "bits/stdc++.h"
     
    using namespace std;
     
    int a[1010], aux[1010];
     
    int main() {
    	int t; cin >> t;
    	while (t--) {
    		for (int i = 0; i < 1010; i++) aux[i] = -1;
    		int n;
    		cin >> n;
    		bool flag = true;
    		for (int i = 0; i < n; i++) cin >> a[i];
    		for (int i = 0; i < n; i++) {
    			//checking from front 
    			if (aux[a[i]] == -1) {
    				aux[a[i]] = 1;
    				continue;
    			}
    			if (aux[n - a[i] - 1] == -1) {
    				aux[n - a[i] - 1] = 1;
    				continue;
    			}
    			flag = false;
    			break;
    		}
    		if (flag) cout << "YES\n";
    		else cout << "NO\n";
    	}
    } 