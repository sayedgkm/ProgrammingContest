#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--) {

        ll k,p,n;
        cin>>k>>p>>n;
        cout<<max(0LL,(k-p)*n)<<endl;
    }



    return 0;
}

