int main()
{
    Account accounts[100]; 
    Account *foundAccount;
    int coun = 0;
    loadaccounts(accounts, 100, &coun); 
    searchByAccountNumber(accounts, coun, 1000000001, &foundAccount);
    if (foundAccount != NULL)
    {
        printf("Account found: %s\n", (*foundAccount).name);
    }
    else
    {
        printf("Account not found.\n");
    }
}
