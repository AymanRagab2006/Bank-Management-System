#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void Login(char username[200],char password[70])
{   
    char us[200]; // username from file
    char ps[70];  // password from file
    int flag = 0 ; 
    FILE *f = fopen("users.txt","r");
    if(f==NULL)
    {
        printf("Error,File Not Found..");
    }
   else
   {
   int i ;
   for(i=0;i<3;i++)  // user has 3 attempts
   {
   printf("Please Eenter The Data >> \n");
   printf("Please Enter Your Username : ");  // prototype>>FirstName.SecondName
   scanf("%s",username);
   printf("Please Enter Your Password : ");
   scanf("%s",password);
   while(fscanf(f,"%s %s",us,ps)!=EOF)
   {  
    if(strcmp(username,us)==0 && strcmp(password,ps)==0)
    {
       flag = 1 ; 
       break;   
    }
   }
   if(flag)
   {
    printf("Login Successful..\n");
    break;
   }
   else 
   {
    printf("Login Failed..\n");
   }
   rewind(f);
  }
  }
  if(!flag)
  {
  printf("You have reached the maximum number of attempts..Try Again After 24 hours\n");
  printf("Or Contact Our Customer Services : 111");
  }
}

int main()
{   
    char username[200],password[70];
    Login(username,password);
    
  
  
    return 0;

}
