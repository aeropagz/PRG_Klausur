#include <stdio.h>
#include <math.h>

#define LAENGE 10

void clearStdInput(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int enthalten(char string[], int size, char c) {
    int i;

    if (c <= 97 || c >= 122)
        return -1;
    for (i = 0; i < size; i++) {
        if (string[i] == c) {
            return 1;
        }
    }
    return 0;
}

int zaehleZeichen(char ein[]) {
    int i = 0;
    while (ein[i] != '\0') {
        i++;
    }
    return i;
}

int palindrom(char ein[]) {
    int i = 0, j = zaehleZeichen(ein) - 1;
    if ((zaehleZeichen(ein) % 2) != 0) {
        printf("ungerade Anzahl an zeichen\n");
        return 0;
    }
    for (i, j; i < zaehleZeichen(ein) && j >= 0; i++, j--) {
        printf("%c - %c\n", ein[i], ein[j]);
        if (j < i)
            break;
        if (ein[i] != ein[j])
            return 0;
    }
    return 1;
}

double pnorm(int vektor[], int n, int p) {
    int i, result = 0;
    for (i = 0; i < n; i++) {
        result += pow((double) fabs(vektor[i]), (double) p);
    }
    return pow(result, 1.0 / p);
}

int main(void) {
    char buffer[256];
    int nums[LAENGE] = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9};
    int p, i, j;
    unsigned long long reis[8][8];
    unsigned long long reiskoerner = 1;
    unsigned long long insgesamt = 0;
    // Aufgabe 6
    do {
        scanf("%s", &buffer);
        printf("Ist ein Palindrom: %d \n", palindrom(buffer));
        clearStdInput();
    } while (buffer[0] != '0');
    printf("Goodbye\n");

    // Aufgabe 7
    while (1) {
        printf("Welche Norm soll berechnet werden?  ");
        scanf("%d", &p);
        clearStdInput();
        for (i = 0; i < LAENGE; i++) {
            printf("%d, ", nums[i]);
        }
        printf("\n");
        if (p == 0) {
            break;
        }
        printf("%.4f\n", pnorm(nums, LAENGE, p));
    }

    // Aufgabe 8
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("i: %d - j: %d\n", i, j);
            reis[i][j] = reiskoerner;
            printf("Auf dem letzten Reisfeld liegen %llu Reiskoerner\n", reiskoerner);
            insgesamt += reiskoerner;
            reiskoerner *= 2;
        }
    }
    printf("Reiskoerner insgesamt: %f Tonnen", insgesamt / (1000.0 * 20000));
}


