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
    vector<pii> person(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        person[i] = {a, i+1};
    }

    sort(all(person));

    if (person[n-1].first != person[n-2].first) {
        cout << person[n-1].second << endl;
        return 0;
    }

    for (int i = n-2; i > 0; i--) {
        if (person[i].first != person[i-1].first && person[i].first != person[i+1].first) {
            cout << person[i].second << endl;
            return 0;
        }
    }

    if (person[0].first != person[1].first) {
        cout << person[0].second << endl;
        return 0;
    }

    cout << -1 << endl;
  
    return 0;
}