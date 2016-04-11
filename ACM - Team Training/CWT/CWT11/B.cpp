//
//  Created by TaoSama on 2016-02-21
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        long long ans = 0;
        for(int i = 1; s[i]; ++i) {
            if((s[i] - '0') % 4 == 0) ++ans;
            if(s[i + 1]) {
                int cur = (s[i] - '0') * 10 + s[i + 1] - '0';
                if(cur % 4 == 0) ans += i;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
