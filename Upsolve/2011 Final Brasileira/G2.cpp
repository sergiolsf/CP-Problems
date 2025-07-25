#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    int type; // 0 for pine, 1 for larch
    ll value;
    Point() : x(0), y(0), type(-1), value(0) {}
    Point(ll x, ll y, int type, ll value) : x(x), y(y), type(type), value(value) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y, -1, 0);
    }
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y, -1, 0);
    }
};

ll cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

ll cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

ll dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

bool cmp_convex(const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

vector<Point> convex_hull(vector<Point> points) {
    if (points.size() <= 1) return points;
    sort(points.begin(), points.end(), cmp_convex);
    vector<Point> hull;
    hull.reserve(points.size() + 1);
    for (int it = 0; it < 2; it++) {
        int start = hull.size();
        for (Point& p : points) {
            while (hull.size() >= start + 2 && cross(hull[hull.size() - 2], hull.back(), p) <= 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(points.begin(), points.end());
    }
    if (hull.size() == 2 && hull[0].x == hull[1].x && hull[0].y == hull[1].y) {
        hull.pop_back();
    }
    return hull;
}

bool point_in_convex_polygon(const Point& p, const vector<Point>& hull) {
    int n = hull.size();
    if (n == 0) return false;
    if (n == 1) {
        return p.x == hull[0].x && p.y == hull[0].y;
    }
    if (n == 2) {
        if (cross(hull[0], hull[1], p) != 0) return false;
        if (p.x < min(hull[0].x, hull[1].x) || p.x > max(hull[0].x, hull[1].x)) 
            return false;
        if (p.y < min(hull[0].y, hull[1].y) || p.y > max(hull[0].y, hull[1].y)) 
            return false;
        return true;
    }
    if (cross(hull[0], hull[1], p) < 0) return false;
    if (cross(hull[0], hull[n-1], p) > 0) return false;

    int lo = 1, hi = n-2;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (cross(hull[0], hull[mid], p) >= 0) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return cross(hull[hi], hull[hi+1], p) >= 0;
}

bool segments_intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (cross(b - a, d - c) == 0) {
        return false;
    }
    ll c1 = cross(b - a, c - a);
    ll c2 = cross(b - a, d - a);
    if ((c1 < 0 && c2 < 0) || (c1 > 0 && c2 > 0)) {
        return false;
    }
    ll c3 = cross(d - c, a - c);
    ll c4 = cross(d - c, b - c);
    if ((c3 < 0 && c4 < 0) || (c3 > 0 && c4 > 0)) {
        return false;
    }
    return true;
}

bool linearly_separable(vector<Point> pines, vector<Point> larches) {
    vector<Point> hull_pine = convex_hull(pines);
    vector<Point> hull_larch = convex_hull(larches);

    for (const Point& p : hull_pine) {
        if (point_in_convex_polygon(p, hull_larch)) {
            return false;
        }
    }
    for (const Point& p : hull_larch) {
        if (point_in_convex_polygon(p, hull_pine)) {
            return false;
        }
    }

    for (int i = 0; i < hull_pine.size(); i++) {
        Point a = hull_pine[i];
        Point b = hull_pine[(i + 1) % hull_pine.size()];
        for (int j = 0; j < hull_larch.size(); j++) {
            Point c = hull_larch[j];
            Point d = hull_larch[(j + 1) % hull_larch.size()];
            if (segments_intersect(a, b, c, d)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int P, L;
        cin >> P >> L;
        if (P == 0 && L == 0) break;

        vector<Point> pines(P);
        vector<Point> larches(L);
        vector<Point> all_trees;

        for (int i = 0; i < P; i++) {
            cin >> pines[i].x >> pines[i].y >> pines[i].value;
            pines[i].type = 0;
            all_trees.push_back(pines[i]);
        }
        for (int i = 0; i < L; i++) {
            cin >> larches[i].x >> larches[i].y >> larches[i].value;
            larches[i].type = 1;
            all_trees.push_back(larches[i]);
        }

        if (linearly_separable(pines, larches)) {
            cout << 0 << '\n';
            continue;
        }

        int n = all_trees.size();
        ll INF = 1LL << 60;
        ll global_ans = INF;

        for (int idx = 0; idx < n; idx++) {
            Point A = all_trees[idx];
            vector<Point> others;
            for (int j = 0; j < n; j++) {
                if (j == idx) continue;
                others.push_back(all_trees[j]);
            }

            ll left_pine = 0, left_larch = 0;
            ll right_pine = 0, right_larch = 0;
            vector<int> side(others.size(), -1);

            for (int i = 0; i < others.size(); i++) {
                Point C = others[i];
                ll dx = C.x - A.x;
                ll dy = C.y - A.y;
                if (dy > 0 || (dy == 0 && dx > 0)) {
                    if (C.type == 0) left_pine += C.value;
                    else left_larch += C.value;
                    side[i] = 0;
                } else {
                    if (C.type == 0) right_pine += C.value;
                    else right_larch += C.value;
                    side[i] = 1;
                }
            }

            ll base_loss = A.value;
            ll loss_half = min(left_larch + right_pine, left_pine + right_larch);
            global_ans = min(global_ans, base_loss + loss_half);

            if (others.empty()) {
                continue;
            }

            sort(others.begin(), others.end(), [&](const Point& C1, const Point& C2) {
                Point v1 = C1 - A;
                Point v2 = C2 - A;
                ll cr = cross(v1, v2);
                if (cr != 0) {
                    return cr > 0;
                }
                return dot(v1, v1) < dot(v2, v2);
            });

            vector<vector<Point>> groups;
            vector<Point> current_group;
            current_group.push_back(others[0]);
            for (int i = 1; i < others.size(); i++) {
                Point v1 = others[i] - A;
                Point v2 = others[i-1] - A;
                ll cr = cross(v1, v2);
                if (cr == 0) {
                    current_group.push_back(others[i]);
                } else {
                    groups.push_back(current_group);
                    current_group.clear();
                    current_group.push_back(others[i]);
                }
            }
            if (!current_group.empty()) {
                groups.push_back(current_group);
            }

            for (const auto& group : groups) {
                ll on_line_pine = 0, on_line_larch = 0;
                for (const Point& C : group) {
                    if (C.type == 0) on_line_pine += C.value;
                    else on_line_larch += C.value;
                }
                for (int i = 0; i < group.size(); i++) {
                    const Point& C = group[i];
                    int idx_in_others = -1;
                    for (int j = 0; j < others.size(); j++) {
                        if (others[j].x == C.x && others[j].y == C.y) {
                            idx_in_others = j;
                            break;
                        }
                    }
                    if (idx_in_others == -1) continue;
                    if (side[idx_in_others] == 0) {
                        if (C.type == 0) left_pine -= C.value;
                        else left_larch -= C.value;
                    } else {
                        if (C.type == 0) right_pine -= C.value;
                        else right_larch -= C.value;
                    }
                }

                ll loss_on_line = base_loss + on_line_pine + on_line_larch;
                loss_half = min(left_larch + right_pine, left_pine + right_larch);
                global_ans = min(global_ans, loss_on_line + loss_half);

                for (int i = 0; i < group.size(); i++) {
                    const Point& C = group[i];
                    if (side[i] == 0) {
                        if (C.type == 0) right_pine += C.value;
                        else right_larch += C.value;
                    } else {
                        if (C.type == 0) left_pine += C.value;
                        else left_larch += C.value;
                    }
                }
            }
        }

        cout << global_ans << '\n';
    }

    return 0;
}