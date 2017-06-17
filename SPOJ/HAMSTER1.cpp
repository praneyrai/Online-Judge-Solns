    #include "bits/stdc++.h"
     
    using namespace std;
    const double pi = 3.141592653589793;
    long long u, k1, k2;
     
    double cal(double an) {
    	double x = u * u * sin(2 * an) / 10.0;
    	double y = u * u * sin(an) * sin(an) / 20.0;
    	double ans = k1 * x + k2 * y;
    	return ans;
    }
    void ts() {
    	double lo = 0, hi = pi/2;
    	double ans = 0;
    	for (int i = 0; i < 80; i++) {
    		double p1 = (2 * lo + hi) / 3;
    		double p2 = (2 * hi + lo) / 3;
    		double f1 = cal(p1);
    		double f2 = cal(p2);
    		if (f1 < f2) {
    			lo = p1;
    			ans = max(ans, f2);
    		} else {
    			hi = p2;
    			ans = max(ans, f1);
    		}
    	}
    	printf("%.3f %.3f\n", lo, ans);
    }
    int main() {
    	int t; cin >> t;
    	while (t--) {
    		cin >> u >> k1 >> k2;
    		ts();
    	}
    } 