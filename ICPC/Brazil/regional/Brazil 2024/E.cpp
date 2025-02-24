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

const int INF = 1e18;

signed main() {
    fastio();

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int menor = 1;
    int l = 0, r = n-1;
    vi prox(n), ant(n, -1); /// guarda o indice do prox e ant que é dif de 0
    int ult = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) ult = i;
        ant[i] = ult;
    }
    ult = INF;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] != 0) ult = i;
        prox[i] = ult;
    }
    while (l <= r) {
        if (a[l] != 0 && a[r] != 0) {
            if (a[l] == menor) l++;
            else if (a[r] == menor) r--;
            else {
                cout << "*\n";
                return 0;
            }
        } else if (a[l] != 0) {
            if (a[l] == menor) l++;
            else {
                a[r] = menor;
                r--;
            }
        } else if (a[r] != 0) {
            if (a[r] == menor) r--;
            else {
                a[l] = menor;
                l++;
            }
        } else {
            int pl = prox[l], ar = ant[r];
            if (pl > r || ar < l) {
                a[l] = menor;
                l++;
            } else if (a[pl] < a[ar]) {
                a[l] = menor;
                l++;
            } else if (a[pl] > a[ar]) {
                a[r] = menor;
                r--;
            } else {
                if (pl - l < r - ar) {
                    a[l] = menor;
                    l++;
                } else {
                    a[r] = menor;
                    r--;
                }
            }
        }
        menor++;
    }


    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n-1 ? "\n" : " ");
    }
  
    return 0;
}