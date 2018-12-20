///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               2005
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
int A[N],B[N];
set<pii> sp;
set<pii> given;
set<int> index[N];
int ar[N];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i =1;i<=2*n;i++) {
        int a;
        cin>>a;
        ar[i] = a;
        given.insert(make_pair(a,i));
        index[a].insert(i);
    }
    SET(A);
    SET(B);
    for(int i = 0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        if(ar[a]>ar[b]) swap(a,b);
        sp.insert(make_pair(a,b));
        A[a] = b;
        B[b]=a;

    }
    int turn ;
    cin>>turn;
    if(turn==1) {

        while(sp.size()) {
            auto it = sp.end();
            it--;
            pii val = *it;
            sp.erase(it);

            int last = val.ss;
            int v = ar[last];
            cout<<last<<endl;
            given.erase(make_pair(v,last));
            cin>>last;
            if(last!=val.ff) assert(0);
            v = ar[last];
            given.erase(make_pair(v,last));
        }
        while(given.size()) {

            //cout<<" "<<given.size()<<endl;
            auto it =given.end();
            it--;
            pii val = *it;
            int last = val.ss;
            int big = val.ff;
            cout<<last<<endl;
            given.erase(make_pair(big,last));
            cin>>last;
            int small = ar[last];
            given.erase(make_pair(small,last));
            //cout<<" "<<given.size()<<endl;

        }


    } else {

        for(int i = 1;i<=n;i++) {
            int last ;
            cin>>last;
            int oposite = -1;
            if(A[last]>0) {
                oposite = A[last];
            } else if(B[last]>0) {
                oposite = B[last];
            }
            if(oposite!=-1) {
                cout<<oposite<<endl;
                if(ar[last]>ar[oposite]) swap(last,oposite);
                sp.erase(sp.find(make_pair(last,oposite)));
                int val = ar[last];
                int ind = last;
                given.erase(given.find(make_pair(val,ind)));
                val = ar[oposite];
                ind = oposite;
                given.erase(given.find(make_pair(val,ind)));
                A[oposite]= B[oposite]=-1;
                A[last]=B[last]=-1;
            } else {
                int val = ar[last];
                given.erase(given.find(make_pair(val,last)));
                break;
            }

        }
        while(sp.size()) {
            auto it = sp.end();
            it--;
            pii val = *it;
            sp.erase(it);

            int last = val.ss;
            int v = ar[last];
            cout<<last<<endl;
            given.erase(make_pair(v,last));
            cin>>last;
            if(last!=val.ff) assert(0);
            v = ar[last];
            given.erase(make_pair(v,last));

        }

         while(given.size()) {

              auto it =given.end();
            it--;
            pii val = *it;
            int last = val.ss;
            int big = val.ff;
            cout<<last<<endl;
            given.erase(make_pair(big,last));
            if(given.size()==0) break;
            cin>>last;
            int small = ar[last];
            given.erase(make_pair(small,last));

        }



    }


    return 0;
}
