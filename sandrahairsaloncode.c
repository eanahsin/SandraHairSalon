#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Name: Nishanae Williams
 Date: January 5, 2024
 Description: Program that facilitates efficient management of Sandra's Hair Salon in Jamaica
*/

int CustomerView ();
int EmployeeView ();
int BookAppointment ();
double PriceAssignment ();
int EditAppointment();
int PrintReceipt ();
int ViewAppointments ();
int ViewRevenueReport ();
int ViewDailyRevenueReport ();
int ViewWeeklyRevenueReport ();
int ViewMonthlyRevenueReport ();
int ViewTotalRevenue ();

typedef struct APPOINTMENTINFO
{
    int day, month, year, id, apptime, hairstylechoice;
    double price;
    char fname[20], lname[20], hairstyle[15];
}APPOINTMENTINFO;

int main ()//main menu
{
    int next;
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("                             /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$\n");
    printf ("                            | $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/\n");
    printf ("                            | $$ /$$$| $$| $$      | $$      | $$  \__/ | $$  \  $$| $$$$  /$$$$| $$      \n");
    printf ("                            | $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$   \n");
    printf ("                            | $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/   \n");
    printf ("                            | $$$/  \  $$$| $$      | $$      | $$    $$| $$  | $$| $$\   $ | $$| $$      \n");
    printf ("                            | $$/    \  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \/   | $$| $$$$$$$$\n");
    printf ("                            |__/      \__/|________/|________/  \______/   \______/ |__/     |__/|________/\n");

    printf  ("  ,---.                     ,--.               ,--.          ,--.  ,--.        ,--.            ,---.          ,--.\n");
    printf (" '   .-'  ,--,--.,--,--,  ,-|  |,--.--. ,--,--.|  |,---.     |  '--'  | ,--,--.`--',--.--.    '   .-'  ,--,--.|  | ,---. ,--,--,\n");
    printf(" `.  `-. ' ,-.  ||      |' .-. ||  .--'' ,-.  |`-'(  .-'     |  .--.  |' ,-.  |,--.|  .--'    `.  `-. ' ,-.  ||  || .-. ||      |\n");
    printf(" .-'    |' '-'  ||  ||  |' `-' ||  |   ' '-'  |   .-'  `)    |  |  |  |' '-'  ||  ||  |       .-'    |' '-'  ||  |' '-' '|  ||  |\n");
    printf(" `-----'  `--`--'`--''--' `---' `--'    `--`--'   `----'     `--'  `--' `--`--'`--'`--'       `-----'  `--`--'`--' `---' `--''--'\n");

    printf ("                                                                                                                     \n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");//welcome screen
    printf ("Please enter 1 to continue: ");
    scanf ("%d", &next);
    while (next != 1)
    {
        printf ("That option is invalid. Please try again\n");
        scanf ("%d", &next);

    }
    if (next==1)
    {
        system ("cls");
    }
    int choice;
    while (choice != 3)
    {
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("                                   SANDRA'S HAIR SALON\n");
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("1: Customer View\n");
        printf ("2: Employee View\n");
        printf ("3: Exit \n");
        printf ("Welcome to Sandra’s Hair Salon. Please enter the number corresponding with your desired feature ");//menu options for entering the program
        scanf ("%d", &choice);
        system ("cls");
        switch (choice){
            case 1:
                CustomerView ();//function call
                break;
            case 2:
                EmployeeView ();//function call
                break;
            case 3:
                system ("cls");
                printf ("You have chosen exit. Thank you for using this program\n");
                exit(0);
                break;
            default:
                printf ("That option is invalid. Please try again\n");//validating menu choice
                break;
        }

    }
}//end of main

int CustomerView ()//function for use by customers
{
    int choice;
    while (choice != 4){
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("                                   SANDRA'S HAIR SALON\n");
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("1: Book an Appointment\n");
        printf ("2: Print a Receipt\n");
        printf ("3: Edit an Appointment\n");
        printf ("4: Exit \n");
        printf ("Welcome to Sandra’s Hair Salon, Customer. Please enter the number corresponding with your desired feature ");//menu options for customers
        scanf ("%d", &choice);
        system ("cls");
        switch (choice){
            case 1:
                BookAppointment ();//function call
                break;
            case 2:
                PrintReceipt ();//function call
                break;
            case 3:
                EditAppointment ();//function call
            case 4:
                system ("cls");
                printf ("You have chosen exit. Thank you for using this program\n");
                exit(0);
                break;
            default:
                printf ("That option is invalid. Please try again\n");//validating menu choice
                break;
        }

    }
}//end of CustomerView

