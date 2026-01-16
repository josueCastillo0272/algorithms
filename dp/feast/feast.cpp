#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define eat cin
#define big long long
#define endl "\n"

int n, K;
big A[300005];
tuple<big,big> solve_opt(big l) {
    // dp[i][bool] = max value of i if in subarray
    tuple<big, big> dp[2] = {make_tuple(0,0), make_tuple(A[0] - l,-1)};

    for (int i = 1; i < n; i++) {
        tuple<big,big> tmp = max(dp[0], dp[1]);
        tuple<big,big> tmp1 = max(
            make_tuple(get<0>(dp[0]) + A[i] - l, get<1>(dp[0]) - 1), //dp[0][0] + A[i] - l, dp[0][1] - 1
            make_tuple(get<0>(dp[1]) + A[i], get<1>(dp[1])) // dp[1][0] + A[i], dp[1][1]
        );

        dp[0] = tmp;
        dp[1] = tmp1;
    }
    return max(dp[0], dp[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n >> K;

    for (int i = 0; i < n; i++) {
        big ai;
        eat >> ai;
        A[i] = ai;
    }

    big lo = 0;
    big hi = 3e14 + 1;
    tuple<big,big> res;
    while (lo < hi) {
        big mid = lo + (hi -lo)/2;
        res = solve_opt(mid);
        big kp = -1*get<1>(res);
        if (kp > K) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    res = solve_opt(lo);
    cout << get<0>(res) + K*lo << endl; 

    return 0;
}