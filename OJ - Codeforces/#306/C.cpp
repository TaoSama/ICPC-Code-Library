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

string s;
vector<int> G[10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(cin >> s) {
        for(int i = 0; i < 10; ++i) G[i].clear();
        for(int i = 0; i < s.size(); ++i)
            G[s[i] - '0'].push_back(i);
        bool ok = false;
        for(int i = 0; i < 1000; ++i) {
            if(i % 8 == 0) {
                int x = i;
                char b[5]; sprintf(b, "%d", x);
                int n = strlen(b), last = -1;
                int can = 0;
                for(int j = 0; j < n; ++j) {
                    for(int k = 0; k < G[b[j] - '0'].size(); ++k) {
                        if(G[b[j] - '0'][k] > last) {
                            ++can;
                            last = G[b[j] - '0'][k];
                            break;
                        }
                    }
                }
                if(can == n) {
                    ok = true, printf("YES\n%d\n", i);
                    break;
                }
            }
        }
        if(!ok) puts("NO");
    }
    return 0;
}