int EmployeeView ()
{
    int choice;
    char username[10], password[15];
    int isAuthenticated = 0; // Flag to track authentication status

    while (choice != 5)
    {
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("                                   SANDRA'S HAIR SALON\n");
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        if (!isAuthenticated) // Check if the user needs to authenticate
        {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            if (strcmp(username, "sandrab") == 0 || strcmp(username, "soniaj") == 0 || strcmp(username, "jerdineh") == 0)
            {
                if (strcmp(password, "Managesalon") == 0)
                {
                    isAuthenticated = 1; // Set flag to indicate successful authentication
                }
                else
                {
                    printf("Incorrect password. Please try again.\n");
                    continue; // Skip the rest of the loop and ask for credentials again
                }
            }
            else
            {
                printf("Invalid username. Please try again.\n");
                continue; // Skip the rest of the loop and ask for credentials again
            }
        }

        printf ("1: View Appointments\n");
        printf ("2: Print a Receipt\n");
        printf ("3: View Revenue Report\n");
        printf ("4: View Total Revenue\n");
        printf ("5: Exit \n");
        printf ("Welcome to Sandra’s Hair Salon. Please enter the number corresponding with your desired feature ");
        scanf ("%d", &choice);
        system ("cls");

        switch (choice)
        {
            case 1:
                ViewAppointments();
                break;
            case 2:
                PrintReceipt();
                break;
            case 3:
                ViewRevenueReport();
                break;
            case 4:
                ViewTotalRevenue();
                break;
            case 5:
                printf("You have chosen exit. Thank you for using this program\n");
                exit(0);
            default:
                printf("That option is invalid. Please try again\n");
                break;
        }
    }
    system("cls");
    printf("You have chosen exit. Thank you for using this program\n");
    exit(0);

}//end of EmployeeView

