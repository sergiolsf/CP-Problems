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
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        for (int j = 1; j <= 2*(n-i)-1; j++) cout << " ";

        for (int j = 0; j < i; j++) {
            cout << " " << j;
        }

        cout << " " << i;

        for (int j = i-1; j >= 0; j--) {
            cout << " " << j;
        }

        cout << endl;
    }

    for (int i = 0; i <= n; i++) cout << i << " ";
    for (int i = n-1; i > 0; i--) cout << i << " ";
    cout << 0 << endl;

    for (int i = n-1; i >= 0; i--) {
        for (int j = 1; j <= 2*(n-i)-1; j++) cout << " ";
        for (int j = 0; j < i; j++) {
            cout << " " << j;
        }
        cout << " " << i;
        for (int j = i-1; j >= 0; j--) {
            cout << " " << j;
        }
        cout << endl;
    }
  
    return 0;
}