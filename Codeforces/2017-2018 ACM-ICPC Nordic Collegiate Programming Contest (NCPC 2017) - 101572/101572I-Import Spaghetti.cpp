//====================================
//======================================
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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              1e9
#define        eps                             1e-9
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos) {
    return n |((T)1<<pos);
}
template < class T> inline T bitoff(T n,T pos) {
    return n & ~((T)1<<pos);
}
template < class T> inline T ison(T n,T pos) {
    return (bool)(n & ((T)1<<pos));
}
template < class T> inline T gcd(T a, T b) {
    while(b) {
        a%=b;
        swap(a,b);
    }
    return a;
}
template <typename T> string NumberToString ( T Number ) {
    ostringstream ss;
    ss << Number;
    return ss.str();
}
inline int nxt() {
    int aaa;
    scanf("%d",&aaa);
    return aaa;
}
inline ll lxt() {
    ll aaa;
    scanf("%lld",&aaa);
    return aaa;
}
inline double dxt() {
    double aaa;
    scanf("%lf",&aaa);
    return aaa;
}
template <class T> inline T bigmod(T p,T e,T m) {
    T ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
}
#ifdef sayed
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names+1, ',');
    cerr.write(names, comma - names) << " is " << arg1 <<endl;
    __f(comma+1, args...);
}
#else
#define debug(...)
#endif
///******************************************START******************************************
int ar[N];
vector<int> node;
vector<int> adj[N];
int color[505],disc[505];
map<string,int> mp;
map<int,string> ulta;
int ans = inf;
int st;
int path[505];
int head = -1;
void bfs(int u) {
   color[u] = 1;
    queue<pii> q;
    q.push(make_pair(u,1));
    disc[u] = 1;
    while(!q.empty()) {
         pii f = q.front();
         q.pop();
         if(adj[f.ff].size()==0) color[f.ff] = 2;
         FOR(i,0,adj[f.ff].size()) {
             int v = adj[f.ff][i];
            if(color[v]==0) {
                path[v] = f.ff;
                  color[v] = 1;
                  q.push(make_pair(v,f.ss+1));
            } else if(color[v]==1&&v==u) {
               if(f.ss<ans) {
                  ans  = f.ss;
                  st = u;
                  head = f.ff;
                 return ;
               }
            }
         }


    }


}


vector<string> go(string s) {
    vector<string > ans;
    string temp;
    s+=' ';
    FOR(i,0,s.size()) {
        if(s[i]==' '||s[i]==',') {
            if(temp.size()&&temp!="import") {
                ans.pb(temp);
            }
            temp.clear();
            continue;

        }
        temp+=s[i];
    }
    return ans;

}
int main() {
#ifdef sayed
    //freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int rnk = 1;
    FOR(i,0,n) {
        string s;
        cin>>s;
        mp[s]=rnk;
        ulta[rnk] = s;
        node.pb(mp[s]);
        rnk++;
    }
    string last ;
    FOR(i,0,n) {
        string s;
        int t ;
        cin>>s>>t;
        string ok ;
        getline(cin,ok);
        FOR(j,0,t) {
            getline(cin,ok);
            vector<string > conect = go(ok);
            FOR(k,0,conect.size()) {
                if(conect[k]==s) {
                    last = s;
                }

                adj[mp[s]].pb(mp[conect[k]]);
            }
        }
    }
    if(last.size()) {
        cout<<last<<endl;
        return 0;
    }

    FOR(i,0,node.size()) {
        CLR(color);
        bfs(node[i]);
        //debug(ans);

    }
    //debug(ans);
    if(ans==inf) {
        cout<<"SHIP IT"<<endl;
    }  else {
        CLR(color);
         bfs(st);
        int c = 0;
        debug(head,c,"if");
        vector<string> res;
        while(1) {
            res.pb(ulta[head]);
            c++;
            if(c==ans) break;
            head = path[head];
        }
        reverse(ALL(res));
        FOR(i,0,res.size()) {
            if(i)cout<<" ";
            cout<<res[i];
        }
        cout<<endl;
    }
    return 0;
}