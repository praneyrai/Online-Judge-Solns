    #include "bits/stdc++.h"
     
    using namespace std;
     
    long long tt;
     
    bool f(long long a) {
    	double ff = (1.0 * a * log(a)) / (1.0 * log(3)) - tt;
    	if (ff > 0) return false;
    	return true;
    }
    void bs() {
    	long long lo = 0, hi = 1e15;
    	while (lo < hi) {
    		long long mid = (hi + lo) / 2;
    		if (f(mid)) lo = mid + 1;
    		else hi = mid;
    	}
    	if (!f(lo)) --lo;
    	cout << lo << '\n';
    }
    int main() {
    	int t; cin >> t;
    	while (t--) {
    		cin >> tt;
    		bs();
    	}
    } 