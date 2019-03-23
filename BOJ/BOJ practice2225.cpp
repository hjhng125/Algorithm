#include <iostream>
#include <cstring>

using namespace std;

int dp[201][201];
int n,k;
int solve(int n,int k){

    if (k == 1) return 1;
    int& ret = dp[n][k];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= n; ++i) {
        ret = (ret + solve(n - i, k - 1)) % 1000000000;
    }
    return ret;
}

int main(){

    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << solve(n,k);
    return 0;
}