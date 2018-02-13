#pragma comment(linker, "/stack:640000000")

#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define ll long long int
#define scanl(a) scanf("%lld",&a)
#define scanii(a,b) scanf("%d%d",&a,&b)
#define scaniii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scanll(a,b) scanf("%lld%lld",&a,&b)
#define scanlll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scani(a) scanf("%d",&a)
#define clr(a) memset(a,0,sizeof(a))
#define clr_(a) memset(a,-1,sizeof(a))
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) a*a
#define eps 1e-9
#define inf INT_MAX
#define pi acos(-1.0)
#define ff first
#define ss second
#define INF (ll)1e18
#define endl '\n'
#define m_p make_pair
#define vsort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define UNIQUE(X) X.erase( unique( X.begin(), X.end() ), X.end() )
int fx[]={0,0,-1,1,-1,1,1,-1};
int fy[]={1,-1,0,0,1,1,-1,-1};
ll lcm(ll a,ll b){return (a/__gcd(a,b))*b;}
ll bigmod(ll a,ll p,ll mod){ll ans=1;while(p){if(p&1)ans=ans*a%mod;a=a*a%mod;p>>=1;}return ans;}
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0){ll y=power(x,n/2);return y*y;}else return x*power(x,n-1);}
struct point{double x,y;point(){}point(double xx,double yy){x=xx;y=yy;}};
inline double Distance(point  a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
#ifdef shaft
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
const int N=(int)1e5;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    #ifdef shaft
       /// freopen("in.txt","r",stdin);
        ///freopen("out.txt","w",stdout);
    #endif ///shaft

        int x,y,x1,y1;
        while(cin>>x>>y>>x1>>y1)
        {
            if(x==x1)
            {
                if(y1<y) y1--;
                else y1++;
                cout<<2*abs(y-y1)+4<<endl;
            }
            else if(y==y1)
            {
                if(x1<x) x1--;
                else x1++;
                cout<<2*abs(x-x1)+4<<endl;
            }
            else
            {
                if(x1<x) x1--;
                else x1++;
                if(y1<y) y1--;
                else y1++;

                cout<<2*(abs(x-x1)+abs(y-y1))<<endl;
            }
        }
    return 0;
}