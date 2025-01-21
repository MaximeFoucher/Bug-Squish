#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *chaine = (char *) malloc(1000 * sizeof(char)); // Déclare une chaîne de caractères
    printf("Entrez une chaine de caracteres : \n");
    scanf("%s", chaine); // Lit une chaîne de caractères
    int taille = strlen(chaine);
    chaine = (char *) realloc(chaine, (taille+1) * sizeof(char));

    for (int i = 0; chaine[i] != '\0'; ++i) {
        if (chaine[i] == 'b' && chaine[i+1] == 'u' && chaine[i+2] == 'g' && chaine[i+3] != 's'){
            for (int j = i; chaine[j+3] != '\0'; ++j) {
                chaine[j] = chaine[j+3];
            }
            //diminuer taille tableau
            taille -= 3;
            i -= 1;
        }
        chaine[taille]='\0';
    }
    // Affiche la réponse
    printf("Lettres dans le tableau sans le(s) bug :\n");
    for (int i = 0; chaine[i] != '\0'; i++) {
        printf("%c", chaine[i]);
    }
    free(chaine);
    return 0;
}