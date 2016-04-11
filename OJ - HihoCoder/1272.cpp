//
//  Created by TaoSama on 2016-03-13
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int a[55], b[55];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            char s[100];  scanf("%s%d", s, b + i);
            bool have = 0; int x = 0;
            for(int j = 0; s[j]; ++j) {
                if(s[j] == '.') {
                    have = true;
                    if(s[j + 1]) x = x * 10 + s[j + 1] - '0';
                    else x = x * 10;
                    break;
                }
                x = x * 10 + s[j] - '0';
            }
            if(!have) x = x * 10;
            a[i] = x;
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            if(a[i] % 50 == 0) ans = max(ans, b[i]);
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                if((a[i] + a[j]) % 50 == 0) ans = max(ans, b[i] + b[j]);
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                for(int k = j + 1; k <= n; ++k)
                    if((a[i] + a[j] + a[k]) % 50 == 0)
                        ans = max(ans, b[i] + b[j] + b[k]);
        printf("%d\n", ans);
    }
    return 0;
}
