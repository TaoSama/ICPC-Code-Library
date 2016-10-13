#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <deque>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, g[26][26];
char s[N];
int f[N][26];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%s", &n, s + 1);
    int k; scanf("%d", &k);
    while(k--) {
        char t[3]; scanf("%s", t);
        t[0] -= 'a'; t[1] -= 'a';
        g[t[0]][t[1]] = g[t[1]][t[0]] = 1;
    }

    for(int i = 0; i < 26; ++i) f[1][s[1] - 'a'] = 1;
    for(int i = 2; i <= n; ++i) {
        s[i] -= 'a';
        for(int j = 0; j < 26; ++j) {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            if(!g[s[i]][j]) f[i][s[i]] = max(f[i][s[i]], f[i - 1][j] + 1);
        }
    }
    int ans = -INF;
    for(int i = 0; i < 26; ++i) ans = max(ans, f[n][i]);
    printf("%d\n", n - ans);
    return 0;
}
