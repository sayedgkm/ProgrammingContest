#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;


class PT {
public:
    ll x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}

};

ll ComputeSignedArea(const vector<PT> &p) {
    ll area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return abs(area) ;
}

ll SignedArea(PT a,PT b,PT c){ //The area is positive if abc is in counter-clockwise direction
    PT temp1(b.x-a.x,b.y-a.y),temp2(c.x-a.x,c.y-a.y);
    return abs(temp1.x*temp2.y-temp1.y*temp2.x);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    int d;
    cin>>n>>d;
    vector<PT> v;
    v.push_back(PT(0,d));
    v.push_back(PT(d,0));
    v.push_back(PT(n,n-d));
    v.push_back(PT(n-d,n));
    ll ar = ComputeSignedArea(v);
    int q;cin>>q;
    PT A(0,d);
    PT B(d,0);
    PT C(n,n-d);
    PT D(n-d,n);
    while(q--) {

        int a,b;
        cin>>a>>b;
        PT X(a,b);
        ll tot = SignedArea(D,C,X)+SignedArea(C,X,B)+SignedArea(A,X,B)+SignedArea(A,X,D);

        if(tot==ar) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

