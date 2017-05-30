    #include "bits/stdc++.h"
    typedef long long ll;
    using namespace std;
    ll a[2020];
    ll mp[2020][2020];
    ll rec(int st, int en, int b) {
    	if (st == en) return b*a[st];
    	if (mp[st][en]) return mp[st][en];
    	mp[st][en] = max(rec(st, en-1, b+1) + b*a[en], rec(st+1, en, b+1) + b*a[st]);
    	return mp[st][en];
    }
    int main() {
    	std::ios::sync_with_stdio(false);
    	std::cin.tie(0);
    	std::cout.tie(0);
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; i++) cin >> a[i];
    	cout << rec(0, n-1, 1);
    } 