#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int sum(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}
int mul(int a, int b) {
    return (1LL*a*b)%MOD;
}
int pw(int a, int b) {
	if (!b) return 1;
	int r = pw(a, b/2);
	r = mul(r, r);
	if (b%2) r = mul(r, a);
	return r;
}

const int MAXN = 2e6+7;
int dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int n = 3; n < MAXN; n++) {
        dp[n] = sum(dp[n-1], mul(dp[n-2], 2));
        if (n%3==0) dp[n] = sum(dp[n], 1);
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << mul(dp[n], 4) << "\n";
    }




    return 0;
}
