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
struct matrix{
  ll mat[16][16];
  int row,clm;
  matrix(){
     memset(mat,0,sizeof mat);
  }
  matrix(int a,int b){
       row=a;clm=b;
     memset(mat,0,sizeof mat);
  }
  void identity(){
      for(int i=0;i<row;i++) mat[i][i]=1;
  }
  void print(){
    for(int i=0;i<row;i++){
        for(int j=0;j<clm;j++) printf("%lld ",mat[i][j]);
        printf("\n");
    }
  }
};
matrix mul(matrix a,matrix b){
    matrix c;
    c.row=a.row;
    c.clm=b.clm;
    for(int i=0;i<c.row;i++)
     for(int j=0;j<c.clm;j++){
         c.mat[i][j]=0;
         for(int k=0;k<a.clm;k++)
              c.mat[i][j]=(c.mat[i][j]+(a.mat[i][k]%M*b.mat[k][j]%M)%M)%M;
     }
     return c;
}
matrix power(matrix p,ll e){
     matrix ret(p.row,p.clm);
     ret.identity();
     while(e){
     if(e&1) ret=mul(p,ret);
     p=mul(p,p);
     e>>=1;
   }
   return ret;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    matrix base(16,16);

    matrix init(16,1);
    init.mat[0][0]=1;
    matrix res(16,1);
    res.mat[0][0]  = 1;
    int n= nxt(); ll k = lxt();
    for(int i =0;i<n;i++) {

        ll a= lxt();
        ll b= lxt();
        int c= nxt();
        CLR(init.mat);
        for(int i =0;i<=c;i++) init.mat[i][0]= res.mat[i][0];
        CLR(base.mat);
        for(int i = 0;i<=c;i++) {
            base.mat[i][i]=1;
            if(i+1<=c)
                base.mat[i][i+1]=1;
            if(i)
                base.mat[i][i-1]=1;
        }
    //    base.print();
       // init.print();
        if(b>k) b=k;
        matrix tmp = power(base,b-a);
       // tmp.print();
        res = mul(tmp,init);
        if(b==k) break;
    }
    printf("%lld\n",res.mat[0][0]);


    return 0;
}