int compareDates(const APPOINTMENTINFO *a, const APPOINTMENTINFO *b) {
    if (a->year != b->year) {
        return a->year - b->year;
    } else if (a->month != b->month) {
        return a->month - b->month;
    } else {
        return a->day - b->day;
    }
}
int BookAppointment ()//function for customers to book appointments
{
    int c, x, count;
    system ("cls");
    FILE *fwtr = fopen ("appointments.txt", "a");//opening appointments file
    APPOINTMENTINFO appointments[60];
    printf ("How many appointments would you like to enter\n");
    scanf ("%d", &count);
    for (c = 1; c<=count; c++){//loop to enter the customers information for the appointment
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("                                  SANDRA'S HAIR SALON\n");
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        do {
            printf ("Please enter the customer's first name: \n");
            scanf ("%s", appointments[c].fname);
            if (strlen(appointments[c].fname)>20){
                printf ("That name is too long. Please try again.\n");//validating customer's first name
            }
        }while (strlen(appointments[c].fname)>20);
        do {
            printf ("Please enter the customer's last name: \n");
            scanf ("%s", appointments[c].lname);
            if (strlen(appointments[c].lname)>20){
                printf ("That name is too long. Please try again.\n");//validating customer's last name
            }
        }while (strlen(appointments[c].lname)>20);
        do {
            printf ("Please enter the date of the customer's appointment. Enter day, then month, then year: \n");
            scanf ("%d\n", &appointments[c].day);
            scanf ("%d\n", &appointments[c].month);
            scanf ("%d", &appointments[c].year);
            if ((appointments[c].day > 31) || (appointments[c].month > 12)||(appointments[c].year > 2024)){
                printf ("That date is invalid. Please try again.\n");//validating date of appointment
            }
        } while((appointments[c].day > 31) || (appointments[c].month > 12)||(appointments[c].year > 2024));
        printf ("Please enter the customer's ID number: \n");
        scanf ("%d", &appointments[c].id);
        printf ("Sandras Hair Salon | Appointment Times\n");
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("   1st Slot        |   7:00 a.m.\n");
        printf ("   2nd Slot        |   8:30 a.m.\n");
        printf ("   3rd Slot        |   10:00 a.m.\n");
        printf ("   4th Slot        |   11:30 a.m.\n");
        printf ("   5th Slot        |   1:00 p.m.\n");
        printf ("   6th Slot        |   2:30 p.m.\n");
        printf ("   7th Slot        |   4:00 p.m.\n");
        printf ("   8th Slot        |   5:30 p.m.\n");
        printf ("   9th Slot        |   7:00 p.m.\n");
        printf ("   10th Slot       |   8:00 p.m.\n");//apointment slots available for customers
        do {
            printf ("Please select from the options the appointment time\n");
            scanf ("%d", &appointments[c].apptime);
            if ((appointments[c].apptime > 10) || (appointments[c].apptime < 1)){
                printf ("That option is invalid. Please try again.\n");//validating customer's appointment slot
            }
        }while ((appointments[c].apptime > 10) || (appointments[c].apptime < 1));
        for (x = 1; x < c; x++) {
            while ((appointments[c].day == appointments[x].day) && (appointments[c].month == appointments[x].month) && (appointments[c].year == appointments [x].year) && (appointments[c].apptime == appointments[x].apptime)){
                printf ("This slot is unavailable. Please re-enter the date and a different appointment time\n");
                scanf ("%d\n", &appointments[c].day);
                scanf ("%d\n", &appointments[c].month);
                scanf ("%d\n", &appointments[c].year);
                scanf ("%d", &appointments[c].apptime);
            }
        }//checks to see if two customers have booked the same appointment time
        printf ("Sandras Hair Salon | Hairstyle Options\n");
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("       1           |       Braids\n");
        printf ("       2           |       Cornrows\n");
        printf ("       3           |       Silk Press\n");
        printf ("       4           |       Twists\n");
        printf ("       5           |       Locs\n");
        printf ("       6           |       Washing\n");
        printf ("       7           |       Perming\n");
        printf ("       8           |       Straightening\n");
        printf ("       9           |       Cutting\n");
        printf ("       10          |       Dyeing\n");
        printf ("       11          |       Bantu Knots\n");
        printf ("       12          |       Finger Coils\n");
        printf ("       13          |       Sew-In\n");
        printf ("       14          |       Wigs\n");
        printf ("       15          |       Retwist\n");//hairstyle options available for customers
        do {
            printf ("Please select a hairstyle from the options\n");
            scanf ("%d", &appointments[c].hairstylechoice);
            appointments[c].price = PriceAssignment(appointments[c].hairstylechoice, appointments[c].price);//function call to assign price based on hairstyle chosen and return the price
            switch (appointments[c].hairstylechoice){//assigning name of hairstyle based on number entered
                case 1:
                    strcpy (appointments[c].hairstyle, "Braids");
                    break;
                case 2:
                    strcpy (appointments[c].hairstyle, "Cornrows");
                    break;
                case 3:
                    strcpy (appointments[c].hairstyle, "SilkPress");
                    break;
                case 4:
                    strcpy (appointments[c].hairstyle, "Twists");
                    break;
                case 5:
                    strcpy (appointments[c].hairstyle, "Locs");
                    break;
                case 6:
                    strcpy (appointments[c].hairstyle, "Washing");
                    break;
                case 7:
                    strcpy (appointments[c].hairstyle, "Perming");
                    break;
                case 8:
                    strcpy (appointments[c].hairstyle, "Straightening");
                    break;
                case 9:
                    strcpy (appointments[c].hairstyle, "Cutting");
                    break;
                case 10:
                    strcpy (appointments[c].hairstyle, "Dyeing");
                    break;
                case 11:
                    strcpy (appointments[c].hairstyle, "Bantu Knots");
                    break;
                case 12:
                    strcpy (appointments[c].hairstyle, "Finger Coils");
                    break;
                case 13:
                    strcpy (appointments[c].hairstyle, "Sew-In");
                    break;
                case 14:
                    strcpy (appointments[c].hairstyle, "Wigs");
                    break;
                case 15:
                    strcpy (appointments[c].hairstyle, "Retwist");
                    break;
                default:
                    printf ("That option is invalid. Please try again.\n");//validating customer's hairstyle choice
                    break;
            }
        }while ((appointments[c].hairstylechoice > 15) || (appointments[c].hairstylechoice < 1));
        system ("cls");
        printf ("You have successfully booked your appointment(s)\n");
    }

    for (x = 1; x <= count; x++) {
        fprintf(fwtr, "%s\t%s\t%d\t%d\t%d\t%d\t%d\t%s\t%.2f\n", appointments[x].fname, appointments[x].lname, appointments[x].day, appointments[x].month, appointments[x].year, appointments[x].id, appointments[x].apptime, appointments[x].hairstyle, appointments[x].price);
    }

    fclose(fwtr);//storing customer's information in file

    FILE *fread = fopen("appointments.txt", "r");
    if (fread == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fread, "%s %s %d %d %d %d %d %s %lf", appointments[i].fname, appointments[i].lname, &appointments[i].day, &appointments[i].month, &appointments[i].year, &appointments[i].id, &appointments[i].apptime, appointments[i].hairstyle, &appointments[i].price) == 9) {
        i++;
    }

    fclose(fread);

    // Sort the appointments array based on date
    qsort(appointments, i, sizeof(APPOINTMENTINFO), (int (*)(const void *, const void *))compareDates);

    // Overwrite the file with the sorted data
    FILE *foverwrite = fopen("appointments.txt", "w");
    if (foverwrite == NULL) {
        printf("Error opening file for overwriting.\n");
        exit(1);
    }

    for (x = 0; x < i; x++) {
        fprintf(foverwrite, "%s\t%s\t%d\t%d\t%d\t%d\t%d\t%s\t%.2f\n", appointments[x].fname, appointments[x].lname, appointments[x].day, appointments[x].month, appointments[x].year, appointments[x].id, appointments[x].apptime, appointments[x].hairstyle, appointments[x].price);
    }

    fclose(foverwrite);

}//end of BookAppointment

