//
//  Created by TaoSama on 2016-07-29
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

int n, q;
pair<int, int> s[N];
int ans, diff, L, R;

void update(int l, int r, int x) {
    if(s[l].second == s[r].second) return; //empty range
    int sum = abs(s[r].first - s[l].first);
    int newDiff = abs(sum - x);
    if(newDiff < diff) {
        diff = newDiff;
        ans = sum;
        L = s[l].second;
        R = s[r].second;
        if(L > R) swap(L, R);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) && (n || q)) {
        s[0] = make_pair(0, 0);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            s[i].first = s[i - 1].first + x;
            s[i].second = i;
        }
        sort(s, s + n + 1);

        while(q--) {
            int x; scanf("%d", &x);
            diff = INF;

            int sum = 0;
            for(int l = 0, r = 0; l <= n; ++l) {
                sum = s[r].first - s[l].first;
                update(l, r, x);
                while(r < n && sum < x) {
                    ++r;
                    update(l, r, x);
                    sum = s[r].first - s[l].first;
                }
            }
            printf("%d %d %d\n", ans, L + 1, R);
        }
    }

    return 0;
}
