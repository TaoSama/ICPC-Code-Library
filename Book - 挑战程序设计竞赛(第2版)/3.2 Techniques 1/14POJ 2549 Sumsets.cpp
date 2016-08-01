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

int n;
pair<int, int> A[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1 && n) {
        vector<pair<int, pair<int, int> > > v;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i].first);
            A[i].second = i;
            for(int j = 1; j < i; ++j)
                v.push_back(make_pair(A[i].first + A[j].first, make_pair(j, i)));
        }
        sort(A + 1, A + 1 + n);
        sort(v.begin(), v.end());

        int ans = -INF;
        for(int i = n; i; --i) {
            for(int j = i - 1; j; --j) {
                int d = A[i].second, c = A[j].second;
                int val = A[i].first - A[j].first;
                pair<int, pair<int, int> > query;
                typedef vector<pair<int, pair<int, int> > >::iterator iterator;
                query = make_pair(val, make_pair(-INF, -INF));
                iterator lower = lower_bound(v.begin(), v.end(), query);
                query = make_pair(val, make_pair(INF, INF));
                iterator upper = upper_bound(v.begin(), v.end(), query);
                for(iterator iter = lower; iter != upper; ++iter) {
                    int a = iter->second.first, b = iter->second.second;
                    if(d == a || d == b || c == a || c == b) continue;
                    ans = A[i].first;
                    break;
                }
                if(ans != -INF) break;
            }
            if(ans != -INF) break;
        }
        if(ans == -INF) puts("no solution");
        else printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
