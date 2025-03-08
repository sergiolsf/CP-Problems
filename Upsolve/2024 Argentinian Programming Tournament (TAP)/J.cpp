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

int n, x;
vi b;

void troca () {
    for (int i = 1; i < n; i++) {
        if (b[i]+b[i-1] == x) {
            if (b[i-1] != b[0]) swap(b[0], b[i-1]);
            else if (b[i] != b[n-1]) swap(b[i], b[n-1]);
            else {
                cout << "*\n";
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << ((i == n-1) ? "\n" : " ");
    }
}

signed main() {
    fastio();
    cin >> n >> x;
    b.resize(n);
    for (auto &i : b) cin >> i;

    sort(all(b));

    if (x&1) {
        troca();
    } else {
        int cnt = upper_bound(all(b), x/2) - lower_bound(all(b), x/2);
        if (cnt < 2) {
            troca();
        } else {
            if (cnt > (n-cnt)+1) cout << "*\n";
            else {
                bool ant = false;
                int c = 1;
                for (int i = 0; i < n; i++) {
                    if (c < cnt && b[i] != x/2 && !ant) {
                        c++;
                        cout << x/2 << " ";
                    }
                    ant = false;
                    if (b[i] != x/2) cout << b[i] << ((i == n-1 && cnt == c) ? "\n" : " ");
                    else {
                        while (i < n && b[i] == x/2) i++;
                        i--;
                        cout << x/2 << ((i == n-1) ? "\n" : " ");
                        ant = true;
                    }
                }
                if (c < cnt) cout << x/2 << endl;
            }
        }
    }
  
    return 0;
}