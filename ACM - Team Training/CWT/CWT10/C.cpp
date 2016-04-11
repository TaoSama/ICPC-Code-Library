//
//  Created by TaoSama on 2016-02-12
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

typedef long long LL;
LL h, n, ans;

//0->left 1->right
void dfs(LL o, bool dir, LL l, LL r) {
//  pr(l);prln(r);
    if(l == r) return;
    LL m = l + r >> 1;
    if(o <= m) {
        if(dir == 0) ++ans;
        else ans += r - m << 1;
        dfs(o, 1, l, m);
    } else {
        if(dir == 0) ans += m + 1 - l << 1;
        else ++ans;
        dfs(o, 0, m + 1, r);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> h >> n) {
        ans = 0;
        dfs(n, 0, 1, 1LL << h);
        cout << ans << endl;
    }
    return 0;
}
