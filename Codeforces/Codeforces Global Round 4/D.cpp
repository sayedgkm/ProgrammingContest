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
vector<int>primes;
bool mark[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
        if(mark[i]==0)
            for(int j = i*i; j <= n; j += i * 2)
                mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
}
vector<pii> edge;
vector<int> group[N];
int ind = 0;
void Add(int a,int b,int c) {
    group[ind].push_back(a);
    group[ind].push_back(b);
    group[ind].push_back(c);
    edge.push_back(make_pair(a,b));
    edge.push_back(make_pair(b,c));
    edge.push_back(make_pair(c,a));
    ind++;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    sieve(10000);
    int n = nxt();
    if(n<=2) {
        cout<<-1<<endl;
        return 0;
    }
    if(n==5) {
        cout<<5<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<3<<endl;
        cout<<3<<" "<<4<<endl;
        cout<<4<<" "<<5<<endl;
        cout<<5<<" "<<1<<endl;
        return 0;
    }
    if(n==7) {
        cout<<7<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<3<<endl;
        cout<<3<<" "<<4<<endl;
        cout<<4<<" "<<5<<endl;
        cout<<5<<" "<<6<<endl;
        cout<<6<<" "<<7<<endl;
        cout<<7<<" "<<1<<endl;
        return 0;
    }
    if(n==8) {
        cout<<11<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<3<<endl;
        cout<<3<<" "<<4<<endl;
        cout<<4<<" "<<5<<endl;
        cout<<5<<" "<<6<<endl;
        cout<<6<<" "<<7<<endl;
        cout<<7<<" "<<8<<endl;
        cout<<8<<" "<<1<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<8<<" "<<4<<endl;
        cout<<7<<" "<<5<<endl;
        return 0;
    }

    int rem = n%3;
    for(int i = 1;i+2<=n;i+=3) {
        Add(i,i+1,i+2);
       // debug(i);
    }
    ind--;
    if(rem==1) {
        edge.push_back(make_pair(group[ind][1],n));
        edge.push_back(make_pair(group[ind][2],n));
    } else if(rem==2) {
        edge.push_back(make_pair(n,n-1));
        edge.push_back(make_pair(group[ind][1],n));
        edge.push_back(make_pair(group[ind][2],n-1));
    }

    int tot = edge.size();
   // debug(tot);
    int index = lower_bound(primes.begin(),primes.end(),tot)-primes.begin();
    int nextPrime = primes[index];
    int x = 0;
    while(true) {
        if(tot==nextPrime) break;
        for(int i = 0;i<3;i++) {
            debug(x,ind);
            if(x+1==ind) {
                if(rem) {
                    if(i>0) break;
                }
            }
            edge.push_back(make_pair(group[x][i],group[x+1][i]));
            tot++;
            if(tot==nextPrime) break;
        }

        x+=2;
        if(x>=ind) break;
    }

    if(tot==nextPrime) {
        cout<<(int) edge.size()<<endl;
        for(int i = 0;i<edge.size();i++) {
            printf("%d %d\n",edge[i].ff,edge[i].ss);
        }
    } else {
        printf("-1\n");
    }


    return 0;
}

