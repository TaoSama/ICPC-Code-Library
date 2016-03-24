//
//  Created by TaoSama on 2015-08-04
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N], full[N], ans[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i) scanf("%d", a + i);
        set<int> s;
        memset(ans, 0, sizeof ans);
        memset(full, 0, sizeof full);
        bool ok = true;
        for(int i = 1; i <= m; ++i) {
//          prln(a[i]);
            if(a[i]) {
                int last = full[a[i]];
//              prln(last);
//              for(auto &x: s) cout << x << ' '; cout << endl;
                auto iter = s.upper_bound(last);
                if(iter == s.end()) {
                    ok = false;
                    break;
                }
//              prln(*iter);
                ans[*iter] = a[i];
                full[a[i]] = i;  //update the time;
                s.erase(iter);
            } else s.insert(i);
        }
        if(ok) {
            puts("YES");
            bool first = true;
            for(int i = 1; i <= m; ++i) {
                if(!a[i]) {
                    if(!first) putchar(' ');
                    else first = false;
                    printf("%d", ans[i]);
                }
            }
            puts("");
        } else puts("NO");
    }
    return 0;
}
