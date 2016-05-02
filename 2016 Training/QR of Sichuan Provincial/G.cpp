//
//  Created by TaoSama on 2016-05-02
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
pair<int, int> a[N];
typedef long long LL;
LL pre[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].first), a[i].second = i;
    }
    scanf("%d", &k);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + a[i].first;

    LL cur = 0;
    for(int i = 1; i < k; ++i) {
        cur += 1LL * i * a[i + 1].first - pre[i];
    }

    pair<LL, int> ans = {cur, 1};
    for(int i = k + 1; i <= n; ++i) {
        cur += 1LL * k * a[i].first - pre[i - 1] + pre[i - 1 - k];
        cur += 1LL * k * a[i - k].first - pre[i] + pre[i - k];
        ans = min(ans, {cur, i - k + 1});
    }
    for(int i = ans.second; i <= ans.second + k - 1; ++i)
        printf("%d ", a[i].second);
    puts("");
    return 0;
}
