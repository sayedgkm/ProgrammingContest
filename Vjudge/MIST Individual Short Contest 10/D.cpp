#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
double p,q,r,s,t,u;
double get(double x) {
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>p>>q>>r>>s>>t>>u) {

       // for(double i = 0;i<=1;i+=0.01)
        double lo = 0;
        double hi = 1;
        for(int i = 0;i<=100;i++) {
            double mid = (lo+hi)/2;
            if(get(mid)>0.0000) lo = mid;
            else hi = mid;
        }
        //cout<<setprecision(10)<<fixed<<get(lo)<<endl;

        if(abs(get(lo)-0.0000)<=1e-9) cout<<setprecision(4)<<fixed<<lo<<endl;
        else cout<<"No solution"<<endl;

    }

    return 0;
}

