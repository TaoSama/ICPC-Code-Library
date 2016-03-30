//
//  Created by TaoSama on 2015-12-14
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

char s[N], t[N];
int a[N], b[N], cnt1, cnt2;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s%s", s, t);
        cnt1 = cnt2 = 0;
        for(int i = 0; s[i]; ++i) {
            if(s[i] == 'a') a[++cnt1] = i;
            if(t[i] == 'a') b[++cnt2] = i;
        }
        if(cnt1 != cnt2) {
            puts("-1");
            continue;
        }
        long long ans = 0;
        for(int i = 1; i <= cnt1; ++i)
            ans += abs(a[i] - b[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
