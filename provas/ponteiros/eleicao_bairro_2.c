#include <stdio.h>

#define MAX 20

typedef struct {
    int id;
    char name[MAX];
    int votes;
} Party;

int get_index_party_by_id(int id, int parties_length, Party parties[parties_length]) {
    int index = -1;

    for (int i = 0; i < parties_length; i++) {
        if (id == parties[i].id) {
            index = i;
        }
    }

    return index;
}

int compute_votes(
  int num_votes, int votes[num_votes],
  int num_parties, Party parties[num_parties],
  Party *most_voted, Party *second_most_voted
) {
    int valid_votes = 0;

    for (int i = 0; i < num_votes; i++) {
        int index_result = get_index_party_by_id(votes[i], num_parties, parties);

        if (index_result != -1) {
            parties[index_result].votes += 1;
            valid_votes += 1;
        }
    }

    int first = 0, second = 0;

    for (int i = 0; i < num_parties; i++) {
        if (parties[i].votes > first) {
            first = parties[i].votes;
            *most_voted = parties[i];
        }
    }

    second = first - parties[0].votes;
    *second_most_voted = parties[0];

    for (int i = 0; i < num_parties; i++) {
        if ((first - parties[i].votes) < second && parties[i].id != most_voted->id) {
            second = first - parties[i].votes;
            *second_most_voted = parties[i];
        }
    }

    return valid_votes;
}

int main(void) {
    int n, m;
    scanf("%d", &n);

    Party parties[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &parties[i].id, parties[i].name);
        getchar();

        parties[i].votes = 0;
    }

    scanf("%d", &m);
    int votes[m];

    for (int i = 0; i < m; i++) {
        scanf("%d", &votes[i]);
    }

    Party most_voted, second_most_voted;

    int valid_votes = compute_votes(m, votes, n, parties, &most_voted, &second_most_voted);

    float most_voted_percent = ((float)most_voted.votes / (float)valid_votes) * 100;
    float second_most_voted_percent = ((float)second_most_voted.votes / (float)valid_votes) * 100;

    printf("VENCEDOR: %s (%d votos = %.2f\%)\n", most_voted.name, most_voted.votes, most_voted_percent);
    printf("VICE: %s (%d votos = %.2f\%)\n", second_most_voted.name, second_most_voted.votes, second_most_voted_percent);
}