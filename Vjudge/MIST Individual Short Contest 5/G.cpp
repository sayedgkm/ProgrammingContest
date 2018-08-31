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
struct point
{
    int x;
    int y;
    point (int _x,int _y) {
        x = _x;
        y =_y;
    }
};
vector<pair<point,point> > v;
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}


int orientation(point p, point q, point r)
{

    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0)? 1: 2;
}


bool doIntersect(point p1, point q1, point p2, point q2)
{

   // debug("asche");
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;


    if (o1 == 0 && onSegment(p1, p2, q1)) return true;


    if (o2 == 0 && onSegment(p1, q2, q1)) return true;


    if (o3 == 0 && onSegment(p2, p1, q2)) return true;


    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

struct line { // Creates a line with equation ax + by + c = 0
    double a, b, c;
    line() {}
    line( point p1,point p2 ) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};

inline bool eq(double a, double b) { return fabs( a - b ) < eps; } //two numbers are equal

inline line findPerpendicularLine( line L, point P ) {
    line res; //line perpendicular to L, and intersects with P
    res.a = L.b, res.b = -L.a;
    res.c = -res.a * P.x - res.b * P.y;
    return res;
}
struct fraction_point{
    int xup,xdown,yup,ydown;
    bool operator<(const fraction_point &other) const {
        return xup<other.xup;
    }
};
inline bool intersection(line L1, line L2, fraction_point &p ) {
    double det = L1.a * L2.b - L1.b * L2.a;
    if( eq ( det, 0 ) ) return false;
    p.xup = ( L1.b * L2.c - L2.b * L1.c );
    p.xdown=det;
    p.yup = ( L1.c * L2.a - L2.c * L1.a );
    p.ydown=det;
    return true;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int cs = 1;
    int test =nxt();
    while(test--) {

        int n = nxt();
        int L = nxt();
        int W = nxt();
        int ans = 1;
        for(int i = 0;i<n;i++) {

            int a= nxt();
            int b= nxt();
            point p1 = point(a,b);
            a = nxt();
            b = nxt();
            point p2 = point(a,b);

            map<fraction_point,int> mp; int c= 0;
            for(int i =0;i<v.size();i++) {
                if(doIntersect(p1,p2,v[i].ff,v[i].ss)) {
                    line l1 = line(p1,p2);
                    line l2 = line(v[i].ff,v[i].ss);
                    fraction_point p;
                    intersection(l1,l2,p);
                    int gc = gcd(abs(p.xup),abs(p.xdown));
                    if(gc>0){
                        p.xup/=gc;
                        p.xdown/=gc;
                    }

                    gc = gcd(abs(p.yup),abs(p.ydown));
                    if(gc>0){
                        p.yup/=gc;
                        p.ydown/=gc;
                    }


                    if(p.xup<0) {
                        p.xup*=-1;
                        p.xdown*=-1;
                    }
                    if(p.yup<0) {
                        p.yup*=-1;
                        p.ydown*=-1;
                    }
                    if(p.xup==0||(p.xdown==1&&p.xup==L)) continue;
                    if(p.yup==0||(p.ydown==1&&p.yup==W)) continue;
                    if(mp.count(p)==0) c++;
                    mp[p]=1;


                }
            }
            v.pb(make_pair(p1,p2));
            ans+=c+1;
        }
        printf("Case %d: %d\n",cs++,ans);

        v.clear();

    }

    return 0;
}
