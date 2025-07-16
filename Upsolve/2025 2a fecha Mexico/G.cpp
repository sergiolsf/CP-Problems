#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

double pi = acos(-1);

struct point {
    double x;
    double y;

    bool operator<(point b) {
        return x < b.y;
    }
};


bool operator<(point a, point b) {
    return a.x < b.y;
}

bool is_inside(double a1, double a2, double a3) {
    if (a1 == -pi) a1 = pi;
    if (a2 == -pi) a2 = pi;
    if (a3 == -pi) a3 = pi;
    if (a1 < a2) swap(a1,a2);
    if (a2 < a3) swap(a2,a3);
    if (a1 < a2) swap(a1,a2);
    double d1, d2, d3;
    d1 = a1 - a2;
    if (d1 >= pi) return false;
    d2 = a2 - a3;
    if (d2 >= pi) return false;
    d3 = 2*pi + a3 - a1;
    if (d3 >= pi) return false;

    return true;
}

signed main() {
    fastio();

    int n;
    double h;
    cin >> n >> h;

    vector<pair<double, point>> islands(n);

    for (int i = 0; i < n; ++i) {
        cin >> islands[i].second.x >> islands[i].second.y  >> islands[i].first;
    }
    sort(islands.begin(), islands.end());
    reverse(islands.begin(), islands.end());

    point golden;
    cin >> golden.x >> golden.y;
    map<double, point> angles;

    double ans = -1;
    for (int i = 0; i < islands.size(); ++i) {
        if (islands[i].second.y == golden.y && islands[i].second.x == golden.x) continue;
        double angle = atan2(islands[i].second.y-golden.y, islands[i].second.x-golden.x);
        if (angle == -pi) angle = pi;
        double opangle = angle + pi;
        if (opangle > pi) opangle -= 2*pi;
        if (angles.contains(angle)) continue;
        if (angles.size() >= 2) {
            auto lb = angles.upper_bound(opangle);
            auto it1 = lb;
            auto it2 = lb;
            if (it1 != angles.begin()) --it1;
            else it1 = prev(angles.end());
            if (it1->first == opangle) {
                if (it1 != angles.begin()) --it1;
                else it1 = prev(angles.end());
            }
            if (it2 == angles.end()) it2 = angles.begin();
            point p1, p2, p3;
            p1 = it1->second;
            p2 = it2->second;
            p3 = islands[i].second;

            if (is_inside(it1->first, it2->first, angle)) {
                ans = max(0.0, h - islands[i].first);
                break;
            }
        }
        angles[angle] = islands[i].second;
    }

    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(20);
        cout << ans << endl;
    }

    return 0;
}