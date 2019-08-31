#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
#define        M                               998244353
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
vector<string> v;
int n;
void get(string t) {
    string s = "";
    for(int i = 0;i<n;i++) s+=t;
    v.push_back(s);
}
void genAnother(char a, char b, char c) {
    string s;
    for(int i = 0;i<n;i++) {
        s+=a;
    }
    for(int i = 0;i<n;i++) {
        s+=b;
    }
    for(int i = 0;i<n;i++) {
        s+=c;
    }
    v.push_back(s);
}
bool check(int ind,string &a, string &b){

    for(int i = 0;i<(3*n)-1;i++) {
        if(v[ind][i]==a[0]&&v[ind][i+1]==a[1]) return false;
    }
     for(int i = 0;i<(3*n)-1;i++) {
        if(v[ind][i]==b[0]&&v[ind][i+1]==b[1]) return false;
    }

    return true;
}
int main() {

    cin>>n;
    get("abc");
    get("acb");
    get("bac");
    get("bca");
    get("cab");
    get("cba");

    genAnother('a','b','c');
    genAnother('a','c','b');
    genAnother('b','a','c');
    genAnother('b','c','a');
    genAnother('c','a','b');
    genAnother('c','b','a');
    string a,b;
    cin>>a>>b;

    for(int i = 0;i<v.size();i++) {
        if(check(i,a,b)) {
            cout<<"YES"<<endl;
            cout<<v[i]<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;


   return 0 ;
}
