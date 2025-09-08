#include <stdio.h>

char minuscule(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int main() {
    char ch;

    printf("Entrez un caractere : ");
    scanf(" %c", &ch);

    printf("Minuscule : %c\n", minuscule(ch));

    return 0;
}