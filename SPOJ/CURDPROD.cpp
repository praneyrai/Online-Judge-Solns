    #include "bits/stdc++.h"
    #define ll long long
    using namespace std;
     
    ll n, k, a[10010];
     
    bool f(ll v) {
    	ll cnt = 0;
    	for (int i =0; i < n; i++) {
    		cnt += v / a[i];
    	}
    	if (cnt >= k) return true;
    	return false;
    }
     
    void bs() {
    	ll lo = 0, hi = 1e18;
    	while (lo < hi) {
    		ll mid = (lo + hi) / 2;
    		if (f(mid)) hi = mid;
    		else lo = mid + 1;
    	}
    	if (!f(lo)) --lo;
    	cout << lo << '\n';
    }
     
    int main() {
    	int t; cin >> t;
    	while (t--) {
    		cin >> n >> k;
    		for (int i = 0; i < n; i++) cin >> a[i];
    		bs();
    	}
    } 