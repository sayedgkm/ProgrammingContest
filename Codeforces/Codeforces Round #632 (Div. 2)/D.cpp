

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
vector<int> ans[N];
string s,t;
int toogle(int i) {
    if(s[i]=='L') s[i] = 'R';
    else s[i] = 'L';
}

int toogleT(int i) {
    if(t[i]=='L') t[i] = 'R';
    else t[i] = 'L';
}


bool isSame(int i, int j) {
    if(i<0 || j>=s.size()) {
        return 0;
    }
    return (s[i]=='R' && s[j]=='L');
}

bool isSameT(int i, int j) {
    if(i<0 || j>=s.size()) {
        return 0;
    }
    return (t[i]=='R' && t[j]=='L');
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int tt[] = {1, 2, 4, 5, 3};
    next_permutation(tt,tt+5);
    for(int i = 0;i<5;i++) {
        cout<<tt[i]<<" ";
    }
    int n = nxt();
    int k = nxt();

    cin>>s;
    t = s;
    set<pii> st;
    for(int i = 0;i<s.size();i++) {
        if(isSame(i-1,i)){
            st.insert(make_pair(i-1,i));
        }
    }

    vector<int> v;
    while(st.size()) {
        pii f = *st.begin();
        st.erase(st.find(f));
        int x = f.ff;
        int y = f.ss;
        v.push_back(x);
        toogle(x);
        toogle(y);

        if(isSame(x-1,x)) st.insert(make_pair(x-1,x));
        if(isSame(y,y+1)) st.insert(make_pair(y,y+1));
    }

   // debug(v.size());
//    for(auto it : v) {
//        debug(it);
//    }
    int ind = 0;
    for(int i = 0;i<k;i++) {
        if(ind<v.size()){
            for(int j = 1; j<=n/2; j++) {
                if(ind>=v.size()) break;
                ans[i].push_back(v[ind++]);
            }
        } else {

            int tot = k-i;
            if(tot%2!=0) {
                if(ans[0].size()>0) {
                ans[i].push_back(ans[0].back());
                ans[0].pop_back();
                i++;
                }
                else {

                    cout<<-1<<endl;
                    return 0;
                }
            }
            for(int tmp = i;tmp<k;tmp++) {
                ans[tmp].push_back(0);
            }
            break;
        }

    }

    bool f = 1;
    for(int i = 0;i<k;i++) {
        if(ans[i].size()==0) {
            f = 0;
        }

        for(int j = 0;j<ans[i].size();j++) {
            toogleT(ans[i][j]);
            toogleT(ans[i][j]+1);
        }
    }

    for(int i = 0;i<n;i++) {
        if(isSameT(i,i+1)) {
            cout<<-1<<endl;
            return 0;
        }
    }

    if(f==0) {
        cout<<-1<<endl;
        return 0;
    }

    for(int i = 0;i<k;i++) {
        printf("%d",ans[i].size());
        for(int j = 0;j<ans[i].size();j++) {
            printf(" %d",ans[i][j]+1);
        }
        printf("\n");
    }

     return 0;
}
