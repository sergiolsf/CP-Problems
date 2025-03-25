#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef pair<double, double> pdd;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const double INF = 1e18;

double dist(pdd p1, pdd p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

void solve(int n) {
    vector<pdd> points(n);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    sort(points.begin(), points.end());

    double d = INF;
    pdd p1, p2;

    set<pdd> st;
    int j = 0;

    for (int i = 0; i < n; i++) {
        auto &[x, y] = points[i];

        while (j < i && (x - points[j].first) > d) {
            st.erase({points[j].second, points[j].first});
            j++;
        }

        auto pont1 = st.lower_bound({y - d, -INF});
        auto pont2 = st.upper_bound({y + d, -INF});

        for (auto it = pont1; it != pont2; ++it) {
            double y1 = it->first, x1 = it->second;
            double curDist = dist({x1, y1}, {x, y});
            if (curDist < d) {
                d = curDist;
                p1 = {x1, y1};
                p2 = {x, y};
            }
        }

        st.insert({y, x});
    }

    cout << fixed << setprecision(6);
    cout << p1.first << " " << p1.second << " ";
    cout << p2.first << " " << p2.second << "\n";
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t) {
        solve(t);
        cin >>t;
    }
    return 0;
}
