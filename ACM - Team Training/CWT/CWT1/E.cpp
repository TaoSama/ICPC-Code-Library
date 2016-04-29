//
//  Created by TaoSama on 2016-01-19
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N], buf[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%s", s + 1);
    int q; scanf("%d", &q);
    while(q--) {
        int l, r, k; scanf("%d%d%d", &l, &r, &k);
        k %= (r - l + 1);
        for(int i = 1; i <= k; ++i) buf[i] = s[r - k + i];
        for(int i = r - k; i >= l; --i) s[i + k] = s[i];
        for(int i = 1; i <= k; ++i) s[l + i - 1] = buf[i];
    }
    puts(s + 1);
    return 0;
}