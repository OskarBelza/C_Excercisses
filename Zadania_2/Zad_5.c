#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_SIZE 10

typedef struct {
    char name[20];
    char surname[20];
    char contactNumber[20];
} Contact;

void addContact(Contact contacts[],int *numberOfContacts, Contact newContact){
    contacts[*numberOfContacts] = newContact;
    (*numberOfContacts)++;
}

int searchContact(Contact contacts[], int numberOfContacts, char *surname){
    for(int i = 0; i < numberOfContacts; i++){
        if(strcmp(contacts[i].surname, surname) == 0){
            return i;
        }
    }
    return -1;
}

void deleteContact(Contact contacts[], int *numberOfContacts, char *surname){
    if(numberOfContacts == 0){
        printf("No contacts to delete");
    }
    else{
        for(int i = 0; i < *numberOfContacts; i++){
            if(strcmp(contacts[i].surname, surname) == 0){
                contacts[i] = contacts[*numberOfContacts-1];
                (*numberOfContacts)--;
            }
        }
    }
}

void writeContacts(Contact contacts[], int numberOfContacts){
    for(int i = 0; i < numberOfContacts; i++){
        printf("Name: %s, Surname: %s, ContactNumber: %s\n",
               contacts[i].name, contacts[i].surname, contacts[i].contactNumber);
    }
}

void collectData(Contact *newContact, int numberOfContacts){
    if(numberOfContacts >= MAX_ARRAY_SIZE){
        printf("Max number of contacts\n");
    }
    else {
        printf("Enter name:\n");
        scanf("%s", newContact->name);
        printf("Enter surname:\n");
        scanf("%s", newContact->surname);
        printf("Enter contactNumber:\n");
        scanf("%s", newContact->contactNumber);
    }
}

int main() {
    Contact contacts[MAX_ARRAY_SIZE] = {
            {"Oskar", "Belza", "222222222"},
            {"Grzegorz", "Drozdz", "333333333"},
            {"Jakub", "Balon", "444444444"},
            {"Jakub", "Dlugosz", "555555555"},
            {"Pawel", "Wajcha", "666666666"},
            {"Jakub", "Cielica", "777777777"}
    };
    int numberOfContacts = 6;
    int control = 1;

    while(control != 0){
        printf("Options:\n"
               "1 - AddContact\n"
               "2 - DeleteContact\n"
               "3 - SearchContact\n"
               "4 - WriteContacts\n"
               "0 - EndLoop\n");
        scanf("%d", &control);

        Contact newContact;
        char surname[20];
        int index;

        switch (control) {
            case 1 :
                collectData(&newContact, numberOfContacts);
                addContact(contacts, &numberOfContacts, newContact);
                break;
            case 2:
                printf("Enter surname you want to delete\n");
                scanf("%s", surname);
                deleteContact(contacts, &numberOfContacts, surname);
                break;
            case 3:
                printf("Enter surname you want to search\n");
                scanf("%s", surname);
                index = searchContact(contacts, numberOfContacts, surname);
                if (index == -1){
                    printf("Contact doesn't exist\n");
                } else {
                    printf("Name: %s, Surname: %s, ContactNumber: %s\n",
                           contacts[index].name, contacts[index].surname, contacts[index].contactNumber);
                }
                break;
            case 4:
                writeContacts(contacts, numberOfContacts);
            case 0:
                break;
            default:
                printf("Wrong number");
        }
    }

    return 0;
}
