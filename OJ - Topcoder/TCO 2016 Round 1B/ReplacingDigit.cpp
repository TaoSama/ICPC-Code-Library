#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class ReplacingDigit {
public:
    int getMaximumStockWorth(vector<int> A, vector<int> D) {
        int ten[10] = {1};
        for(int i = 1; i <= 7; ++i) ten[i] = ten[i - 1] * 10;
        priority_queue<int, vector<int>, greater<int> > q[7];
        for(int x : A) {
            int cnt = 0;
            while(x) {
                q[cnt++].push(x % 10);
                x /= 10;
            }
        }

        int ans = accumulate(A.begin(), A.end(), 0);
        for(int i = D.size() - 1; ~i; --i) {
            int x = i + 1, cnt = D[i];
            if(!cnt) continue;
            for(int j = 6; ~j; --j) {
                priority_queue<int, vector<int>, greater<int> >& cur = q[j];
                while(cur.size() && cnt) {
                    int u = cur.top(); cur.pop();
                    if(x > u) {
                        ans += (x - u) * ten[j];
                        --cnt;
                    } else break;
                }
            }
        }
        return ans;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { {100, 90}, {0, 0, 0, 0, 2, 1, 0, 0, 0} }, {745} },
        { { {9}, {1, 1, 1, 1, 1, 1, 1, 1, 0} }, {9} },
        { { {123456}, {9, 8, 7, 6, 5, 4, 3, 2, 1} }, {988777} },
        { { {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870}, {11, 2, 8, 10, 7, 6, 3, 1, 3} }, {3297500} },
        { { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {111, 111, 111, 111, 111, 111, 111, 111, 111} }, {198} },
        // Your custom test goes here:
        //{ { {}, {}}, {} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    vector<int> p0; vector<int> p1;

    int run(ReplacingDigit* x) {
        return x->getMaximumStockWorth(p0, p1);
    }
    void print() {
        //Tester::printArgs(p0,p1);
    }
};

int main() {
    return Tester::runTests<ReplacingDigit>(
               getTestCases<input, Tester::output<int>>(), disabledTest,
               500, 1460473733, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