double PriceAssignment (int hairstylechoice, double price)//function to assign price based on hairstyle chosen
{
     switch (hairstylechoice){
            case 1:
                price = 3000.00;
                break;
            case 2:
                price = 2500.00;
                break;
            case 3:
                price = 2000.00;
                break;
            case 4:
                price = 2500.00;
                break;
            case 5:
                price = 2500.00;
                break;
            case 6:
                price = 1500.00;
                break;
            case 7:
                price = 2000.00;
                break;
            case 8:
                price = 2000.00;
                break;
            case 9:
                price = 2500.00;
                break;
            case 10:
                price = 2500.00;
                break;
            case 11:
                price = 3500.00;
                break;
            case 12:
                price = 3000.00;
                break;
            case 13:
                price = 4000.00;
                break;
            case 14:
                price = 4000.00;
                break;
            case 15:
                price = 2500.00;
                break;
            default:
                printf ("That option is invalid. Please try again.\n");//validating customer's hairstyle choice
                break;
        }
        return (price);
}//end of PriceAssignment

int PrintReceipt ()//function for customers or employees to see receipts
{
    int day, month, year, searchid, apptime, c, x=0, found=0, hour, minute, choice;
    double price;
    APPOINTMENTINFO appointments[60];
    char fname[20], lname[20], hairstyle[15];
    FILE *fPointer = fopen ("appointments.txt", "r");//opening file
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("                                   SANDRA'S HAIR SALON\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (!feof(fPointer)){
        x=x+1;
        fscanf (fPointer, "%s %s %d %d %d %d %d %s %lf", appointments[x].fname, appointments[x].lname, &appointments[x].day, &appointments[x].month, &appointments[x].year, &appointments[x].id, &appointments[x].apptime, appointments[x].hairstyle, &appointments[x].price);
    }//reading information stored in file into array
    fclose (fPointer);
    printf ("Please enter the ID number of the customer you would like to search for: \n");
    scanf ("%d", &searchid);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for (c=1; c<=x; c++){
        if (appointments[c].id == searchid){//loop to search for id number entered
            found = 1;
            do{
                printf ("Please enter the time finished, enter HH, then MM\n");
                scanf ("%d\n%d", &hour, &minute);
                if (hour > 12 || minute > 59)
                {
                    printf ("That time is invalid. Please try again\n");
                }
            }while (hour > 12 || minute > 59);
            system ("cls");
            printf ("RECEIPT FOR %s %s\n\n", appointments[c].fname,  appointments[c].lname);//printing customer's receipt
            printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
            printf ("ID Number: %d\n", appointments[c].id);
            printf ("Appointment Slot: %d\n", appointments[c].apptime);
            printf ("Hairstyle: %s\n", appointments[c].hairstyle);
            printf ("Price: %.2f\n", appointments[c].price);
            printf ("Time Finished: %d:%d\n\n", hour, minute);
            while (choice != 2){
            printf ("Please enter 1 to return to main menu or 2 to print another receipt: \n");
            scanf ("%d", &choice);
            switch (choice) {
                case 1:
                    system ("cls");
                    main ();//function call
                    break;
                case 2:
                    system ("cls");
                    PrintReceipt ();//function call
                    break;
                default:
                    printf ("That option is invalid. Please try again\n");//validating user's choice
                    break;
            }
            }
        }
        if (appointments[c].id != searchid){
            found = 2;
        }

    }
    if (found == 2){
        printf ("Customer was not found.\n");
    }

    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}//end of PrintReceipt

