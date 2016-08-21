//
//  Created by TaoSama on 2016-08-21
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, L;
int a[N];

bool check(int x) {
    vector<int> b(a, a + n);
    for(int t = 0; t < n; ++t) {
        int bk = b.back(); b.pop_back();
        b.insert(b.begin(), bk);

        int lft = m, ok = 1;
        for(int i = 0; i < n && ok;) {
            if(b[i] >= x) ++i;
            else {
                i += L;
                if(--lft < 0) ok = 0;
            }
        }
        if(ok) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &L);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int l = 1, r = 1e9 + 10, ans = -1;
    while(l <= r) {
        int m = l + r >> 1;
        if(check(m)) ans = m, l = m + 1;
        else r = m - 1;
    }
    printf("%d\n", ans);

    return 0;
}
