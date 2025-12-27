#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void Quit()
{
    exit(0);
}
void Login()
{
    char username[200], password[70];
    char us[200]; // username from file
    char ps[70];  // password from file
    int flag, temp, i, choice;
    FILE *f = fopen("users.txt", "r");
    if (f == NULL)
    {
        printf("Error,File Not Found..");
    }
    else
    {
        printf("BeCareful,You Have 3 Attempts\n");
        for (i = 0; i < 3; i++) // user has 3 attempts
        {
            flag = 0, temp = 0;
            printf("Please Eenter The Data >> \n");
            printf("Please Enter Your Username : "); // prototype>>FirstName.SecondName
            scanf("%s", username);
            rewind(f);
            while (fscanf(f, "%s %s", us, ps) != EOF)
            {
                if (strcmp(username, us) == 0)
                {
                    temp = 1;
                    printf("Please Enter Your Password : ");
                    scanf("%s", password);
                    if (strcmp(password, ps) == 0)
                    {
                        flag = 1;
                    }
                    break;
                }
            }
            if (temp == 0)
            {
                if (i == 2)
                {
                    printf("Maximum Attempts And You Also Have Errors!");
                    Quit();
                }
                printf("Failed User Name\n");
                printf("Please Enter What Do You Want\n");
                printf("1-Try Again\n");
                printf("2-Exit The Program\n");
                printf("Choice : ");
                scanf("%i", &choice);

                switch (choice)
                {
                case 1:
                    continue;
                case 2:
                    Quit();
                    break;
                default:
                    printf("Invalid Choice\n");
                    printf("Try Again");
                    continue;
                }
            }
            if (flag)
            {
                printf("Login Successful..\n");
                break;
            }
            else
            {
                printf("Login Failed..\n");
                printf("Failed Password\n");
            }
        }
    }
    fclose(f);
}
int main()
{
    Login();
    return 0;
}
