//
//  Created by TaoSama on 2016-08-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
int cnt[N], last[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        int sum = 0;
        memset(cnt, 0, sizeof cnt);
        memset(last, 0, sizeof last);
        vector<pair<int, int> > v(q + 1);
        int ptr = 1, last3 = 0;
        for(int i = 1; i <= q; ++i) {
            int op, x; scanf("%d%d", &op, &x);
            v[i] = {op, x};
            if(op == 1) {
                sum += 1;
                cnt[x] += 1;
            } else if(op == 2) {
                last[x] = i;
                sum -= cnt[x];
                cnt[x] = 0;
            } else {
                for(; last3 < x; ++ptr) {
                    int t, y; tie(t, y) = v[ptr];
                    if(t == 1) {
                        if(last[y] < ptr) {
                            --cnt[y];
                            --sum;
                        }
                        ++last3;
                    }
                }
            }
            printf("%d\n", sum);
        }
    }

    return 0;
}
