//
//  Created by TaoSama on 2015-06-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;
bool a[105][105], t[105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%1d", &a[i][j]);

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            memcpy(t, a, sizeof a);
            for(int j = 1; j <= n; ++j) {
                if(!a[i][j]) {
                    for(int k = 1; k <= n; ++k) {
                        t[k][j] ^= 1;
                    }
                }
            }
            int cnt = 0;
            for(int j = 1; j <= n; ++j) {
                bool ok = true;
                for(int k = 1; k <= n; ++k) {
                    if(!t[j][k]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) ++cnt;
            }
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
    }
    return 0;
}
