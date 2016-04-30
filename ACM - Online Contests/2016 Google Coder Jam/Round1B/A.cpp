//
//  Created by TaoSama on 2016-04-30
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
#include <array>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int cnt[26];
char s[N];
char digit[][10] =
{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int o[] = {0, 2, 4, 1, 6, 7, 8, 5, 3, 9};
char c[] = "ZWUOXSGVTI";


int main() {
#ifdef LOCAL
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; s[i]; ++i) cnt[s[i] - 'A']++;
        int ans[10] = {};
        for(int i = 0; i < 10; ++i) {
            int d = o[i];
            ans[d] = cnt[c[i] - 'A'];
//            printf("ans[%d] = %d\n", d, ans[d]);
            for(int j = 0; digit[d][j]; ++j) cnt[digit[d][j] - 'A'] -= ans[d];
        }

        static int kase = 0;
        printf("Case #%d: ", ++kase);
        for(int i = 0; i < 10; ++i) while(ans[i]--) putchar(i + '0'); puts("");
    }
    return 0;
}

