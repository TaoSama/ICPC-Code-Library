//
//  Created by TaoSama on 2016-05-29
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N];
typedef long long LL;
bitset<62> t[505]

inline int ID(char c) {
    if(isdigit(c)) return c - '0' + 52;
    else if(isupper(c)) return c - 'A' + 26;
    return c - 'a';
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(gets(s) != NULL) {
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            int cnt; char buf[70];
            scanf("%d%s", &cnt, buf);
            t[i].reset();
            for(int j = 0; j < cnt; ++j) t[i][ID(buf[j])] = 1;
        }
        bool ok = false;
        for(int i = 0; s[i]; ++i){

        }
        getchar();
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
