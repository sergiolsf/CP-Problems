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
    int s, n; cin >> s >> n;
    swap(s, n);
    int ant = 0;
    while (n--) {
        int a; cin >> a;
        if (a-ant > s) {
            cout << "No\n";
            return 0;
        }
        ant =  a;
    }

    cout << "Yes\n";
  
    return 0;
}