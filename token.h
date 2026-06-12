#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 10
#define NAME_LEN 32

typedef struct {
    char address[NAME_LEN];
    int balance;
} Account;

typedef struct {
    char sender[NAME_LEN];
    char receiver[NAME_LEN];
    int amount;
} Transaction;

// Function Prototypes
void initialize_accounts();
void print_balances();
bool process_transaction(Transaction tx);

#endif // TOKEN_H
