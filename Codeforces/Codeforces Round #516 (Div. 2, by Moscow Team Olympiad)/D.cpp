///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               2010
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
char str[N][N];
int color[N][N];
pii U(-1,0),D(1,0),R(0,1),L(0,-1);
struct info {
    int x,y,bam,dan;
    info(int x,int y,int bam,int dan) : x(x),y(y),bam(bam),dan(dan){}
};
bool isvalid(int x,int y,int r,int c) {
    if(x>=0&&x<r&&y>=0&&y<c&&str[x][y]=='.'&&color[x][y]==0) return true;
    return false;
}
void bfs(int stx,int sty,int r,int c,int left,int right) {
    color[stx][sty] = 1;
    deque<info> q;
    q.push_front(info(stx,sty,0,0));
    while(!q.empty()) {

        info top = q.front();
        q.pop_front();
        int x = top.x;
        int y = top.y;
        int nx = x+U.ff;
        int ny = y+U.ss;
//        if(x==2&&y==0) {
//            cout<<nx<<" "<<ny<<endl;
//        }
        if(isvalid(nx,ny,r,c)) {
            color[nx][ny]=1;
            q.push_front(info(nx,ny,top.bam,top.dan));
        }
        nx = x+D.ff;
        ny = y+D.ss;
        if(isvalid(nx,ny,r,c)) {
            color[nx][ny]=1;
            q.push_front(info(nx,ny,top.bam,top.dan));
        }

        if(left<right) {

            nx = x+R.ff;
            ny = y+R.ss;
            if(isvalid(nx,ny,r,c)&&top.dan+1<=right) {
                color[nx][ny]=1;
                q.push_back(info(nx,ny,top.bam,top.dan+1));
            }

            nx = x+L.ff;
            ny = y+L.ss;
            if(isvalid(nx,ny,r,c)&&top.bam+1<=left) {
                color[nx][ny]=1;
                q.push_back(info(nx,ny,top.bam+1,top.dan));
            }

        } else {
             nx = x+L.ff;
            ny = y+L.ss;
            if(isvalid(nx,ny,r,c)&&top.bam+1<=left) {
                color[nx][ny]=1;
                q.push_back(info(nx,ny,top.bam+1,top.dan));
            }

            nx = x+R.ff;
            ny = y+R.ss;
            if(isvalid(nx,ny,r,c)&&top.dan+1<=right) {
                color[nx][ny]=1;
                q.push_back(info(nx,ny,top.bam,top.dan+1));
            }

        }

    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int r = nxt();
    int c= nxt();
    int stx = nxt()-1;
    int sty = nxt()-1;
    int left = nxt();
    int right = nxt();
    for(int i = 0;i<r;i++) scanf("%s",str[i]);
    bfs(stx,sty,r,c,left,right);
    int cnt = 0;
    for(int i = 0;i<r;i++) {
        for(int j = 0;j<c;j++) {
            if(color[i][j]==1) cnt++;
           // cout<<color[i][j]<<" ";
        }
       // cout<<endl;
    }
    cout<<cnt<<endl;

    return 0;
}
