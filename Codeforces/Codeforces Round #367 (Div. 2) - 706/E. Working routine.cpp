 /// Bismillahir-Rahmanir-Rahim
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
struct node{
    node *l,*r,*u,*d;
    int val ;
};
node *head[1005];
int ar[1005][1005];
int n,m;
void Insert(int i){
    head[i] = new node();
    node *prev = head[i];
    node *cur;
    int j = 0;
    while(j<=m+1) {
        cur = new node();
        cur->val = ar[i][j];
        prev->r = cur;
        cur->l = prev;
        prev = cur;
        j++;
    }
    cur->r =NULL;
}
node *get(int x,int y) {
    node *cur = head[x]->r;
    while(y--) cur= cur->r;
    return cur;
}
void SwapR(node *cur1,node *cur2){
    cur1->r->l = cur2;
    cur2->r->l = cur1;
    swap(cur1->r,cur2->r);
}
void SwapL(node *cur1,node *cur2){
    cur1->l->r = cur2;
    cur2->l->r = cur1;
    swap(cur1->l,cur2->l);
}
void SwapD(node *cur1,node *cur2){
    cur1->d->u = cur2;
    cur2->d->u = cur1;
    swap(cur1->d,cur2->d);
}
void SwapU(node *cur1,node *cur2){
    cur1->u->d = cur2;
    cur2->u->d = cur1;
    swap(cur1->u,cur2->u);
}
void print() {
    printf("**********\n");
    for(int i = 1;i<=n;i++) {
        node *cur = head[i]->r->r;
        for(int j = 1;j<=m;j++,cur=cur->r) printf("%d ",cur->val);
        printf("\n");
    }

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
     n = nxt();
     m = nxt();
     int q= nxt();
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            ar[i][j] = nxt();
        }
    }
    for(int i = 0;i<=n+1;i++) {
        Insert(i);
    }
    for(int i = 1;i<=n+1;i++) {
        node *cur1 = head[i-1]->r;
        node *cur2 = head[i]->r;
        for(int j = 0;j<=m+1;j++) {
            cur2->u = cur1;
            cur1->d = cur2;
            cur1= cur1->r;
            cur2= cur2->r;
        }
    }
    while(q--) {
        int x1 = nxt();
        int y1 = nxt();
        int x2 = nxt();
        int y2 = nxt();
        int h = nxt();
        int w =nxt();
        node *cur1 = get(x1,y1);
        node *cur2 = get(x2,y2);
        SwapL(cur1,cur2);
        for(int i = 1;i<w;i++) {
            SwapU(cur1,cur2);
            swap(cur1,cur2);
            if(i!=w) {
                cur1= cur1->r;
                cur2= cur2->r;
            }
        }
       // print();
        SwapU(cur1,cur2);
        for(int i = 1;i<h;i++) {
            SwapR(cur1,cur2);
            swap(cur1,cur2);
            if(i!=h) {
                cur1= cur1->d;
                cur2= cur2->d;
            }
        }
        SwapR(cur1,cur2);
        for(int i = 1;i<w;i++) {
            SwapD(cur1,cur2);
            swap(cur1,cur2);
            if(i!=w) {
                cur1= cur1->l;
                cur2= cur2->l;
            }
        }
        SwapD(cur1,cur2);
        for(int i = 1;i<h;i++) {
            SwapL(cur1,cur2);
            swap(cur1,cur2);
            if(i!=h) {
                cur1= cur1->u;
                cur2= cur2->u;
            }
        }
    }
    for(int i = 1;i<=n;i++) {
        node *cur = head[i]->r->r;
        for(int j = 1;j<=m;j++,cur=cur->r) printf("%d ",cur->val);
        printf("\n");
    }
    return 0;
}
