#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Movie;

int compare_movies(const void* a, const void* b) {
    Movie* movieA = (Movie*)a;
    Movie* movieB = (Movie*)b;
    return movieA->end - movieB->end;
}

int main(void) {
    int n;
    scanf("%d", &n);

    Movie* movies = (Movie*)malloc(n * sizeof(Movie));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &movies[i].start, &movies[i].end);
    }

    // Sort the movies by their ending times
    qsort(movies, n, sizeof(Movie), compare_movies);

    int count = 0;
    int last_end_time = 0;

    for (int i = 0; i < n; i++) {
        if (movies[i].start >= last_end_time) {
            count++;
            last_end_time = movies[i].end;
        }
    }

    printf("%d\n", count);

    free(movies);
    return 0;
}
