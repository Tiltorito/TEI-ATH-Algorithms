#include <iostream>


/**
 * Το struct χρησημευει για να γυρισω 2 τιμες απο την συναρτηση...
 * Εναλακτικα θα μπορουσαμε να γυρισουμε εναν πινακα με 2 θεσεις
 */
typedef struct {
    int buyIndex;
    int sellIndex;
} Result;

int calculateProfit(int*, int , int );
Result findBetterDays(int*, int);

int main() {
    // Οι τιμες των μετοχων
    int stockPrices[7] = {4, 1, 8, 2, 5, 8, 4};

    // Περνουμε το αποτελεσμα
    Result result = findBetterDays(stockPrices, 7);

    // Εμφανιζουμε το αποτελεσμα
    int profit = stockPrices[result.sellIndex] - stockPrices[result.buyIndex];
    printf("buyIndex: %d\nsellIndex: %d\nprofit: %d\n", result.buyIndex, result.sellIndex, profit);

    return 0;
}

/**
 * Υπολογιζει τις καλυτερες δυνατες μερες που μπορουμε να αγορασουμε και να πουλισουμε μια μετοχη.
 * @param stockPrices    Οι τιμες των μετοχων.
 * @param n              Το πληθως των ημερων.
 * @return               Επιστρεφει μια δομη ή οποια περιεχει το καλυτερο δυνατο σημειο αγορας και πολησης μιας μετοχης.
 */
Result findBetterDays(int* stockPrices, int n) {
    int buyIndex = 0; // αυτος ο δικτης θα διχνει την ημερα που θα πρεπει να αγοραζουμε την μετοχη
    int sellIndex = 0; // αυτος ο δικης θα διχνει την ημερα που θα πρεπει να πουλισουμε την μετοχη ωστε να βγαλουμε το μεγιστο κερδος
    int profit = -1; // το κερδος, το κανουμε initilize με -1 για να αλλαξει γρηγορα.

    /**
     * Πολυπλοκοτητα O(n^2) δεν μπορουσα να σκεφτω κατι καλυτερο ουτε ηθελα να το καψω..
     * Κοιταμε για ολους τους συνδιασμους να βρουμε την καλυτερη επιλογη..
     */
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {

            /**
             * Καλοντας την calculateProfit για 2 index μας επιστρεφει ποσα λεφτα κερδιζουμε
             * εαν αγορασουμε στο i και πουλισουμε στο j
             */
            int tempProfit = calculateProfit(stockPrices,i,j);

            if(tempProfit > profit) { // Εαν το κερδος που πειραμε με τον απο πανω υπολογισμω ειναι μεγαλυτερο του γενικου κερδους
                // ενημερωσε τους δεικτες
                buyIndex = i;
                sellIndex = j;
                // ενημερωσε το κερδος
                profit = tempProfit;
            }
        }
    }

    Result result = {buyIndex,sellIndex}; // init το struct με τα index

    return result; // επιστρεφουμε το αποτελεσμα
}

/**
 * Δεχετε τον πινακα των μετοχων και 2 θεσεις σε αυτον & επιστρεφει το κερδος που θα εχουμε εαν αγορασουμε την μετοχη στο buyIndex και την πουλησουμε στο sellIndex
 * @param arr         Ο πινακας των μετοχων
 * @param buyIndex    Το index που θα αγορασουμε την μετοχη
 * @param sellIndex   Το index που θα πουλησουμε την μετοχη
 * @return            Επιστρεφει το κερδος που θα εχουμε εαν αγορασουμε την μετοχη στο buyIndex και την πουλησουμε στο sellIndex
 */
int calculateProfit(int* arr, int buyIndex, int sellIndex) {
    return arr[sellIndex] - arr[buyIndex];
}


