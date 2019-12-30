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
bool notFound(string &a, string &b) {
    int ar[40] = {0};

    for(int i = 0;i<b.size();i++) {
        ar[b[i]-'a']++;
    }

    for(int i = 0;i<a.size();i++) {
        if(ar[a[i]-'a']==0) return true;
        ar[a[i]-'a']--;
    }

    return false;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
   /// freopen("in.txt","r",stdin);
    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int test;
    cin>>test;
    while(test--) {

        string a,b;
        cin>>a>>b;
       // cout<<a<<" " <<b<<endl;
        string temp = "";
        bool isSmall =  0 ;
        for(int i = 1;i<a.size();i++) {
            if(a[i]>a[0]) break;
            if(a[i]<a[0]) {
                isSmall = 1;
            }
        }
        if(b.size()<a.size() || notFound(a,b)) {

            cout<<"Impossible"<<endl;
        } else {
            multiset<char> st;
            for(int i = 0;i<b.size();i++){
                st.insert(b[i]);
            }
            for(int i = 0;i<a.size();i++) {
                st.erase(st.find(a[i]));
            }
            string ans = "";
            bool done  = 0;
            for(auto it : st) {
                if(isSmall){
                    if(it>=a[0]&&done==0){
                        done = 1;
                        ans+=a;
                    }
                } else {
                    if(it>a[0]&&done==0) {
                        ans+=a;
                        done = 1;
                    }
                }
                ans+=it;
            }

            if(done==0) ans+=a;
            assert(ans.size()==b.size());
            cout<<ans<<endl;
        }

    }
    return 0;
}
