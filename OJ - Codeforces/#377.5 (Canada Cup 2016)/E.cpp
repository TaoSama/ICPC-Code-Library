#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int c, n;
int cnt[N], can[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(scanf("%d%d", &c, &n) == 2) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++cnt[x];
        }

        int last = 0;
        for(int i = 1; i <= c; ++i) {
            if(cnt[i]) last = i;
            can[i] = last;
        }

        int ans = 0;
        for(int i = 1; i < c && !ans; ++i) {
            bool took = false;
            int lft = c, act = c;
//            prln(i);
            while(lft > 0) {
                int cur = can[act];
//                prln(act);
                if(i >= cur && i <= lft && !took) {
                    took = true;
                    lft -= i;
                    act = min(lft, i);
//                    printf("took = %d lft = %d\n", i, lft);
                } else {
                    if(!cur) break;
                    int times = min(cnt[cur], lft / cur);
                    lft -= times * cur;
                    act = min(lft, cur - 1);
//                    printf("took = %d * %d lft = %d\n", cur, times, lft);
                }
            }
            if(lft) ans = i;
        }
        if(ans) printf("%d\n", ans);
        else puts("Greed is good");

//        return 0;
    }
    return 0;
}
