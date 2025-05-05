#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    set<int> ys;
    for (auto &p : points) {
        cin >> p.first >> p.second;
        ys.insert(p.second);
    }

    // Find the smallest y_coord not used by any point
    int y_coord = 1;
    while (ys.count(y_coord)) {
        y_coord++;
    }

    // Sort points by x then y
    sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    // Group points by x
    vector<vector<pair<int, int>>> groups;
    int current_x = -1;
    for (auto &p : points) {
        if (p.first != current_x) {
            groups.push_back(vector<pair<int, int>>());
            current_x = p.first;
        }
        groups.back().push_back(p);
    }

    vector<pair<int, int>> vertices;
    int first_x = -1, first_y = -1;

    for (size_t i = 0; i < groups.size(); ++i) {
        int x = groups[i][0].first;
        vertices.emplace_back(x, y_coord);
        if (first_x == -1) {
            first_x = x;
            first_y = y_coord;
        }

        for (auto &p : groups[i]) {
            vertices.push_back(p);
        }

        // Add next helper if not the last group
        if (i != groups.size() - 1) {
            int next_x = x + 1;
            vertices.emplace_back(next_x, y_coord);
        }
    }

    // Close the polygon
    vertices.emplace_back(first_x, first_y);

    // Remove consecutive duplicates
    vector<pair<int, int>> unique_verts;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (i == 0 || vertices[i] != vertices[i-1]) {
            unique_verts.push_back(vertices[i]);
        }
    }

    cout << unique_verts.size() << endl;
    for (auto &p : unique_verts) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}