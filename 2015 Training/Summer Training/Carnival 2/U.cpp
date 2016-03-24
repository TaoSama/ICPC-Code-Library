//
//  Created by TaoSama on 2015-08-02
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

char a[15], b[15];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a >> b) {
        int aa = 0, bb = 0;
        for(int i = 0; a[i]; ++i) {
            if(a[i] == '0') continue;
            else aa = aa * 10 + a[i] - '0';
        }
        for(int i = 0; b[i]; ++i) {
            if(b[i] == '0') continue;
            else bb = bb * 10 + b[i] - '0';
        }
        int cc = atoi(a) + atoi(b);
        char c[15]; sprintf(c, "%d", cc);
        cc = 0;
        for(int i = 0; c[i]; ++i) {
            if(c[i] == '0') continue;
            else cc = cc * 10 + c[i] - '0';
        }
//      cout << aa << ' ' << bb << ' ' << cc << endl;
        cout << (aa + bb == cc ? "YES" : "NO") << '\n';
    }
    return 0;
}
