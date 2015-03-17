//Michael Womack
//CS 3540
//Sept 19, 2014
//Homework 4

#include "bank_account.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
  bank_account* b = create_account("Michael Womack", 2000.00, 
				    "0129");

  if (b == NULL)
	printf("Invalid Entry\n");
  else 
  {	display_account(b);
	deposit(b, 100.00);
	withdraw(b, 40.0);
	delete_account(b);
	
	//delete_account(b);
  }
 
  printf("\nThis next example will be a NULL bank account\n\n");
  
  //invalid example
  bank_account* c = create_account("", 3000.00, "1111");
  
  if (c == NULL)
	printf("This is the null example, by the owner name being an empty string\n");
  else
  {
	display_account(c);
	delete_account(c);
  }
  return 0;
}
