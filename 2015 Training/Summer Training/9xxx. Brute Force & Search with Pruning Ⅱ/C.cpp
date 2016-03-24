//
//  Created by TaoSama on 2015-07-28
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, num[1005], cnt, maxd;

bool dfs(int cur, int dep) {
    if(dep >= maxd) return cur == n;
    int maxv = *max_element(num, num + cnt);
    if(maxv << maxd - dep < n) return false;

    for(int i = cnt - 1; i >= 0; --i) {
        num[cnt++] = cur + num[i];
        if(dfs(cur + num[i], dep + 1)) return true;
        --cnt;
        num[cnt++] = cur - num[i];
        if(dfs(cur - num[i], dep + 1)) return true;
        --cnt;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        for(maxd = __lg(n); ; maxd++) {
            cnt = 1; num[0] = 1;
            if(dfs(1, 0)) break;
        }
        cout << maxd << '\n';
    }
    return 0;
}
