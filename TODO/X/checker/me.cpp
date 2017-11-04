#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct FastIO {
    static const int S = 5 << 20; //MB
    int wpos; char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if(pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if(pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while(~c && c <= 32) c = xchar();
        for(; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while(c <= 32) c = xchar();
        if(c == '-') s = -1, c = xchar();
        for(; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char* s) {
        int c = xchar();
        while(c <= 32) c = xchar();
        for(; c > 32; c = xchar()) * s++ = c;
        *s = 0;
    }
    inline void wchar(int x) {
        if(wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void wint(int x) {
        if(x < 0) wchar('-'), x = -x;

        char s[24];
        int n = 0;
        while(x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while(n--) wchar(s[n]);
    }
    inline void wstring(const char* s) {
        while(*s) wchar(*s++);
    }
    ~FastIO() {
        if(wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;


int n, q;
vector<int> G[N];
set<int> s[N];
vector<pair<int, int> > qs[N];
int ans[N];

void dfs(int u, int fa, int val) {
    s[u].insert(val);
    s[u].insert(-INF);
    s[u].insert(INF);
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u, 1LL * val * v % 20161119);

        if(s[u].size() < s[v].size()) swap(s[u], s[v]);
        for(set<int>::iterator iter = s[v].begin(); iter != s[v].end(); ++iter)
            s[u].insert(*iter);
        s[v].clear();
    }

    for(int i = 0; i < qs[u].size(); ++i) {
        pair<int, int>& p = qs[u][i];
        int v = p.first, id = p.second;
        int r = *s[u].upper_bound(v);
        int l = *--s[u].lower_bound(v);
        ans[id] = min(r - v, v - l);
    }
}

int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    while(true) {
//        n = io.xuint();
//        if(!n) break;
//        for(int i = 1; i <= n; ++i) {
//            G[i].clear();
//            s[i].clear();
//            qs[i].clear();
//        }
//        for(int i = 1; i < n; ++i) {
//            int u = io.xuint(), v = io.xuint();
//            G[u].push_back(v);
//            G[v].push_back(u);
//        }
//        q = io.xuint();
//        for(int i = 1; i <= q; ++i) {
//            int u = io.xuint(), val = io.xuint();
//            qs[u].push_back(make_pair(val, i));
//        }
//        dfs(1, -1, 1);
//        for(int i = 1; i <= q; ++i) {
//            io.wint(ans[i]);
//            io.wchar('\n');
//        }
//    }

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            s[i].clear();
            qs[i].clear();
        }
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d", &q);
        for(int i = 1; i <= q; ++i) {
            int u, val; scanf("%d%d", &u, &val);
            qs[u].push_back(make_pair(val, i));
        }
        dfs(1, -1, 1);
        for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
