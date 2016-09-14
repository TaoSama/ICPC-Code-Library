//
//  Created by TaoSama on 2016-09-14
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

int q;
int cnt[1 << 20];
typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &q) == 1) {
        memset(cnt, 0, sizeof cnt);
        while(q--) {
            char op[2]; char s[18];
            scanf("%s%s", op, s);
            int n = strlen(s);
            reverse(s, s + n);
            LL patern = 0;
            for(int i = 0; i < 18; ++i) {
                int d = i < n ? s[i] - '0' : 0;
//              printf("%d ",d);
                d &= 1;
                patern = patern << 1 | d;
            }
//          puts("");
//          prln(patern);
            if(*op == '+') ++cnt[patern];
            else if(*op == '-') --cnt[patern];
            else printf("%d\n", cnt[patern]);
        }

    }

    return 0;
}