int EditAppointment()
{
    int idToEdit, choice, editOption;
    printf("Enter your ID: ");
    scanf("%d", &idToEdit);

    FILE *fr = fopen("appointments.txt", "r");
    FILE *fw = fopen("temp.txt", "w");

    if (fr == NULL || fw == NULL) {
        printf("Error opening files for editing.\n");
        exit(1);
    }

    int found = 0;
    APPOINTMENTINFO appointment;

    while (fscanf(fr, "%s %s %d %d %d %d %d %s %lf",
                  appointment.fname, appointment.lname,
                  &appointment.day, &appointment.month, &appointment.year,
                  &appointment.id, &appointment.apptime,
                  appointment.hairstyle, &appointment.price) != EOF) {

        if (appointment.id == idToEdit) {
            found = 1;
            printf("Name: %s %s\n", appointment.fname, appointment.lname);
            printf("Date: %d.%d.%d\n", appointment.day, appointment.month, appointment.year);
            printf("ID: %d\n", appointment.id);
            printf("Appointment Slot: %d\n", appointment.apptime);
            printf("Hairstyle: %s\n", appointment.hairstyle);
            printf("Price: %.2f\n", appointment.price);

            int editOption;
            printf("\nChoose an option to edit:\n");
            printf("1: Name\n");
            printf("2: Date\n");
            printf("3: Appointment Slot\n");
            printf("4: Hairstyle\n");
            printf("Enter your choice: ");
            scanf("%d", &editOption);

            switch (editOption) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s %s", appointment.fname, appointment.lname);
                    printf("Appointment successfully edited.\n");
                    break;
                case 2:
                    printf("Enter new date (day month year): ");
                    scanf("%d\n", &appointment.day);
                    scanf ("%d\n", &appointment.month);
                    scanf ("%d", &appointment.year);
                    printf("Appointment successfully edited.\n");
                    break;
                case 3:
                    printf ("Sandras Hair Salon | Appointment Times\n");
                    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf ("   1st Slot        |   7:00 a.m.\n");
                    printf ("   2nd Slot        |   8:30 a.m.\n");
                    printf ("   3rd Slot        |   10:00 a.m.\n");
                    printf ("   4th Slot        |   11:30 a.m.\n");
                    printf ("   5th Slot        |   1:00 p.m.\n");
                    printf ("   6th Slot        |   2:30 p.m.\n");
                    printf ("   7th Slot        |   4:00 p.m.\n");
                    printf ("   8th Slot        |   5:30 p.m.\n");
                    printf ("   9th Slot        |   7:00 p.m.\n");
                    printf ("   10th Slot       |   8:00 p.m.\n");//apointment slots available for customers
                    printf("Enter new appointment slot: ");
                    scanf("%d", &appointment.apptime);
                    printf("Appointment successfully edited.\n");
                    break;
                case 4:
                    printf ("Sandras Hair Salon | Hairstyle Options\n");
                    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf ("       1           |       Braids\n");
                    printf ("       2           |       Cornrows\n");
                    printf ("       3           |       Silk Press\n");
                    printf ("       4           |       Twists\n");
                    printf ("       5           |       Locs\n");
                    printf ("       6           |       Washing\n");
                    printf ("       7           |       Perming\n");
                    printf ("       8           |       Straightening\n");
                    printf ("       9           |       Cutting\n");
                    printf ("       10          |       Dyeing\n");
                    printf ("       11          |       Bantu Knots\n");
                    printf ("       12          |       Finger Coils\n");
                    printf ("       13          |       Sew-In\n");
                    printf ("       14          |       Wigs\n");
                    printf ("       15          |       Retwist\n");//hairstyle options available for customers
                    printf("Enter new hairstyle option: ");
                    scanf("%d", &appointment.hairstylechoice);
                    appointment.price = PriceAssignment(appointment.hairstylechoice, appointment.price);
                    strcpy(appointment.hairstyle, ""); // Resetting the hairstyle to be determined from the choice
                    switch (appointment.hairstylechoice){
                        case 1:
                            strcpy (appointment.hairstyle, "Braids");
                            break;
                        case 2:
                            strcpy (appointment.hairstyle, "Cornrows");
                            break;
                        case 3:
                            strcpy (appointment.hairstyle, "SilkPress");
                            break;
                        case 4:
                            strcpy (appointment.hairstyle, "Twists");
                            break;
                        case 5:
                            strcpy (appointment.hairstyle, "Locs");
                            break;
                        case 6:
                            strcpy (appointment.hairstyle, "Washing");
                            break;
                        case 7:
                            strcpy (appointment.hairstyle, "Perming");
                            break;
                        case 8:
                            strcpy (appointment.hairstyle, "Straightening");
                            break;
                        case 9:
                            strcpy (appointment.hairstyle, "Cutting");
                            break;
                        case 10:
                            strcpy (appointment.hairstyle, "Dyeing");
                            break;
                        case 11:
                            strcpy (appointment.hairstyle, "Bantu Knots");
                            break;
                        case 12:
                            strcpy (appointment.hairstyle, "Finger Coils");
                            break;
                        case 13:
                            strcpy (appointment.hairstyle, "Sew-In");
                            break;
                        case 14:
                            strcpy (appointment.hairstyle, "Wigs");
                            break;
                        case 15:
                            strcpy (appointment.hairstyle, "Retwist");
                            break;
                        default:
                            printf ("That option is invalid. Please try again.\n");//validating customer's hairstyle choice
                            break;
                    }
                    printf("Appointment successfully edited.\n");
                    break;
                default:
                    printf("That option is invalid. Please try again\n");

            }
        }
        fprintf(fw, "%s\t%s\t%d\t%d\t%d\t%d\t%d\t%s\t%.2f\n",
                appointment.fname, appointment.lname, appointment.day, appointment.month,
                appointment.year, appointment.id, appointment.apptime,
                appointment.hairstyle, appointment.price);
    }

    fclose(fr);
    fclose(fw);

    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");

    if (!found) {
        printf("Appointment not found with the given ID.\n");
    }
    while (choice != 2){
    printf ("Please enter 1 to return to main menu or 2 to edit another appointment: \n");
    scanf ("%d", &choice);
    switch (choice) {
        case 1:
            system ("cls");
            main ();//function call
            break;
        case 2:
            system ("cls");
            EditAppointment ();//function call
            break;
        default:
            printf ("That option is invalid. Please try again\n");//validating user's choice
            break;
    }
    }
}//end of EditAppointment

