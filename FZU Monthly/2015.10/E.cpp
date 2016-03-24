//
//  Created by TaoSama on 2015-10-06
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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m, a[100005], b[100005][2], all, gs;
bool vis[100005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        all = 0;
        memset(b, 0, sizeof(b));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if(a[i] > 0) {
                all++;
                b[a[i]][0]++;
            } else b[-a[i]][1]++;
        }
        gs = 0;
        for(int i = 1; i <= n; i++) {
            if(b[i][0] + n - all - b[i][1] == m) {
                vis[i] = true;
                gs++;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(vis[abs(a[i])]) {
                if(gs == 1) {
                    if(a[i] < 0) printf("Lie\n");
                    else printf("Truth\n");
                } else printf("Not defined\n");
            } else {
                if(a[i] > 0) printf("Lie\n");
                else printf("Truth\n");
            }
        }
    }
    return 0;
}
