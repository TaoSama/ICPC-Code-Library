//
//  Created by TaoSama on 2016-07-17
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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N];
int ans[N];
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        vector<int> digit(10, 0);
        for(int i = 0; s[i]; ++i) digit[s[i] - '0']++;
        int nonZero = 0;
        for(int i = 1; i < 10; ++i) nonZero += digit[i];
//        prln(nonZero);
        if(nonZero < 2) {
            puts("Uncertain");
            continue;
        }

        int first;
        for(int i = 1; i < 10; ++i) {
            if(digit[i]) {
                first = i;
                digit[i]--;
                break;
            }
        }
        int cnt = 0;
        memset(ans, 0, sizeof ans);
        ans[0] = first;
        for(int i = 0; i < 10; i++) {
            while(digit[i]--) {
                ans[cnt] += i;
                ans[cnt + 1] += ans[cnt] / 10;
                ans[cnt] %= 10;
                ++cnt;
            }
        }

        int st = ans[cnt] ? cnt : cnt - 1;
        for(int i = st; ~i; --i)
            printf("%d", ans[i]);
        puts("");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
