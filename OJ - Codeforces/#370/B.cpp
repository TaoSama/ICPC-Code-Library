//
//  Created by TaoSama on 2016-09-11
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

char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1);
        if(n & 1) puts("-1");
        else {
            int ud = 0, lr = 0;
            for(int i = 1; i <= n; ++i) {
                if(s[i] == 'L') ++lr;
                else if(s[i] == 'R') --lr;
                else if(s[i] == 'U') ++ud;
                else if(s[i] == 'D') --ud;
            }
            printf("%d\n", abs(ud) + abs(lr) >> 1);
        }
    }

    return 0;
}
