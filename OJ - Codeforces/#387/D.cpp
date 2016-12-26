#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, a[N];
int can[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(scanf("%d%d", &n, &k) == 2) {
        int neg = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            neg += a[i] < 0;
        }
        memset(can, 0, sizeof can);

        if(k < neg) {puts("-1"); continue;}
        if(neg == 0) {puts("0"); continue;}

        k -= neg;
        vector<pair<int, int> > v;
        int last = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] < 0) {
                if(last) v.push_back({last, i});
                last = i;
            }
        }
        typedef pair<int, int> P;
        sort(v.begin(), v.end(), [](P A, P B) {
            return A.second - A.first < B.second - B.first;
        });

        for(auto& p : v) {
            int sz = p.second - p.first - 1;
            if(sz <= k) {
                can[p.first + 1]++;
                can[p.second]--;
                k -= sz;
            }
        }
        int sz = n - last;
        if(sz <= k) {
            can[last + 1]++;
            can[n + 1]--;
        }
        for(int i = 1; i <= n; ++i) can[i] += can[i - 1];

        int ans = 0, sta = 0;
        for(int i = 1; i <= n; ++i) {
            if(!sta) {
                if(a[i] < 0) ++ans, sta = 1;
            } else {
                if(a[i] < 0) {}
                else if(can[i]) {}
                else ++ans, sta = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
