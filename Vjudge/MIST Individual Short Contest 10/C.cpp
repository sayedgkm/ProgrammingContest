#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
int n;
int m ;
const int MOD = 1000000007;
ll dp[102][(1<<10)+10][10][2];
ll go(int pos,int mask,int last,int isStart) {
   // cout<<pos<<" " <<mask<<" " <<last<<" "<<isStart<<endl;
    if(pos==m) {
        return mask==(1<<n)-1;
    }
    ll &res = dp[pos][mask][last][isStart];
    if(res!=-1) return res;
    res = 0;
    if(isStart==0) {
        for(int i =0;i<n;i++) {
            res+=go(pos+1,i>0?mask|1<<i:mask,i,isStart|i>0);
        }
    } else {
        if(last+1<n) res+=go(pos+1,mask|1<<(last+1),last+1,isStart);
        if(last-1>=0) res+=go(pos+1,mask|1<<(last-1),last-1,isStart);
    }
    res%=MOD;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--) {


        cin>>n>>m;
        memset(dp,-1,sizeof(dp));
        cout<<go(0,0,0,0)<<endl;

    }

    return 0;
}

