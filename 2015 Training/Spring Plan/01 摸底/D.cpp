//
//	ACdream 1863 娜娜梦游仙境系列——村民的怪癖
//
//  Created by TaoSama on 2015-04-11
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

char s[200005];
int nxt[200005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        int len = strlen(s);
        memset(nxt, 0, sizeof(nxt));
        scanf("%s", s + len);
        len = strlen(s);
        int ans = 0, j = -1;
        nxt[0] = -1;
        for(int i = 0; i < len;) {
            if(j == -1 || s[i] == s[j])
                nxt[++i] = ++j;
            else j = nxt[j];
        }
        /*for(int i = 0; i <= len; ++i)
			cout<<nxt[i]<<' ';
		cout<<endl; */
        for(int i = len; ~nxt[i]; i = nxt[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