int ViewAppointments ()//function for employees to view appointments
{
    int day, month, year, id, apptime, c, x=0, found=0, choice;
    double price;
    APPOINTMENTINFO appointments[60];
    char fname[20], lname[20], hairstyle[15];
    FILE *fPointer = fopen ("appointments.txt", "r");//opening file
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("                                   SANDRA'S HAIR SALON\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (!feof(fPointer)){
        x=x+1;
        fscanf (fPointer, "%s %s %d %d %d %d %d %s %lf", appointments[x].fname, appointments[x].lname, &appointments[x].day, &appointments[x].month, &appointments[x].year, &appointments[x].id, &appointments[x].apptime, appointments[x].hairstyle, &appointments[x].price);
    }//reading information stored in file into array
    fclose (fPointer);
    do{
        printf ("Please enter a date for the appointments you would like to view. Enter day, then month, then year: \n");
        scanf ("%d\n", &day);
        scanf ("%d\n", &month);
        scanf ("%d", &year);
        if ((day > 31) || (month > 12)||(year > 2024)){
            printf ("That date is invalid. Please try again.\n");
        }
    } while((day > 31) || (month > 12)||(year > 2024));//validating date entered by customer
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("                                  APPOINTMENTS FOR THE DAY %d.%d.%d\n", day, month, year);//appointment information for the date entered
    for (c=1; c<=x; c++){//loop to search for date entered
        if ((appointments[c].day == day) && (appointments[c].month == month) && (appointments[c].year == year)){
            found = 1;
            printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
            printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
            printf ("ID Num: %d\n", appointments[c].id);
            printf ("Appointment Slot: %d\n", appointments[c].apptime);
            printf ("Hairstyle: %s\n", appointments[c].hairstyle);
            printf ("Price: %.2f\n\n", appointments[c].price);
            while (choice != 2){
            printf ("Please enter 1 to return to main menu or 2 to view appointments for another day: \n");
            scanf ("%d", &choice);
            switch (choice) {
                case 1:
                    system ("cls");
                    main ();//function call
                    break;
                case 2:
                    system ("cls");
                    ViewAppointments ();//function call
                    break;
                default:
                    printf ("That option is invalid. Please try again\n");//validating employee's choice
                    break;
            }
            }
        }
        if ((appointments[c].day != day) && (appointments[c].month != month) && (appointments[c].year != year)) {
            found = 2;
        }
    }
    if (found == 2){
        printf ("There are no appointments on this date\n");
    }
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}//end of ViewAppointments


int ViewRevenueReport ()//function to view daily, weekly, or monthly revenue reports for the salon
{
    int choice;
    while (choice != 4){
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("                                   SANDRA'S HAIR SALON\n");
        printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("1: View Daily Revenue Report\n");
        printf ("2: View Weekly Revenue Report\n");
        printf ("3: View Monthly Revenue Report \n");
        printf ("4: Exit\n");
        printf ("Welcome to Sandra’s Hair Salon. Please enter the number corresponding with your desired feature ");//menu options for viewing revenue reports
        scanf ("%d", &choice);
        system ("cls");
        switch (choice){
            case 1:
                ViewDailyRevenueReport ();//function call
                break;
            case 2:
                ViewWeeklyRevenueReport ();//function call
                break;
            case 3:
                ViewMonthlyRevenueReport ();//function call
                break;
            case 4:
                system ("cls");
                printf ("You have chosen exit. Thank you for using this program\n");
                exit(0);
                break;
            default:
                printf ("That option is invalid. Please try again\n");//validating employee's choice
                break;
        }

    }

}//end of ViewRevenueReport

int ViewDailyRevenueReport ()//function to view daily revenue reports for the salon
{
    int day, month, year, id, apptime, c, x=0, choice;
    double price, TotalRev = 0;
    APPOINTMENTINFO appointments[60];
    char fname[20], lname[20], hairstyle[15];
    FILE *fPointer = fopen ("appointments.txt", "r");//opening file
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("                                   SANDRA'S HAIR SALON\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (!feof(fPointer)){
        x=x+1;
        fscanf (fPointer, "%s %s %d %d %d %d %d %s %lf", appointments[x].fname, appointments[x].lname, &appointments[x].day, &appointments[x].month, &appointments[x].year, &appointments[x].id, &appointments[x].apptime, appointments[x].hairstyle, &appointments[x].price);
    }//reading information stored in file into array
    fclose (fPointer);
    do {
        printf ("Please enter a date you would like to get a report for. Enter day, then month, then year: \n");
        scanf ("%d\n", &day);
        scanf ("%d\n", &month);
        scanf ("%d", &year);
        if ((day > 31) || (month > 12)||(year > 2024)){
            printf ("That date is invalid. Please try again.\n");
        }
    } while((day > 31) || (month > 12)||(year > 2024));//validating date entered
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for (c=1; c<=x; c++){//loop to search for date entered
        if ((appointments[c].day == day) && (appointments[c].month == month) && (appointments[c].year == year)){
            printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
            printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
            printf ("ID Num: %d\n", appointments[c].id);
            printf ("Appointment Slot: %d\n", appointments[c].apptime);
            printf ("Hairstyle: %s\n", appointments[c].hairstyle);
            printf ("Price: %.2f\n\n", appointments[c].price);
            TotalRev = TotalRev + appointments[c].price;
        }
    }
    printf ("\nTOTAL REVENUE FOR THE DAY: %.2f\n", TotalRev);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (choice != 2){
    printf ("Please enter 1 to return to main menu or 2 to view revenue for another day: \n");
    scanf ("%d", &choice);
    switch (choice) {
        case 1:
            system ("cls");
            main ();//function call
            break;
        case 2:
            system ("cls");
            ViewDailyRevenueReport ();//function call
            break;
        default:
            printf ("That option is invalid. Please try again\n");//validating employee's choice
            break;
    }
    }

}//end of ViewDailyRevenueReport

