//
//  Created by TaoSama on 2017-04-29
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int M = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = M << 4;

int n, w[N];
typedef long long LL;
LL ans[N];

namespace FFT {
    const int G = 3, P = 1004535809;
    LL quick(LL x, LL n) {
        LL ret = 1;
        for(; n; n >>= 1) {
            if(n & 1) ret = ret * x % P;
            x = x * x % P;
        }
        return ret;
    }

    int len;
    LL A[N], B[N];
    void rader(LL* y, int len) {
        for(int i = 1, j = len / 2; i < len - 1; i++) {
            if(i < j) swap(y[i], y[j]);
            int k = len / 2;
            while(j >= k) {j -= k; k /= 2;}
            if(j < k) j += k;
        }
    }
    void ntt(LL* y, int len, int op) {
        rader(y, len);
        for(int h = 2; h <= len; h <<= 1) {
            LL wn = quick(G, (P - 1) / h);
            if(op == -1) wn = quick(wn, P - 2);
            for(int j = 0; j < len; j += h) {
                LL w = 1;
                for(int k = j; k < j + h / 2; k++) {
                    LL u = y[k];
                    LL t = w * y[k + h / 2] % P;
                    y[k] = (u + t) % P;
                    y[k + h / 2] = (u - t + P) % P;
                    w = w * wn % P;
                }
            }
        }
        if(op == -1) {
            LL inv = quick(len, P - 2);
            for(int i = 0; i < len; i++) y[i] = y[i] * inv % P;
        }
    }
}

struct Edge {
    int v, nxt;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}

bool vis[N];
int sz[N], mx[N], centroid;

int getAll(int u, int f) {
    int ret = 1;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        ret += getAll(v, u);
    }
    return ret;
}

void getCentroid(int u, int f, int all) {
    sz[u] = 1; mx[u] = 0;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        getCentroid(v, u, all);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], all - sz[u]);
    if(!centroid || mx[u] < mx[centroid]) centroid = u;
}

void getDs(int u, int f, int dis, vector<pair<int, int>>& ds) {
    ds.push_back({dis, u});
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        getDs(v, u, dis + 1, ds);
    }
}

struct CNT {
    int num[N], vis[N], timStp;
    inline void init() { timStp = 0;}
    inline void newOne() {++timStp;}
    inline void lazyClear(int x) {
        if(vis[x] != timStp) vis[x] = timStp, num[x] = 0;
    }
    int& operator[](int k) { return num[k]; }
} num;

void calc(vector<pair<int, int>>& ds, int delta) {
    num.newOne();
    int maxdepth = 0;
    for(const auto& p : ds) {
        int x, u; tie(x, u) = p;
        num.lazyClear(x); ++num[x];
        maxdepth = max(maxdepth, x);
    }
    assert(ds.size() >= maxdepth);

    for(FFT::len = 1; FFT::len <= maxdepth << 1; FFT::len <<= 1);

    for(int i = 0; i < FFT::len; ++i) {
        num.lazyClear(i);
        FFT::A[i] = num[i];
        FFT::B[i] = w[FFT::len - i - 1];
    }
    FFT::ntt(FFT::A, FFT::len, 1);
    FFT::ntt(FFT::B, FFT::len, 1);
    for(int i = 0; i < FFT::len; ++i) FFT::A[i] = FFT::A[i] * FFT::B[i];
    FFT::ntt(FFT::A, FFT::len, -1);

    for(const auto& p : ds) {
        int x, u; tie(x, u) = p;
        ans[u] += delta * FFT::A[FFT::len - x - 1];
    }
}


void solve(int u) {
    centroid = 0;
    getCentroid(u, -1, getAll(u, -1));

    int s = centroid;
    vis[s] = true;

    for(int i = head[s]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;
        solve(v);
    }
    vector<pair<int, int>> ds; ds.push_back({0, s});
    for(int i = head[s]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;
        vector<pair<int, int>> tds;
        getDs(v, s, 1, tds);
        calc(tds, -1);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }
    calc(ds, 1);
    vis[s] = false;
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", w + i);
    cnt = 0; memset(head, -1, sizeof head);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    num.init();
    solve(1);
    for(int i = 1; i <= n; ++i) printf("%lld%c", ans[i], " \n"[i == n]);
}
