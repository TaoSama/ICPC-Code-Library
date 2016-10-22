//
//  Created by TaoSama on 2015-11-24
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

int n, k;

/*
n:     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
k:  1  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
k:  2  1  2  0  1  2  0  1  2  0  1  2  0  1  2  0
k:  3  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
k:  4  1  0  1  4  0  1  0  1  4  0  1  0  1  4  0
k:  5  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
k:  6  1  0  1  0  1  6  0  1  0  1  0  1  6  0  1
k:  7  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
k:  8  1  0  1  0  1  0  1  8  0  1  0  1  0  1  0
k:  9  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
k: 10  1  0  1  0  1  0  1  0  1 10  0  1  0  1  0
k: 11  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
k: 12  1  0  1  0  1  0  1  0  1  0  1 12  0  1  0
k: 13  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
k: 14  1  0  1  0  1  0  1  0  1  0  1  0  1 14  0
k: 15  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
*/

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        if(k & 1) printf("%d\n", n & 1);
        else {
            if(n % (k + 1) == k) printf("%d\n", k);
            else printf("%d\n", n % (k + 1) & 1);
        }
    }
    return 0;
}

/*
long long delta[20] = {1};

bool dfs(int x) {
    if(!x) return false;
    for(int i = 0; i <= 10 && delta[i] <= x; ++i) {
        if(!dfs(x - delta[i])) return true;
    }
    return false;
}
int main(){
    printf("n:   ");
    for(int i = 1; i <= 20; ++i) printf("%3d", i); puts("");
    for(k = 1; k <= 15; ++k) {
        for(int i = 1; i <= 10; ++i)
            delta[i] = delta[i - 1] * k;
        printf("k: %2d", k);
        for(int i = 1; i <= 15; ++i){
            if(dfs(i)){
                for(int j = 0; j <= 10; ++j){
                    if(i - delta[j] >= 0 && !dfs(i - delta[j])){
                        printf("%3d", delta[j]);
                        break;
                    }
                }
            }
            else printf("%3d", 0);
        }
        puts("");
    }
    return 0;
}
*/
