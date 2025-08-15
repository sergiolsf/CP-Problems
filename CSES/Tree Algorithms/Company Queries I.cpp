#include <iostream>
#include <vector>
using namespace std;

const int max_N = 200'005;
int jmp[max_N][20];
int depth[max_N];

int main() {
    int n, q;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            jmp[i][j] = -1;
        }
    }

    for (int i = 1; i < n; ++i) {
        cin >> jmp[i][0];
        jmp[i][0]--;
    }

    for (int j = 0; (1 << j) <= n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (jmp[i][j] == -1) continue;
            jmp[i][j + 1] = jmp[jmp[i][j]][j];
        }
    }

    for (int qi = 0; qi < q; ++qi) {
        int a, k;
        cin >> a >> k;
        a--;

        int ans;
        for (int j = 19; j >= 0; j--) {
            if (k & (1<<j)) {
                a = jmp[a][j];
            } 
            if (a == -1) {
                ans = -1;
                break;
            }
        }
        
        ans = a;
        if (ans != -1) ans++;
        cout << ans << endl;
    }
}