int ViewWeeklyRevenueReport ()//function to view weekly revenue reports for the salon
{
    int day, month, year, id, apptime, c, x=0, weeknum, choice;
    double price, TotalRev = 0;
    APPOINTMENTINFO appointments[60];
    char fname[20], lname[20], hairstyle[15];
    FILE *fPointer = fopen ("appointments.txt", "r");//opening file
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("                                   SANDRA'S HAIR SALON\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (!feof(fPointer)){
        x=x+1;
        fscanf (fPointer, "%s %s %d %d %d %d %d %s %lf", appointments[x].fname, appointments[x].lname, &appointments[x].day, &appointments[x].month, &appointments[x].year, &appointments[x].id, &appointments[x].apptime, appointments[x].hairstyle, &appointments[x].price);
    }//reading information stored in file into array
    fclose (fPointer);
    do {
        printf ("Please enter the number corresponding to a month and the year you would like to get a report for\n");
        scanf ("%d\n", &month);
        scanf ("%d", &year);
        if ((month > 12)||(year > 2024)){
            printf ("That date is invalid. Please try again.\n");//validating date entered by customer
        }
    } while((month > 12)||(year > 2024));
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("Week 1 01st to 07th\n");
    printf ("Week 2 08th to 14th\n");
    printf ("Week 3 15th to 21st\n");
    printf ("Week 4 22nd to 28th\n");
    printf ("Week 5 29th to 31st\n");//list of options for different weeks of the month
    do {
        printf ("Please select from the list of options the week you would like to get a report for\n");
        scanf ("%d", &weeknum);
        if ((weeknum > 5) || (weeknum < 1))
        {
            printf ("That option is invalid. Please try again.\n");
        }
    } while ((weeknum > 5) || (weeknum < 1));
    for (c=1; c<=x; c++){//loop to search for month and year entered
        if ((appointments[c].month == month) && (appointments[c].year == year)){
            if (weeknum == 1){
                if ((appointments[c].day == 1)|| (appointments[c].day == 2)||(appointments[c].day == 3)||(appointments[c].day == 4)||(appointments[c].day == 5)||(appointments[c].day == 6)||(appointments[c].day == 7)){
                    printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
                    printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
                    printf ("ID Num: %d\n", appointments[c].id);
                    printf ("Appointment Slot: %d\n", appointments[c].apptime);
                    printf ("Hairstyle: %s\n", appointments[c].hairstyle);
                    printf ("Price: %.2f\n\n", appointments[c].price);
                    TotalRev = TotalRev + appointments[c].price;
                }//report for week 1
            }
            if (weeknum == 2){
                if ((appointments[c].day == 8)|| (appointments[c].day == 9)||(appointments[c].day == 10)||(appointments[c].day == 11)||(appointments[c].day == 12)||(appointments[c].day == 13)||(appointments[c].day == 14)){
                    printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
                    printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
                    printf ("ID Num: %d\n", appointments[c].id);
                    printf ("Appointment Slot: %d\n", appointments[c].apptime);
                    printf ("Hairstyle: %s\n", appointments[c].hairstyle);
                    printf ("Price: %.2f\n\n", appointments[c].price);
                    TotalRev = TotalRev + appointments[c].price;
                }//report for week 2
            }
            if (weeknum == 3){
                if ((appointments[c].day == 15)|| (appointments[c].day == 16)||(appointments[c].day == 17)||(appointments[c].day == 18)||(appointments[c].day == 19)||(appointments[c].day == 20)||(appointments[c].day == 21)){
                    printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
                    printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
                    printf ("ID Num: %d\n", appointments[c].id);
                    printf ("Appointment Slot: %d\n", appointments[c].apptime);
                    printf ("Hairstyle: %s\n", appointments[c].hairstyle);
                    printf ("Price: %.2f\n\n", appointments[c].price);
                    TotalRev = TotalRev + appointments[c].price;
                }//report for week 3
            }
            if (weeknum == 4){
                if ((appointments[c].day == 22)|| (appointments[c].day == 23)||(appointments[c].day == 24)||(appointments[c].day == 25)||(appointments[c].day == 26)||(appointments[c].day == 27)||(appointments[c].day == 28)){
                    printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
                    printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
                    printf ("ID Num: %d\n", appointments[c].id);
                    printf ("Appointment Slot: %d\n", appointments[c].apptime);
                    printf ("Hairstyle: %s\n", appointments[c].hairstyle);
                    printf ("Price: %.2f\n\n", appointments[c].price);
                    TotalRev = TotalRev + appointments[c].price;
                }//report for week 4
            }
            if (weeknum == 5){
                if ((appointments[c].day == 29)|| (appointments[c].day == 30)||(appointments[c].day == 31)){
                    printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
                    printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
                    printf ("ID Num: %d\n", appointments[c].id);
                    printf ("Appointment Slot: %d\n", appointments[c].apptime);
                    printf ("Hairstyle: %s\n", appointments[c].hairstyle);
                    printf ("Price: %.2f\n\n", appointments[c].price);
                    TotalRev = TotalRev + appointments[c].price;
                }//report for week 5
            }
        }
    }
    printf ("\nTOTAL REVENUE FOR THE WEEK: %.2f\n", TotalRev);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (choice != 2){
    printf ("Please enter 1 to return to main menu or 2 to view revenue for another week: \n");
    scanf ("%d", &choice);
    switch (choice) {
        case 1:
            system ("cls");
            main ();//function call
            break;
        case 2:
            system ("cls");
            ViewWeeklyRevenueReport ();//function call
            break;
        default:
            printf ("That option is invalid. Please try again\n");//validating employee's choice
            break;
    }
    }

}//end of ViewWeeklyRevenueReport

