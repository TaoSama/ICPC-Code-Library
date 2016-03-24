//
//  Created by TaoSama on 2015-11-13
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
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
char s[10005], tmp[10005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);
    while(q--) {
        int l, r, k; scanf("%d%d%d", &l, &r, &k);
        k = k % (r - l + 1);
        for(int i = r - k + 1, j = 1; i <= r; ++i, ++j) tmp[j] = s[i];
        for(int i = r - k; i >= l; --i)
            s[i + k] = s[i];
        for(int i = l, j = 1; j <= k; ++i, ++j)
            s[i] = tmp[j];
    }
    puts(s + 1);
    return 0;
}
