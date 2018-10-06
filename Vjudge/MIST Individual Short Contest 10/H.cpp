#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
int m;
ll ans;
ll n ;
ll lcm(ll a,ll b) {
    if(!a||!b) return max(a,b);
    return a*b/__gcd(a,b);
}
void go(int pos,int cnt,ll lc) {
    if(pos==m) {
        if(cnt==0) return;
        if(cnt&1) ans+=n/lc;
        else ans-=n/lc;
        return ;
    }
    go(pos+1,cnt,lc);
    go(pos+1,cnt+1,lcm(lc,ar[pos]));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m) {

        for(int i = 0;i<m;i++) {
            cin>>ar[i];
        }
        ans = 0;
        go(0,0,0);
        cout<<n-ans<<endl;

    }


    return 0;
}

