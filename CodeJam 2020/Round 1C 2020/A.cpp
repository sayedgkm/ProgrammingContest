
///Bismillahir-Rahmanir-Rahim
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
int dx[]={0, 0,1,-1,-1,-1,1,1};
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
map<pair<int,int>, int> mp;
map<pair<int,int>, vector<int> > pappur;
string s;
int cnt = 0;
int getInd(char c) {
    if(c=='S') {
        return 0;
    }
    if(c=='N') {
        return 1;
    }
    if(c=='W') {
        return 2;
    }

    return 3;
}

int bfs(int sx, int sy) {
    mp.clear();

    queue<pii> q;
    q.push(make_pair(sx, sy));
    mp[make_pair(sx, sy)] = 0; int ans = INT_MAX;
    while(!q.empty()) {

        pii f = q.front();
        if(pappur.find(f)!=pappur.end()) {
            int tt = mp[f];
            int st = INT_MIN;
            int l = lower_bound(pappur[f].begin(), pappur[f].end(), tt) - pappur[f].begin();
            if(l<pappur[f].size()) {
                st = pappur[f][l];
            }
            if(tt<=st) {
                ans = min(ans, st);
            }

            cnt--;
            if(cnt<=0) {
              break;
            }
        }
        q.pop();
        for(int i = 0;i<4;i++) {
            int nx = f.first+dx[i];
            int ny = f.second + dy[i];
            if(nx<-2100 || nx>2100) continue;
            if(ny<-2100  || ny > 2100) continue;
            if(mp.find(make_pair(nx, ny))==mp.end()) {
                q.push(make_pair(nx, ny));
                mp[make_pair(nx, ny)] = mp[f]+1;
            }
        }
    }

    return ans;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test; int cs = 1;
    cin>>test;
    while(test--) {

        int n, m;
        cin>>n>>m;
        int sx = 0;
        int sy = 0;
        int ex = sx - n;
        int ey = sy - m;


        int res = INT_MAX;
        if(abs(ex)+abs(ey)<=0) {
            res = 0;
        }

        string s;
        cin>>s;
        if(res) {
            for(int i = 0 ;i<s.size();i++) {
                int dir = getInd(s[i]);

                ex+=dx[dir];
                ey+=dy[dir];

                if(abs(ex)+abs(ey)<=i+1) {
                    res = min(res, i+1);
                }
            }
        }


        cout<<"Case #"<<cs++<<": ";
        if(res==INT_MAX) {
            cout<<"IMPOSSIBLE"<<endl;
        }else cout<<res<<endl;


    }
     return 0;
}