int ViewMonthlyRevenueReport ()//function to view monthly revenue reports for the salon
{
    int day, month, year, id, apptime, c, x=0, choice;
    double price, TotalRev = 0;
    APPOINTMENTINFO appointments[60];
    char fname[20], lname[20], hairstyle[15];
    FILE *fPointer = fopen ("appointments.txt", "r");//opening file
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("                                   SANDRA'S HAIR SALON\n");
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (!feof(fPointer)){
        x=x+1;
        fscanf (fPointer, "%s %s %d %d %d %d %d %s %lf", appointments[x].fname, appointments[x].lname, &appointments[x].day, &appointments[x].month, &appointments[x].year, &appointments[x].id, &appointments[x].apptime, appointments[x].hairstyle, &appointments[x].price);
    }//reading information stored in file into array
    fclose (fPointer);
    do {
        printf ("Please enter the number corresponding to a month and the year you would like to get a report for\n");
        scanf ("%d\n", &month);
        scanf ("%d", &year);
        if ((month > 12)||(year > 2024)){
            printf ("That date is invalid. Please try again.\n");//validating date entered by user
        }
    } while((month > 12)||(year > 2024));
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for (c=1; c<=x; c++){//loop to search for month and year entered
        if ((appointments[c].month == month) && (appointments[c].year == year)){
            printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
            printf ("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
            printf ("ID Num: %d\n", appointments[c].id);
            printf ("Appointment Slot: %d\n", appointments[c].apptime);
            printf ("Hairstyle: %s\n", appointments[c].hairstyle);
            printf ("Price: %.2f\n\n", appointments[c].price);
            TotalRev = TotalRev + appointments[c].price;
        }
    }
    printf ("\nTOTAL REVENUE FOR THE MONTH: %.2f\n", TotalRev);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (choice != 2){
    printf ("Please enter 1 to return to main menu or 2 to view revenue for another month: \n");
    scanf ("%d", &choice);
    switch (choice) {
        case 1:
            system ("cls");
            main ();//function call
            break;
        case 2:
            system ("cls");
            ViewMonthlyRevenueReport ();//function call
            break;
        default:
            printf ("That option is invalid. Please try again\n");
            break;
    }
    }
}//end of ViewMonthlyRevenueReport

int ViewTotalRevenue()
{
    int c, x = 0, choice;
    double TotalRev = 0;
    APPOINTMENTINFO appointments[60];
    FILE *fPointer = fopen("appointments.txt", "r");
    // Check if the file opened successfully
    if (fPointer == NULL) {
        printf("Error opening the file for reading.\n");
        exit(1);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                                   SANDRA'S HAIR SALON\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    // Read information from the file into the array
    while (!feof(fPointer) && x < 60) {
        x = x + 1;
        fscanf(fPointer, "%s %s %d %d %d %d %d %s %lf",
               appointments[x].fname, appointments[x].lname,
               &appointments[x].day, &appointments[x].month, &appointments[x].year,
               &appointments[x].id, &appointments[x].apptime, appointments[x].hairstyle, &appointments[x].price);
    }
    fclose(fPointer);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    // Calculate total revenue by adding up prices
    for (c = 1; c <= x; c++) {
        printf("Name: %s %s\n", appointments[c].fname,  appointments[c].lname);
        printf("Date: %d.%d.%d\n", appointments[c].day, appointments[c].month, appointments[c].year);
        printf("ID Num: %d\n", appointments[c].id);
        printf("Appointment Slot: %d\n", appointments[c].apptime);
        printf("Hairstyle: %s\n", appointments[c].hairstyle);
        printf("Price: %.2f\n\n", appointments[c].price);
        TotalRev = TotalRev + appointments[c].price;
    }
    printf("\nTOTAL REVENUE FOR ALL APPOINTMENTS: %.2f\n", TotalRev);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (choice != 1){
    printf("Please enter 1 to return to the main menu: \n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls");
            main();
            break;
        default:
            printf("That option is invalid. Please try again\n");
            break;
    }
    }
}//end of ViewTotalRevenue
