#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
struct twod{
    ll mat[22][22];
    void CLE() {
        memset(mat,0,sizeof(mat));
    }
    void init(int n,int m){ /// 1 based index
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int i = 1;i<=m;i++) {
            for(int j = 1;j<=n;j++){
                mat[j][i]+=mat[j-1][i];
            }
        }
    }
    void print(int n,int m) {
        cout<<"*****"<<endl;
        for(int i =1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                printf("%lld ",mat[i][j]);
            }
            printf("\n");
        }
    }
   ll getsum(int x1,int y1,int x2,int y2){
      return mat[x2][y2]+mat[x1-1][y1-1]-mat[x2][y1-1]-mat[x1-1][y2];
    }
}S[25];
ll kadane(vector<ll> &v) {
    ll sum =-3e17;
    for(auto it : v) sum = max(sum,it);
    if(sum<0) return sum;
    ll tmpSum = 0;
    for(int i = 0;i<v.size();i++) {
        tmpSum+=v[i];
        sum = max(sum,tmpSum);
        if(tmpSum<0) tmpSum =0;
    }
    return sum;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;int cs = 0;
    while(test--) {

        int n ,m,o;
        cin>>n>>m>>o;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                for(int k = 1;k<=o;k++) {
                        cin>>S[i].mat[j][k];
                }
            }
            S[i].init(m,o);
        }

        ll ans = -3e18;
        for(int i = 1;i<=m;i++) {
            for(int j = 1;j<=o;j++) {
                for(int k = i;k<=m;k++) {
                    for(int l = j;l<=o;l++) {
                        vector<ll> v;
                        for(int x = 1;x<=n;x++) {
//                            cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
//                            cout<<x<<" = "<<S[x].getsum(i,j,k,l)<<endl;
                            v.push_back(S[x].getsum(i,j,k,l));
                        }
                        ans = max(ans,kadane(v));
                    }
                }
            }
        }
        if(cs) cout<<endl;
        cs = 1;
        cout<<ans<<endl;
        for(int i =1;i<=20;i++) S[i].CLE();

    }

    return 0;
}

