#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int sum = 0;
    int mx = 0;
    for(int i = 0;i<n;i++) {
        int a;
        cin>>a;
        sum+=a;
        mx = max(mx,a);
    }
    cout<<sum+mx<<endl;

    return 0;
}

