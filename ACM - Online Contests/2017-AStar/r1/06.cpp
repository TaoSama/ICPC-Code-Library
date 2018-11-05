
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, m;
pair<int, int> a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].first, &a[i].second);
        }
        sort(a + 1, a + 1 + n);

        vector<pair<int, int> > seg; seg.reserve(n);
        int l = -INF, r = -INF;
        for(int i = 1; i <= n; ++i) {
            if(a[i].first > r + 1) {
                if(l != -INF) seg.push_back(make_pair(l, r));
                l = a[i].first;
                r = a[i].second;
            }
            else r = max(r, a[i].second);
        }
        seg.push_back(make_pair(l, r));
        // for(auto  p : seg) cout << p.first << ' ' << p.second << endl;

        int ans = 0, sum = 0;;
        for(size_t r = 0, l = 0; r < seg.size(); ++r) {
            if(r > 0) sum += seg[r].first - seg[r - 1].second - 1;
            // printf("r = %d sum = %d\n", r, sum);
            while(l + 1 < seg.size() && sum > m) {
                sum -= seg[l + 1].first - seg[l].second - 1;
                ++l;
            }
            ans = max(ans, seg[r].second - seg[l].first + 1 + m - sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
