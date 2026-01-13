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
int m;

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

// static bool sortbyth(const tuple<int,int,big> &a, const tuple<int,int,big> &b)
// {
//     return (get<2>(a) <get<2>(b));
// }
// )
big create_MST()
{   
    big min_cost = 0;
    for (auto edge: edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        big w = get<2>(edge);

        if (root(u) != root(v)) {
            join(u,v);
            mst.push_back({u,v,w});
            min_cost += w;
        }
    }
    return min_cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);
    eat >> n;
    eat >> m;

    // Initialize edge list
    for (int i = 0; i < m; i++) {
        int a;
        int b;
        big c;
        eat >> a >> b >> c;


        // Edge list
        edges.push_back({a,b,c});
        // edges.push_back({b,a,c});
    }

    // Initialize parents
    for (int i = 1; i < n + 1; i++) {
        par[i] = i;
    }


    // Set initial size to 1
    fill(sz, sz + n+1, 1);
    sort(edges.begin(), edges.end(), [&] (tuple<int,int,big> a, tuple<int,int,big> b) {return get<2>(a) < get<2>(b);});

    big min_cost = create_MST();

    if (mst.size() != n-1) {
        moo << "IMPOSSIBLE" << endl;
    } else {
        moo << min_cost << endl;
    }
    return 0;
}   