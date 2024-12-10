#include <stdio.h>
#include <stdlib.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {
    int* connection_indexes = malloc(sizeof(int));
    int counter = 0;

    for (int i = 0; i < n; i++) {
        int cell_left_limit = cells[i] - distance;
        int cell_right_limit = cells[i] + distance;

        if (user >= cell_left_limit && user <= cell_right_limit) {
            connection_indexes[counter] = i;
            connection_indexes = realloc(connection_indexes, sizeof(int) * (counter + 1));

            counter += 1;
        } 
    }

    if (counter != 0) {
        *left_index = connection_indexes[0];
        *right_index = connection_indexes[counter - 1];
    }

    return counter == 0;
}

int main(void) {
    int num_cells, distance, user;

    scanf("%d %d %d", &num_cells, &distance, &user);

    int cells[num_cells];
    for (int i = 0; i < num_cells; i++) {
        int pos;
        scanf("%d", &pos);

        cells[i] = pos;
    }

    int left_index, right_index;
    int is_user_disconnected = get_range(num_cells, cells, distance, user, &left_index, &right_index);

    if (is_user_disconnected) {
        printf("USUARIO DESCONECTADO\n");
    } else {
        for (int i = left_index; i <= right_index; i++) {
            printf("%d ", cells[i]);
        }
    }
}