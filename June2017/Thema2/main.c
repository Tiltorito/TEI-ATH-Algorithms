#include <stdio.h>
#include <stdlib.h>

#define BOOL short
#define TRUE 1
#define FALSE 0

int* addArrays(int A[], int B[], int N);
void printArray(int array[], int N);


/**
 * Μερικα σχολια. Η υποθεση μας λεει οτι ειναι μικροτερου του Ν τα ψηφια του καθε αριθμου.
 * Εαν υποθεσουμε οτι και στους 2 πινακες βρισκετε ο μεγαλυτερος αριθμος που μπορει να υπαρξει με N-1 ψηφια,
 * το τελικο αποτελεσμα θα ειναι το πολυ N ψηφια.
 * πχ, εστω N = 4, μεγαλυτερος αριθμος με N-1 = 3 ψηφια ειναι ο 999,  999 + 999 = 1998
 */

int main() {
    int N = 10;

    int A[10] = {8,1,3,4 /* οι υπολοιπες θεσεις θα γινουν 0 */};
    int B[10] = {2,4,6,1,7 /* οι υπολοιπες θεσεις θα γινουν 0 */};

    // Περνουμε τον τελικο πινακα.
    int* C = addArrays(A, B, N);

    // Τον εμφανιζουμε.
    printArray(C, N);

    // Τελος αποδεσμευουμε την μνημη που δεσμεψαμε δυναμικα.
    free(C);

    return 0;
}

/**
 * Δεχετε 2 πινακες μεγεθους Ν και επιστρεφει εναν αλλον πινακα ο οποιος περιεχει
 * το αθροισμα τον ψηφιων τους.
 * @param A Ο πρωτος πινακας.
 * @param B Ο δευτερος πινακας.
 * @param N Το μεγεθος των πινακων.
 * @return  επιστρεφει εναν δικτη σε εναν δυναμικα δεσμευμενο πινακα ο οποιος
 *          περιεχει το αθροισμα των ψηφιων των 2 παραπανω πυνακων.
 */
int* addArrays(int A[], int B[], int N) {

    /**
     * Δεσμευουμε δυναμικα N * sizeof(int) bytes για τον C πινακα.
     * Η calloc ειναι ιδια με malloc απλα αρχικοποιει την μνημη στο 0, για να μην εχουμε σκουπιδια.
     */
    int* C = (int*)calloc(N, sizeof(int));

    /**
     * Αυτη η μεταβλητη θα μας βοηθησει να καταλαβουμε εαν υπαρχει κρατουμενο.
     * Θα περνει τιμες 1 ή 0, ετσι και αλλιως το μεγιστο κρατουμενο που μπορει να παρει ειναι το 1.
     */
    BOOL hasCarry = FALSE;
    for(int i = 0; i < N; i++) {

        // Προσθετουμε τα 2 ψηφια, στο τελος του for, αυτο που θα μπει στο πινακα C[i] θα ειναι το sum

        int sum = A[i] + B[i];

        // Κοιταμε εαν εχουμε προηγουμενο κρατουμενο
        if(hasCarry) {
            /**
             * Εαν εχουμε, αυξησε κατα 1 το αποτελεσμα της προσθεσεις που καναμε απο πανω
             * και σημειωσε οτι πλεον δεν εχουμε κρατουμενο.
             */
            sum++;
            hasCarry = FALSE;
        }

        /**
         * Εαν το αθοισμα ειναι μεγαλυτερο του 10, τοτε εχουμε κρατουμενο, βαλε TRUE στο flag,
         * και αφερεσε 10 ή παρε το υπολοιπο της διερεσεις με το 10 απο το αθροισμα.
         */
        if(sum >= 10) {
            hasCarry = TRUE;
            sum = sum % 10;
        }

        // Τελος βαλε το αθροισμα στον πινακα C
        C[i] = sum;
    }

    return C;
}

/**
 * Μεθοδος η οποια εμφανιζει τα περιοχομενα ενος ακερεου πινακα.
 * @param array ο πινακας του οποιου θα εμφανισει τα στοιχια.
 * @param N ο μεγιστος αριθμος ψηφιων που θα εμφανιστουν.
 */
void printArray(int array[], int N) {
    for(int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
}