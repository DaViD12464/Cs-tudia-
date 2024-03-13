#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10
#define MAX_NAME_LEN 20
#define MAX_SURNAME_LEN 50
#define MAX_PHONE_LEN 9

typedef struct {
    char name[MAX_NAME_LEN];
    char surname[MAX_SURNAME_LEN];
    char tel_num[MAX_PHONE_LEN];
}Contact;

Contact contacts[MAX_CONTACTS];
int numOfContacts =0;

void addContact(){
    if(numOfContacts < MAX_CONTACTS)
    {
        Contact newContact;
        printf("Enter first name:\n");
        scanf("%s",newContact.name);
        printf("Enter last name:\n");
        scanf("%s", newContact.surname);
        printf("Enter telephone number:\n");
        scanf("%s",newContact.tel_num);

        contacts[numOfContacts++]=newContact;
        printf("\tContact added successfully.\n");
    }
    else { printf("Cannot add more contacts, maximum number of contacts reached.");}
}

void findContact(char *surname)
{
    int result =0;
    for (int i =0;i<numOfContacts;++i)
    {
        if(strcmp(contacts[i].surname, surname)==0)
        {
            printf("Contact found:\n");
            printf("\tFirst name: %s\n", contacts[i].name);
            printf("\tLast name: %s\n", contacts[i].surname);
            printf("\tPhone number: %s\n", contacts[i].tel_num);
            result=1;
            break;
        }
        if(!result)
        {
            printf("Cannot find contact to display with given last name.");
        }
    }
}

void deleteContact(char *surname) {
    int result = 0;
    for (int i = 0; i < numOfContacts; ++i) {
        if (strcmp(contacts[i].surname, surname) == 0) {
            result=1;
            for (int j=i; j<numOfContacts;++j)
            {
                contacts[j]=contacts[j+i];
            }
            numOfContacts--;
            printf("Contact deleted successfully.\n");
            break;
        }
        if(!result)
        {
            printf("Cannot find contact to delete with given last name.");
        }
    }
}

void displayContacts(){
    if (numOfContacts==0)
        printf("No contacts to display.\n");
    else{
        printf("\tAll Contacts:\n");
        for(int i=0;i<numOfContacts;i++)
        {
            printf("%d. %s %s, %s\n",i+1,contacts[i].name,contacts[i].surname,contacts[i].tel_num);
        }
    }
}

int main()
{   char choice;
    char lastname[MAX_SURNAME_LEN];
    while(1){
        printf("\tPhoneBook\n\n");
        printf("1.Add Contact.\n");
        printf("2.Find contact using last name.\n");
        printf("3.Delete contact by last name.\n");
        printf("4.Display all contacts.\n");
        printf("5.EXIT\n");
        scanf(" %c",&choice);

        switch (choice) {
            case '1':
                addContact();
                break;
            case '2':
                printf("Enter last name to find:");
                scanf("%s",lastname);
                findContact(lastname);
                break;
            case '3':
                printf("Enter last name to delete:");
                scanf("%s",lastname);
                deleteContact(lastname);
                break;
            case '4':
                displayContacts();
                break;
            case '5':
                printf("Closing program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}