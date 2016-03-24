//
//  Created by TaoSama on 2015-07-29
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

struct Cell {
    int x, y;
    Cell() {}
    Cell(int x, int y): x(x), y(y) {}
    bool operator< (const Cell& rhs) const {
        return x < rhs.x || x == rhs.x && y < rhs.y;
    }
};
typedef set<Cell> Polyomino;

//try to normalize the Polyomino near the (0,0)
Polyomino normalize(const Polyomino& p) {
    int minX = p.begin()->x, minY = p.begin()->y;
    for(auto &c : p) {
        minX = min(minX, c.x);
        minY = min(minY, c.y);
    }
    Polyomino p2;
    for(auto &c : p)
        p2.insert(Cell(c.x - minX, c.y - minY));
    return p2;
}

//rotate it by 90бу counter-clockwise
Polyomino rotate(const Polyomino& p) {
    Polyomino p2;
    for(auto &c : p)
        p2.insert(Cell(c.y, -c.x));
    return normalize(p2);
}

//flip it from right to left for normalizing
Polyomino flip(const Polyomino& p) {
    Polyomino p2;
    for(auto &c : p)
        p2.insert(Cell(c.x, -c.y));
    return normalize(p2);
}

set<Polyomino> poly[15];
int ans[15][15][15];
int d[][2] = { -1, 0, 0, -1, 0, 1, 1, 0};

// add a cell to p0 and check whether it's new. If so, add to the Polyomino set
void tryToInsert(const Polyomino& p0, const Cell& c) {
    Polyomino p = p0;
    p.insert(c);
    p = normalize(p);

    int n = p.size();
    for(int i = 0; i < 4; ++i) {
        if(poly[n].count(p)) return;
        p = rotate(p);
    }
    p = flip(p);
    for(int i = 0; i < 4; ++i) {
        if(poly[n].count(p)) return;
        p = rotate(p);
    }
    poly[n].insert(p);
}

void generate() {
    Polyomino s;
    s.insert(Cell(0, 0));
    poly[1].insert(s);

    //generate for n > 1
    for(int n = 2; n <= 10; ++n) {
        for(auto &p : poly[n - 1]) {
            for(auto &c : p) {
                for(int i = 0; i < 4; ++i) {
                    Cell newc(c.x + d[i][0], c.y + d[i][1]);
                    if(!p.count(newc)) tryToInsert(p, newc);
                }
            }
        }
    }

    //precompute the answer table
    for(int n = 1; n <= 10; ++n) {
        for(int w = 1; w <= 10; ++w) {
            for(int h = 1; h <= 10; ++h) {
                int cnt = 0;
                for(auto &p : poly[n]) {
                    int maxX = 0, maxY = 0;
                    for(auto &c : p) {
                        maxX = max(maxX, c.x);
                        maxY = max(maxY, c.y);
                    }
                    if(min(maxX, maxY) < min(h, w) && max(maxX, maxY) < max(h, w))
                        ++cnt;
                }
                ans[n][w][h] = cnt;
            }
        }
    }
}

int n, w, h;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    generate();
    while(scanf("%d%d%d", &n, &w, &h) == 3) {
        printf("%d\n", ans[n][w][h]);
    }
    return 0;
}
