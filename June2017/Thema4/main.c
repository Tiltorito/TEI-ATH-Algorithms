#include <stdio.h>
#include <stdlib.h>

#define null NULL
#define BOOL short
#define TRUE 1
#define FALSE 0

const char* inputFileName = "NUMBERS.TXT";   // Το ονομα του αρχειου εισοδου
const char* outputFileName = "NUMBERS1.TXT"; // Το ονομα του αρχειου εξοδου

BOOL contains(int* arr, int length, int value);

int main() {

    FILE* inputFile = fopen(inputFile, "r"); // ανοιγουμε το αρχειο για εισοδο

    if(inputFile != null) { // εαν ανοιξε το αρχειο εισοδου κομπλε

        FILE* outputFile = fopen(outputFileName, "w"); // ανοιγουμε το αρχειο για εξοδο

        if(outputFile != null) { // εαν ανοιξε το αρχειο εξοδου κομπλε
            int n;

            // Διαβαζουμε το πληθως των αριθμων που θα εισαγει ο χρηστης
            printf("Δωσε το πληθος των αριθμων που θα βαλεις: ");
            scanf("%d", n);

            // φτιαχνουμε εναν πινακα που θα μπει η εισοδος του χρηστη
            int* arr = (int*)malloc(sizeof(int) * n);

            // Διαβαζουμε τους αριθμους
            for(int i = 0; i < n; i++) {
                printf("Βαλε τον %d αριθμο: ", i+1);
                scanf("%d", arr + i);
            }

            int valueFromInput; // θα χρησημοποιειθει για να περνουμε 1-1 τους αριθμους απο το αρχειο εισοδου.

            while(fscanf(inputFile, "%d", &valueFromInput) != EOF) {
                // Εαν ο πινακας δεν περιεχει τον αριθμο που μολις διαβασαμε, γραψτον στο αρχειο.
                if(!contains(arr, n, valueFromInput)) {
                    fprintf(outputFile, "%d ", valueFromInput);
                }
            }

            fclose(outputFile); // κλεινουμε το αρχειο εξοδου
            free(arr);          // αποδεσμευουμε την μνημη που δεσμεφσαμε

        }
        else { // Δεν ανοιξαμε το αρχειο εξοδου..
            printf("Δεν μπορουμε να φτιαξουμε αρχειο με ονομα: %s\n", outputFileName);
        }

        fclose(inputFile); // κλεινουμε το αρχειο εισοδου..
    }
    else { // Δεν ανοιξαμε το αρχειο εισοδου..
        printf("Δεν υπαρχει το αρχειο: %s\n", inputFileName);
    }

    return 0;
}

/**
 * Κοιταει εαν ο πινακας περιεχει μια συγκεκριμενη τιμη.
 * @param arr       Ο πινακας.
 * @param length    Το μηκος του πινακα.
 * @param value     Η τιμη, ή οποια θα εξεταστη εαν υπαρχει μεσα στον πινακα στις προτες @length θεσεις του.
 * @return          Επιστρεφει TRUE εαν υπαρχει το @value μεσα στον πινακα @arr, FALSE διαφορειτκα.
 */
BOOL contains(int* arr, int length, int value) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == value) {
            return TRUE;
        }
    }

    return FALSE;
}