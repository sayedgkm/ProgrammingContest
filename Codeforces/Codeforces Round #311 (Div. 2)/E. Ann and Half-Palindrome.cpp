 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               5005
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
int dp[N][N];

class node{
public:
	node *ar[2];
	int cnt;
	int tot = 0;
	node(){
		for (int i = 0; i < 2; i++) ar[i] = NULL,cnt=0,tot=0;
    }
};
node *root;
string s;
void Insert(int st,int e){
	node *current =root;
	for (int i = st; i <=e; i++){
		int ascii = s[i] - 'a';
        if (current->ar[ascii] == NULL)
            current->ar[ascii] = new node();
        current= current->ar[ascii];
        current->cnt+=dp[st][i];
        current->tot+=dp[st][i];

   }
}
void dfs(node *cur,int l = 0) {
    for(int i =0;i<2;i++) {
        if(cur->ar[i]!=NULL){
            //debug(i,l+1);
            dfs(cur->ar[i],l+1);
            cur->tot+=cur->ar[i]->tot;
        }
    }
}
string ans;
void Search(node *cur,int val){
    if(val<=0) return;
    if(cur->ar[0]!=NULL&&cur->ar[1]!=NULL) {
        if(cur->ar[0]!=NULL&&cur->ar[0]->tot<val) {
            ans+='b';
            Search(cur->ar[1], val-((cur->ar[0]->tot)+(cur->ar[1]->cnt)));

        } else {
            ans+='a';
            Search(cur->ar[0],val-cur->ar[0]->cnt);
        }
    } else {

        for(int i = 0;i<2;i++) {
            if(cur->ar[i]!=NULL){
                ans+=i+'a';
                Search(cur->ar[i],val-cur->ar[i]->cnt);
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
    root = new node();
    cin>>s;
    int k = nxt();
    int n = s.length();
    for(int i = n-1;i>=0;i--) {
        for(int j = i;j<n;j++) {
            if(j-i<=4) dp[i][j]=(s[i]==s[j]);
            else {
                if(s[i]==s[j]) dp[i][j] = dp[i+2][j-2];
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = n-1;j>=i;j--) if(dp[i][j]){ Insert(i,j);break;}
    }
    dfs(root);
    Search(root,k);
    cout<<ans<<endl;
    return 0;
}

