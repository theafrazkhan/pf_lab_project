#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<string.h>


/***************************************FUNCTION TO VALIDATE CARD STARTS HERE***************************************************/

int validate_card(long long card) {
    long long counter;
    counter = card;
    int rem_doub;
    int rem_sin;
    int sum_doub = 0;
    int sum_sin = 0;
    int sum_total;

    // to find the sum of doubled digits of the card
    while (counter > 0) {
        counter /= 10;
        rem_doub = counter % 10;
        counter /= 10;
        rem_doub = rem_doub * 2;

        if (rem_doub >= 10) {
            int r = rem_doub % 10;
            rem_doub /= 10;
            rem_doub = rem_doub + r;

        }

        sum_doub += rem_doub;

    }

    counter = card;

    // to sum up the non doubled digits of the card
    while (counter > 0) {
        rem_sin = counter % 10;
        sum_sin += rem_sin;
        counter /= 100;
    }

    sum_total = sum_sin + sum_doub;

    return (sum_total % 10 == 0);

}

/*********************************FUNCTION TO VALIDATE CARD ENDS HERE*********************************************************/

/*********************************fUNCTION TO CHECK CARD TYPE STARTS HERE*********************************************************/

void card_type(long long card) {

    //AMEX use 15 digit card number starting from 34 or 37

    if ((card >= 340000000000000 && card < 350000000000000) || (card >= 370000000000000 && card < 380000000000000)) {
        printf("\nYou have an AMEX card ");
    }

    //Master card uses 16 digit numbers starting with 51 52 53 54 55

    if ((card >= 5100000000000000 && card < 5600000000000000)) {
        printf("\nYou have a Master card card ");
    }

    //Visa uses  13 and 16 digits and starts with 4

    if ((card >= 4000000000000 && card < 5000000000000) || (card >= 4000000000000000 && card < 5000000000000000)) {
        printf("\nYou have a Visa card ");
    }

    //discover starts with 6 and have 16 digits

    if (card >= 6000000000000000 && card < 7000000000000000) {
        printf("\nYou have a discover card");
    }

    //union pay start with 62 and have 16 - 19 digits

    if ((card >= 6200000000000000 && card < 6300000000000000) || (card >= 62000000000000000 && card < 6300000000000000) || (card >= 620000000000000000 && card < 63000000000000000) || (card >= 6200000000000000000 && card < 6300000000000000000)) {
        printf("\nYou have a Union pay ");
    }

}

/********************************FUNCTION TO CHECK CARD TYPE ENDS HERE**********************************************************/

/********************************VISA GENERATOR START HERE**********************************************************/

long long visa_gen(void) {
    // visa uses 13 and 16 digits and starts with 4

    long long num = 0, value = 1;

    long long temp_card = 4000000000000;

    long long final_card;

    long long card = 0;

    srand(time(0));

    while (card < 100000000000) {
        num = rand() % 8 + 1;
        num *= value;
        value *= 10;
        card += num;
    }

    while (card > 100000000000) {
        card /= 10;
    }

    final_card = temp_card + card;

    int temp = 2;
    int values = 10;

    do {
        final_card += temp;
        temp++;
        values *= 10;
        temp *= values;

        if (validate_card(final_card)) {
            break;
        }
    } while (1);

    return final_card;
}
/********************************VISA GENERATOR ENDS HERE**********************************************************/

/********************************MASTER CARD GENERATOR STARTS HERE**********************************************************/

long long mastercard_gen(void) {
    long long num = 0, value = 1;

    long long temp_card = 5100000000000000;

    long long final_card;

    long long card = 0;

    srand(time(0));

    while (card < 100000000000) {
        num = rand();
        num *= value;
        value *= 10;
        card += num;
    }
    while (card > 100000000000) {
        card /= 10;
    }
    final_card = temp_card + card;

    int temp = 2;
    int values = 10;

    do {
        final_card += temp;
        temp += 2;
        values *= 10;
        temp *= values;
        final_card;

        if (validate_card(final_card)) {
            break;
        }

    } while (1);

    return final_card;

}

/********************************MASTER CARD GENERATOR ENDS HERE**********************************************************/

/********************************AMEX GENERATOR STARTS HERE**********************************************************/

long long amex_gen(void) {
    //Amex uses 15 digit card number and starts from 34 or 37

    long long num = 0, value = 1;

    long long temp_card = 340000000000000;

    long long final_card;

    long long card = 0;

    srand(time(0));

    while (card < 10000000000000) {
        num = rand() % 8 + 1;

        num *= value;
        value *= 10;
        card += num;
    }

    while (card > 10000000000000) {
        card /= 10;
    }

    final_card = temp_card + card;

    int temp = 2;
    int values = 10;

    do {
        final_card += temp;
        temp++;
        values *= 10;
        temp *= values;

        if (validate_card(final_card)) {
            break;
        }
    } while (1);

    return final_card;
}
/********************************AMEX GENERATOR ENDS HERE**********************************************************/

/********************************DISCOVER GENERATOR STARTS HERE**********************************************************/

