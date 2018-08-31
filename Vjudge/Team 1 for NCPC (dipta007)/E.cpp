/// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (1e9)+1000
#define        eps                             1e-9
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos)
{
    return n |((T)1<<pos);
}
template < class T> inline T bitoff(T n,T pos)
{
    return n & ~((T)1<<pos);
}
template < class T> inline T ison(T n,T pos)
{
    return (bool)(n & ((T)1<<pos));
}
template < class T> inline T gcd(T a, T b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}
inline int nxt()
{
    int aaa;
    scanf("%d",&aaa);
    return aaa;
}
inline ll lxt()
{
    ll aaa;
    scanf("%lld",&aaa);
    return aaa;
}
inline double dxt()
{
    double aaa;
    scanf("%lf",&aaa);
    return aaa;
}
template <class T> inline T bigmod(T p,T e,T m)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
}
#ifdef sayed
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cerr.write(names, comma - names) << " is " << arg1 <<" | ";
    __f(comma+1, args...);
}
#else
#define debug(...)
#endif
///******************************************START******************************************
int ar[N];
ll go(ll n)
{
    if(n%2==0)
    {
        return (n/2)*(n+1);
    }
    else
    {
        return ((n+1)/2)*n;
    }
}
int main()
{
#ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int test = nxt();
    int cs = 1;
    while(test--)
    {

        ll a1= lxt(),a2= lxt();
        ll b1= lxt(),b2= lxt();
        ll c1= lxt(),c2= lxt();
        ll n = lxt();
         int cnt = 0;
    for(int i = a1;i<=a2;i++) for(int j = b1;j<=b2;j++) for(int k = c1;k<=c2;k++) {
        if(i+j+k==n) cnt++;
    }
    debug(cnt);


        ll ans = 0;
        if(a1+b1+c1>n||a2+b2+c2<n)
        {
            printf("0\n");
        }
        else
        {
            ll lo = a1;
            ll hi = a2;
            while(lo<=hi)
            {
                ll mid = (lo+hi)/2;
                ll last = c2;
                ll baki = n- mid- c2;
                if(baki>b2)
                {
                    lo = mid+1;
                }
                else
                {
                    hi = mid-1;
                }

            }

            ll f1 = lo;
            ll s1 = n-f1-c2;
            ll t1 = c2;
            ll d = 0;
            if(s1<b1)
            {
                d= b1-s1;
                s1 = b1;
            }
            t1-=d;
            ll mn = min(a2-f1+1,s1-b1+1);
            debug(mn);
            if(t1-c1<=b2-s1)
            {
                ans+=mn*(t1-c1+1);
                ans%=M;
            }
            else
            {
                ll tmn = b2-s1+1;
                ll tmx = c2-c1+1;
                ll mx = min(tmx,mn+tmn-1);
                debug(mn,tmn,tmx,mx);
                ans+=(((go(mx)%M- go(tmn-1)%M)%M)+M)%M;
                ll baki = max(mx-tmx,0LL)%M;
                ans+=baki*tmx%M;
                ans%=M;
            }
            s1-=mn;
            f1+=mn;
            if(s1<b1) s1 = b1;
            t1= n-f1-s1;
            ll janina =go(t1-c1+1);
            janina-=go(t1-c1+1-(a2-f1+1));
            janina%=M;
            janina+=M;
            ans+=janina;
            ans%=M;
            printf("%lld\n",ans);

        }

    }

    return 0;
}
