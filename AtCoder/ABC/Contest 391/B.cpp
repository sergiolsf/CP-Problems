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
    int N, M;
    cin >> N >> M;

    vector<vector<char>> S(N+1, vector<char>(N+1));
    vector<vector<char>> T(M+1, vector<char>(M+1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> T[i][j];
        }
    }

    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            bool ok = true;
            for (int i = 1; i <= M && ok; i++) {
                for (int j = 1; j <= M && ok; j++) {
                    if (T[i][j] != S[a+i-1][b+j-1]) ok = false;
                }
            }
            if (ok) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
  
    return 0;
}