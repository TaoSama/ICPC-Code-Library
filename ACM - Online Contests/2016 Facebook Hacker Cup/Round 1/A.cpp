//
//  Created by TaoSama on 2016-01-17
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

int n, a[N];

int main() {
    freopen("coding_contest_creation.txt", "r", stdin);
    freopen("coding_contest_creation_out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        int ans = 0, cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(!cnt) {++cnt; continue;}
            int dif = a[i] - a[i - 1];
            if(dif > 0 && dif <= 10) {
                if(++cnt == 4) cnt = 0;
            } else if(dif > 0 && dif <= 20) {
                ++ans;
                if(cnt == 1) cnt += 2;
                else if(cnt == 2) cnt = 0;
                else if(cnt == 3) cnt = 1;
            } else if(dif > 0 && dif <= 30) {
                if(cnt == 1) ans += 2, cnt = 0;
                else if(cnt == 2) ans += 2, cnt = 1;
                else if(cnt == 3) ++ans, cnt = 1;
            } else {
                ans += 4 - cnt;
                cnt = 1;
            }
//          printf("%d: %d\n", i, ans);
        }
        if(cnt) ans += 4 - cnt;

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
