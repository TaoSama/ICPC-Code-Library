#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , A , B , C;
int a[N];
void work() {
    assert(1 <= n && n <= 100000);
    scanf("%d%d" , &A , &B);
    assert(0 <= A && A <= 1000);
    assert(0 <= B && B <= 1000);
    int cnt[3] = {};
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        //a[i] = rand() % 3;
        assert(0 <= a[i] && a[i] <= 2);
        cnt[a[i]] ++;
    }
    int sum[3][3] = {};
    for (int i = 0 ; i < n ; ++ i) {
        int j = 0;
        if (i >= cnt[0])
            ++ j;
        if (i >= cnt[0] + cnt[1])
            ++ j;
        if (a[i] != j)
            ++ sum[a[i]][j];
    }
    int res = 0;
    for (int i = 0 ; i < 3 ; ++ i) {
        for (int j = i + 1 ; j < 3 ; ++ j) {
            int mn = min(sum[i][j] , sum[j][i]);
            sum[i][j] -= mn;
            sum[j][i] -= mn;
            res += mn;
        }
    }
    printf("%d\n" , ((sum[0][1] + sum[1][0]) * 2 + res) * B);
}

int main() {
    while (~scanf("%d" , &n))
        work();
    return 0;
}