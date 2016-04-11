//
//
//
//  Created by TaoSama on 2015-04-16
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

char a[5][8], ta[8], tb[8];
int ans;

bool same(char *a, char *b) {
    int x = strlen(a), y = strlen(b);
    if(x == y) {
        for(int i = 0; i < x; ++i)
            if(a[i] != '*' && a[i] != b[i])
                return false;
    } else return false;
    return true;
}

void dfs(int x) {
    if(x == 5) {
        int aa = atoi(ta), bb = atoi(tb);
        int cc = aa * (bb % 10), dd = aa * (bb / 10),
            ee = cc + dd * 10;
        char c[8], d[8], e[8];
        sprintf(c, "%d", cc);
        sprintf(d, "%d", dd);
        sprintf(e, "%d", ee);

        /*printf("%5d\n", aa); printf("%5d\n", bb); printf("% d\n", cc);
        printf("% d\n", dd); printf("%d\n", ee);
        printf("**********\n\n");*/

        if(same(a[2], c) && same(a[3], d) && same(a[4], e)) {
            ++ans;
        }
        return;
    }
    if(x < 3) {
        if(a[0][x] != '*') {
            ta[x] = a[0][x];
            dfs(x + 1);
        } else {
            for(int i = 0; i <= 9; ++i) {
                if(x == 0 && i == 0) continue;
                ta[x] = i + '0';
                dfs(x + 1);
            }
        }
    } else {
        if(a[1][x - 3] != '*') {
            tb[x - 3] = a[1][x - 3];
            dfs(x + 1);
        } else {
            for(int i = 0; i <= 9; ++i) {
                if(x == 3 && i == 0) continue;
                tb[x - 3] = i + '0';
                dfs(x + 1);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < 5; ++i) cin >> a[i];

        ans = 0;
        dfs(0);
        cout << ans << endl;
    }
    /*fclose(stdout);
    system("out.txt");*/
    return 0;
}
