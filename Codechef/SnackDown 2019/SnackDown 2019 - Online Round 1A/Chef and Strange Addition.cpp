#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
int mxPos;
bool isPossible(int x,int y,int &carry,int need) {
    if(x+y+carry==0) {
        if(need==0){
            carry = 0;
            return true;
        }
    }
    if(x+y+carry==1&&need==1) {
        carry = 0;
        return true;
    }
    if(x+y+carry==2&&need==0) {
        carry = 1;
        return true;
    }
    if(x+y+carry==3&&need==1) {
        carry = 1;
        return true;
    }
    return false;
}
int c;
long long dp[32][32][32][2];
ll go(int pos,int bita,int bitb,int carry) {
   // cout<<pos<< ' '<<bita<<" "<<bitb<< ' '<<carry<<endl;
    if(pos>mxPos) {
        return bita==0&&bitb==0&&carry==0;
    }
    ll &res = dp[pos][bita][bitb][carry];
    if(res!=-1) return res;
    res = 0;
    int nc = carry;
    if((c&(1<<pos))==0) {
        nc = carry;
        if(bita&&bitb&&isPossible(1,1,nc,0))
            res+=go(pos+1,bita-1,bitb-1,nc);
        nc = carry;
        if(bita&&isPossible(1,0,nc,0))
            res+=go(pos+1,bita-1,bitb,nc);
        nc = carry;
        if(bitb&&isPossible(0,1,nc,0))
            res+=go(pos+1,bita,bitb-1,nc);
        nc = carry;
        if(isPossible(0,0,nc,0)){

            res+=go(pos+1,bita,bitb,nc);
        }

    } else {
        nc = carry;
        if(bita&&bitb&&isPossible(1,1,nc,1))
            res+=go(pos+1,bita-1,bitb-1,nc);
        nc  = carry;
        if(bita&&isPossible(1,0,nc,1))
            res+=go(pos+1,bita-1,bitb,nc);
        nc = carry;
        if(bitb&&isPossible(0,1,nc,1))
            res+=go(pos+1,bita,bitb-1,nc);
        nc = carry;
        if(isPossible(0,0,nc,1))
            res+=go(pos+1,bita,bitb,nc);

    }
     return res;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--) {

        int a,b;
        cin>>a>>b>>c;
        for(int i = 31;i>=0;i--) {
            if(c&(1<<i)) {
                mxPos = i;
                break;
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<go(0,__builtin_popcount(a),__builtin_popcount(b),0)<<endl;
    }



    return 0;
}
