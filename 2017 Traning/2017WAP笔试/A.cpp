#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10, MOD = 1e9 + 7;
int f[N][N];

int solve(string s) {
    int n = s.size(), ans = 0;
    for(int k = 1; k <= n; ++k) {
        if(k == 1 || k == n) {
            ans = (ans + 1) % MOD;
            continue;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                f[i][j] = 0;
                if(i == k && j >= k || i <= k && j == k) f[i][j] = 1;
            }
        }
        for(int l = 2; l <= n; ++l) {
            for(int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                if(i < k && j > k) {
                    if(s[i - 1] == s[j - 1])
                        f[i][j] = f[i + 1][j] + f[i][j - 1];
                    else f[i][j] = f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
                    f[i][j] %= MOD;
                    if(f[i][j] < 0) f[i][j] += MOD;
                }
            }
        }
//        if(k == 2) {
//            for(int l = 1; l <= n; ++l)
//                for(int i = 1; i + l - 1 <= n; ++i)
//                    printf("f[%d][%d] = %d\n", i, i + l - 1, f[i][i + l - 1]);
//            printf("f[%d][%d] = %d\n", 2, 2, f[2][2]);
//            printf("f[%d][%d] = %d\n", 1, 3, f[1][3]);
//        }
//        printf("%d: %d\n", k, f[1][n]);
        ans = (ans + f[1][n]) % MOD;
    }
    return ans;
}
int main() {
    string line;
//  cin >> line;
    cout << solve("axbcba") << endl;
    return 0;
}
