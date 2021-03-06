#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef complex<double> CP;
const int M = 1 << 19;
const double Pi = acos(-1.0);
CP a[M], c[M], w[M], temp[M];
long long ans, bb[M], cc[M], sum[N];
int n, root, size, tot, cnt, cnt2, po, pr[N], to[N << 1], nxt[N << 1], head[N], sz[N], dis[N], f[N];
bool vis[N], check[N];
void add(int u, int v) {
    to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
    to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
void fft(CP* p, int deep, int flag) {
    if (deep == po) return;
    int step = 1 << deep;
    fft(p, deep + 1, flag);
    fft(p + step, deep + 1, flag);
    int num= 1 << (po - deep);
    int ss = 0, half = num / 2;
    CP a,b;
    for (int i = 0; i < half; ++i) {
        a = p[ss];
        b = p[ss + step];
        if (!flag)  b *= w[i << deep];
        else b /= w[i << deep];
        temp[i] = a + b;
        temp[i + half] = a - b;
        ss += 2 * step;
    }
    for (int i = 0; i < num; ++i)   p[i * step] = temp[i];
    return;
}
void getroot(int u, int fa) {
    f[u] = 0, sz[u] = 1;
    for (int i = head[u], v; ~i; i = nxt[i]) {
        v = to[i];
        if (v != fa && !vis[v]) {
            getroot(v, u);
            sz[u] += sz[v];
            f[u] = max(f[u], sz[v]);
        }
    }
    f[u] = max(f[u], size - sz[u]);
    if (f[u] < f[root]) root = u;
}
void dfs(int u, int fa, int d) {
    dis[cnt++] = d;
    for (int i = head[u], v; ~i; i = nxt[i]) {
        v = to[i];
        if (v != fa && !vis[v]) dfs(v, u, d + 1);
    }
}
long long calc(int u, int d, int delta) {
    int mx = 0;
    long long t = 0;
    cnt = 0;
    dfs(u, 0, d);
    for (int i = 0; i < cnt; ++i)   ++sum[dis[i]], mx = max(mx, dis[i]);
    int l = 1;
    po = 0;
    while ((mx + 1) * 2 > l)    l <<= 1, ++po;
    for (int i = 0; i < l; ++i) w[i] = CP(cos(2 * Pi * i / l), sin(2 * Pi * i / l));
    for (int i = 0; i <= mx; ++i)   a[i] = CP(sum[i], 0.0);
    for (int i = mx + 1; i < l; ++i)    a[i] = CP(0.0, 0.0);
    fft(a, 0, 0);
    for (int i = 0; i < l; ++i) c[i] = a[i] * a[i];
    fft(c, 0, 1);
    for (int i = 0; i < l; ++i) bb[i] = (long long)round(c[i].real() / l);
    l = 2 * mx;
    for (int i = 0; i < cnt; ++i)   --bb[dis[i] << 1];
    for (int i = 0; i <= l; ++i)    bb[i] >>= 1;
    for (int i = 0; i <= mx; ++i)   sum[i] = 0;
    for (int i = 0; i <= l; ++i) cc[i] += delta * bb[i];
    for (int i = 0; i <= l; ++i)    bb[i] = 0;
    return t;
}
void gao(int u) {
    f[root = 0] = size;
    getroot(u, 0);
    calc(root, 0, 1);
    vis[root] = 1;
    for (int i = head[root], v; ~i; i = nxt[i]) {
        v = to[i];
        if (!vis[v]) {
            calc(v, 1, -1);
            size = sz[v];
            gao(v);
        }
    }
}
void init() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    size = n;
}
int main() {
    init();
    gao(1);
    ans = 0;
    for(int i = 1; i <= n; ++i) {
        // cout << i << "=" << cc[i] << endl;
        ans += (i + 1) / 2 * cc[i];
    }
    cout << ans << endl;
    return 0;
}
