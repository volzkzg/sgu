#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int k;
    int b;
    int i;
} node;

int cmp1(const void* a, const void* b) {
    node* pa = (node*)a;
    node* pb = (node*)b;
    return pb->b - pa->b;
}

int cmp2(const void* a, const void* b) {
    node* pa = (node*)a;
    node* pb = (node*)b;
    return pa->i - pb->i;
}

int main(void) {
    int n, m, y;
    scanf ("%d%d%d", &n, &m, &y);
    int x[1000];
    node h[1000];
    int i, total = m;
    for (i = 0; i < n; ++i) {
        scanf ("%d", x+i);
        h[i].k = m*x[i]/y;
        h[i].b = m*x[i]%y;
        h[i].i = i;
        total -= h[i].k;
    }
    qsort(h, n, sizeof(h[0]), cmp1);
    i = 0;
    while (total--) {
        h[i++].k++;
    }
    qsort(h, n, sizeof(h[0]), cmp2);
    printf ("%d", h[0].k);
    for (i = 1; i < n; ++i) {
        printf (" %d", h[i].k);
    }
    printf ("\n");
    return 0;
}
