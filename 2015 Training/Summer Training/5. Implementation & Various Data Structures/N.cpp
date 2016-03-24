//
//  Created by TaoSama on 2015-07-23
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

const string dir = "NESW", turn = "FRL";
string maze;
int d[][2] = { -1, 0, 0, 1, 1, 0, 0, -1}; //clockwise
int tx, ty, sx, sy, sc, gx, gy;
bool canMove[10][10][4][3];

struct P {
    int x, y, dir;
    P() {}
    P(int x, int y, int dir): x(x), y(y), dir(dir) {}
} pre[10][10][4];

int getDir(char c) {
    return dir.find(c);
}

int getTurn(char c) {
    return turn.find(c);
}

P getNxt(P& u, int turn) {
    int dir = u.dir;
    if(turn == 1) dir = (dir + 1) % 4; //right for clockwise
    if(turn == 2) dir = (dir - 1 + 4) % 4;
    return P(u.x + d[dir][0], u.y + d[dir][1], dir);
}

int dp[10][10][4];

void print(P u) {
    vector<P> path;
    while(true) {
        path.push_back(u);
        if(dp[u.x][u.y][u.dir] == 0) break;
        u = pre[u.x][u.y][u.dir];
    }
    path.push_back(P(tx, ty, 0));
    reverse(path.begin(), path.end());

    cout << maze << '\n';
    for(int i = 0; i < path.size(); ++i) {
        P& u = path[i];
        if(i % 10 == 0) cout << ' ';
        cout << " (" << u.x << ',' << u.y << ')';
        if(i % 10 == 9) cout << '\n';
    }
    if(path.size() % 10 != 0) cout << '\n'; //not a multiple of 10
}

bool bfs() {
    queue<P> q;
    memset(dp, 0x3f, sizeof dp);
    dp[sx][sy][sc] = 0;
    q.push(P(sx, sy, sc));
    while(q.size()) {
        P u = q.front(); q.pop();
        if(u.x == gx && u.y == gy) {
            print(u);
            return true;
        }
        for(int i = 0; i < 3; ++i) {
            P v = getNxt(u, i);
            if(v.x < 1 || v.x > 9 || v.y < 1 || v.y > 9 || !canMove[u.x][u.y][u.dir][i])
                continue;
            if(dp[v.x][v.y][v.dir] == INF) {
                dp[v.x][v.y][v.dir] = dp[u.x][u.y][u.dir] + 1;
                pre[v.x][v.y][v.dir] = u;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(getline(cin, maze) && maze != "END") {
        memset(canMove, false, sizeof canMove);

        char c; cin >> tx >> ty >> c >> gx >> gy;
        sc = getDir(c);
//        prln(sc);
        sx = tx + d[sc][0]; sy = ty + d[sc][1];

        int x, y; string op;
        while(cin >> x && x) {
            cin >> y;
            while(cin >> op && op != "*") {
                int dir = getDir(op[0]);
                for(int i = 1; i < op.size(); ++i) {
                    int turn = getTurn(op[i]);
                    canMove[x][y][dir][turn] = true;
                }
            }
        }
        cin.get();
        if(!bfs()) cout << maze << "\n  No Solution Possible\n";
    }
    return 0;
}
