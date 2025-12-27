#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"system_structs.h"


Account *DeleteByAccountNumber(int *newcount)
{
    Account acc;
    int count = 0 ;
    Account *Accounts = NULL,*temp ,*newaccounts;
    int i , j =0 ; 
    FILE *f = fopen("accounts.txt","r");
    if(f==NULL)
    {
        printf("Error,File Not Founded.");
        exit(1) ;
    }
    while(fscanf(f,"%lld,%49[^,],%49[^,],%f,%11[^,],%d-%d,%9s",
    &acc.accountNumber,
    acc.name,
    acc.email,
    &acc.balance,
    acc.mobileNumber,
    &acc.dateOpened.month,
    &acc.dateOpened.year,
    acc.status)==8)
    {
        temp = realloc(Accounts,(count+1)*sizeof(Account));  // Temp Array
        if(temp==NULL)
        {
            printf("Memory Error");
            free(Accounts);
            fclose(f);
            exit(1);
        }
        else 
        {   
            Accounts = temp ;
            Accounts[count++] =  acc ; 
        }
    }
    long long target ;
    printf("Please Enter The Account Number Which You Want Delete : ");
    scanf("%lld",&target);
    Account *found = searchByAccountNumber(Accounts,count,target);
    if(found==NULL)
    {
        printf("Error Messege..Account Number Not Found.\n");
    }
    else 
    {   
        printf("Account Founded\n");
        char chioce[3];
        printf("Are You Want Delete that Account [y/n] : ");
        scanf(" %2s",chioce);
        newaccounts = malloc(count * sizeof(Account));
    if(strcmp(chioce,"Y")==0||strcmp(chioce,"y")==0)
    { 
       if(found->balance==0.0)
       {    
        
        for(i=0;i<count;i++)
        {
            if(Accounts[i].accountNumber!=target)
            {  
            newaccounts[j++] = Accounts[i];
            }
        }
        }
        else 
        {
       printf("Balance Greater Than 0 , Cannot Delete that Account.\n");  
        for(i=0;i<count;i++)
        {
            {
               newaccounts[j++] = Accounts[i];
            }
        }
        }
        }
        else if(strcmp(chioce,"N")==0||strcmp(chioce,"n")==0)
        {
            Quit();
        }
    }
    *newcount = j ;
    fclose(f);
    return newaccounts;
}

