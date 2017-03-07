//
//  Created by TaoSama on 2017-01-21
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vector<int> v;
        for(int i = 1; i <= n; ++i) {
            int val, cnt; scanf("%d%d", &val, &cnt);
            while(cnt--) v.push_back(val);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int ans = 0, sum = 0, cur = 0;
        for(int x : v) {
            sum += x;
            cur += sum;
            ans = max(ans, cur);
        }

        printf("%d\n", ans);
    }

    return 0;
}
