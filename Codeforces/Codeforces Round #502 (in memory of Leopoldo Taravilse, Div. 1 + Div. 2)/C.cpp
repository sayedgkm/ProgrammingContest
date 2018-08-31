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
int br[N];
int tmp[100];
int lis(int n) {
    CLR(tmp);
    int ans = 0;
    for(int i = 0;i<n;i++) {
        int l = lower_bound(tmp+1,tmp+ans+1,br[i])-tmp;
        ans = max(ans,l);
        tmp[l] = br[i];
    }
    return ans;
}
int go(int i,int n) {
    int ans = i;
    ans+=n/i;
    if(n%i) ans+=1;
    return ans;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
//    int n = nxt();
//    for(int i =0;i<n;i++) ar[i]=i,br[i]=i;
//    int ans = inf;
//    do{
//
//        for(int i =0;i<n;i++) br[i] =ar[i];
//        int lc = lis(n);
//        reverse(br,br+n);
//        lc+= lis(n);
//        ans = min(ans,lc);
//
//    }while(next_permutation(ar,ar+n));
//    sort(ar,ar+n);
//    do{
//
//        for(int i =0;i<n;i++) br[i] =ar[i];
//        int lc = lis(n);
//        reverse(br,br+n);
//        lc+= lis(n);
//        if(lc==ans) {
//            cout<<lc<<endl;
//            for(int i=0;i<n;i++) cout<<ar[i]+1<<" ";
//            cout<<endl;
//            break;
//
//        }
//
//    }while(next_permutation(ar,ar+n));

    vector<int> v[10];
    v[1]={1};
    v[2]={1,2};
    v[3]={1,3,2};
    v[4]={3,4,1,2};
    v[5]={1, 3 ,2 ,5 ,4};
    int n=nxt();
    if(n<6) {
        for(auto it : v[n]) printf("%d ",it);
        printf("\n");
    } else {
       int ans = inf;
       for(int i = 3;i<=n;i++) {
            ans = min(ans,go(i,n));
       }

       for(int i = 3;i<=n;i++) {
            if(ans==go(i,n)) {
                for(int j = 0;j<n/i;j++) {
                    for(int k = i;k>=1;k--) {
                        printf("%d ",j*i+k);
                    }
                }
                for(int j = n;j%i;j--) {
                    printf("%d ",j);
                }
                printf("\n");
                break;
            }
       }

    }

    return 0;
}
