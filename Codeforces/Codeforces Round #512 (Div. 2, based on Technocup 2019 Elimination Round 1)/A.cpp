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
    for(int i =0;i<n;i++) {
        int a;
        cin>>a;
        if(a){
                cout<<"HARD"<<endl;
                return 0;
        }
    }
    cout<<"EASY"<<endl;

    return 0;
}
