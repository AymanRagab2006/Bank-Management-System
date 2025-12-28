#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "login.h"
#include "color.h"

void Quit()
{
    exit(0);
}

int login()
{   
    char username[200],password[70];
    char us[200]; // username from file
    char ps[70];  // password from file
    int flag , temp , i,choice; 
    FILE *f = fopen("users.txt","r");
    if(f==NULL) {
        set_color(COLOR_RED);
        printf("Error,File Not Found..");
        reset_color();
        Quit();
    }
    else { 
        set_color(COLOR_YELLOW);
        printf("BeCareful,You Have 3 Attempts\n");
        reset_color();
        for(i=0;i<3;i++) {
            flag = 0 , temp = 0 ;
            set_color(COLOR_CYAN);
            printf("Please Eenter The Data >> \n");
            printf("Please Enter Your Username : ");
            reset_color();
            scanf("%s",username);
            rewind(f);
            while(fscanf(f,"%s %s",us,ps)!=EOF) {  
                if(strcmp(username,us)==0) {   
                    temp = 1 ;
                    set_color(COLOR_CYAN);
                    printf("Please Enter Your Password : ");
                    reset_color();
                    scanf("%s",password);
                    if(strcmp(password,ps)==0) {
                        flag = 1; 
                    }
                    break;
                }    
            }
            if(temp==0) {
                if(i==2) {   
                    set_color(COLOR_RED);
                    printf("Maximum Attempts And You Also Have Errors!");
                    reset_color();
                    Quit();
                }
                set_color(COLOR_RED);
                printf("Failed User Name\n");
                reset_color();
                set_color(COLOR_MAGENTA);
                printf("Please Enter What Do You Want\n");
                reset_color();
                set_color(COLOR_YELLOW);
                printf("1-Try Again\n");
                printf("2-Exit The Program\n");
                reset_color();
                set_color(COLOR_CYAN);
                printf("Choice : ");
                reset_color();
                scanf("%i",&choice);
    
                switch(choice) {
                    case 1: 
                        continue;
                    case 2:
                        Quit();
                        break;
                    default :
                        set_color(COLOR_RED);
                        printf("Invalid Choice\n");
                        printf("Try Again\n");
                        reset_color();
                        continue;
                }
            }
            if(flag) {
                set_color(COLOR_GREEN);
                printf("Login Successful..\n");
                reset_color();
                return 1; 
            }
            else {
                set_color(COLOR_RED);
                printf("Login Failed..\n");
                printf("Failed Password\n");
                reset_color();
                
            }
        }
    }  
    fclose(f);
}