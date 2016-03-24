//
//  Created by TaoSama on 2015-06-05
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int k, con[300][300];

void addEdge(int s, int t) {
    for(int i = s; i <= t; ++i) {
        con[s - 1][i] = con[i][t + 1] = con[i][t + 2] = true;
        for(int j = i + 1; j <= t; ++j)
            con[i][j] = true;
    }

    for(int i = s; i < t; i += 2)  //decrease 1 degree
        con[i][i + 1] = false;

    con[t + 1][t + 2] = true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> k) {
        if(k % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if(k == 1) {
            cout << "2 1\n2 1\n";
            continue;
        }

        memset(con, false, sizeof con);
        int V = 2 * k + 4, E = V * k >> 1;

        addEdge(2, k);
        con[1][k + 3] = true;
        addEdge(k + 4, V - 2);

        cout << V << ' ' << E << '\n';
        int cnt = 0;
        for(int i = 1; i <= V; ++i)
            for(int j = i + 1; j <= V; ++j)
                if(con[i][j]) cout << i << ' ' << j << '\n';
    }
    return 0;
}
