#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Self-referencing Structure (linked list).
typedef struct node{
    char course_name[30];
    char course_number[10];

    struct node *next;
}Node;

// Function to print menu and return the selected option therein.
int menu(){
    int option;
    printf("What courses would you like to do?\n");
    printf("1. Add Course\n");
    printf("2. Drop Course\n");
    printf("3. Print Schedule\n");
    printf("4. Exit\n");
    scanf("%d", &option);

    return option;
}

// Function to print the schedule.
void print_schedule(Node *head) {
    int index = 1;
    if (head == NULL){
        printf("You aren't currently taking any courses.\n\n");
    } else {
        while (head != NULL) {
            printf("%d. %s - %s\n", index, head->course_number, head->course_name);
            head = head->next;
            index++;
        }
        printf("\n");
    }
}

// Function to check if a course exists in the schedule.
bool check_presence(Node *head, char temp[]) {
    Node *curr = head;
    bool answer = false;
    while (curr != NULL) {
        if (strcmp(curr->course_number, temp) == 0) {
            answer = true;
        }
        curr = curr->next;
    }
    return answer;
}

int main() {
    // These pointers will point to the first and current elements of the list, respectively.
    Node *head = NULL;
    Node *current = NULL;

    // We use the menu option to get user's input, then store it to a variable.
    int option = menu();

    // Endless loop, we don't know how many times the user will run.
    while (option != 0){

        // if they choose to add...
        if (option == 1){

            //add_sorted
            char num[10];
            char name[30];
            printf("What course name would you like to add?\n");
            scanf("%s", name);

            printf("What course number would you like to add?\n");
            scanf("%s", num);
            Node *link = (Node *) malloc(sizeof(Node)); //allocate memory for our next node.

            // Then copy inputted values to said node.
            strcpy(link->course_number, num);
            strcpy(link->course_name, name);
            link->next = NULL; // And set the pointer to the next to NULL until is time to use it.

            // Checks if the course exists already, if so, do not proceed.
            if (check_presence(head, num) == true){
                printf("This course is already in your schedule.\n\n");
            }
            else {
                // If the list is empty, simply add the new inputted values.
                if (head == NULL) {
                    head = link;
                    printf("Added!\n\n");
                }
                    // Otherwise, we must add the values in alphabetical order.
                else {
                    int flag = 0; // We use a flag to determine if something has already happened
                    if (strcmp(head->course_number, link->course_number) == 0) {
                        flag = 1; // We do not add repeated.
                    }
                    // If the head comes after the new value, the new value is now the head.
                    if (strcmp(head->course_number, link->course_number) > 0) {
                        link->next = head;
                        head = link;
                        flag = 1;
                    }
                    current = head; // We set current at head and sort from that point forward.

                    while (current->next != NULL && flag == 0) {
                        if (strcmp(current->next->course_number, link->course_number) == 0) {
                            flag = 1; // We do not add repeated values.
                        } else if (strcmp(current->next->course_number, link->course_number) > 0) {
                            link->next = current->next;
                            current->next = link;
                            flag = 1;
                            break;
                        }
                        current = current->next;
                    }
                    // If no sorting took place, and the value is not present already, add it to the end.
                    if (flag == 0) {
                        current->next = link;
                        printf("Added!\n\n");
                    }
                }
            }
          // if they choose to delete...
        } else if (option == 2) {

            char delete[10];
            // If no elements present, print an error.
            if (head == NULL) {
                printf("You aren't currently taking any courses.\n\n");
            }
            else {
                printf("What course code would you like to drop?\n");
                scanf("%s", delete);

                // Using our function, if the course is not in the list, no need to proceed.
                if (check_presence(head, delete) == false) {
                    printf("This course is not in your schedule.\n\n");// simply print an error.
                }
                // If the course exists...
                else {
                    // This here deletes the first element if it is the one inputted.
                    if (strcmp(head->course_number, delete) == 0) {
                        Node *temp = head;
                        if (head->next != NULL) {
                            head = head->next;
                            free(temp);
                            printf("Course has been removed.\n\n");
                        }
                        else {
                            Node *link = NULL;
                            head->next = link;
                            head = head->next;
                            free(temp);
                            printf("Course has been removed.\n\n");
                        }
                    }
                    // If it is not the first element, we iterate through the list until we find it.
                    else {
                        current = head;
                        while (current != NULL && current->next != NULL) {
                            if (strcmp(current->next->course_number, delete) == 0) {
                                Node *temp = current->next;
                                current->next = current->next->next;
                                free(temp);
                                printf("Course has been removed.\n\n");
                                break;
                            }
                            else {
                                current = current->next;
                            }
                        }
                    }
                }
            }

        } else if (option == 3){
            // Call our print_schedule function.
            print_schedule(head);

        } else if (option == 4) {
            printf("Done!");
            break;
        }
        // We prompt the user for a new option so that we have a way out of the loop.
        option = menu();
    }
    return 0;
}