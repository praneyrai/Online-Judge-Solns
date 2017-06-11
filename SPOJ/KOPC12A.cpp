#include "bits/stdc++.h"
#define ll long long
using namespace std;

ll h[100100], c[100100], n;

ll f(ll ht) {
	ll cst = 0;
	for (int i = 0; i < n; i++) {
		cst += abs(h[i] - ht) * c[i];
	}	
	return cst;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		ll lo = 1, hi = 1e6;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		for (int i = 0; i < n; i++) cin >> c[i];
		ll ans = 1e18;
		for (int i = 0; i < 80; i++) {
			ll i1 = (2*lo + hi) / 3;
			ll i2 = (2*hi + lo) / 3;
			if (f(i1) < f(i2)) {
				hi = i2;
				ans = min (ans, f(i1));
			} else {
				lo = i1;
				ans = min (ans, f(i2));
			}
		}
		cout << ans << '\n';
	}
}