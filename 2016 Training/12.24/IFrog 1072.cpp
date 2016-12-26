#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];

pair<int, int> add[N << 2];
pair<int, int> val[N << 2];

void down(int rt) {
    if(!add[rt].first) return;
    int ls = rt << 1, rs = ls | 1;
    if(add[rt].first == -INF) {
        val[ls] = val[rs] = add[ls] = add[rs] = add[rt];
    } else if(add[rt].first) {
        add[ls] = max(add[ls], add[rt]);
        add[rs] = max(add[rs], add[rt]);
        val[ls] = max(val[ls], add[rt]);
        val[rs] = max(val[rs], add[rt]);
    }
    add[rt] = {0, 0};
}

void up(int rt) {
    val[rt] = max(val[rt << 1], val[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    add[rt] = val[rt] = {0, 0};
    if(l == r) return;
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

void update(int L, int R, pair<int, int> v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        if(v.first == -INF) {
            val[rt] = v;
            add[rt] = v;
        } else {
            val[rt] = max(val[rt], v);
            add[rt] = max(add[rt], v);
        }
        return;
    }
    down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, l, m, rt << 1);
    if(R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
    up(rt);
}

int dep[N], dfn[N], odfn[N], vs[N], dfsNum;

void dfs(int u, int f) {
    dfn[u] = ++dfsNum;
    vs[dfsNum] = u;
    dep[u] = dep[f] + 1;
    for(int v : G[u]) dfs(v, u);
    odfn[u] = dfsNum;
}

int op[N], u[N], v[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n + 5; ++i) G[i].clear();
        int idx = 1;
        for(int i = 1; i <= n; ++i) {
            char buf[10]; scanf("%s", buf);
            op[i] = *buf == '+';
            u[i] = atoi(buf + 1);
            if(op[i]) {
                v[i] = ++idx;
                G[u[i]].push_back(v[i]);
            }
        }

        dfsNum = 0;
        dfs(1, 0);
        build(1, idx, 1);

        update(dfn[1], dfn[1], {dep[1], -1}, 1, idx, 1);
        for(int i = 1; i <= n; ++i) {
            if(op[i]) {
                int x = v[i];
//                printf("u = %d id = %d dep = %d\n", x, dfn[x], dep[x]);
                update(dfn[x], dfn[x], {dep[x], -x}, 1, idx, 1);
            } else {
                int x = u[i];
//                pr(dfn[x]); prln(odfn[x]);
                update(dfn[x], odfn[x], { -INF, -INF}, 1, idx, 1);
            }
            printf("%d\n", -val[1].second);
        }
    }
    return 0;
}
