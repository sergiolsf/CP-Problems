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

signed main() {
    fastio();
    int a[6];

    for (int i = 1; i <= 5; i++) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 1; i <= 5; i++) {
        if (a[i] != i) {
            a[i] = -1;
            count++;
        }
    }

    if (count != 2) {
        cout << "No\n";
        return 0;
    }

    for (int i = 1; i < 5; i++) {
        if (a[i] == -1 && a[i+1] == -1) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";    
    return 0;
}