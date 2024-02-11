#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *next;
    int data;
} Node;

Node *head = NULL;

void printMenu() {
    printf("\t1. Add a node\n");
    printf("\t2. Remove a node\n");
    printf("\t3. Insert a node\n");
    printf("\t4. Print your list\n");
    printf("\t5. Quit\n");
    printf("\n");
}

Node* add(int data) {

    Node *new = NULL;

    // if the list is empty
    if (head == NULL) {
        new = malloc(sizeof(Node));
        if (new == NULL) {
            return NULL;
        }
        new->data = data;
        head = new;
        new->next = NULL;
    } else {
        new = malloc(sizeof(Node));
        if (new == NULL) {
            return NULL;
        }
        new->data = data;
        new->next = head;
        head = new;
    }

    return new;
}

void printNodes() {
    Node *current = head;

    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("\n");
    return;
}

int main(int argc, char **argv) {
    int option = -1;
    printMenu();

    scanf("%d", &option);

    while (option != 5) {
        switch (option) {
            case 1:
            // Add
            printf("What data should I add");
            scanf("%d", &option);
            Node *new = add(option);
            break;
            
            case 2:
            // Remove
            break;
            
            case 3:
            // Insert
            break;
            
            case 4:
            // Print list
            printNodes();
            scanf(" ");
            break;

            case 5:
            // Quit
            break;
        }
    }
    
    return 0;
}