#include <bits/stdc++.h>

using namespace std;

class MultiplicationTable2 {
    public:
    int minimalGoodSet(vector<int> table) {
        return 0;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {1,1,2,3,1,0,3,2,2,0,1,3,1,2,3,0} }, {2} },
    { { {0,1,2,3,1,2,3,0,2,3,0,1,3,0,1,2} }, {1} },
    { { {1,1,1,1,2,2,2,2,3,3,3,3,0,0,0,0} }, {4} },
    { { {0} }, {1} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #define DISABLE_COLORS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        int run(MultiplicationTable2* x) {
            return x->minimalGoodSet(p0);
        }
        void print() { Tester::printArgs(p0); }
    };

    int main() {
        return Tester::runTests<MultiplicationTable2>(
            getTestCases<input, Tester::output<int>>(), disabledTest,
            250, 1459098362, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
