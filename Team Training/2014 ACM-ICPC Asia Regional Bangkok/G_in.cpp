//
//  Created by TaoSama on 2015-12-12
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
#include <ctime>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[15][15];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    freopen("G.txt", "w", stdout);

    char b[] = "-L";
    srand(time(0));

    int n, m; n = 1, m = 11;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            s[i][j] = b[rand() % 2];
	for(int i = 1; i <= n; ++i) puts(s[i] + 1); puts("");


	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			int tmp = s[i][j] == 'L' ? 3 : 0;
			for(int dx = -1; dx <= 1; ++dx)
				for(int dy = -1; dy <= 1; ++dy)
					tmp += s[i + dx][j + dy] == 'L';
			printf("%d%c", tmp, " \n"[j == m]);
		}
	}
    return 0;
}
