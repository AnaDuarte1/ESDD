#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 21

void bubble_sort(char students[][MAX_NAME_LENGTH], int n);

int main() {
    int n, k;
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%s", students[i]);
    }

    bubble_sort(students, n);

    printf("%s\n", students[k - 1]);

    return 0;
}
void bubble_sort(char students[][MAX_NAME_LENGTH], int n) {
    char temp[MAX_NAME_LENGTH];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j], students[j + 1]) > 0) {
                // Troca os nomes
                strcpy(temp, students[j]);
                strcpy(students[j], students[j + 1]);
                strcpy(students[j + 1], temp);
            }
        }
    }
}
