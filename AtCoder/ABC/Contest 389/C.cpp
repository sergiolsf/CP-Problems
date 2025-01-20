#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<pii> snakes;
int ult = 0;
int del = 0;
int tira = 0;

signed main() {
    fastio();
    int Q;
    cin >> Q;

    while (Q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int l;
            cin >> l;
            snakes.push_back({ult, l});
            ult += l;
        } else if (c == 2) {
            tira += snakes[del].second;
            del++;
        } else {
            int k;
            cin >> k;
            cout << snakes[k-1+del].first - tira << endl;

        }

    }

    return 0;
}