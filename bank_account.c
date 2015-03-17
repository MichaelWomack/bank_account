//Michael Womack
//CS 3540
//Sept 19,2014
//Homework 4

#include "bank_account.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//checks to determine if user entered all digits
int is_all_digits (char* b)
{
  int result = 0;
  if(b != NULL)
  {
    int i = 0;
    while (i < strlen(b) && isdigit(b[i]))
    
	i++;
        result = i == strlen(b);
  }  
   return result;
}

//creates copy of object
char* create_copy (char* b)
{
  char* cpy = NULL; //points to empty location
  if (b != NULL)
  { 
    cpy = malloc ((strlen(b) + 1) * sizeof (char));
    strcpy (cpy, b); //copies info pointed at b to cpy
    cpy[strlen(b)] = 0; //what is this for?
  }
  return cpy;
}

//create bank account object
bank_account* create_account (char* acct_owner, double init_balance,
			      char* acct_num)
{ //preconditions to create account
  bank_account* acct = NULL;
  if (acct_owner != NULL && strlen(acct_owner) > 0)
    if (acct_num != NULL && strlen(acct_num) > 0 && 
			    is_all_digits(acct_num))
	if (init_balance >= 0)
	{ 
	  acct = malloc (sizeof (bank_account));
	  acct -> owner = create_copy(acct_owner);//copy to have new location
  	  acct -> num = create_copy(acct_num);
	  acct -> balance = init_balance;
	}
	return acct;
}

//deposit
int deposit (bank_account* acct, double amount)
{
  if (acct != NULL && amount >= 0)
  {
    acct->balance = acct->balance + amount;
    printf("Balance has increased by %.2f\n", amount);
    
    return 0;
  }
  return 1;
}

//withdrawl
int withdraw (bank_account* acct, double amount)
{
  if (acct != NULL)
    if (amount >= 0 && amount <= acct->balance)
    { 
      acct->balance = acct->balance - amount;
      printf("Balance has decreased by %.2f\n", amount);

      return 0;
    }
    return 1;
}

//display account
void display_account (bank_account* acct)
{
    printf("\nAccount Holder: %s\n", acct->owner);
    printf("Account Number: %s\n", acct->num);
    printf("Balance: %.2f\n", acct->balance);
}

//delete account
void delete_account (bank_account* acct)
{
  if (acct != NULL)
  {
    free (acct -> owner);
    free (acct -> num);
    free (acct);
  }
}
