#include <bits/stdc++.h>
using namespace std;
const int N = 13 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<vector<int>> g{
    {2, 3},
    {2, 5},
    {0, 1, 3, 5, 6},
    {0, 2, 4, 6, 7}, // 3
    {3, 7},
    {1, 2, 6, 8, 9},
    {2, 3, 5, 7, 9, 10}, // 6
    {3, 4, 6, 10, 11},
    {5, 9},
    {5, 6, 8, 10, 12}, // 9
    {6, 7, 9, 11, 12},
    {7, 10},
    {9, 10}
};
vector<int> can[N];
int o[N], need[N];

int vis[N], visCol[N];
vector<int> actList;
void dfs(int u, int p, int act, int actId, int& ans) {
    if(vis[u] != -1) return;
    if(ans == 5) return;
    
    for(int x : can[actId]) {
        vis[u] = x;
        for(int v : g[u]) dfs(v, p + 1, act, 5, ans);
    }
    if(act < 5) {
        actList.emplace_back(u);
        for(int i = 0; i < 5; ++i) {
            if(visCol[i] || need[i] > g[u].size()) continue;
            visCol[i] = true;
            vis[u] = i;
            for(int v : g[u]) {
                dfs(v, p + 1, act + 1, i, ans);
            }
            visCol[i] = false;
        }
        actList.pop_back();
    }
    if(p == 12) {
        bool ok = true;
        // for(int x : actList) cout << x << ' '; cout << endl;
        for(int x : actList) {
            int wh = vis[x];
            int col[N] = {};
            for(int v : g[x]) if(~vis[v]) col[vis[v]] = 1;
            for(int y : can[wh]) {
                ok &= col[y];
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(ok) ans = max(ans, act);
    }
    vis[u] = -1;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < 5; ++i) {
            cin >> o[i] >> need[i];
            can[i].clear();
            for(int j = 0; j < 6; ++j) {
                int x; cin >> x;
                if(x) can[i].push_back(j);
            }
        }
        can[5] = {0, 1, 2, 3, 4, 5};

        int ans = 0;
        actList.clear();
        memset(vis, -1, sizeof vis);
        dfs(6, 0, 0, 5, ans);
        cout << ans << endl;
    }
    return 0;
}
