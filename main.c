#include<stdio.h>

#include "functions.c"

char first_name[100][12];
char last_name[100][12];
char email_adress[100][30];
long long phone_num[100];
long long cards[100];
int balance[100];
int pin[100];

int users;

/**********************************FUNCTION TO FIND INDEX STARTS  HERE*********************************************************/
int find_index(long long card) {
  int index;
  for (int i = 0; i < 100; i++) {
    if (card = cards[i]) {
      index = i;
      break;
    }
  }

  return index;
}
/**********************************FUNCTION TO FIND INDEX ENDS HERE*********************************************************/

/*****************************FUNTION TO REDGISTER A NEW USER ENDS HERE *************************************************************/
void transfer_funds(long long sender, long long receiver, int amount, int trans_pin) {
  char transfer = 'n';
  char pass_check = 'y';

  for (int i = 0; i < 100; i++) {
    if (cards[i] == sender) {
      if (balance[i] >= amount) {
        if (trans_pin == pin[i]) {

          balance[i] -= amount;
          printf("balance for user is %d card number is %lld and name is %s", balance[i], cards[i], first_name[i]);
          transfer = 'y';
        } else {
          printf("OOPS!, Incorrect PIN, funds cannot be transfered\n ");
          pass_check = 'n';
        }
      }
    }

    if (transfer == 'y') {

      if (cards[i] == receiver) {
        balance[i] += amount;
        printf("balance for user is %d card number is %lld and name is %s", balance[i], cards[i], first_name[i]);
      }
    }
  }

  if (transfer == 'n' && pass_check == 'y') {
    printf("OOPS! transaction failed, Insufficient balance\n");
  }
  FILE * ptrbalance;
  ptrbalance = fopen("balance.txt", "w");
  for (int i = 0; i < users; i++) {
    fprintf(ptrbalance, "%d\n", balance[i]);
  }
  fclose(ptrbalance);

}
/**********************************FUNCTION FOR TRANSFERRING FUNDS ends HERE ********************************************************/

/**********************************FUNCTION FOR CASH WITHDRAW STARTS HERE*********************************************************/
void cash_withdraw(long long card, int amount, int pin_rec) {
  int index = find_index(card);
  char signal = 'y';

  if (amount > balance[index]) {
    printf("OOPS!, transaction failed, Insufficient balance\n");

  } else if ((pin_rec != pin[index]) && (signal = 'n')) {
    printf("OOPS!,transaction failed, incorrect pin\n");
  } else {
    balance[index] -= amount;
    printf("Transaction successfull,Pleas collet your money from the tray below:\n");

    FILE * ptrbalance;
    ptrbalance = fopen("balance.txt", "w");
    for (int i = 0; i < users; i++) {
      fprintf(ptrbalance, "%d\n", balance[i]);
    }
    fclose(ptrbalance);
  }
}
/**********************************FUNCTION FOR CASH WITHDRAW ENDS HERE*********************************************************/

/**********************************FUNCTION FOR PAYING BILLS START HERE*********************************************************/

void pay_bills(long long card, int amount, int password) {
  int index = find_index(card);
  char signal = 'y';
  if (amount > balance[index]) {
    printf("Sorry, bill cannot be paid,Insufficient balance\n");
    signal = 'n';
  } else if ((password != pin[index]) && signal == 'y') {
    printf("Sorry, bill cannot be paid, Incorrect pin\n");
  } else {
    balance[index] -= amount;
    printf("\nBill paid successfully, your new account balace is %d", balance[index]);

    FILE * ptrbalance;
    ptrbalance = fopen("balance.txt", "w");
    for (int i = 0; i < users; i++) {
      fprintf(ptrbalance, "%d\n", balance[i]);
    }
    fclose(ptrbalance);
  }

}

/**********************************FUNCTION FOR PAYING BILLS ENDS HERE*********************************************************/

