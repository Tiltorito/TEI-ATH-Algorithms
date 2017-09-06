#include <stdio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define MAX_INT 0xFFFFFFFF

BOOL isEven(int number);
int divide(int number);
int multiply(int number);
BOOL coltatz(int startTerm, unsigned int times);

int main() {
    int givenNumber;

    // Διαβαζουμε τον αριθμο απο τον χρηστη.
    printf("Δωσε τον αρχικο ορο: ");
    scanf("%d", &givenNumber);

    // Οσο ο αριθμος ειναι μικρος ή ισος του 0, ξανα διαβαζε
    while(givenNumber <= 0) {
        printf("Δωσε αριθμο μεγαλυτερο του 0: ");
        scanf("%d", &givenNumber);
    }

    /**
     * Καλουμε την coltatz με MAX_INT φορες, ο λογος ειναι επειδη δεν ηθελα να κολησουμε σε κανα απειρο loop.
     * Εαν οντως βρουμε εναν αριθμο για τον οποιο δεν ισχυει η ακολουθια χωρις να βαζαμε για ποσες φορες να κανει την ακολουθια
     * μπορει να κολουσαμε σε ατερμον βρονχο.
     *
     */
    BOOL result = coltatz(givenNumber, MAX_INT);

    // Εαν επαλυθευτηκε
    if(result) {
        printf("Η ακολουθια επαλυθευτηκε\n");
    }
    else { // Εαν δεν επαλυθευτηκε
        printf(":O Η ακολουθια ΙΣΩΣ δεν ισχυει για τον αριθμο %d\n", givenNumber);
    }

    return 0;
}

/**
 * Αυτη η συναρτηση αποφασιζει εαν θα εκτελεσει την divide ή την multiply
 * @param startTerm Ο αρχικος ορος της ακολουθιας
 * @param times Ποσες φορες να κανει επαναληψη
 * @return Επιστρεφει 1 εαν επαλυθευτηκε η ακολουθια μεσα σε @times επαναλυψεις, 0 σε διαφορετικη περιπτωση.
 */
BOOL coltatz(int startTerm, unsigned int times) {

    int currentTerm = startTerm; // Ο τρεχον ορος, ξεκιναει απο τον αρχικο ορο

    for(int i = 0; i < times; i++) {
        /**
         * Εαν ο τρεχον ορος ειναι == 1 τοτε η ακολουθια επαλυθευτηκε, επιστρεφουμε true (1),
         * για να καταλαβει η συναρτηση η οποια καλεσε αυτην την συναρτηση οτι επαλυθευτηκε.
         */
        if(currentTerm == 1) {
            return TRUE;
        }

        /**
         * Ανεξαρτητα με το εαν ειναι μονος ή ζυγος ο τρεχον ορος της ακολουθιας θα αλλαξει στον επομενο.
         */
        if(isEven(currentTerm)) { // Εαν ειναι ζυγος, καλουμε την divide
            currentTerm = divide(currentTerm);
        }
        else { // Εαν ειναι περιτος, καλουμε την multiply
            currentTerm = multiply(currentTerm);
        }
    }
    /**
     * Για να εχουμε φτασει εδω, σημαινει οτι ο currentTerm δεν εγινε ποτε == 1 (εαν ειχε γινει θα ειχε τερματισει)
     * και το for τελειωσε επιτυχος, αρα ή ακολουθεια δεν επαλυθευτηκε.
     */
    return FALSE;
}


BOOL isEven(int number) {
    return number % 2 == 0;
}

/**
 * Αυτη η συναρτηση θα καλειτε οταν ο αριθμος ειναι ζυγος, εμφανιζει στην οθονη το βημα.
 * @param number Ο ζυγος αριθμος
 * @return επιστρεφει @number / 2
 */
int divide(int number) {
    int result = number / 2;
    printf("%d / 2 = %d\n", number, result);

    return result;
}

/**
 * Αυτη η συναρτηση θα καλειτε οταν ο αριθμος ειναι περιτος, εμφανιζει στην οθονη το βημα.
 * @param number Ο αριθμος της ακολουθιας ο οποιος ειναι περιτος.
 * @return 3 * @number + 1
 */
int multiply(int number) {
    int result = 3 * number + 1;
    printf("3 * %d + 1 = %d\n", number, result);

    return result;
}