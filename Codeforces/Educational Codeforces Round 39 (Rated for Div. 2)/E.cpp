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
int sum[N];
int mark[20];
  string s;
int isok(int pos) {
    vector<int> odd;
    for(int i =0;i<10;i++){
        if(mark[i]==0) continue;
        odd.pb(i);
    }
    int last = (int)s.size()-(int)odd.size();
    if(sum[last-1]-sum[pos-1]>0) return true;
    int j = 0;
    for(int i = last;i<s.size();i++) {
        if(odd[j]+48>s[i]) return false;
        if(odd[j]+48<s[i]) return true;
    }
    return true;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin>>n;
    while(n--) {

        cin>>s;
        for(int i = 0;i<s.length();i++) {
            sum[i] =s[i]-'0';
            sum[i]+=sum[i-1];
        }
        if(s.length()%2) {
            if(s.length()==1) cout<<0;
            else for(int i = 0;i<s.length()-1;i++) cout<<9;
            cout<<endl;
        } else {
            string newString ;
            for(int i = 0;i<s.length();i++) {
                int curdig = s[i]-48;
                mark[curdig]^=1;
                if(isok(i+1)) newString+=s[i];
                else {
                    int curdig = s[i]-48;
                    mark[curdig]^=1;
                    curdig--;
                    mark[curdig]^=1;
                    newString+=(s[i]-1);
                    vector<int> odd;
                    for(int j = 0;j<=9;j++) {
                        if(mark[j]==0) continue;
                        odd.pb(j);
                    }
                    int j ;
                    for(j =i+1;j+odd.size()-1<s.length();j++) {
                        newString+=(9+48);
                    }
                    int x = odd.size()-1;
                    while(j<s.length()) {
                        newString+=odd[x]+48;
                        x--;
                    }
                    cout<<newString<<endl;
                   break;
                }
            }
            if(newString.size()%2==0)
                cout<<newString<<endl;
            else cout<<newString.substr(1,newString.size()-1)<<endl;
        }
    }

    return 0;
}
