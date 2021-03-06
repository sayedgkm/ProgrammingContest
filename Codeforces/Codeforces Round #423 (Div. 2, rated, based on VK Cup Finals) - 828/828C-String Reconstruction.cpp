//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               2000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9e9+100
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
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
///******************************************START******************************************
int ar[N];
string s[N];
vector<int> v[N];
struct info{
   char  val;
   bool ok;
    info() {
      ok=false;
    }
}tree[N*4];
void segment_tree(int node,int low,int high){
     if(low==high){
          tree[node].val='a';
          tree[node].ok=false;
         return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
}
string S;
void update(int node,int low,int hi,int i,int j) {
    if(low>j||hi<i) return;
     if(low>=i&&hi<=j) {
        if(tree[node].ok) return;
    }
    if(low==hi) {
        tree[node].val=S[low-i];
        tree[node].ok=1;
        return ;
    }

    int mid=(low+hi)/2;
    update(node*2,low,mid,i,j);
    update(node*2+1,mid+1,hi,i,j);
    tree[node].ok=tree[2*node].ok&tree[node*2+1].ok;

}
char query(int node,int low,int hi,int i) {

     if(low==hi) return tree[node].val;
    int mid=(low+hi)/2;
    if(i<=mid) return query(2*node,low,mid,i);
    else return query(2*node+1,mid+1,hi,i);

}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    int n;
    cin>> n;
    int last=0;
    FOR(i,0,n) {
       cin>>s[i];
       int mx=0;
       int x;
       cin>>x;
       while(x--){
             int tem;
       cin>>tem;
                v[i].pb(tem);
                mx=max(mx,v[i].back());
       }
       last=max(mx+(int)s[i].size()-1,last);
    }
    segment_tree(1,1,last);
    FOR(i,0,n) {
       S=s[i];
       FOR(j,0,v[i].size()) {
           int x=v[i][j];
           int y=x+S.size()-1;
           update(1,1,last,x,y);
       }
    }
    FOR(i,1,last+1) {
       cout<<query(1,1,last,i);
    }
    cout<<endl;
return 0;
}