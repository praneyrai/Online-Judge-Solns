    /*  praney_rai
        Praney Rai
      IIT(ISM) Dhanbad*/
      
    // Welcome (: 
    #include <stdio.h>
    using namespace std;
    #include <bits/stdc++.h>
     
    #define loop(i,a,b) for(ll i=(a); i<(b); i++)
    #define rep(i,b) for(ll i=(0); i<(b); i++)
    #define rev(i,b,a) for(ll i=(b-1); i>=(a); i--)
    #define loopi(it, l) for (auto it = l.begin(); it != l.end(); it++)
    #define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define apac freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
    #define fill(a,v)	memset(a, v, sizeof(a))
    #define si(n)	int n; scanf("%d",&n)
    #define sc(n)   char n; scanf("%c",&n)
    #define sl(n)   ll n; scanf("%lld",&n)
    #define sd(n)   db n; scanf("%lf",&n)
    #define TC(x)   si(x); while(x --)
    #define all(x) x.begin(), x.end()
    #define xx first
    #define yy second
    #define pb push_back
    #define mp make_pair
    #define eb emplace_back
    #define rtn return
    #define Max(x,y) ((x)>(y)?(x):(y))
    #define Min(x,y) ((x)<(y)?(x):(y))
    #define Mid(s,e) (s+(e-s)/2)
    #define Abs(a , b)	Max(a-b,b-a)
    #define Ceil(a , b)	(a%b == 0 ? (a == 0 ? 0 : a/b) : a/b + 1)
    #define Floor(a , b) a/b
    #define debug(x) cout << #x << ": " << x << "\n"
    #ifdef _WIN32
    	#define pc putchar
    	#define gc getchar
    #else
    	#define pc putchar_unlocked 
    	#define gc getchar_unlocked 
    #endif
     
    typedef long long ll;
    typedef double db;
    typedef unsigned long long ull;
    typedef std::string str;
    typedef double db;
    typedef vector<ll> vi;
    typedef pair<ll,ll> pll;
    typedef vector<pll> vpll;
    typedef vector<vi> MATRIX;
     
    //const. list--->>>
    const int MOD7 = int(1e9) + 7;
    const int MOD9 = int(1e9) + 9;
    const db PI = acos(-1.0);
    const db DELTA = 0.000000001;
    const ll INF = 1e18;
    const ll N = 100100;
     
    //Fast-I/O--->>>
    inline ll in(){ll n=0,s=1;char p=gc();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=gc();if(p=='-')s=-1,p=gc();while(p>='0'&&p<='9'){n=(n<< 3)+(n<< 1)+(p - '0');p=gc();}return n*s;}
    inline str sin(){str s="";while (1){char c = gc();if(c==' '||c=='\n')break;s+=c;}rtn s;}
    inline void put(ll x){int i = 20;char buf[21];buf[20]=' ';do{buf[--i] = x % 10 + '0';x/= 10;}while(x);do{putchar(buf[i]);}while(buf[i++]!=' ');}
    inline void putln(ll x){int i = 20;char buf[21];buf[20]='\n';do{buf[--i] = x % 10 + '0';x/= 10;}while(x);do{putchar(buf[i]);}while(buf[i++]!='\n');}
     
    //Other Utilities--->>>
    inline ll fmm(ll a,ll b,ll m=MOD7) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
    inline ll fme(ll a,ll b,ll m=MOD7) {ll r=1;a%=m;while(b>0){if(b&1){r*=a;r%=m;}a*=a;a%=m;b>>=1;}return r%m;}
    inline ll sfme(ll a,ll b,ll m=MOD7) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}
    ll fact[1000001],invfact[1000001];
    inline void init(ll MOD = MOD7){ll i;fact[0] = 1;for (i = 1; i <= 1000000; i++)fact[i] = (fact[i - 1] * i) % MOD;invfact[1000000] = fme(fact[1000000], MOD - 2,MOD);for (i = 1000000 - 1; i >= 0; i--)invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;}
    inline ll nCk(ll n, ll k, ll MOD = MOD7){rtn (((fact[n] * invfact[k]) % MOD) * invfact[n - k]) % MOD;}
    inline ll nPk(ll n, ll k, ll MOD = MOD7){rtn ((fact[n] * invfact[k]) % MOD);}
    //nCk in O(k)
    ll NCK(ll n, ll k){ll res=1;if(k>n-k)k=n-k;rep(i,k){res*=(n-i);res/=(i+1);}rtn res%MOD7;}
    template<class T> T gcd(T a,T b){if(b == 0)rtn a;rtn gcd(b,a%b);}
    inline void extGCD(ll a,ll b,ll &x,ll &y) {if(b==0){x=1,y=0;rtn;}ll x1,y1;extGCD(b,a%b,x1,y1);x=y1;y=x1-(a/b)*y1;}
    template<class T> T lcm(T a, T b){rtn (a*b)/gcd(a,b);}
    inline MATRIX mul(MATRIX &A, MATRIX &B, ll m=MOD7){int n = A.size(),i,j,k;MATRIX C(n, vector<ll>(n));for(i=0;i<n;i++)for(j=0;j<n;j++)for(k=0;k<n;k++)C[i][j]=(C[i][j]+A[i][k]*B[k][j])%m;rtn C;}
    inline MATRIX pow(MATRIX &A, ll x, ll m=MOD7) {int n=A.size(),i;MATRIX B(n, vi(n));for(i=0;i<n;i++)B[i][i]=1;while (x>0){if(x%2)B=mul(B,A,m);x/=2;A=mul(A,A,m);}rtn B;}
    inline bool isSub(str txt, str s){int pos=-1;bool ok=true;for(int i=0;ok&&i!=s.size();i++){ok=(pos=txt.find(s[i],pos+1))!=string::npos;}rtn ok;}
    inline int countOne(ll n){int count=0;while(n){n = n&(n-1);count++;}rtn count;}
    inline str srev(str s){str demo="";for(int i=s.length()-1;i>=0;i--)demo+=s[i];rtn demo;}
    inline str ts(ll i){str s="",nm="0123456789";if(i==0){s="0";}while(i){s+=nm[i%10];i/=10;}rtn srev(s);}
    inline str tb(ll i){str ans = "";str arr = "01";while(i){ans+=arr[i%2];i=i/2;}rtn srev(ans);}
    inline ll maxSub(ll a[],ll n){ll e=-INF,s=0;rep(i,n){s+=a[i];if(e<s)e=s;if(s<0)s=0;}rtn e;}
    inline ll minSub(ll a[],ll n){ll e=INF,s=0;rep(i,n){s+=a[i];if(e>s)e=s;if(s>0)s=0;}rtn e;}
    //seive of Eratosthenes(prime's marked with 0)
    /*ll isPrime[1000100];
    void pinit(){isPrime[0]=1,isPrime[1]=1;for(ll i=2;i*i<=1000100;i++){if(!isPrime[i]){for(ll j=2*i;j<1000100;j+=i)isPrime[j]=1;}}}*/
     
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
     
    int main(){
    	std::ios_base::sync_with_stdio(false);
    	std::cin.tie(NULL);
    	std::cout.tie(NULL);
    	ll n, w, t, r;
    	cin >> n >> w >> t >> r;
    	init();
    	ll ans = (((fact[n]*invfact[w])%MOD7)*((invfact[t]*invfact[r])%MOD7))%MOD7;
    	cout << ans;
    } 