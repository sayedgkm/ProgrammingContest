 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               600010
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
int pairL[N];
int pairR[N];
stack<int> st;
int parL[N];
int parR[N];
int getL(int x) {
    if(parL[x]==x) return x;
    return parL[x] =getL(parL[x]);
}
int getR(int x) {
    if(parR[x]==x) return x;
    return parR[x] =getR(parR[x]);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,p;
    cin>>n>>m>>p;
    string s;
    cin>>s;
    s='?'+s;
    for(int i = 1;i<=n;i++) {
        if(s[i]=='(') st.push(i);
        else {
            int l = st.top();
            st.pop();
            pairL[l] = i;
            pairR[i] = l;
        }
        parL[i]= parR[i] = i;
    }
    parL[n+1]= parR[n+1] = n+1;
    string t;
    cin>>t;
    for(int i = 0;i<m;i++) {
        if(t[i]=='L') {
            p--;
            p = getL(p);
        } else if(t[i]=='R'){
            p++;
            p = getR(p);
        } else {
            if(s[p]=='('){
                int np = pairL[p];
                parR[getR(p)]= getR(np+1);
                parL[getL(np)] = getL(p-1);
                if(getR(np+1)>n) {
                    p = getL(p-1);
                }  else p = getR(np+1);
            } else {
                int np =pairR[p];
                parR[getR(np)] = getR(p+1);
                parL[getL(p)] = getL(np-1);
                if(getR(p+1)>n) {
                    p = getL(np-1);
                }  else p = getR(p+1);

            }
        }
    }
    for(int i = 1;i<=n;) {
        if(s[i]=='(') if(getR(i)==i) cout<<s[i];
        if(s[i]==')')  cout<<s[i];
        if(getR(i)==i||s[i]==')') i++;
        else i = getR(i);
       // debug(i);
    }
    cout<<endl;
    return 0;
}
