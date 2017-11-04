//
//  Created by TaoSama on 2017-01-14
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

char board[3][3];
const int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11};

bool vis[3][3];
bool dfs(int x, int y, char* word) {
    if(!*word) return true;
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if(!i && !j) continue;
            int nx = x + i, ny = y + j;
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3 || vis[nx][ny]) continue;
            if(board[nx][ny] != *word) continue;
            vis[nx][ny] = true;
            if(dfs(nx, ny, word + 1)) return true;
            vis[nx][ny] = false;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 3; ++i) scanf("%s", board[i]);
        int q; scanf("%d", &q);
        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        while(q--) {
            char word[20]; scanf("%s", word);
            int len = strlen(word);
            if(len < 3) puts("0");
            else {
                bool ok = false;
                for(int i = 0; i < 3 && !ok; ++i) {
                    for(int j = 0; j < 3 && !ok; ++j) {
                        if(board[i][j] != word[0]) continue;
                        memset(vis, 0, sizeof vis);
                        vis[i][j] = true;
                        ok = dfs(i, j, word + 1);
                    }
                }
                printf("%d\n", ok ? score[len] : 0);
            }
        }
    }

    return 0;
}
