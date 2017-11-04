//
//  Created by TaoSama on 2017-01-16
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        map<int, int> teamID;
        for(int i = 1; i <= n; ++i) {
            int cnt; scanf("%d", &cnt);
            while(cnt--) {
                int x; scanf("%d", &x);
                teamID[x] = i;
            }
        }

        static int kase = 0;
        printf("Scenario #%d\n", ++kase);

        queue<int> teamQ;
        vector<queue<int> > memberQ(n + 1);

        char cmd[10];
        while(scanf("%s", cmd) == 1) {
            if(*cmd == 'E') {
                int x; scanf("%d", &x);
                int id = teamID[x];
                if(memberQ[id].size()) {}
                else {
                    teamQ.push(id);
                }
                memberQ[id].push(x);
            } else if(*cmd == 'D') {
                int id = teamQ.front();
                printf("%d\n", memberQ[id].front());
                memberQ[id].pop();
                if(!memberQ[id].size()) teamQ.pop();
            } else break;
        }
        puts("");
    }

    return 0;
}
