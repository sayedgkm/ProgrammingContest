 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               155
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
const ll INF=(ll)1<<60;
struct Edge{
	ll from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
};
namespace mcmf{
	int n,m,s,t;
	vector<Edge> edges;
	vector<ll> G[N];
	bool inq[N];
	ll d[N],p[N],a[N];
	void init(int src,int sink,int node)
	{
		n=node;
		s= src;
		t = sink;
		edges.clear();
		for(int i=0;i<=n;++i) G[i].clear();
	}
	void addEdge(int from,int to,ll cap,ll cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool spfa(ll &flow,ll& cost)
	{
		for(int i=0;i<=n;++i) d[i]=INF,inq[i]=0;
		queue<int> que;
		que.push(s);
		inq[s]=1;d[s]=0;p[s]=0;a[s]=INF;
		while(!que.empty())
		{
			int x=que.front();que.pop();
			inq[x]=0;
			for(int i=0;i<G[x].size();++i)
			{
				Edge &e=edges[G[x][i]];
				if(e.cap>e.flow && d[e.to]>d[x]+e.cost)
				{
					d[e.to]=d[x]+e.cost;
					p[e.to]=G[x][i];
					a[e.to]=min(a[x],e.cap-e.flow);
					if(!inq[e.to]) inq[e.to]=1,que.push(e.to);
				}
			}
		}
		if(d[t]==INF) return 0;
		flow+=a[t];
		cost+=d[t];    /// multiply by d[t]*a[t] if per unit cost is given.
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return 1;
	}
	pll solve()
	{
		ll flow=0,cost=0;
		while(spfa(flow,cost));
		return make_pair(cost,flow);
	}
}
int atMost[N],atLeast[N];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n =nxt();
    int k = nxt();
    for(int i = 1;i<=n;i++) {
        atLeast[i] = 1;
        atMost[i] = n;
    }
    for(int i = 0;i<k;i++) {
        int t=nxt();
        int l = nxt();
        int r = nxt();
        int v= nxt();
        FOR(i,l,r+1) {
            if(t==1) {
                atLeast[i] = max(atLeast[i],v);
            } else {
                atMost[i] = min(atMost[i],v);
            }
        }
    }
    mcmf::init(0,n+n+1,n+n+10);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++)
            mcmf::addEdge(0,i,1,2*j-1);
        mcmf::addEdge(n+i,n+n+1,1,0);
    }
    for(int i = 1;i<=n;i++) {

        if(atLeast[i]>atMost[i]) {
            printf("-1\n");
            return 0;
        }
        for(int j = atLeast[i];j<=atMost[i];j++) {
            mcmf::addEdge(j,i+n,1,0);
        }
    }
    cout<<mcmf::solve().ff<<endl;
    return 0;
}

