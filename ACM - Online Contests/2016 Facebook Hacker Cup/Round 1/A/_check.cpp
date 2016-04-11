#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int n, d[100005], f[100005];
int g(int i) {
    if(i < 0) return 0;
    return f[i];
}
void gao(int i, int j) {
    if(j == 1) {
        if(!(d[i - 1] < d[i])) return;
        if(d[i] - d[i - 1] <= 30) f[i] = min(f[i], g(i - j - 1) + 2);
    }
    if(j == 2) {
        if(!(d[i - 2] < d[i - 1] && d[i - 1] < d[i]))
            return;
        if(d[i] - d[i - 2] <= 20)
            f[i] = min(f[i], g(i - j - 1) + 1);
    }
    if(j == 3) {
        for(int k = i - 2; k <= i; ++k)
            if(!(d[k] - d[k - 1] > 0 && d[k] - d[k - 1] <= 10)) return;
        f[i] = min(f[i], g(i - j - 1));
    }
}
int solve() {
    scanf("%d", &n);
    f[0] = 3;
    for(int i = 0; i < n; ++i) scanf("%d", d + i);
    for(int i = 1; i < n; ++i) {
        f[i] = f[i - 1] + 3;
        for(int j = 1; j < 4 && i - j >= 0; ++j) {
            if(d[i - j] >= d[i])
                break;
            gao(i, j);
        }
    }
    return f[n - 1];
}
int main() {
    // freopen("in", "r", stdin);
//  freopen("coding_contest_creation.txt", "r", stdin);
//  freopen("out", "w", stdout);
    int T; scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_)
        printf("Case #%d: %d\n", _, solve());
    return 0;
}
