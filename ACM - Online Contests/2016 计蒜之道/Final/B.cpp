//
//  Created by TaoSama on 2016-07-03
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a, b, c;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);

        int ans = 0;
        while(c > 0) {
            if(a < b) swap(a, b);
            if(a != b) { //AB AC
                int x = min(c, min(a / 3, b / 2));
                x = min(x, abs(a - b));
                ans += 2 * x;
                a -= 3 * x, b -= 2 * x, c -= x;
                if(x == 0) break;
            } else { //ABAC
                int x = min(c / 2, a / 5);
                ans += 4 * x;
                a -= 5 * x, b -= 5 * x, c -= 2 * x;
                if(x == 0) break;
            }
        }
        if(a && b && c) ++ans, --a, --b, --c;

        int x = min(a / 3, b / 3); //BC
        ans += 2 * x;
        a -= 3 * x, b -= 3 * x;


        if(a >= 2 && b >= 1 || a >= 1 && b >= 2) ++ans;

        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
