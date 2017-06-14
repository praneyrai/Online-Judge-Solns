    #include "bits/stdc++.h"
     
    using namespace std;
     
    int a[50050], n, k;
     
    bool f(long long x) {
    	long long cnt = 0;
    	for (int i = 0; i < n; i++) {
    		cnt += a[i] / x; 
    	}
    	if (cnt >= k) return true;
    	return false;
    }
    void solve() {
    	long long lo = 0, hi = 1e18;
    	while (lo < hi) {
    		long long mid = (lo + hi) / 2;
    		if (mid == 0) {
    			cout << 0 << '\n';
    			return;
    		}
    		if (f(mid)) lo = mid + 1;
    		else hi = mid;
    	}
    	if (!f(lo)) --lo;
    	cout << lo << '\n';
    }
    int main() {
    	int t; cin >> t;
    	while (t--) {
    		cin >> n >> k;
    		for (int i = 0; i < n; i++) cin >> a[i];
    		solve();
    	} 
    } 