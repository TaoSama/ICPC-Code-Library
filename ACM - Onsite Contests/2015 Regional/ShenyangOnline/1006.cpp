//
//  Created by TaoSama on 2015-09-19
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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int t;
char s[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    getchar();
    int kase = 0;
    while(t--) {
        printf("Case #%d: ", ++kase);
//        puts("");
        int ans = 0;
        gets(s + 1);
        int n = strlen(s + 1);
        if(n == 0) {
            puts("-1");
            continue;
        }

        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            if(s[i] != 'c' && s[i] != 'f') {
                ok = false;
                break;
            }
            s[n + i] = s[i];
        }
        s[2 * n + 1] = 0;
        if(!ok) {
            puts("-1");
            continue;
        }
//        puts(s + 1);


        int i = 1;
        while(s[i] == 'f' && i <= n) ++i;
        if(i == n + 1) {
            printf("%d\n", n + 1 >> 1);
            continue;
        }
//        printf("%d %d\n", i, n + i - 1);
        int cnt = 0;
        for(int j = i; j <= n + i - 1;) {
            if(s[j] == 'c') {
                cnt = 0;
                ++j;
                while(s[j] == 'f' && j <= n + i - 1) ++j, ++cnt;
//                printf("j: %d\n", j);
                if(cnt >= 2) ++ans;
                else {
                    ok = false;
                    break;
                }
            }
        }

        if(ok) printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}
