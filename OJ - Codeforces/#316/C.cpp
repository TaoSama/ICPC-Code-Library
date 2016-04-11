//
//  Created by TaoSama on 2015-08-14
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, l[N], r[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%s", &n, &m, s) == 3) {
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '.') ++cnt;
            else {
                if(cnt) ans += cnt - 1;
                cnt = 0;
            }
        }
        if(cnt) ans += cnt - 1;
//      printf("%d\n", ans);
//        cnt = 0;
//        for(int i = n - 1; i >= 0; --i) {
//            r[i] = cnt;
//            if(s[i] == '.') ++cnt;
//            else cnt = 0;
//        }
//
//        for(int i = 0; i < n; ++i) cout << s[i] << ' '; cout << endl;
//        for(int i = 0; i < n; ++i) cout << l[i] << ' '; cout << endl;
//        for(int i = 0; i < n; ++i) cout << r[i] << ' '; cout << endl;

        while(m--) {
            int i; char op[2];
            scanf("%d%s", &i, op);
            --i;
            if(s[i] == '.') {
                if(op[0] != '.') { //.->x
                    if(i - 1 >= 0 && s[i - 1] == '.') --ans;
                    if(i + 1 < n && s[i + 1] == '.') --ans;
                }
                s[i] = op[0];
            } else {
                if(op[0] == '.') { //x->.
                    if(i - 1 >= 0 && s[i - 1] == '.') ++ans;
                    if(i + 1 < n && s[i + 1] == '.') ++ans;
                }
                s[i] = op[0];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
