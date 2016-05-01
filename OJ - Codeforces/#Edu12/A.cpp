//
//  Created by TaoSama on 2016-04-20
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int a, ta, b, tb;
int h, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d%d:%d", &a, &ta, &b, &tb, &h, &m) == 6) {
        int st = 5 * 60, ed = 24 * 60;
        int x = h * 60 + m, y = x + ta;
//      pr(x);prln(y);
        int ans = 0;
        while(st < ed) {
            int tmp = st + tb;
            if(tmp > x && st < y) ++ans;
            st += b;
        }
        printf("%d\n", ans);
    }
    return 0;
}
