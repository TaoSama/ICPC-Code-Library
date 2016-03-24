//
//  Created by TaoSama on 2015-09-28
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

int n, ans[N];
int sum[N << 2];
typedef pair<int, int> P;
P a[N];

int b[N];
void add(int i, int v) {
    for(; i <= n; i += i & -i) b[i] += v;
}

int find_kth(int k) {
    int m = 31 - __builtin_clz(n);  //��32λlog2(n)
    int cnt = 0, ret = 0;
    for(int i = m; i >= 0; --i) {
        ret += 1 << i;
        if(ret >= n || cnt + b[ret] >= k) ret -= 1 << i;
        //���ܻ��кܶ����������cnt+bit[ret]>=k �ҵ�����ret����cnt+bit[ret]<k
        else cnt += b[ret];
        //cnt�ۼӱȵ�ǰansС������
    }
    //ret��cnt����С�ڵ���ret�����ĸ�����С��k����������ֵ ret+1����k�����
    return ret + 1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);
        bool ok = true;
        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; ++i) add(i, 1);
        for(int i = 1; i <= n; ++i) {
            int k = a[i].second, v = a[i].first;
            k = min(k, n - i - k);
            if(k < 0) {
                ok = false;
                break;
            }
            int p = find_kth(k + 1);
            ans[p] = v;
            add(p, -1);
        }
        printf("Case #%d: ", ++kase);
        if(!ok) puts("impossible");
        else for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
