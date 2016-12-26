#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
int server[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(scanf("%d%d", &n, &q) == 2) {
        memset(server, 0, sizeof server);

        for(int i = 1; i <= q; ++i) {
            int t, k, d; scanf("%d%d%d", &t, &k, &d);
            int can = 0;
            for(int i = 1; i <= n; ++i) if(server[i] < t) ++can;
            if(can < k) puts("-1");
            else {
                int sum = 0;
                for(int i = 1; i <= n && k; ++i) {
                    if(server[i] < t) {
                        server[i] = t + d - 1;
                        sum += i;
                        k--;
                    }
                }
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}
