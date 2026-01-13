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
#define moo cout
#define big long long
vector<tuple<int,int,big>> edges;

vector<tuple<int,int, big>> mst;

int n;
int Q;

big par[200005];
big sz[200005];

int root(int x)
{
    if (par[x] == x) return x;
    par[x] = root(par[x]);
    return par[x];
}

void join(int x, int y)
{
    if (root(x) == root(y)) return;
    if (sz[x] < sz[y]) swap(x,y);

    sz[root(x)] += sz[root(y)];
    par[root(y)] = root(x);
}


int main()
{
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);
    eat >> n;
    eat >> Q;

    // Initialize parents
    for (int i = 1; i < n + 1; i++) {
        par[i] = i;
    }
    // Set initial size to 1
    fill(sz, sz + n+1, 1);
    // Initialize edge list
    for (int i = 0; i < Q; i++) {
        int a;
        int b;
        int t;
        eat >> t >>  a >> b;

        if (t == 0) {
            join(a,b);
        } else {
            moo << ((root(a) == root(b)) ? 1 : 0) << endl;
        }

    }

    return 0;
}   