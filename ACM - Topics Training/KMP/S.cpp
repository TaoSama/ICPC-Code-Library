//
//  Created by TaoSama on 2015-10-30
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, v[26], p[N], sum[N];
char a[N], s[N];

void manacher() {
    s[0] = '@'; s[1] = '#'; n = 2;
    for(int i = 0; a[i]; ++i) {
        sum[n] = sum[n - 1] + v[a[i] - 'a'];
        s[n++] = a[i];
        sum[n] = sum[n - 1];
        s[n++] = '#';
    }
    s[n] = 0;

    int mx = 0, id;
    for(int i = 1; i < n; ++i) {
        if(mx > i) p[i] = min(mx - i, p[2 * id - i]);
        else p[i] = 1;
        while(s[i - p[i]] == s[i + p[i]]) ++p[i];
        if(mx < p[i] + i) mx = p[i] + i, id = i;
    }
}

/*
 1  2  3  4  5  6  7  8  9 10 11 12 13
 #  a  #  c  #  a  #  c  #  a  #  c  #
 1  2  1  4  1  6  1  6  1  4  1  2  1
*/
/*
 1  2  3  4  5  6  7  8  9
 #  w  #  w  #  b  #  b  #
 1  2  3  2  1  2  3  2  1
*/
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 26; ++i) scanf("%d", v + i);
        scanf("%s", a);
        manacher();
        int ans = -INF;
        for(int i = 3; i < n - 1; i += 2) {
            int l = 0, r = 0;
            if(p[(i + 1) / 2] * 2 - 1 == i)
                l = sum[i];
            if(p[i + (n - 1 - i) / 2] * 2 - 1 == n - i)
                r = sum[n - 1] - sum[i];
            ans = max(ans, l + r);
        }
        printf("%d\n", ans);

    }
    return 0;
}
