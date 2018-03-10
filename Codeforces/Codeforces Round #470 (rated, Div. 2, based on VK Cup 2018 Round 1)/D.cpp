/// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               500010
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
int br[N];
class node{
public:
	int cnt;
	node *ar[2];
	node(){
		cnt = 0;
		for (int i = 0; i < 2; i++) ar[i] = NULL;
    }
};
node *root;
void Insert(int word){

	node *current =root;
	for (int i = 31; i >=0; i--){
		int ascii = ison(word,i);
        if (current->ar[ascii] == NULL)
			 current->ar[ascii] = new node();
        current= current->ar[ascii];
        current->cnt++;
   }

}
ll Search(int word){
    ll ans = 0;
	node *current = root;
	for (int i = 31; i >=0; i--){
		int ascii = ison(word,i);
		if(ascii==0) {
            if(current->ar[0]!=NULL&&current->ar[0]->cnt){
                ans*=2;
                current= current->ar[0];
                current->cnt--;

            } else if(current->ar[1]!=NULL&&current->ar[1]->cnt){
                ans*=2;
                ans++;
                current= current->ar[1];
                current->cnt--;
            }
		} else {
            if(current->ar[1]!=NULL&&current->ar[1]->cnt){
                ans*=2;
                current= current->ar[1];
                current->cnt--;

            } else if(current->ar[0]!=NULL&&current->ar[0]->cnt){
                ans*=2;
                ans++;
               current= current->ar[0];
                current->cnt--;
            }

		}
		//debug(ans);
	}
    return ans;
}



int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    root = new node();
    int n = nxt();
    for(int i = 0;i<n;i++) {
        br[i] = nxt();
    }
    for(int i = 0;i<n;i++) {
        int a= nxt();
        Insert(a);
    }
    //Insert(0);
   // Search(br[0]);
    for(int i = 0;i<n;i++) {
        printf("%lld ",Search(br[i]));
    }
    printf("\n");



    return 0;
}
