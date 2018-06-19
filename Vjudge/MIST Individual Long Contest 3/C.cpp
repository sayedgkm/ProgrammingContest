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
int dp[100][10000];int weight[100],cost[100];
bool taken[100][10000];
int knapsack(int n,int cap){
    for(int i=1;i<=n;i++){
        for(int w=1;w<=cap;w++){
            if(w>=weight[i]){
                if(cost[i]+dp[i-1][w-weight[i]]>dp[i-1][w]){
                    taken[i][w]=1;
                } else taken[i][w]=0;
                dp[i][w]=max(cost[i]+dp[i-1][w-weight[i]],dp[i-1][w]);
            }
            else {
                dp[i][w]=dp[i-1][w];
                taken[i][w]=0;
            }

        }
    }

    return dp[n][cap];
}
vector<pii> v;
vector<pii> res;
void printItem(int item,int total){
    while(item>0){
        if(taken[item][total]){
            res.pb(v[item-1]);
            total-=weight[item];
            item--;
        } else item--;

   }
   cout<<res.size()<<endl;
   reverse(ALL(res));
   for(int i = 0;i<res.size();i++) cout<<res[i].ff<<" "<<res[i].ss<<endl;
   res.clear();
   v.clear();

}
int main()
{
    int n,cap,w;int cs = 0;
    while(cin>>cap>>w>>n){
        for(int i = 1;i<=n;i++){
            cin>>weight[i]>>cost[i];
            v.pb(make_pair(weight[i],cost[i]));
            weight[i]*=w;
            weight[i]+=weight[i]*2;
        }
        if(cs) printf("\n");
        cs = 1;
        int res=knapsack(n,cap);
        cout<<res<<endl;
        printItem(n,cap);
        v.clear();


    }


return 0;
}
