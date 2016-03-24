//  Created by Chlerry in 2015.
//  Copyright (c) 2015 Chlerry. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define Size 201315
#define ll long long
#define mk make_pair
#define pb push_back
#define mem(array, x) memset(array,x,sizeof(array))
typedef pair<int, int> P;

ll sum[Size], len[Size], size[Size], ans[Size];
ll M = 530600414;

int main() {
    //freopen("in.txt","r",stdin);
    sum[3] = 0; sum[4] = 2;
    len[3] = 3; len[4] = 5;
    size[3] = size[4] = 1;
    for(int i = 5; i < Size; i++) {
        len[i] = (len[i - 1] + len[i - 2]) % M;
        size[i] = (size[i - 2] + size[i - 1]) % M;
        sum[i] = ((sum[i - 2] + sum[i - 1]) % M + len[i - 2] * size[i - 1] % M) % M;
        // cout<<len[i]<<' '<<size[i]<<' '<<sum[i]<<endl;
        ans[i] = ((ans[i - 1] + ans[i - 2]) % M + (sum[i - 1] + len[i - 2] * size[i - 1]
                  % M) % M * size[i - 2] % M) % M - sum[i - 2] * size[i - 1] % M;
        ans[i] = (ans[i] + M) % M;
        //printf("ans[%d]=%lld\n",i,ans[i]);
    }
    int T; cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        int n;
        cin >> n;
        printf("Case #%d: %lld\n", ca, ans[n]);
    }
    return 0;
}
