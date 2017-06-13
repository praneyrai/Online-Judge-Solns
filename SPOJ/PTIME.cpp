        #include "bits/stdc++.h"
        #define ll long long
        using namespace std;
         
        const int MAX = 100005;
        bool v[MAX];
    	ll sp[MAX];
    	void Sieve() {
    	for (ll i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
    	for (long long i = 3; i < MAX; i += 2) {
    		if (!v[i])	{
    				sp[i] = i;
    				for (long long  j = i; (j*i) < MAX; j += 2){
    					if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
    				}
    			}
    		}
    	}
        set<int> st;
        map<int, int> mp;
        int main() {
        	Sieve();
        	ll n; cin >> n;
        	ll mx = -99;
        	for (int i = 2; i <= n; i++) {
        		ll k = i;
        		while (k>1) {
        			st.insert(sp[k]); mp[sp[k]]++;
        			mx = max(mx, sp[k]);
        			k/=sp[k];
        		}
        	}
        	for (auto i : st) {
        		if (i == mx) {
        			cout << i << '^' << mp[i];
        		} else {
        			cout << i << '^' << mp[i] << " * ";
        		}
        		
        	}
        }  