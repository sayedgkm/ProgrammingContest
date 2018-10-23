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

        int n ;
        cin>>n;
        for(int i = 0;i<n-1;i++) {
            cin>>ar[i];
        }
        sort(ar,ar+n-1);
        int x = 1;
        bool f= 0;
        for(int i = 0;i<n-1;i++) {
            if(ar[i]!=x) {
                cout<<x<<endl;
                f = 1;
                break;
            }
            x++;
        }
        if(!f) cout<<x<<endl;
    }

    return 0;
}

