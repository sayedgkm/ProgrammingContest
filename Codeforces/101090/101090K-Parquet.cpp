// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>

//  http://ideone.com/kxcEk8
using namespace std;
#define inf                  1e7
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pii                  pair <int,int>
#define pll                  pair <ll,ll>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define ff                   first
#define ss                   second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
#define WRITE                freopen("a.txt","w",stdout);
//***********************************************
#define MOD
#define ashraf
#ifdef ashraf
     #define so(args...) {cerr<<"so: "; dbg,args; cerr<<endl;}
#else
    #define so(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;


//******************************************************
inline void take(int &x) {scanf("%d",&x);}
inline void take(int &x ,int &y)  {scanf("%d %d",&x, &y);}
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b) {
  while (a > 0 && b > 0)
    a > b ? a%=b : b%=a;
  return a + b;
}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}

template < class T> T POW(T b , T p){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = POW(b,p/2);
        return (x*x);
    }
    else return (b*POW(b,p-1));
}

int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while(test--){
        ll a , b;
        cin >> a >> b;
        int flag = 0;
        if( a% 2 == 0 && b%3 == 0){
            flag = 1;
        }
        swap(a,b);
        if( a% 2 == 0 && b%3 == 0){
            flag = 1;
        }
        if(a%2 == 3 && (b%2 == 0 && b%3 == 0)){
            flag = 1;
        }
        if(a%3 == 2 && (b%2 == 0 && b%3 == 0) ){
            flag = 1;
        }
        swap(a,b);
        if(a%2 == 3 && (b%2 == 0 && b%3 == 0)){
            flag = 1;
        }
        if(a%3 == 2 && (b%2 == 0 && b%3 == 0) ){
            flag = 1;
        }
        if(flag == 0){
            cout << "No" << endl;
        } else cout << "Yes" << endl;
    }
}