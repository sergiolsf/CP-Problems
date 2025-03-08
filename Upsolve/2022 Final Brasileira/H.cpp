#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    int n; cin >> n;
    map<string, pii> mp; // string, numero, qtd de vezes que aparece
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s] = {0, 0};
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int m, w; cin >> m >> w;
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            if (mp[s].second == w) mp[s].first++;
            else if (mp[s].second < w) mp[s] = {w, 1};
        }
    }

    vector<tuple<int, int, string>> tp;
    for (auto e: mp) {
        tp.push_back({e.second.first, -e.second.second, e.first});
    }
    sort(all(tp));

    deque<string> lista;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        int pos, qtd; string s;
        if (j < n) tie(pos, qtd, s) = tp[j];

        if (j < n && pos < i) lista.push_back(s);
        else if (j < n && pos == i) {
            cout << s << endl;
            j++;
        } else {
            cout << lista.front() << " ";
            lista.pop_front();
        }
        int p1, p2; string p3;
        if (j < n) tie(p1, p2, p3) = tp[j];
        while (j < n && p1 == i) {
            lista.push_back(p3);
            j++;
            tie(p1, p2, p3) = tp[j];
        }
    }
  
    return 0;
}