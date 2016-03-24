//
//  Created by TaoSama on 2015-11-23
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

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &a, &b) == 3) {
        int follow = 0, magic = 0, fg = 0;
        for(int i = 1; i <= n; ++i) {
            bool f = false, g = false;
            for(int j = 1; j <= 3; ++j) {
                int x; scanf("%d", &x);
                if(!x) f = true;
                else g = true;
            }
            if(f && g) ++fg;
            else if(f) ++follow;
            else ++magic;
        }
//      pr(follow); pr(magic); prln(fg);
        a = max(0, a - follow); b = max(0, b - magic);
        if(a + b <= fg) puts("YES");
        else puts("NO");
    }
    return 0;
}
