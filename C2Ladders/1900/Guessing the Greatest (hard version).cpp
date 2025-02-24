#include <bits/stdc++.h>

signed main() {
    int n;
    scanf("%d", &n);

    printf("? 1 %d\n", n);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    int l, r;
    if (k > 1) {
        printf("? 1 %d\n", k);
        fflush(stdout);
        int p;
        scanf("%d", &p);
        if (p == k) {
            l = 0;
            r = k;
        } else {
            l = k;
            r = n+1;
        }
    } else {
        l = 1; 
        r = n+1;
    }
    if (r == n+1) {
        while (r-l != 1) {
            int m = (l+r)/2;
            printf("? %d %d\n", k, m);
            fflush(stdout);
            int p;
            scanf("%d", &p);
            if (p != k) l = m;
            else r = m;
        }
        printf("! %d\n", r);
        fflush(stdout);        
    } else {
        while (r-l != 1) {
            int m = (l+r)/2;
            printf("? %d %d\n", m, k);
            fflush(stdout);
            int p;
            scanf("%d", &p);
            if (p != k) r = m;
            else l = m;
        }
        printf("! %d\n", l);
        fflush(stdout);
    }    
    
    return 0;
}