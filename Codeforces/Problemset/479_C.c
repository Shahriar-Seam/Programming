#include <stdio.h>
#include <stdlib.h>

typedef struct days days;

struct days {
    int scheduled;
    int before_schedule;
};

int compare(const void *a, const void *b)
{
    if (((days *) a)->scheduled != ((days *) b)->scheduled) {
        return ((days *) a)->scheduled - ((days *) b)->scheduled;
    }
    else {
        return ((days *) a)->before_schedule - ((days *) b)->before_schedule;
    }
}

int main()
{
    int n, i, last_day = 0;

    scanf("%d", &n);

    days drr[n];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &drr[i].scheduled, &drr[i].before_schedule);
    }

    qsort(drr, n, sizeof(days), compare);

    for (i = 0; i < n; i++) {
        last_day = (drr[i].before_schedule >= last_day) ? drr[i].before_schedule : drr[i].scheduled;
    }

    printf("%d\n", last_day);

    return 0;
}