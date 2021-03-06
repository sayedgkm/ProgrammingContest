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
int ar[N];
int mxBit = 17;
set<pii> st[18];
ll ans[18];
ll go(ll n) {
    return (n*n+n)/2;
}
void build(int bt,int n) {
    int cnt = 0;
    int l=-1,r=-1;
    for(int i = 0;i<=n;i++) {
        if(ison(ar[i],bt)) {
            if(l==-1) l = r= i;
            else r = i;
        } else {
            if(l>-1){
                //if(bt==0) debug(l,r);
                st[bt].insert(make_pair(l,0)),st[bt].insert(make_pair(r,1));
                ans[bt]+=go(r-l+1);
            }
            l = -1;
            r = -1;
        }
    }

}
void change(int bt,int ind,int to) {
    if(to==0) {
        auto it = st[bt].lower_bound(make_pair(ind,1));
        pii last = *it;
        it--;
        pii first = *it;
        ans[bt]-=go(last.ff-first.ff+1);
        st[bt].erase(st[bt].find(first));
        st[bt].erase(st[bt].find(last));
        if(ind-1>=first.ff) {
            ans[bt]+=go(ind-first.ff);
            st[bt].insert(make_pair(first.ff,0));
            st[bt].insert(make_pair(ind-1,1));
        }
        if(ind+1<=last.ff) {
            ans[bt]+=go(last.ff-ind);
            st[bt].insert(make_pair(ind+1,0));
            st[bt].insert(last);
        }

    } else {
        auto it = st[bt].lower_bound(make_pair(ind,0));
        pii last = *it;
        it--;
        pii first= *it;
        debug(first.ff,last.ff,ind);
        if(first.ff+1==ind&&ind+1==last.ff) {
            it--;
            pii tmp1 = *it;
            ans[bt]-=go(first.ff-tmp1.ff+1);
            it++;
            it++;
            it++;
            pii tmp2 = *it;
            ans[bt]-=go(tmp2.ff-last.ff+1);
            ans[bt]+=go(tmp2.ff-tmp1.ff+1);
            st[bt].erase(first);
            st[bt].erase(last);

        } else if(first.ff+1==ind) {
            it--;
            pii tmp1 = *it;
            ans[bt]-=go(first.ff-tmp1.ff+1);
            st[bt].erase(first);
            st[bt].insert(make_pair(ind,1));
            ans[bt]+=go(first.ff-tmp1.ff+2);
        } else if(ind+1==last.ff) {
            it++;
            it++;
            pii tmp2 = *it;
            ans[bt]-=go(tmp2.ff-last.ff+1);
            st[bt].erase(last);
            st[bt].insert(make_pair(ind,0));
            ans[bt]+=go(tmp2.ff-last.ff+2);


        } else {
            ans[bt]+=go(1);
            st[bt].insert(make_pair(ind,0));
            st[bt].insert(make_pair(ind,1));
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
    int n= nxt();int q= nxt();
    for(int i = 0;i<n;i++) ar[i] =  nxt();
    for(int i = 0;i<=mxBit;i++) {
        st[i].insert(make_pair(-5,0));
        st[i].insert(make_pair(n+5,1));
    }
    for(int i = 0;i<=mxBit;i++) {
        build(i,n);
    }
    while(q--) {
        int ind = nxt();
        ind--;
        int val = nxt();
        for(int i = 0;i<=mxBit;i++) {
            if(ison(val,i)==ison(ar[ind],i)) continue;
            change(i,ind,ison(val,i));
        }
        ar[ind] = val;
        ll sum = 0;
        for(int i = 0;i<=mxBit;i++)sum+=ans[i]*(1LL<<i);
        printf("%lld\n",sum);
    }


    return 0;
}

