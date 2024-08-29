#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// Binary search to find the first element that is greater than the target
int binary_search(ll *arr, int left, int right, ll target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int n;
    scanf("%d", &n);

    ll *cubes = (ll *)malloc(n * sizeof(ll)); // Explicit cast to (ll*)
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &cubes[i]);
    }

    ll *towers = (ll *)malloc(n * sizeof(ll)); // Explicit cast to (ll*)
    int tower_count = 0;

    for (int i = 0; i < n; i++)
    {
        int pos = binary_search(towers, 0, tower_count - 1, cubes[i]);

        // If position to place cube is equal to tower_count, a new tower is needed
        if (pos == tower_count)
        {
            towers[tower_count++] = cubes[i];
        }
        else
        {
            towers[pos] = cubes[i];
        }
    }

    printf("%d\n", tower_count);

    free(cubes);
    free(towers);
    return 0;
}
