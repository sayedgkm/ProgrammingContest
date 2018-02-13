//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        psi                             pair<int,string>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {1,-1,0,0,-1,1,1,-1};
inline int nxt() {
    int aaa;
    scanf("%d",&aaa);
    return aaa;
}
vector<int>ar;
vector<int>br;
vector<psi> ans;
bool go(int x,int y) {
    vector<ll>v; //cout<<x<<" "<<y<<endl;
    for(int i=x; i<=y; i++) {
        v.pb(ar[i]);
    }
    for(int i=x; i<y; i++) ar.erase(ar.begin());
    while(1) {

        if(v.size()==1)
            return true;

        ll mx=0;
        for(int i=0; i<v.size(); i++)
            mx=max(mx,v[i]);

        bool khailo=false;
        for(int i=0; i<v.size(); i++) {
            if(v[i]==mx) {

                if(i<v.size()-1) {
                    if(v[i+1]<v[i]) {
                        khailo=true;
                        v[i]+=v[i+1];
                        v.erase(v.begin()+i+1);
                        ans.pb(psi(x+i+1,"R"));
                        break;
                    }
                }
                if(i>0) {
                    if(v[i-1]<v[i]) {
                        khailo=true;
                        v[i]+=v[i-1];
                        v.erase(v.begin()+i-1);
                        ans.pb(psi(x+i+1,"L"));
                        break;
                    }
                }
            }
        }
        if(!khailo) return false;
    }
}
int main() {

    int n=nxt();
    ll s1=0,s2=0;
    for(int i=0; i<n; i++) {
        int a=nxt();
        ar.pb(a);
    }
    int m=nxt();

    for(int i=0; i<m; i++)
        br.pb(nxt());

    for(int i=0; i<m; i++) {
        ll sum=0;
        int j=i;
        while(j<n&&sum<br[i]) sum+=ar[j],j++;
        if(sum!=br[i]) {
            puts("NO");
            return 0;
        }
        bool ans=go(i,j-1);
        if(!ans) {
            puts("NO");
            return 0;
        }
    }
    if(ar.size()!=br.size()) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=0; i<ans.size(); i++) {
        printf("%d %s\n",ans[i].ff,ans[i].ss.c_str());
    }
    return 0;
}