///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (1e9)+1000
#define        eps                             1e-9
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
#define EPS 1e-9
inline int dcmp (double x) { return x < -EPS ? -1 : (x > EPS); }
bool isValid(int x,int y,int z) {
    vector<int> v;
    v.pb(ar[x]);
    v.pb(ar[y]);
    v.pb(ar[z]);
    sort(ALL(v));
    return v[0]+v[1]>v[2];
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--) {

        int n = nxt();
        double p = dxt();
        double q = dxt();
        for(int i = 0;i<n;i++) {
            ar[i] = nxt();
        }
        sort(ar,ar+n);
        int x1=-1,y1=-1,z1=-1;
        double theta = EPS;
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                double z = ar[i];
                double y = ar[j];
                double need = z*z+y*y-2*z*y*(p/q);
                need = sqrt(need);
                double alpha = (acos(p/q)*180.0)/pi;
                int lagbe = (int) need;
               // if(lagbe>=ar[i]+ar[j]) continue;
               // cout<<lagbe<<endl;
                int l = upper_bound(ar,ar+n,lagbe)-ar;
                l--;
               // cout<<l<<' '<<i<<' '<<j<<endl;
                if(l==j||l==i) l--;
                if(l==j||l==i) l--;
                if(l>=0) {
                    if(!isValid(i,j,l)) continue;
                    if(alpha>=theta) {
                        x1 = l;
                        y1 = j;
                        z1 = i;
                        theta = alpha;
                    }

                }


            }
        }
        if(x1==-1) {
            printf("-1\n");
        } else printf("%d %d %d\n",x1+1,y1+1,z1+1);
    }

    return 0;
}
