//
//  Created by TaoSama on 2016-08-07
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

typedef long long LL;
map<LL, LL> f;
LL s, k;

LL get(int k, int n) {
    if(n < k) return 0;
    if(n == k) return 1;
    if(f.count(n)) return f[n];
    LL& ret = f[n];
    ret = 0;
    for(int i = n - 1; i >= max(k, n - k); --i)
        ret += get(k, i);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> s >> k;
    vector<int> v;
    for(int i = k - 1; ; ++i) {
        LL cur = get(k, i);
        v.push_back(cur);
        if(cur > 1e9) break;
    }

    vector<int> ans;
    int sum = 0;
    for(int i = v.size() - 1; ~i; --i) {
        if(sum + v[i] > s) continue;
        sum += v[i];
        ans.push_back(v[i]);
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);

    return 0;
}
