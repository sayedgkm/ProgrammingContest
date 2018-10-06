#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll res = n*m*2LL;
    if(res%k!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    ll a = n,b = m;
    if(k%2==0){
        cout<<"YES"<<endl;
        k/=2;
        ll gc = __gcd(n,k);
        a/=gc;
        k/=gc;
        b/=k;
        cout<<"0 0"<<endl;
        cout<<a<<" 0"<<endl;
        cout<<"0 "<<b<<endl;
    } else {
        ll gc = __gcd(n,k);
        a/=gc;
        k/=gc;
        b/=k;
        if(a*2<=n) a*=2;
        else if(b*2<=m) b*=2;
        else {
            cout<<"NO"<<endl;
            return 0;
        }
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<a<<" 0"<<endl;
        cout<<"0 "<<b<<endl;
    }
    return 0;
}

