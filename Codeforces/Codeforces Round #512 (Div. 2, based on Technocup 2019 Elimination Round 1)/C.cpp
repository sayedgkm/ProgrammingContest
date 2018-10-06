#include <bits/stdc++.h>
#define    ll     long long int
#define    N      1000010
using namespace std;
int ar[N];
string s;
bool isPossible(int x) {
    int tot = 0;
    int i =0;
    int cnt = 0;
    while(i<s.size()) {
        if(tot<x) {
            tot+=s[i]-'0';
            i++;
        } else if(tot==x) {
            tot=0;
            cnt++;
            if(!x)i++;
        } else if(tot>x) {
            return false;
        }
    }

    if(tot==x) cnt++;
    if(cnt==1) return false;
   return tot==0||tot==x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    cin>>s;
    s+='0';
    int sum =0;
    for(int i =0;i<n-1;i++) {
        sum+=s[i]-'0';
        if(sum==0) continue;
        if(isPossible(sum)) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    if(sum==0&&s[n-1]=='0') {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}

