//
//  Created by TaoSama on 2015-07-20
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

int n, m;
int s[10005][15];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        getchar();
        char x[105], comma;
        map<string, int> dict; int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < m; ++j) {
                scanf("%[^,]%c", x, &comma);
                string t(x);
                if(!dict.count(t)) dict[t] = ++cnt;
                s[i][j] = dict[t];
//                cout << s[i][j] << ' ' ;
            }
            scanf("%[^\n]", x); string t(x);
            getchar();
            if(!dict.count(t)) dict[t] = ++cnt;
            s[i][m] = dict[t];
//            cout << s[i][m] << endl;
        }
//        cout << endl;

        int c1, c2, r1, r2;
        bool ok = true;
        for(int i = 1; i < m; ++i) {
            for(int j = i + 1; j <= m; ++j) {
                map<pair<int, int>, int> mp;
                for(int k = 1; k <= n; ++k) {
                    int x = s[k][i], y = s[k][j];
                    if(!mp.count({x, y})) {
                        mp[ {x, y}] = k;
//                        cout << s[k][i] << ' ' << s[k][j] << endl;
                    }
                    else {
//                      cout << "same " << s[k][i] << ' ' << s[k][j] << endl;
                        c1 = i, c2 = j;
//                      cout << i << ' ' << j << endl;
                        r1 = mp[ {x, y}], r2 = k;
//                        cout << r1 << ' ' << r2 << endl;
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(ok)  puts("YES");
        else printf("NO\n%d %d\n%d %d\n", r1, r2, c1, c2);
    }
    return 0;
}
