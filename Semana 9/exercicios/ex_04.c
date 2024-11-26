#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 1000
#define CODE_LENGTH 5

void bubble_sort(char books[][CODE_LENGTH], int n);


int main() {
    char books[MAX_BOOKS][CODE_LENGTH];
    int n;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", books[i]);
        }

        bubble_sort(books, n);

        for (int i = 0; i < n; i++) {
            printf("%s\n", books[i]);
        }

    }

    return 0;
}

void bubble_sort(char books[][CODE_LENGTH], int n) {
    char temp[CODE_LENGTH];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(books[j], books[j + 1]) > 0) {
                // Troca os elementos
                strcpy(temp, books[j]);
                strcpy(books[j], books[j + 1]);
                strcpy(books[j + 1], temp);
            }
        }
    }
}