#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user
{
                char phone_number[20];
                char account_number[20];
                char password[20];
                float balance;
};
int main()
{
                struct user usr,usr1;
                int option;
                FILE *fptr;
                char filename[50];
                char phone_no[50],pword[50];
                char cont='y';
                int choice;
                float amount;

                printf("\n\nSelect the option : \n\n");
                printf("1.Register an account\n\n");
                printf("2.Login to account\n\n");
                printf("Enter your option : ");
                scanf("%d",&option);

                if(option == 1)
                {
                                system("clear");
                                printf("Enter your phone number : ");
                                scanf("%s",usr.phone_number);
                                printf("\nEnter your account number : ");
                                scanf("%s",usr.account_number);
                                printf("\nEnter your Password : ");
                                scanf("%s",usr.password);
                                usr.balance=0; //Initial balance
                                strcpy(filename,usr.phone_number);
                                fptr=fopen(strcat(filename,".dat"),"w");
                                fwrite(&usr,sizeof(struct user),1,fptr);
                                if(fwrite != 0)
                                                printf("\nAccount successfully created\n");
                                else
                                                printf("\nSomething went wrong,Please try again\n");
                                fclose(fptr);
                }
                if(option == 2)
                {
                                system("clear");
                                printf("Enter your phone number : ");
                                scanf("%s",phone_no);
                                printf("\nEnter your password : ");
                                scanf("%s",pword);
                                strcpy(filename,phone_no);
                                fptr=fopen(strcat(filename,".dat"),"r");
                                fread(&usr,sizeof(struct user),1,fptr);
                                fclose(fptr);
                                if(!strcmp(pword,usr.password))
                                {
                                                while(cont == 'y')
                                                {
                                                                system("clear");
                                                                printf("\npress 1 -> Balanace enquiry\n");
                                                                printf("\npress 2 -> Deposite amount to account\n");
                                                                printf("\npress 3 -> Transfer amount to UPI account\n");
                                                                printf("\npress 4 -> Transfer amount to mobile number\n");
                                                                printf("\npress 5 -> change the password\n");

                                                                printf("\nEnter your option : ");
                                                                scanf("%d",&choice);

                                                                switch(choice)
                                                                {
                                                                                case 1:
                                                                                                printf("\nYour current balance is Rs.%.2f\n",usr.balance);
                                                                                                break;
                                                                                case 2:
                                                                                                printf("\nEnter the amount : ");
                                                                                                scanf("%f",&amount);
                                                                                                usr.balance+=amount;
                                                                                                fptr=fopen(filename,"w");
                                                                                                fwrite(&usr,sizeof(struct user),1,fptr);
                                                                                                if(fwrite != NULL)
                                                                                                {
                                                                                                                printf("\nSuccessfully deposited\n");
                                                                                                }
                                                                                                fclose(fptr);
                                                                                                break;
                                                                                case 3:
                                                                                                printf("\nEnter the amount : ");
                                                                                                scanf("%f",&amount);
                                                                                                usr.balance-=amount;
                                                                                                fptr=fopen(filename,"w");
                                                                                                fwrite(&usr,sizeof(struct user),1,fptr);
                                                                                                if(fwrite != NULL)
                                                                                                {
                                                                                                                printf("\nYou have transferred RS.%.2f to your UPI account\n",amount);
                                                                                                }
                                                                                                fclose(fptr);
                                                                                                break;
                                                                                case 4:
                                                                                                printf("\nEnter the phone number to transfer the amount : ");
                                                                                                scanf("%s",phone_no);
                                                                                                printf("\nEnter the amount to be transfer : ");
                                                                                                scanf("%f",&amount);
                                                                                            strcpy(filename,phone_no);
                                                                                            fptr=fopen(strcat(filename,".dat"),"r");
                                                                                            if(fptr == NULL)
                                                                                            {
                                                                                                           printf("\nAccount number not registeerd\n");
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                           fread(&usr1,sizeof(struct user),1,fptr);
                                                                                                           fclose(fptr);
                                                                                            }
                                                                                            if(amount > usr.balance)
                                                                                            {
                                                                                                           printf("\nInsufficient balance\n");
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                           fptr=fopen(filename,"w");
                                                                                                           usr1.balance+=amount;
                                                                                                           fwrite(&usr1,sizeof(struct user),1,fptr);
                                                                                                           fclose(fptr);

                                                                                                           if(fwrite != NULL)
                                                                                                           {

  printf("\nYou have successfully transfered Rs.%.2f to %s \n",amount,phone_no);

  strcpy(filename,usr.phone_number);

  fptr=fopen(strcat(filename,".dat"),"w");

  usr.balance-=amount;

  fwrite(&usr,sizeof(struct user),1,fptr);

  fclose(fptr);
                                                                                                           }
                                                                                            }
                                                                                           break;
                                                                                case 5:
                                                                                           printf("\nPlease enter the new password : ");
                                                                                           scanf("%s",pword);
                                                                                           fptr=fopen(filename,"w");
                                                                                           strcpy(usr.password,pword);
                                                                                           fwrite(&usr,sizeof(struct user),1,fptr);
                                                                                           fwrite(&usr1,sizeof(struct user),1,fptr);
                                                                                           if(fwrite != NULL)
                                                                                           {
                                                                                                           printf("\nPassword changed successfully\n");
                                                                                           }
                                                                                           break;
                                                                                default :
                                                                                           printf("\nInvalid option..\n");
                                                                }

                                                                printf("\nDo you want to continue the transaction [y/n] : ");
                                                                scanf("%s",&cont);
                                                }
                                }
                                else
                                {
                                                printf("\nInavlid password..\n");
                                }
                                }


}