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
map<vector<int> ,int > mp;
vector<int> v[N];
vector<int> allPossible;
ll subAns = 0;

vector<int>subAllPossible;
void get(int pos,int f,int ind){
    if(pos==allPossible.size()) {
        if(subAllPossible.size()==0) return;
        if(subAllPossible.size()%2==1) {
            subAns+=mp[subAllPossible];
        } else subAns-=mp[subAllPossible];
        return;
    }

    get(pos+1,0,ind);
    subAllPossible.push_back(allPossible[pos]);
    get(pos+1,1,ind);
    subAllPossible.pop_back();

}

ll ans = 0;int gone;
void go(int ind,int pos,int f) {
    if(pos==v[ind].size()) {
        if(allPossible.size()!=0) {
            subAns = 0;
            get(0,0,ind);
           // if(ind==1) debug(subAns);
            if(allPossible.size()%2==1){
                ans+=gone-subAns;
            } else ans-=gone-subAns;
        }
        return;
    }
    go(ind,pos+1,0);
    allPossible.push_back(v[ind][pos]);
    go(ind,pos+1,1);
    allPossible.pop_back();
}
void mark(int ind,int pos,int f) {

    if(pos==v[ind].size()) {
        if(allPossible.size()>0) mp[allPossible]++;
        return;
    }
    mark(ind,pos+1,0);
    allPossible.push_back(v[ind][pos]);
    mark(ind,pos+1,1);
    allPossible.pop_back();
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int test = nxt(); int cs = 1;
    while(test--) {

        int n = nxt();
        int s = nxt();
        for(int i =0;i<n;i++) {
            v[i].clear();
            int x = nxt();
            while(x--) v[i].push_back(nxt());
            sort(ALL(v[i]));
        }
        mp.clear();
        ans = 0;
        for(int i = 0;i<n;i++) {
            gone = i;
            go(i,0,0);
            mark(i,0,0);
        }
        mp.clear();
        for(int i = n-1;i>=0;i--) {
            gone = n-i-1;
            go(i,0,0);
            mark(i,0,0);
        }
        printf("Case #%d: %lld\n",cs++,ans);
    }


    return 0;
}
