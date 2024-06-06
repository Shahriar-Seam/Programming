#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct player player;

struct player {
    char name[35];
    int score;
    int time;
};

int compare(const void *a, const void *b)
{
    if (((player *) a)->score == ((player *) b)->score) {
        return ((player *) a)->time - ((player *) b)->time;
    }
    else {
        return ((player *) b)->score - ((player *) a)->score;
    }
}

int find(player *pl, char *name, int *size)
{
    int i;

    for (i = 0; i < *size; i++) {
        if (strcmp(pl[i].name, name) == 0) {
            return i;
        }
    }

    *size = *size + 1;

    return i;
}

int num_of_players_with_max_score(player *pl, int size)
{
    int i;

    for (i = 1; i < size; i++) {
        if (pl[i].score != pl[0].score) {
            break;
        }
    }

    return i;
}

int is_present(player *pl, char *name, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(pl[i].name, name) == 0) {
            return 1;
        }
    }

    return 0;
} 

int main()
{
    int n, i, score, index, size = 0, max_num;
    char name[35];

    scanf("%d", &n);

    player pl[n];
    player all[n];

    for (i = 0; i < n; i++) {
        pl[i].score = 0;
    }

    for (i = 0; i < n; i++) {
        scanf(" %s %d", name, &score);

        strcpy(all[i].name, name);
        all[i].score = score;
        all[i].time = i;

        index = find(pl, name, &size);

        strcpy(pl[index].name, name);
        pl[index].score += score;
        pl[index].time = i;
    }

    qsort(pl, size, sizeof(player), compare);

    strcpy(name, pl[0].name);

    if (pl[0].score == pl[1].score) {
        player who_did_it_first[size];

        for (i = 0; i < size; i++) {
            who_did_it_first[i].score = 0;
        }

        max_num = num_of_players_with_max_score(pl, size);
        size = 0;

        for (i = 0; i < n; i++) {
            if (is_present(pl, all[i].name, max_num) == 0) {
                continue;
            }

            strcpy(name, all[i].name);
            score = all[i].score;

            index = find(who_did_it_first, name, &size);

            strcpy(who_did_it_first[index].name, name);
            who_did_it_first[index].score += score;
            who_did_it_first[index].time = i;

            if (who_did_it_first[index].score >= pl[0].score) {
                strcpy(name, who_did_it_first[index].name);

                break;
            }
        }
    }

    printf("%s", name);

    return 0;
}