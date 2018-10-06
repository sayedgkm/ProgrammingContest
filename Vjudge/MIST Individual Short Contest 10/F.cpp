#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        if(!n) break;
        int x =-1;
        int y =-1;
        for(int i = 1;i<5000;i++) {
            for(int j = 1;j<i;j++) {
                if(n==i*i*i-j*j*j) {
                    x = i;
                    y =j;
                    break;
                }
            }
            if(x>-1) break;
        }
        if(x==-1) cout<<"No solution"<<endl;
        else cout<<x<<" " <<y<<endl;

    }

    return 0;
}

