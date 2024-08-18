#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

typedef struct {
    ll time;
    int type; // +1 for arrival, -1 for leaving
} Event;

int compare_events(const void* a, const void* b) {
    Event* eventA = (Event*)a;
    Event* eventB = (Event*)b;
    
    if (eventA->time == eventB->time) {
        return eventA->type - eventB->type; // Arrival comes before leaving if times are the same
    }
    return (eventA->time < eventB->time) ? -1 : 1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of events must be greater than 0.\n");
        return 1;
    }

    Event* events = (Event*)malloc(2 * n * sizeof(Event));

    for (int i = 0; i < n; i++) {
        ll arrival, leaving;
        scanf("%lld %lld", &arrival, &leaving);
        events[2 * i].time = arrival;
        events[2 * i].type = 1; // arrival
        events[2 * i + 1].time = leaving;
        events[2 * i + 1].type = -1; // leaving
    }

    qsort(events, 2 * n, sizeof(Event), compare_events);

    int current_count = 0;
    int max_count = 0;

    for (int i = 0; i < 2 * n; i++) {
        current_count += events[i].type;
        if (current_count > max_count) {
            max_count = current_count;
        }
    }

    printf("%d\n", max_count);

    // Free the allocated memory
    free(events);

    return 0;
}
