#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, minv[N][10][2];


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    cin >> n;
    memset(minv, 0x3f, sizeof minv);
    for(int j = 0; 1 << j <= n; ++j) {
        vector<int> qs[2];
        for(int i = 1; i <= n; ++i) {
            qs[i >> j & 1].push_back(i);
        }
        auto query = [&](int b) {
            cout << qs[b].size() << endl;
            for(int x : qs[b]) cout << x << ' '; cout << endl;
            for(int i = 1; i <= n; ++i) cin >> minv[i][j][b];
        };
        query(0); query(1);
    }

    cout << -1 << endl;
    for(int i = 1; i <= n; ++i) {
        int val = INF;
        for(int j = 0; 1 << j <= n; ++j) {
            val = min(val, minv[i][j][i >> j & 1 ^ 1]);
        }
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}
