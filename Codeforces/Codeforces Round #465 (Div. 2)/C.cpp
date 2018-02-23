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
bool eq(long double a,long double b){
    return fabs(a-b)<eps;
}
long double go(long double x1,long double y1,long double x2,long double y2,long double mid,long double &x,long double &y) {
    double X = x2-x1;
    double Y = y2-y1;
    x = x1+X*mid;
    y = y1+Y*mid;
}
long double ok(long double x1,long double y1,long double R,long double x2,long double y2){
    long double dx = x1-x2;
    long double dy = y1-y2;
    dx = dx*dx;
    dy = dy*dy;
    R = R*R;
    return R>(dx+dy)+eps||eq(R,dx+dy);
}
long double sq(long double x){
    long double lo = 0;
    long double hi = 1e10;
    for(int i = 0;i<1000;i++){
        long double mid = (lo+hi)/2;
        if((mid*mid)>x) hi = mid;
        else lo = mid;
    }
    return lo;
}
long double ok1(long double x1,long double y1,long double x2,long double y2){
    long double dx = x1-x2;
    long double dy = y1-y2;
    dx = dx*dx;
    dy = dy*dy;
    return dx+dy;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    long double R,x1,y1,x2,y2,boudaryX,boundaryY;
    cin>>R>>x1>>y1>>x2>>y2;
    if(ok1(x1,y1,x2,y2)>=(R*R)){
        cout<<setprecision(20)<<fixed<<x1<<" "<<y1<<" "<<R<<endl;
        return 0;
    }
    if(x1==x2&&y1==y2){
        boudaryX = x1+R;
        boundaryY= y1;
    } else {

        long double lo = 0,hi=1e10;
        for(int i = 0;i<100000;i++) {
            double mid = (lo+hi)/2.0;
            go(x2,y2,x1,y1,mid,boudaryX,boundaryY);
            if(ok(x1,y1,R,boudaryX,boundaryY)) lo = mid;
            else hi = mid;
        }
    }

    long double leftX=x2,leftY=y2;
    debug(leftX,leftY,boudaryX,boundaryY);
    long double ansx = boudaryX+(leftX-boudaryX)*.50000000000;
    long double ansy = boundaryY+(leftY-boundaryY)*.500000000000;
    cout<<setprecision(20)<<fixed<<ansx<<" "<<ansy;
    cout<<setprecision(20)<<fixed<<" "<<sq(ok1(ansx,ansy,boudaryX,boundaryY))<<endl;;

    return 0;
}
