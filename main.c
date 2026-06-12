#include "token.h"

int main() {
    initialize_accounts();
    print_balances();

    // Valid Transaction
    Transaction tx1 = {"Genesis", "Node_A", 250};
    process_transaction(tx1);

    // Invalid Transaction (Insufficient funds)
    Transaction tx2 = {"Node_B", "Node_A", 50};
    process_transaction(tx2);

    // Valid Transaction
    Transaction tx3 = {"Node_A", "Node_B", 100};
    process_transaction(tx3);

    print_balances();

    return 0;
}
