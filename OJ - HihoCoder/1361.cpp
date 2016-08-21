//
//  Created by TaoSama on 2016-08-21
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

char a[10][10];
char s[205];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s) == 1) {
        memset(a, 0, sizeof a);
        vector<int> vis(26, 0);
        int r = 0, c = 0;
        for(int i = 0; s[i]; ++i) {
            if(s[i] == 'J') s[i] = 'I';
            if(!vis[s[i] - 'A']) {
                a[r][c] = s[i];
                vis[s[i] - 'A'] = true;
                if(++c == 5) ++r, c = 0;
            }
        }
        for(int i = 0; i < 26; ++i) {
            if((i + 'A') == 'J') continue;
            if(vis[i]) continue;
            a[r][c] = 'A' + i;
            if(++c == 5) ++r, c = 0;
        }
        for(int i = 0; i < 5; ++i) puts(a[i]);
    }

    return 0;
}
