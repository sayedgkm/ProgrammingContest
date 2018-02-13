#include<bits/stdc++.h>
#define N 200010
using namespace std;
set<int>st[500];
int tree[N];
void update(int i,int limit,int val) {
    while(i<=limit) {
        tree[i] += val;
        i+=(i)&(-i);
    }
}
int query(int i) {
    int sum = 0;
    while(i>0) {
        sum+=tree[i];
        i-=(i)&(-i);
    }
    return sum;
}
int go(int x) {
    int b = 1;
    int e = N-1;
    while(b<=e) {
        int mid = (b+e)/2;
        int val = query(mid);
        if(val>=x) e = mid-1;
        else b = mid+1;
    }
    return b;
}
int main() {


    int n ,m;
    scanf("%d %d",&n,&m);
    string s;
    cin>>s;
    s= ' '+s;
    for(int i = 1;i<=n;i++){
        st[s[i]].insert(i);
    }
    for(int i = 1;i<=n;i++) {
        update(i,N-1,1);
    }
    //cout<<query(n)<<endl;
    while(m--) {
        char c[2];
        int x,y;
        scanf("%d %d",&x,&y);
        scanf("%s",c);
        int l = go(x);
        int r = go(y);
      //  cout<<l<<" "<<r<<endl;
        char t = c[0];
        auto it1= st[t].lower_bound(l);
        auto it2 = st[t].upper_bound(r);
        vector<int > v;
        while(true) {
            if(it1==it2) break;
            v.push_back(*it1);
            it1++;
        }
        for(int i = 0;i<v.size();i++) {
            update(v[i],N-1,-1);
            st[t].erase(v[i]);
        }


    }
    for(int i = 1;i<=n;i++) {
        if(st[s[i]].find(i)!=st[s[i]].end()) {
            printf("%c",s[i]);
        }
    }
        printf("\n");
    return 0;
}