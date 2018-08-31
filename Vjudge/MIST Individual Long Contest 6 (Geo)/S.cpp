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
#define EPS 1e-6
#define NEX(x) ((x+1)%n)
#define PRV(x) ((x-1+n)%n)
#define RAD(x) ((x*pi)/180)
#define DEG(x) ((x*180)/pi)
const double PI=acos(-1.0);

inline int dcmp (double x) { return x < -EPS ? -1 : (x > EPS); }
//inline int dcmp (int x) { return (x>0) - (x<0); }

class PT {
public:
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    double Magnitude() {return sqrt(x*x+y*y);}

    bool operator == (const PT& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const PT& u) const { return !(*this == u); }
    bool operator < (const PT& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
    bool operator > (const PT& u) const { return u < *this; }
    bool operator <= (const PT& u) const { return *this < u || *this == u; }
    bool operator >= (const PT& u) const { return *this > u || *this == u; }
    PT operator + (const PT& u) const { return PT(x + u.x, y + u.y); }
    PT operator - (const PT& u) const { return PT(x - u.x, y - u.y); }
    PT operator * (const double u) const { return PT(x * u, y * u); }
    PT operator / (const double u) const { return PT(x / u, y / u); }
    double operator * (const PT& u) const { return x*u.y - y*u.x; }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p, PT q)   { return sqrt(dist2(p,q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
bool LinesParallel(PT a, PT b, PT c, PT d) {
    return dcmp(cross(b-a, c-d)) == 0;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
      && dcmp(cross(a-b, a-c)) == 0
      && dcmp(cross(c-d, c-a)) == 0;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (LinesCollinear(a, b, c, d)) {
        if (dcmp(dist2(a, c)) == 0 || dcmp(dist2(a, d)) == 0 ||
            dcmp(dist2(b, c)) == 0 || dcmp(dist2(b, d)) == 0) return true;
        if (dcmp(dot(c-a, c-b)) > 0 && dcmp(dot(d-a, d-b)) > 0 && dcmp(dot(c-b, d-b)) > 0)
            return false;
        return true;
    }
    if (dcmp(cross(d-a, b-a)) * dcmp(cross(c-a, b-a)) > 0) return false;
    if (dcmp(cross(a-c, d-c)) * dcmp(cross(b-c, d-c)) > 0) return false;
    return true;
}
bool PointOnSegment(PT s, PT e, PT p) {
    if(p == s || p == e)    return 1;
    return dcmp(cross(s-p, s-e)) == 0
        && dcmp(dot(PT(s.x-p.x, s.y-p.y), PT(e.x-p.x, e.y-p.y))) < 0;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

double minimumDistancePointX(pair<PT,PT> segment,double l) {
    PT A(0,0),B(l,0);
    PT C= segment.ff;
    PT D = segment.ss;
    if(SegmentsIntersect(A,B,C,D)) return ComputeLineIntersection(A,B,C,D).x;
    double x,mn = 3e18;
    if(DistancePointSegment(C,D,A)<=mn) {
        mn = DistancePointSegment(C,D,A);
        x = A.x;
    }
    if(DistancePointSegment(C,D,B)<=mn) {
        mn = DistancePointSegment(C,D,B);
        x = B.x;
    }
    if(C.x>=0&&C.x<=l) {
        double d = DistancePointSegment(C,D,PT(C.x,0));
        if(d<=mn) {
            mn = d;
            x  = C.x;
        }
    }

    if(D.x>=0&&D.x<=l) {
        double d = DistancePointSegment(C,D,PT(D.x,0));
        if(d<=mn) {
            mn = d;
            x  = D.x;
        }
    }
    return x;

}
vector<pair<PT,PT> > v;

vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
    vector<PT> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
        ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}


bool ispossible (double r,double l) {

    vector<pair<double,double> > v1;
    for(int i = 0;i<v.size();i++) {

        double submid =minimumDistancePointX(v[i],l);
        if(dcmp(DistancePointSegment(v[i].ff,v[i].ss,PT(submid,0))-r)>0) {
            continue;
        }
        double lo = 0;
        double hi = submid;
        for(int j = 0;j<50;j++) {
            double mid = (lo+hi)/2;
            vector<PT> tmp = CircleLineIntersection(v[i].ff,v[i].ss,PT(mid,0),r);
            bool f = 0;
            for(auto it : tmp) {
                if(PointOnSegment(v[i].ff,v[i].ss,it)) f =1;
            }
            if(dcmp(dist(PT(mid,0),v[i].ff)-r)<0&&dcmp(dist(PT(mid,0),v[i].ss)-r)<0) f=1;
            if(f) hi = mid;
            else lo = mid;
        }


        double lo1 = submid;
        double hi1 = l;
        for(int j = 0;j<50;j++) {
            double mid = (lo1+hi1)/2;
            vector<PT> tmp = CircleLineIntersection(v[i].ff,v[i].ss,PT(mid,0),r);
            bool f = 0;
            for(auto it : tmp) {
                if(PointOnSegment(v[i].ff,v[i].ss,it)) f =1;
            }
            if(dcmp(dist(PT(mid,0),v[i].ff)-r)<0&&dcmp(dist(PT(mid,0),v[i].ss)-r)<0) f=1;
            if(f) lo1 = mid;
            else hi1 = mid;
        }
      //  debug(lo,lo1);
        v1.pb(make_pair(lo,lo1));
    }
    sort(ALL(v1));
    double last = 0;
    for(int i = 0;i<v1.size();i++) {
        if(dcmp(v1[i].ff-last)>0) return true;
        last = max(last,v1[i].ss);
    }
    if(dcmp(l-last)>0) return true;
    return false;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--) {

        int n = nxt();
        int l = nxt();
        for(int i = 0;i<n;i++) {
           PT A,B;
           A.x = dxt();
           A.y = dxt();
           B.x = dxt();
           B.y = dxt();
           v.pb(make_pair(A,B));
        }

        double lo =0;
        double hi  = 1e9;
        for(int  i = 0;i<50;i++) {
            double mid=(lo+hi)/2;
            if(ispossible(mid,l)) lo = mid;
            else hi =mid;
        }
        printf("%0.3f\n",lo);
        v.clear();
    }

    return 0;
}
