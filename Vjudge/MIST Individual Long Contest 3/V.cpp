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
vector<int> adj[51][26];
vector<int> radj[51][26];
string  dp[51][51][2];
string go(int st,int ed,int f) {
    if(st==ed) return "";
    if(ed<st) {
        if(f) return "";
        return "?";
    }
    string &res = dp[st][ed][f];
    if(res!="??") return res;
    res = "";
    for(int i=0;i<26;i++){
       for(int j = 0;j<adj[st][i].size();j++) {
            int st1 = adj[st][i][j];
            for(int k = 0;k<radj[ed][i].size();k++) {
                int ed1 = radj[ed][i][k];
                if(ed1<st1&&st==ed1&&ed==st1) {
                    string tmp = go(st1,ed1,1);
                    if(tmp!="?"){
                        tmp+=(char)i+'A';
                        if(tmp.size()>res.size()) {
                            res = tmp;
                        } else if(res.size()==tmp.size()) {
                            res = min(res,tmp);
                        }
                    }

                } else{
                    string tmp = go(st1,ed1,0);
                    if(tmp!="?") {
                        string tmp1 ;
                        tmp1+=(char)i+'A';
                        tmp1+=tmp;
                        tmp1+=(char)i+'A';
                        tmp = tmp1;

                        if(tmp.size()>res.size()) {
                            res = tmp;
                        } else if(res.size()==tmp.size()) {
                            res = min(res,tmp);
                        }
                    }

                }
            }
       }
    }
    return res;
}
//vector<int> F,l;
//void printPath(int st,int ed,int f,int tot) {
//    if(st==ed) return;
//    if(ed<st) {
//        if(f) return;
//        return;
//    }
//    int br = 0;
//    for(int i=0;i<26;i++){
//       for(int j = 0;j<adj[st][i].size();j++) {
//            int st1 = adj[st][i][j];
//            for(int k = 0;k<radj[ed][i].size();k++) {
//                int ed1 = radj[ed][i][k];
//                if(ed1<st1&&st==ed1&&ed==st1&&go(st1,ed1,1)+1==tot) {
//                    F.pb(i);
//                    printPath(st1,ed1,1,tot-1);
//                    br = 1;
//                    break;
//
//                } else if(go(st1,ed1,f)+2==tot){
//                    F.pb(i);
//                    l.pb(i);
//                    printPath(st1,ed1,f,tot-2);
//                    br = 1;
//                    break;
//                }
//
//            }
//            if(br) break;
//       }
//       if(br) break;
//    }
//}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    char s[100];
    while(test--) {
        int n =nxt();
        for(int i = 0;i<n;i++){
            scanf("%s",s);
            for(int j =i+1;j<n;j++){
                adj[i][s[j]-'A'].pb(j);
                radj[j][s[j]-'A'].pb(i);
            }
        }
        FOR(i,0,51) FOR(j,0,51) FOR(f,0,2) dp[i][j][f]="??";
        string ans = go(0,n-1,0);
        printf("%s\n",ans.c_str());
        for(int i =0;i<51;i++) for(int j = 0;j<26;j++) adj[i][j].clear(),radj[i][j].clear();


    }

    return 0;
}
