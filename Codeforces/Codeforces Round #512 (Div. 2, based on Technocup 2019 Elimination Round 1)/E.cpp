#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
int sum[N];
int tree[2][N];
void update(int id,int pos,int limit) {
    while(pos<=limit) {
        tree[id][pos]+=1;
        pos+=pos&-pos;
    }
}
int query(int id,int pos) {
    int sum = 0;
    while(pos>0)  sum+=tree[id][pos],pos-=pos&-pos;
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin>>n;
    for(int i = 0;i<n;i++) {
        ll a;
        cin>>a;
        ar[i+1]=__builtin_popcountll(a);
    }
    for(int i = 1;i<=n;i++) {
        sum[i]+=ar[i]+sum[i-1];
        update(sum[i]%2,i,n);
    }
    ll res = 0;
    int id = 0;
    for(int i = 1;i<=n;i++) {
        int j ;
        int tmp =0;
        int mx = 0;
        for(j = i;j<=n&&j<=i+66;j++) {
            tmp+=ar[j];
            mx = max(mx,ar[j]);
            if(mx>(tmp-mx)&&tmp%2==0) res--;
        }
        res+=(ll)(query(id,n)-query(id,i-1));
        id^=(ar[i]&1);
    }
    cout<<res<<endl;
    return 0;
}

