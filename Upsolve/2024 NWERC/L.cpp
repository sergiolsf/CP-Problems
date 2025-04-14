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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vi shelf(n), book(m);
    for (auto &i: shelf) cin >> i;
    for (auto &i: book) cin >> i;

    sort(all(shelf));
    sort(all(book));

    vi qnt(n, 0);

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (book[i] > shelf[j]) {
            j++;
            continue;
        }
        int cont = 0;
        while (i < m && book[i] <= shelf[j] && cont < x) {
            cont++;
            i++;
        }
        qnt[j] = cont;
        j++;
    }

    if (i < m) {
        cout << "impossible\n";
        return 0;
    }

    int add = 0;
    int ans = 0;
    for (int k = n-1; k >= 0; k--) {
        if (qnt[k] <= y) {
            add += y-qnt[k];
            ans++;
        } else {
            if (add >= qnt[k]-y) {
                add -= qnt[k]-y;
                ans++;
            } else {
                add += x-qnt[k];
            }
        }
    }

    cout << ans << endl;
  
    return 0;
}