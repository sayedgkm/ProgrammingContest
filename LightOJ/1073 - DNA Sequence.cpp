 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               16
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

string s[N];
int mark[N];
char t[105];
vector<string > v;
int pref[15][15];
bool sub(int i,int j) {
    if(s[i].size()>s[j].size()) return false;
    for(int k = 0;k+s[i].size()-1<s[j].size();k++) {
        if(s[j].substr(k,s[i].size())==s[i]) return true;
    }
    return false;
}
int dp[15][(1<<15)+5];
int P(int last,int cur) {
    int mx = 0;
    for(int i = v[last].size()-1;i>=0;i--) {
        int sz = v[last].size()-i;
        if(sz>v[cur].size()) return mx;
        if(v[last].substr(i,sz)==v[cur].substr(0,sz)) mx = sz;
    }
    return mx;
}
int go(int last,int mask){
    if(mask==(1<<v.size())-1) return 0;
    int &res = dp[last][mask];
    if(res!=-1) return res;
    res = inf;
    for(int i =0;i<v.size();i++) {
        if(ison(mask,i)) continue;
        if(mask==0)
            res = min(res,go(i,biton(mask,i))+(int)v[i].size());
        else
            res =  min(res,go(i,biton(mask,i))+((int)v[i].size()-pref[last][i]));
    }
    return res;
}
string ans;
int res;
void print(int last,int mask){
    if(mask==(1<<v.size())-1) return;
    vector<pair<string,int> > vv;
    for(int i =0;i<v.size();i++) {
        if(ison(mask,i)) continue;
        if(mask==0){
            if(go(i,biton(mask,i))+(int)v[i].size()==res) {
                res-=(int)v[i].size();
                ans += v[i];
                print(i,biton(mask,i));
                break;
            }
        }
        else{

            if(go(i,biton(mask,i))+((int)v[i].size()-pref[last][i])==res){

                int len = ((int)v[i].size()-pref[last][i]);
               // debug(s[i].substr(pref[last][i],len),s[i],last,pref[last][i],i);
                vv.pb(make_pair(v[i].substr(pref[last][i],len),i));


            }
        }
    }
    sort(ALL(vv));
  //  for(auto it : vv) debug(it.ff);
    if(vv.size()) {
        res-=vv[0].ff.size();
        ans+=vv[0].ff;
        print(vv[0].ss,biton(mask,(int)vv[0].ss));
    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int test = nxt();
    int cs = 1;
    while(test--) {

        int n= nxt();
        for(int i = 0;i<n;i++){
            scanf("%s",t);
            s[i] = t;
        }
        sort(s,s+n);
        for(int i = 0;i<n;i++) {
            bool f= 0;
            for(int j = 0;j<n;j++){
                if(i==j||mark[j]) continue;
                f|=sub(i,j);
                if(f) break;
            }
            mark[i] = f;
        }
        for(int i = 0;i<n;i++){
            if(mark[i]) continue;
            v.pb(s[i]);
        }
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v.size();j++) {
                if(i==j) continue;
                pref[i][j] = P(i,j);
            }
        }
        SET(dp);
        res = go(0,0);
        print(0,0);
        printf("Case %d: %s\n",cs++,ans.c_str());
        ans.clear();
        CLR(mark);
        CLR(pref);
        v.clear();

    }

    return 0;
}
