//
//  Created by TaoSama on 2016-07-30
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int ans[5][N];

int nxt(int delta) {
    static int o = 0;
    return (o++) % 5 + delta;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n + 1; i += 2) {
            if(i + 1 <= n) {
                for(int j = 1; j <= 2; ++j)
                    ans[j][i] = ans[j][i + 1] = nxt(0);
            } else {
                ans[1][i] = ans[2][i] = nxt(0);
            }
        }
        ans[3][1] = ans[4][1] = nxt(5);
        for(int i = 2; i <= n + 1; i += 2) {
            if(i + 1 <= n) {
                for(int j = 3; j <= 4; ++j)
                    ans[j][i] = ans[j][i + 1] = nxt(5);
            } else {
                ans[3][i] = ans[4][i] = nxt(5);
            }
        }
        for(int i = 1; i <= 4; ++i) {
            for(int j = 1; j <= n; ++j)
                printf("%c", 'a' + ans[i][j]);
            puts("");
        }
    }

    return 0;
}
