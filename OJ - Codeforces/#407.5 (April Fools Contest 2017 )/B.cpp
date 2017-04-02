//
//  Created by TaoSama on 2017-03-31
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int x;
    while(cin >> x) {
        int ans = x == 0;
        for(; x; x >>= 4) {
            int d = x & 15, c;
            if(d >= 10) c = 'A' + d - 10;
            else c = '0' + d;
            if(strchr("0469AD", c)) ++ans;
            else if(strchr("8B", c)) ans += 2;
        }
        cout << ans << endl;
    }

    return 0;
}
