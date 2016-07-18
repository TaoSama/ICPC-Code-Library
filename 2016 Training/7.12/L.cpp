//
//  Created by TaoSama on 2016-07-12
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

char s[100];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(gets(s) && *s != '*') {
        bool ok = true;
        int n = strlen(s);
        for(int d = 1; d < n; ++d) {
            set<pair<char, char> > st;
            for(int j = 0; j + d < n; ++j) {
                pair<char, char> p(s[j], s[j + d]);
                if(st.count(p)) {
                    ok = false;
                    break;
                }
                st.insert(p);
            }
            if(!ok) break;
        }
        if(ok) printf("%s is surprising.\n", s);
        else printf("%s is NOT surprising.\n", s);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
