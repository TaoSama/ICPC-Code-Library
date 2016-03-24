//
//  Created by TaoSama on 2015-12-26
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

int n, a, b;
char s[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%s", &n, &a, &b, s) == 4) {
        bool ok = false;
        for(int i = 0; i <= n / a; ++i) {
            if((n - i * a) % b == 0) {
                ok = true;
                printf("%d\n", i + (n - i * a) / b);
                for(int j = 0; j < i; ++j) {
                    for(int k = 0; k < a; ++k)
                        putchar(s[j * a + k]);
                    puts("");
                }
                for(int j = 0; j < (n - i * a) / b; ++j) {
                    for(int k = 0; k < b; ++k)
                        putchar(s[i * a + j * b + k]);
                    puts("");
                }
                break;
            }
        }
        if(!ok) puts("-1");
    }
    return 0;
}
