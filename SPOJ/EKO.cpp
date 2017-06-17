    #include "bits/stdc++.h"
    #define ll long long
    using namespace std;
     
    long long n, m, a[1000001];
     
    bool f(ll mid) {
    	ll cnt = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] > mid) {
    			cnt += a[i] - mid;
    		}
    	}
    	if(cnt >= m) return true;
    	return false;
    }
     
    void bs() {
    	ll lo = 0, hi = 1e10;
    	while (lo < hi) {
    		ll mid = (lo + hi) / 2;
    		if (f(mid)) lo = mid + 1;
    		else hi = mid;
    	//	cout << lo << ' ' << hi << '\n';
    	}
    	if (!f(lo)) --lo;
    	cout << lo;
    }
    int main() {
    	cin >> n >> m;
    	for (int i = 0; i < n; i++) cin >> a[i];
    	bs();	
    } 