#include "token.h"

// Simple state array for demonstration
Account ledger[MAX_USERS];
int user_count = 0;

void initialize_accounts() {
    strcpy(ledger[0].address, "Genesis");
    ledger[0].balance = 1000; 
    
    strcpy(ledger[1].address, "Node_A");
    ledger[1].balance = 0;
    
    strcpy(ledger[2].address, "Node_B");
    ledger[2].balance = 0;
    
    user_count = 3;
}

void print_balances() {
    printf("\n-- Current Ledger Balances --\n");
    for (int i = 0; i < user_count; i++) {
        printf("Address: %-10s | Balance: %d\n", ledger[i].address, ledger[i].balance);
    }
    printf("-------------------------------\n");
}

bool process_transaction(Transaction tx) {
    int sender_idx = -1;
    int receiver_idx = -1;

    // Locate accounts in the state
    for (int i = 0; i < user_count; i++) {
        if (strcmp(ledger[i].address, tx.sender) == 0) sender_idx = i;
        if (strcmp(ledger[i].address, tx.receiver) == 0) receiver_idx = i;
    }

    // Validation checks
    if (sender_idx == -1 || receiver_idx == -1) {
        printf("Transaction Failed: Invalid address.\n");
        return false;
    }
    if (tx.amount <= 0) {
        printf("Transaction Failed: Amount must be greater than zero.\n");
        return false;
    }
    if (ledger[sender_idx].balance < tx.amount) {
        printf("Transaction Failed: Insufficient funds for %s.\n", tx.sender);
        return false;
    }

    // Execute state change
    ledger[sender_idx].balance -= tx.amount;
    ledger[receiver_idx].balance += tx.amount;
    
    printf("Success: %d transferred from %s to %s.\n", tx.amount, tx.sender, tx.receiver);
    return true;
}
