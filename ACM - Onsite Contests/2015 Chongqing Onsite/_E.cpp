#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>

using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int maxn = 1010;

int dp[maxn][maxn], a[maxn], b[maxn], n, m;
vector<int> va[maxn], vb[maxn];
map<int, int> mp;

int main() {
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
    freopen("estdout.pc2", "w", stdout);
#endif // ONLINE_JUDGE
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        mp.clear();
        int cnt = 1;
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
            if(mp.count(a[i]) == 0) mp[a[i]] = cnt++;
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", b + i);
            if(mp.count(b[i]) == 0) mp[b[i]] = cnt++;
        }
        for(int i = 0; i < n; i++) a[i] = mp[a[i]];
        for(int i = 0; i < m; i++) b[i] = mp[b[i]];
        for(int i = 0; i < cnt; i++) {
            va[i].clear();
            vb[i].clear();
        }
        for(int i = 0; i < n; i++) va[a[i]].push_back(i);
        for(int i = 0; i < m; i++) vb[b[i]].push_back(i);
        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = 0;
        for(int i = n - 2; i >= 0; i--) for(int j = m - 2; j >= 0; j--) {
                dp[i][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i][j] = max(dp[i][j + 1], dp[i][j]);
                if(a[i] != b[j]) {
                    int pa = lower_bound(va[b[j]].begin(), va[b[j]].end(), i) - va[b[j]].begin();
                    int pb = lower_bound(vb[a[i]].begin(), vb[a[i]].end(), j) - vb[a[i]].begin();
                    if(pa != va[b[j]].size() && pb != vb[a[i]].size()) {
                        dp[i][j] = max(dp[i][j], dp[va[b[j]][pa] + 1][vb[a[i]][pb] + 1] + 2);
                    }
                }
            }
        printf("%d\n", dp[0][0]);
    }
    return 0;
}
