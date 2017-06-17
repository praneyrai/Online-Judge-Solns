    #include "bits/stdc++.h"
     
    using namespace std;
     
    long long a[100100], b[100100];
     
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	int t; cin >> t;
    	while (t--) {
    		memset(b, 0, sizeof(b));
    		int n, q;
    		cin >> n >> q;
    		while (q--) {
    			int aa, bb, val;
    			cin >> aa >> bb >> val;
    			b[aa] += val;
    			b[bb+1] -= val;
    		}
    		long long ans = 0;
    		for (int i = 0; i < n; i++) {
    			ans += b[i];
    			a[i] = ans;
    		}
    		cin >> q;
    		while (q--) {
    			int x; cin >> x;
    			cout << a[x] << '\n';
    		}
    	}
    } 