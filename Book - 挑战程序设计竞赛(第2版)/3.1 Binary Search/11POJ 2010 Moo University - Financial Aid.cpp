//
//  Created by TaoSama on 2015-04-28
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, c, f, half;
struct Cow {
    int id, s, f;
} sco[N], aid[N];

bool cmpByScore(const Cow& x, const Cow& y) {
    return x.s < y.s;
}
bool cmpByAid(const Cow& x, const Cow& y) {
    return x.f < y.f;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &c, &n, &f) == 3) {
        half = c >> 1;
        for(int i = 1; i <= n; ++i)
            scanf("%d%d", &sco[i].s, &sco[i].f);

        sort(sco + 1, sco + 1 + n, cmpByScore);
        for(int i = 1; i <= n; ++i) sco[i].id = i;
        memcpy(aid + 1, sco + 1, sizeof(Cow) * n);
        sort(aid + 1, aid + 1 + n, cmpByAid);

        int l = 0, r = n + 1, ans;
        while(l + 1 < r) {
            int mid = l + r >> 1;

            int lef = 0, rig = 0, sum = sco[mid].f;
            for(int i = 1; i <= n; ++i) {
                if(aid[i].id < mid && sum + aid[i].f <= f && lef < half)
                    sum += aid[i].f, ++lef;
                if(aid[i].id > mid && sum + aid[i].f <= f && rig < half)
                    sum += aid[i].f, ++rig;
            }
            if(lef < half && rig < half) {
                ans = -1;
                break;
            } else if(lef < half) l = mid;
            else if(rig < half) r = mid;
            else l = mid, ans = sco[mid].s;
        }

        printf("%d\n", ans);
    }
    return 0;
}
