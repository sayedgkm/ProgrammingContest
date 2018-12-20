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
vector<pair<string,int> > v[N];
string ans[N];
int n;
bool getSoution(string pf,string sf) {

    for(int i = 1;i<n;i++) {
        pair<string,int>tmp=v[i][0];
        pair<string,int>tmp1=v[i][1];
        string s1 = tmp.ff;
        string s2 = tmp1.ff;
           // cout<<s1<<" "<<s2<<endl;
        if(pf.substr(0,s1.size())==s1&&sf.substr( (int) (sf.size()-s2.size()) )==s2) {
            ans[tmp.ss] = "P";
            ans[tmp1.ss] = "S";
        } else if(pf.substr(0,s2.size())==s2&&sf.substr(sf.size()-s1.size())==s1){
            ans[tmp.ss] = "S";
            ans[tmp1.ss] = "P";
        } else return false;


    }
    return true;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    string s;
    if(n==2) {
        cin>>s>>s;
        cout<<"PS"<<endl;
        return 0;
    }
    string pf,sf;
    for(int i = 0;i<2*n-2;i++) {
        string s;
        cin>>s;
        int len = s.size();
        v[len].pb(make_pair(s,i));
        if(s.size()==n-1) {
            if(pf.size()==0) pf = s;
            else sf = s;
        }
    }
    if(!getSoution(pf,sf)) {
        swap(pf,sf);
        getSoution(pf,sf);
    }

    for(int i = 0;i<n*2-2;i++) cout<<ans[i];
    cout<<endl;
    return 0;
}
