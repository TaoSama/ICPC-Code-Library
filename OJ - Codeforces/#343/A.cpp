//
//  Created by TaoSama on 2016-02-22
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[105][105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            int cnt = 0;
            for(int j = 1; j <= n; ++j)
                cnt += s[i][j] == 'C';
            ans += cnt * (cnt - 1) >> 1;
        }
        for(int j = 1; j <= n; ++j) {
            int cnt = 0;
            for(int i = 1; i <= n; ++i)
                cnt += s[i][j] == 'C';
            ans += cnt * (cnt - 1) >> 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}