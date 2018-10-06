#include<bits/stdc++.h>
#define ll long long
#define M  (int)1e9+7
using namespace std;
int n;
string s;
int mx=0;
int sum = 0;
int dp[202][202][205][2];
int go(int pos,int open,int ind,int f) {

    if(pos>2*n) return 0;
    if(ind>=(int)s.length()) return 0;
    if(pos==2*n)
        return f&&open==0;
    if(dp[pos][open][ind][f]!=-1) return dp[pos][open][ind][f];
    ll res = 0;


    return dp[pos][open][ind][f]=(int)res;
}
int main(){

    cin>>n;
    cin>>s;
    for(char i : s){
        if(i=='(') sum++;
        else sum--;
        mx = max(mx,-sum);
    }
    memset(dp,-1,sizeof(dp));
    cout<<go(0,0,0,0)<<endl;


    return 0;
}
