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
        deque<int> dq;
        int mn,mx;
        for(int i = 0;i<n;i++) {
            int a;
            cin>>a;
            dq.push_back(a);
            if(i==0) mn = a,mx= a;
            else mn = min(mn,a),mx= max(mx,a);
        }
        bool f= 1;
        if(mn!=mx) {
            while((dq.front())>=dq.back()) {
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
            for(int i = 1;i<n;i++) {
                if(dq.at(i)<dq.at(i-1)) f = 0;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

