#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, s;
vector<pair<int, int>> G[2][N];
typedef long long LL;

LL f[2][N];
bool done[N];

typedef pair<int, int> Sta;
void dijkstra(int idx) {
    priority_queue<Sta, vector<Sta>, greater<Sta>> q;
    memset(f[idx], 0x3f, sizeof f[idx]);
    memset(done, 0, sizeof done);
    q.push({0, s}); f[idx][s] = 0;
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(auto& e : G[idx][u]) {
            int v, c; tie(v, c) = e;
            if(f[idx][v] > f[idx][u] + c) {
                f[idx][v] = f[idx][u] + c;
                q.push({f[idx][v], v});
            }
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &s);
        for(int i = 1; i <= n; ++i) G[0][i].clear(), G[1][i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[0][u].push_back({v, c});
            G[1][v].push_back({u, c});
        }
        dijkstra(0);
        dijkstra(1);

        LL ans = -1e18;
        for(int i = 1; i <= n; ++i) {
            assert(f[0][i] <= 1e15);
            assert(f[1][i] <= 1e15);
            ans = max(ans, f[0][i] + f[1][i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