long long discover_gen(void) {
    //Discover uses  15 digit number and starts with 6011

    long long num = 0, value = 1;

    long long temp_card = 601100000000000;

    long long final_card;

    long long card = 0;

    srand(time(0));

    while (card < 10000000000) {
        num = rand() % 8 + 1;
        num *= value;
        value *= 10;
        card += num;
    }

    while (card > 10000000000) {
        card /= 10;
    }

    final_card = temp_card + card;

    int temp = 2;

    int values = 10;

    do {
        final_card += temp;
        temp++;
        values *= 10;
        temp *= values;

        if (validate_card(final_card)) {
            break;
        }
    } while (1);

    return final_card;

}
/********************************DISCOVER GENERATOR ENDS HERE**********************************************************/

/********************************UNION PAY GENERATOR STARTS HERE**********************************************************/

long long unionpay_gen(void) {
    // unionpay uses 16 digits and starts with 62

    long long num = 0, value = 1;

    long long temp_card = 6200000000000000;

    long long final_card;

    long long card = 0;

    srand(time(0));

    while (card < 100000000000) {
        num = (rand() % 8) + 1;
        num *= value;
        value *= 10;
        card += num;
    }

    while (card > 100000000000) {
        card /= 10;
    }

    final_card = temp_card + card;

    int temp = 2;
    int values = 10;

    do {
        final_card += temp;
        temp++;
        values *= 10;
        temp *= values;

        if (validate_card(final_card)) {
            break;
        }
    } while (1);

    return final_card;
}
/********************************UNION PAY GENEREATOR ENDS HERE **********************************************************/

/******************************************************************************************/

//per day transaction
/******************************************************************************************/
//transaction charges
/******************************************************************************************/
//delete account
/*****************************************************************************************/
//dummy balanc
/*****************************************************************************************/
//
/******************************************************************************************/
// dollar pound rupee account
/******************************************************************************************/

/******************************FUNTION TO REDGISTER A NEW USER STARTS HERE ************************************************************/

int create_account(void) {
    char first_name[12];
    char last_name[12];
    char email_adress[30];
    long long phone_num;
    int pin;
    int pin_conf;
    int balance;

    printf("Enter First name: ");
    scanf("%s", first_name);

    printf("Enter last name: ");
    scanf("%s", last_name);

    printf("Enter your email adress: ");
    scanf("%s", email_adress);

    printf("Enter your phone number: ");
    scanf("%lld", & phone_num);

    while (phone_num <= 0) {
        printf("Please enter a valid phone number: ");
        scanf("%lld", & phone_num);
    }

    do {
        printf("Enter your pin: ");
        scanf("%d", & pin);
        if (pin < 100000) {
            printf("Pin must be atleast 6 digits: ");
            scanf("%d", & pin);
        }

        printf("Confirm your pin: ");
        scanf("%d", & pin_conf);
    } while (pin != pin_conf || pin <= 0 || pin_conf <= 0);

    int card_choise;
    long long card_generated;

    printf("\nWe provide the following cards to our new costumers: \n\n");
    printf("1. VISA\n");
    printf("2. MASTER CARD\n");
    printf("3. AMERICAN EXPRESS CARD\n");
    printf("4. DISCOVER\n");
    printf("5. UNION PAY\n");

    printf("VISA and UNION PAY will cost you 1200 rupees, where MASTERCARD, AMERICAN EXPRESS CARD AND DISCOVER WILL COST YOU 4800\n");
    printf("\t\t\t\t\t\t\t\t\t\tterms and conditions applied\n");

    printf("\nPlease enter your choise in numbers: ");
    scanf("%d", & card_choise);

    while (card_choise < 1 || card_choise > 5) {
        printf("\nplease enter correct choise: ");
        scanf("%d", & card_choise);
    }

    if (card_choise == 1) {
        card_generated = visa_gen();
    } else if (card_choise == 2) {
        card_generated = mastercard_gen();
    } else if (card_choise == 3) {
        card_generated = amex_gen();
    } else if (card_choise == 4) {
        card_generated = discover_gen();

    } else if (card_choise == 5) {
        card_generated = unionpay_gen();
    }

    printf("\nyour card number is %lld", card_generated);

    printf("\n\nplease note it down to use, we will deliver your physical card to your adress within three working days: ");
    printf("\nYour new account will have a default balance of 10,000 rupees as a compliment for choosing use ");
    printf("\nYour data may not be updated in the system so please make sure to restart the application to use it\n");

    FILE * ptr_email;
    FILE * ptr_balance;
    FILE * ptr_first_name;
    FILE * ptr_last_name;
    FILE * ptr_phone_num;
    FILE * ptr_cards;
    FILE * ptr_pin;

    ptr_email = fopen("emails.txt", "a");
    fprintf(ptr_email, "%s \n", email_adress);
    fclose(ptr_email);

    ptr_balance = fopen("balance.txt", "a");
    fprintf(ptr_balance, "%d \n", 10000);
    fclose(ptr_balance);

    ptr_first_name = fopen("first_names.txt", "a");
    fprintf(ptr_first_name, "%s \n", first_name);
    fclose(ptr_first_name);

    ptr_last_name = fopen("last_names.txt", "a");
    fprintf(ptr_last_name, "%s \n", last_name);
    fclose(ptr_last_name);

    ptr_phone_num = fopen("phone_nums.txt", "a");
    fprintf(ptr_phone_num, "%lld \n", phone_num);
    fclose(ptr_phone_num);

    ptr_cards = fopen("cards.txt", "a");
    fprintf(ptr_cards, "%lld \n", card_generated);
    fclose(ptr_cards);

    ptr_pin = fopen("pins.txt", "a");
    fprintf(ptr_pin, "%d \n", pin);
    fclose(ptr_pin);

}