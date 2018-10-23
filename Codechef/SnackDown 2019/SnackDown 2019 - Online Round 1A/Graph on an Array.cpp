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
         int n;
         cin>>n;
         vector<int> res;
         for(int i = 0;i<n;i++) cin>>ar[i];
         int change = 0;
         for(int i = 0;i<n;i++) {
            if(n==1) break;
            int f = 0;
            for(int j = 0;j<n;j++) {
                if(__gcd(ar[i],ar[j])==1) {
                    f = 1;
                    break;
                }
            }
            if(f==0) {
                if(ar[i]==47) {
                    ar[i]=43;
                } else ar[i] = 47;
                change = 1;
                break;
            }
         }
         cout<<change<<endl;
         for(int i = 0;i<n;i++) {
            if(i) cout<<' ';
            cout<<ar[i];
         }
         cout<<endl;
    }

    return 0;
}

