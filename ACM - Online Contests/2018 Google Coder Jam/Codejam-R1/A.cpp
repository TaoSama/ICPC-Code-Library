
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[N][N], row[N], col[N], ka[N], kb[N];
int n, m, h, v;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
    //  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, m, h, v;
        cin >> n >> m >> h >> v;
        int tot = 0;
        for (int i = 1; i <= n; i++) row[i] = 0;
        for (int j = 1; j <= m; j++) col[j] = 0;
        for (int i = 1; i <= n; i++) {
            char buf[N]; cin >> (buf + 1);
            for (int j = 1; j <= m; j++) {
                int o = buf[j] == '@';
                a[i][j] = o;
                tot += o;
                row[i] += o;
                col[j] += o;
            }
        }
        static int kase = 0;
        if (tot % ((h + 1)*(v + 1)) != 0)
        {
            cout << "Case #" << ++kase << ": IMPOSSIBLE\n";
            continue;
        }
        int avg = tot / (h + 1) / (v + 1);
        int k1 = 1;
        int k2 = 1;
        int pa = tot / (h + 1);
        int pb = tot / (v + 1);
        int ta = pa, tb = pb;
        int flag = 1;
        auto check = [](int* row, int n, int& ta, int pa, int *ka, int& k1) {
            for (int i = 1; i <= n; i++)
            {
                row[i] += row[i - 1];
                if (row[i] < ta) continue;
                if (row[i] > ta)
                {
                    return false;
                    break;
                }
                ta += pa;
                ka[k1++] = i;
            }
            return true;
        };
        flag &= check(row, n, ta, pa, ka, k1);
        flag &= check(col, m, tb, pb, kb, k2);
        if (flag == 0) {
            cout << "Case #" << ++kase << ": IMPOSSIBLE\n";
            continue;
        }
        for (int i = 0; i + 1 < k1 && flag; i++) {
            for (int j = 0; j + 1 < k2 && flag; j++) {
                int sum = 0;
                for (int x = ka[i] + 1; x <= ka[i + 1]; x++) {
                    for (int y = kb[i] + 1; y <= kb[i + 1]; y++) {
                        sum += a[x][y];
                    }
                }
                if (sum != avg) flag = 0;
            }
        }
        cout << "Case #" << ++kase << ": " << (flag ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
    }
    return 0;
}
