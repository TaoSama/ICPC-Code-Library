//
//  Created by TaoSama on 2015-05-14
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

int n, m;
char a[50][50];
typedef pair<int, int> P;
vector<P> C, H;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n + m)) {
        C.clear(); H.clear();
        for(int i = 0; i < n; ++i) {
            scanf("%s", a + i);
            for(int j = 0; j < m; ++j){
				if(a[i][j] == 'C') C.push_back(P(i, j));
				if(a[i][j] == 'H') H.push_back(P(i, j));
            }
        }
        int Min = INF;
        P h, c;
        for(int i = 0; i < H.size(); ++i){
			for(int j = 0; j < C.size(); ++j){
				P a = H[i], b = C[j];
				int t = abs(a.first - b.first) + abs(a.second - b.second);
				if(t < Min){
					Min = t;
					h = a, c = b;
				}
			}
        }
        printf("%d %d %d %d\n",h.first, h.second, c.first, c.second);
    }
    return 0;
}
