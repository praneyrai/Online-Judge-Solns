    #include "bits/stdc++.h"
     
    using namespace std;
     
    const double pi = acos(-1);
    const double eps = 0.0000001;
    int n, r[10010], f;
     
    bool func(double v) {
    	int cnt = 0;
    	for (int i = 0; i < n; i++) {
    		double kk = 1.0 * pi * r[i] * r[i] / v;
    		cnt += (int)kk;
    	}
    	if (cnt >= f + 1) return true;
    	return false;
    }
     
    void binary_search() {
    	double lo = eps , hi = 1e18;
    	while (hi - lo > eps) {
    		double mid = (lo + hi) / 2;
    		if (func(mid)) lo = mid;
    		else hi = mid;
    	//	cout << fixed << setprecision(10) << lo << ' ' << fixed << setprecision(10) << hi << '\n';
    	}
    	printf("%.4lf\n", lo);
    }
     
    int main() {
    	int t; cin >> t;
    	while (t--) {
    		cin >> n >> f;
    		for (int i = 0; i < n; i++) cin >> r[i];
    		binary_search();
    	}
    } 