/**********************************FUNCTION FOR ADDING BALANCE STARTS HERE*********************************************************/
void add_balance(long long card, int amount, int pass) {

  int index = find_index(card);
  char signal = 'y';

  if (pass != pin[index]) {
    printf("Incorrect password !\n");
  } else if (pass == pin[index]) {
    balance[index] += amount;
    printf("amount added successfully, new account balance is %d\n", balance[index]);

    FILE * ptrbalance;
    ptrbalance = fopen("balance.txt", "w");
    for (int i = 0; i < users; i++) {
      fprintf(ptrbalance, "%d\n", balance[i]);
    }
    fclose(ptrbalance);

  }
}
/**********************************FUNCTION FOR ADDING BALANCE ENDS HERE*********************************************************/

/**********************************FUNCTION FOR CHECKING BALANCE STARTS  HERE*********************************************************/
void check_balance(long long card, int pass) {
  int index = find_index(card);

  if (pass != pin[index]) {
    printf("Incorrect password !\n");
  } else if (pass == pin[index]) {
    printf("your balance is %d\n", balance[index]);
  }

}
/**********************************FUNCTION FOR CHECKING BALANCE  ENDS HERE*********************************************************/

int main(void) {
  //***********************************THIS WILL CREATE THE FILES IF THE DOES NOT EXIST TO AVOID ANY ERRORS/////////////////
  FILE * ptrbalance = fopen("balance.txt", "r");
  if (ptrbalance == NULL) {
    ptrbalance = fopen("balance.txt", "a");
    fclose(ptrbalance);
  };
  FILE * ptrcards = fopen("cards.txt", "r");
  if (ptrcards == NULL) {
    ptrcards = fopen("cards.txt", "a");
    fclose(ptrcards);
  };
  FILE * ptremails = fopen("emails.txt", "r");
  if (ptremails == NULL) {
    ptremails = fopen("emails.txt", "a");
    fclose(ptremails);
  };
  FILE * ptrfirstnames = fopen("first_names.txt", "r");
  if (ptrfirstnames == NULL) {
    ptrfirstnames = fopen("first_names.txt", "a");
    fclose(ptrfirstnames);
  };
  FILE * ptrlastnames = fopen("last_names.txt", "r");
  if (ptrlastnames == NULL) {
    ptrlastnames = fopen("last_names.txt", "a");
    fclose(ptrlastnames);
  };
  FILE * ptrphonenums = fopen("phone_nums.txt", "r");
  if (ptrphonenums == NULL) {
    ptrphonenums = fopen("phone_nums.txt", "a");
    fclose(ptrphonenums);
  };
  FILE * ptrpins = fopen("pins.txt", "r");
  if (ptrpins == NULL) {
    ptrpins = fopen("pins.txt", "a");
    fclose(ptrpins);
  };
  //***********************************THIS WILL CREATE THE FILES IF THE DOES NOT EXIST TO AVOID ANY ERRORS/////////////////

  //MAIN HEADING OF THE PROGRAM
  printf("\t\t\t\tWelcome to ABL\n\n\n");

  /***********************************THIS MODULE ENSURE THE FLOW OF DATA FROM THE FILES INTO THE PROGRAM*********************************************************/

  //////////////////////////////////////FIRST NAMES STARTS HERE////////////////////////////////////////////////////////////////
  do {

    FILE * ptrfirstname;

    ptrfirstname = fopen("first_names.txt", "r");

    if (ptrfirstname == NULL) {
      printf("Error opening the file\n");
    }

    int num = 0;

    while (!feof(ptrfirstname) && !ferror(ptrfirstname)) {
      if (fgets(first_name[num], 12, ptrfirstname) != NULL) {
        num++;
      }
    }
    fclose(ptrfirstname);

    //////////////////////////////////////FIRST NAMES ENDS HERE////////////////////////////////////////////////////////////////

    /////////////////////////////////////INITITAL BALANCE STARTS HERE ////////////////////////////////////////////////////////

    FILE * ptrbalance;

    ptrbalance = fopen("balance.txt", "r");

    if (ptrbalance == NULL) {
      printf("Error opening the file\n");
    }

    num = 0;

    while (fscanf(ptrbalance, "%d", & balance[num]) == 1) {
      num++;
    }
    fclose(ptrbalance);

    ////////////////////////////////////INITIAL BALANCE ENDS HERE  //////////////////////////////////////////////////////////

    //////////////////////////////////////LAST NAMES STARTS HERE////////////////////////////////////////////////////////////////

    FILE * ptrlastname;

    ptrlastname = fopen("last_names.txt", "r");

    if (ptrlastname == NULL) {
      printf("Error opening the file\n");
    }

    num = 0;

    while (!feof(ptrlastname) && !ferror(ptrlastname)) {
      if (fgets(last_name[num], 12, ptrlastname) != NULL) {
        num++;
      }
    }
    fclose(ptrlastname);

    //////////////////////////////////////LASTE NAMES ENDS HERE////////////////////////////////////////////////////////////////

    ////////////////////////////////////// PHONE NUMBERS STARTS HERE////////////////////////////////////////////////////////////////

    FILE * ptrphonenum;

    ptrphonenum = fopen("phone_nums.txt", "r");

    if (ptrphonenum == NULL) {
      printf("Error opening the file\n");
    }

    num = 0;

    while (fscanf(ptrphonenum, "%lld", & phone_num[num]) == 1) {
      num++;
    }
    fclose(ptrphonenum);
    //////////////////////////////////////PHONE NUMBERS ENDS HERE////////////////////////////////////////////////////////////////

    //////////////////////////////////////CARDS START HERE////////////////////////////////////////////////////////////////

    FILE * ptrcards;

    ptrcards = fopen("cards.txt", "r");

    if (ptrcards == NULL) {
      printf("Error opening the file\n");
    }

    num = 0;

    while (fscanf(ptrcards, "%lld", & cards[num]) == 1) {
      num++;
    }
    fclose(ptrcards);

    //////////////////////////////////////CARDS END HERE////////////////////////////////////////////////////////////////

    //////////////////////////////////////PINS NUMBERS ENDS HERE////////////////////////////////////////////////////////////////

    FILE * ptrpins;

    ptrpins = fopen("pins.txt", "r");

    if (ptrpins == NULL) {
      printf("Error opening the file\n");
    }

    num = 0;

    while (fscanf(ptrpins, "%d", & pin[num]) == 1) {
      num++;
    }
    fclose(ptrpins);

    //////////////////////////////////////PINS ENDS HERE////////////////////////////////////////////////////////////////

    //////////////////////////////////////EMAILS STARTS HERE/////////////////////////////////////////////////////////////////////

    FILE * ptremail;

    ptremail = fopen("emails.txt", "r");

    if (ptremail == NULL) {
      printf("Error in opening the file\n");
    }

    num = 0;

    while (!feof(ptremail) && !ferror(ptremail)) {
      if (fgets(email_adress[num], 30, ptremail) != NULL) {
        num++;
      }

    }
    fclose(ptremail);
    //total number of entries of users
    users = num;

    /////////////////////////////////////////EMAILS END HERE///////////////////////////////////////////////////////////////////

    /**********************************DATA MOBILITY ENDS HERE **********************************************************/

    /*********************************MAIN FUNCTION*****************************************************/

    int choise;

    printf("1. Create account\n2. Enter you card\n");

    printf("Enter you choise: ");
    scanf("%d", & choise);

    while (choise > 3 || choise < 0) {
      printf("Please enter correct choise: ");
      scanf("%d", & choise);
    }

    if (choise == 1) {
      create_account();
    } else if (choise == 3) {
      return 0;
    } else if (choise == 2) {
      long long card;
      char check = 'n';
      int trans_pin;
      printf("Please enter your card number: ");
      scanf("%lld", & card);
      if (validate_card(card)) {
        for (int i = 0; i < 100; i++) {
          if (cards[i] == card) {
            printf("Welcome %s ", first_name[i]);

            check = 'y';
            printf("\n");
            card_type(card);
            printf("\nSelect an option from the list below");

            printf("\n1. transfer funds: ");
            printf("\n2. withdraw cash: ");
            printf("\n3. Add balance: ");
            printf("\n4. pay bills: ");
            printf("\n5. Check your account balance:");
            printf("\n6. Exit");
            scanf("%d", & choise);

            while (choise > 6 || choise < 1) {
              printf("Incorrect option, Please select from the list above: ");
              scanf("%d", & choise);
            }

            if (choise == 1) {
              long long card_reciver;

              printf("Enter the card of reciever: ");
              scanf("%lld", & card_reciver);

              int amount;

              printf("Enter the amount to be transferred: ");
              scanf("%d", & amount);

              printf("\nEnter your account pin: ");
              scanf("%d", & trans_pin);

              transfer_funds(card, card_reciver, amount, trans_pin);

              char rec;
              printf("\nDo you want to print recipt y|n: ");
              scanf(" %c", & rec);

              if (rec == 'y' || rec == 'Y') {
                int index = find_index(card);
                printf("\n\n\t\t\tCASH RECIPT\n");
                printf("\nCard number: %lld", cards[index]);
                printf("\nMoney transferred: %d", amount);
                printf("\nBalance left : %d", balance[index]);

              } else {
                printf("\nThanks for using our services \n");
              }

            } else if (choise == 2) {
              int pin_withdraw;
              int amount;

              printf("Enter your amount: ");
              scanf("%d", & amount);
              printf("Enter your pin: ");
              scanf("%d", & pin_withdraw);

              cash_withdraw(card, amount, pin_withdraw);

              char rec;
              printf("\nDo you want to print recipt y|n: ");
              scanf(" %c", & rec);

              if (rec == 'y' || rec == 'Y') {
                int index = find_index(card);
                printf("\n\n\t\t\tCASH RECIPT\n");
                printf("\nCard number: %lld", cards[index]);
                printf("\nMoney withdrawn : %d", amount);
                printf("\nBalance left : %d", balance[index]);
              } else {
                printf("\nThanks for using our services \n");
              }

            } else if (choise == 3) {
              int money;
              int password;
              printf("\nEnter the amount to add: ");
              scanf("%d", & money);

              printf("\nEnter your pin: ");
              scanf("%d", & password);

              add_balance(card, money, password);

              char rec;
              printf("\nDo you want to print recipt y|n: ");
              scanf(" %c", & rec);

              if (rec == 'y' || rec == 'Y') {
                int index = find_index(card);
                printf("\n\n\t\t\tCASH RECIPT\n");
                printf("\nCard number: %lld", cards[index]);
                printf("\nMoney added: %d", money);
                printf("\nUpdated balance : %d", balance[index]);
              } else {
                printf("\nThanks for using our services \n");
              }

            } else if (choise == 4) {
              int ref_num, pin_bill, billing_amount;
              printf("Enter the reference number of bill: ");
              scanf("%d", & ref_num);

              printf("Enter the billing amount: ");
              scanf("%d", & billing_amount);

              printf("Enter your pin: ");
              scanf("%d", & pin_bill);

              pay_bills(card, billing_amount, pin_bill);

              char rec;
              printf("\nDo you want to print recipt y|n: ");
              scanf(" %c", & rec);

              if (rec == 'y' || rec == 'Y') {
                int index = find_index(card);
                printf("\n\n\t\t\tCASH RECIPT\n");
                printf("\nCard number: %lld", cards[index]);
                printf("\n Billed amount: %d", billing_amount);
                printf("\nBalance left : %d", balance[index]);

              } else {
                printf("\nThanks for using our services \n");
              }
            } else if (choise == 5) {
              int pass;
              printf("Enter your account pin: ");
              scanf("%d", & pass);

              check_balance(card, pass);

            } else if (choise == 6) {
              return 0;
            }
          }
        }

        if (check == 'n') {
          printf("Data not found please redgister your self\n");

          create_account();

        }

      } else {
        printf("\nnotvalid card:");
      }
    }

  } while (1); //REPEATING THE WHOLE MAIN FUNCTION.

}