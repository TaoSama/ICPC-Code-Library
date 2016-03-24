// ZOJ 3645 BiliBili
// 把12个二次方程相邻相减 变成一次 求解
// 高斯消元

const double EPS = 1e-8;

double a[N][N], ans[N];
bool l[N];
int gauss(int n) {
    int res = 0, r = 0;
    for(int i = 0; i < n; i++) l[i] = false;
    for(int i = 0; i < n; i++) {
        //行交换
        for(int j = r; j < n; j++) {
            if(fabs(a[j][i]) > EPS) {
                for(int k = i; k <= n; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        }
        if(fabs(a[r][i]) < EPS) {res++; continue;}
        //消元
        for(int j = 0; j < n; j++) {
            if(j != r && fabs(a[j][i]) > EPS) {
                double tmp = a[j][i] / a[r][i];
                for(int k = i; k <= n; k++) {
                    a[j][k] -= tmp * a[r][k];
                    //这里注意精度问题
                    if(fabs(a[j][k]) < EPS) a[j][k] = 0;
                }
            }
        }
        l[i] = true; r++;
    }
    for(int i = 0; i < n; i++) {
        if(!l[i]) continue;
        for(int j = 0; j < n; j++)
            if(fabs(a[j][i]) > 0) ans[i] = a[j][n] / a[j][i];
    }
    return res; //自由未知量数量
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n = 11;
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= n; ++j)
                scanf("%lf", &a[i][j]);
        for(int i = 0; i < n; ++i) {
            a[i][n] = a[i][n] * a[i][n] - a[n][n] * a[n][n];
            for(int j = 0; j < n; ++j) {
                a[i][n] -= a[i][j] * a[i][j] - a[n][j] * a[n][j];
                a[i][j] = 2 * (a[n][j] - a[i][j]);
            }
        }
        gauss(n);
        for(int i = 0; i < n; ++i)
            printf("%.2f%c", ans[i] + EPS, " \n"[i == n - 1]);
    }
    return 0;
}
