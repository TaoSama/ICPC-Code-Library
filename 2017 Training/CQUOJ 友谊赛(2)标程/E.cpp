#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int f[N][3][3];

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        memset(f, 0, sizeof f);
        f[0][0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= 2; ++j) {
                for(int k = 0; k <= 2; ++k) {
                    add(f[i][j + (i == 1 || i == n)][0], f[i - 1][j][k]);
                    if(k < 2) add(f[i][j][k + 1], f[i - 1][j][k]);
                }
            }
        }
        int ans = 0;
        for(int j = 1; j <= 2; ++j) {
            for(int k = 0; k <= 2; ++k) {
                add(ans, f[n][j][k]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
