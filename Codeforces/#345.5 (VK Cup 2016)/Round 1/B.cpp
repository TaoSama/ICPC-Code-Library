//
//  Created by TaoSama on 2016-03-29
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, k;
int t[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &k, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", t + i);
    set<int> s;
    while(q--) {
        int op, id; scanf("%d%d", &op, &id);
        if(op == 1) s.insert(t[id]);
        else {
            auto iter = s.rbegin();
            bool ok = false;
            for(int i = 1; i <= k && iter != s.rend(); ++i, ++iter) {
                if(*iter == t[id]) {
                    ok = true;
                    break;
                }
            }
            puts(ok ? "YES" : "NO");
        }
    }
    return 0;
}
