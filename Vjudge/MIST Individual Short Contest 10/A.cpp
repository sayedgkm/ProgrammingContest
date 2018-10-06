#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
bool go(int n) {

    int sum1 = 0;
    for(int i = 0;i<3;i++) {
        sum1+=n%10;
        n/=10;
    }
    int sum2 = 0;
    for(int i = 0;i<3;i++) {
        sum2+=n%10;
        n/=10;
    }
    return sum1==sum2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    if(go(n-1)||go(n+1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

