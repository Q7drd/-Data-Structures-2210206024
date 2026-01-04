#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    struct Node* temp = head;
    printf("Liste Durumu: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Basa dondu)\n");
}

void insertEnd(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (*head_ref == NULL) {
        new_node->next = new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }
    struct Node* last = (*head_ref)->prev;
    new_node->next = *head_ref;
    new_node->prev = last;
    last->next = (*head_ref)->prev = new_node;
}

int main() {
    struct Node* head = NULL;
    int n, val, pos, delVal;

    printf("Kac eleman girilecek? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("%d. eleman: ", i + 1);
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    traverse(head);

   
    printf("\nAraya eklemek istediginiz deger: ");
    scanf("%d", &val);
    printf("Hangi degerden sonrasina eklensin? ");
    scanf("%d", &pos);

    struct Node* temp = head;
    int found = 0;
    if (head != NULL) {
        do {
            if (temp->data == pos) {
                struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
                new_node->data = val;
                new_node->next = temp->next;
                new_node->prev = temp;
                temp->next->prev = new_node;
                temp->next = new_node;
                found = 1;
                break;
            }
            temp = temp->next;
        } while (temp != head);
    }
    traverse(head);

    
    printf("\nSilmek istediginiz deger: ");
    scanf("%d", &delVal);

    struct Node* del = head;
    if (head != NULL) {
        do {
            if (del->data == delVal) {
                if (del->next == del) { 
                    head = NULL;
                } else {
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                    if (del == head) head = del->next;
                }
                free(del);
                break;
            }
            del = del->next;
        } while (del != head);
    }
    traverse(head);

    return 0;
}
