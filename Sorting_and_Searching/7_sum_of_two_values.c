#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;
typedef struct {
    ll val;
    int idx;
} map_entry;

int compare(const void *a, const void *b) {
    return ((map_entry *)a)->val - ((map_entry *)b)->val;
}

int binary_search(map_entry *map, int size, ll target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (map[mid].val == target) {
            return map[mid].idx;
        } else if (map[mid].val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int n;
    ll target;
    scanf("%d %lld", &n, &target);

    map_entry *map = (map_entry *)malloc(n * sizeof(map_entry));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &map[i].val);
        map[i].idx = i;
    }

    // Sort the array based on values
    qsort(map, n, sizeof(map_entry), compare);

    for (int i = 0; i < n; i++) {
        ll complement = target - map[i].val;
        int complement_idx = binary_search(map, n, complement);

        if (complement_idx != -1 && complement_idx != map[i].idx) {
            if (map[i].idx < complement_idx) {
                printf("%d %d\n", map[i].idx + 1, complement_idx + 1);
            } else {
                printf("%d %d\n", complement_idx + 1, map[i].idx + 1);
            }
            free(map);
            return 0;
        }
    }

    printf("IMPOSSIBLE\n");
    free(map);
    return 0;
}
