//
//  Created by TaoSama on 2016-06-24
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

int n, m;
int len[2];

bool check(vector<int>& digit, int s) {
    int lft = 0, rht = 0;
    for(int i = 0; i < s; ++i)
        lft = lft * 7 + digit[i];
    for(int i = s; i < digit.size(); ++i)
        rht = rht * 7 + digit[i];
//    if(lft <= n && rht <= m) {
//        puts("digits");
//        for(auto x : digit) printf("%d ", x); puts("");
//        printf("%d %d\n", lft, rht);
//    }
    return lft <= n && rht <= m;
}

int getLength(int x) {
    if(!x) return 1;
    int cnt = 0;
    for(; x; x /= 7) ++cnt;
    return cnt;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        --n; --m;
        len[0] = getLength(n);
        len[1] = getLength(m);

        int ans = 0;
        for(int msk = 1; msk < 1 << 7; ++msk) {
            vector<int> digit;
            for(int i = 0; i < 7; ++i)
                if(msk >> i & 1) digit.push_back(i);
            if(digit.size() != len[0] + len[1]) continue;
            do {
                ans += check(digit, len[0]);
            } while(next_permutation(digit.begin(), digit.end()));
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
