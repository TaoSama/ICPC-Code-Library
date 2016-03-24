//
//  Created by TaoSama on 2015-08-03
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
#include <cassert>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], wh[N];

vector<pair<int, int> > ans;
void exchange(int l, int r) {
    ans.push_back({l, r});
    assert((r - l + 1) % 2 == 0);

    int mid = l + r >> 1;
    for(int i = l, j = mid + 1; i <= mid; ++i, ++j) {
        swap(a[i], a[j]);
        swap(wh[a[i]], wh[a[j]]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            wh[a[i]] = i;
        }

        ans.clear();
        for(int i = 1; i <= n; ++i) {
            if(wh[i] == i) continue;

            int mid = i + n + 1 >> 1;
//          printf("i = %d  mid = %d\n", i, mid);
            if(wh[i] > mid) {
//                printf("in swap(%d->%d)\n", mid - (wh[i] - mid - 1), wh[i]);
                exchange(mid - (wh[i] - mid - 1), wh[i]);
//                for(int i = 1; i <= n; ++i) printf("%d ", a[i]); printf("\n");
            }
//            printf("swap(%d->%d)\n", i, wh[i] + (wh[i] - i - 1));
            exchange(i, wh[i] + (wh[i] - i - 1));
//            for(int i = 1; i <= n; ++i) printf("%d ", a[i]); printf("\n");
        }

        printf("%d\n", ans.size());
        for(auto &i : ans) printf("%d %d\n", i.first, i.second);
    }
    return 0;
}
