///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        M                               1000000007
#define        N                             1000010
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


int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N];
int rnk[N],height[N];

void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}

int sa[N],data[N],n,p,q;
char str[N];

void Deal ()
{
    DA(data,sa,n+1,128);
    calheight(data,sa,n);

    ///here rank said in which position a suffix is situated
    ///in the sorted suffix list.

    ///height gives the LCP of id && id-1

    ///sa gives the sorted suffix indexes
}
ll tSix[N];
ll sum1[N];
ll pre[N];

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
  // double cl = clock();
   tSix[0] =0LL;
   pre[0]=1LL;
   for(int i = 1;i<N;i++){
        pre[i]= pre[i-1]*26LL;
        pre[i]%=M;
        tSix[i]=(tSix[i-1]+pre[i])%M;
   }
    int test = nxt();
    int cs = 1;
    while(test--) {
        scanf("%s",str);
        int  nnn = strlen(str);
        n=nnn;
        string s = str;
        for(int i =0;i<nnn;i++) data[i] = (int)str[i];
        data[nnn]=0;
        Deal();
        CLR(sum1);
        for(int i = 1;i<=nnn;i++) {
            int x = sa[i];
            int tot = nnn-x;

            int lc = 0;
            if(i) lc =height[i];

            sum1[lc+1]++;
            sum1[tot+1]--;

        }
        for(int i = 1;i<=nnn;i++) sum1[i]+=sum1[i-1];
        for(int i = 1;i<=nnn;i++) sum1[i]+=sum1[i-1];
      //  for(int i =1;i<=nnn;i++) debug(sum1[i]);
        int q = nxt();
        printf("Case %d:\n",cs++);
        while(q--) {
            int a= nxt();
            int b= nxt();
           // debug(a,b);
            ll res = tSix[b]-tSix[a-1];
            res%=M;
            res-=(sum1[b]-sum1[a-1]);
            res%=M;
            res+=M;
            res%=M;
            printf("%lld\n",res);
        }

    }
    ///debug((clock()-cl)/CLOCKS_PER_SEC);
    return 0;
}

