struct BANK_ACCOUNT
{
    char type; // ‘S’=savings, ‘C’=checking
    double balance;
    union ACCOUNT_SPECIFIC {
        double charge;    // for withdrawal from savings accounts
        int credit_score; // for checking account
    } specific;
};

