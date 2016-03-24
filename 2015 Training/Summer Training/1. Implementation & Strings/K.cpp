//
//  Created by TaoSama on 2015-07-18
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

string a[5], op;
int sx, sy;

bool isLegal(int x, int y) {
    if(x < 0 || x >= 5 || y < 0 || y >= 5) return false;
    else return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(true) {
        for(int i = 0; i < 5; ++i) {
            getline(cin, a[i]);
            if(!i && a[i] == "Z") return 0;
            for(int j = 0; j < 5; ++j)
                if(a[i][j] == ' ')
                    sx = i, sy = j;
        }
        if(kase) cout << '\n';
        op.clear();
        while(true) {
            string x; getline(cin, x);
            op += x;
            if(op[op.size() - 1] == '0') {
                op.erase(op.size() - 1, 1);
                break;
            }
        }

        bool legal = true;
        for(int i = 0; i < op.size(); ++i) {
            int nx, ny;
            if(op[i] == 'A') nx = sx - 1, ny = sy;
            else if(op[i] == 'B') nx = sx + 1, ny = sy;
            else if(op[i] == 'L') nx = sx, ny = sy - 1;
            else nx = sx, ny = sy + 1;
            if(!isLegal(nx, ny)) {
                legal = false;
                break;
            }
//          pr(sx); pr(sy); pr(nx); prln(ny);
            swap(a[sx][sy], a[nx][ny]);
            sx = nx, sy = ny;
        }

        cout << "Puzzle #" << ++kase << ":\n";
        if(!legal) {
            cout << "This puzzle has no final configuration.\n";
            continue;
        }
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                cout << a[i][j] << (j == 4 ? '\n' : ' ');
    }
    return 0;
}
