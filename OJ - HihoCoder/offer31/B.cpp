#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
char a[400][401];
char c[400][400];

int d[400][400], vis[400][400], timStp;
void lazyClear(int x, int y) {
    if(vis[x][y] != timStp) {
        vis[x][y] = timStp;
        d[x][y] = INF;
    }
}

static const int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
int bfs(int sx, int sy, int gx, int gy) {
    ++timStp;
    queue<pair<int, int>> q;
    lazyClear(sx, sy);
    lazyClear(gx, gy);
    d[sx][sy] = 0;
    q.push({sx, sy});
    while(q.size()) {
        int x, y; tie(x, y) = q.front();
        q.pop();
        // cout << x << ' ' << y << endl;
        if(x == gx && y == gy) return d[x][y];
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 1) continue;
            lazyClear(nx, ny);
            if(d[nx][ny] == INF) {
                d[nx][ny] = d[x][y] + 1;
                if(nx == gx && ny == gy) return d[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    return d[gx][gy];
}
int d1[20], d2[20];
int d2d[20][20];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        for(int j = 0; j < m; ++j) a[i][j] -= '0';
    }
    vector<pair<pair<int, int>, int>> v;
    for(int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        c[x][y] |= 1 << i;
        v.push_back({{x, y}, i});
    }
    for(int i = 0; i < k; ++i) {
        int x, y; tie(x, y) = v[i].first;
        d1[i] = bfs(0, 0, x, y); 
        d2[i] = bfs(x, y, n - 1, m - 1);
        // cout << d1[i] << ' ' << d2[i] << endl;
        for(int j = 0; j < k; ++j) {
            int nx, ny; tie(nx, ny) = v[j].first;
            d2d[i][j] = bfs(x, y, nx, ny);
            // cout << i << ' ' << j << d2d[i][j] << endl;
        }
    }
    long long ans = INF;
    if(k == 0) ans = bfs(0, 0, n - 1, m - 1);
    else {
        sort(v.begin(), v.end());
        do {
            long long cur = 0;
            cur += d1[v.front().second] + d2[v.back().second];
            for(int i = 0; i + 1 < k; ++i) {
                cur += d2d[v[i].second][v[i + 1].second];
            }
            ans = min(ans, cur);
        }while(next_permutation(v.begin(), v.end()));
        
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
