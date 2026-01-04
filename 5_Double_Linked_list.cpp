#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void traverse(struct Node* node) {
    printf("Liste Durumu: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;
    int n, val, pos, delVal;

    printf("Kac elemanli liste olusturulsun? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d. eleman: ", i + 1);
        scanf("%d", &val);
        push(&head, val);
    }
    traverse(head);

    
    printf("\nAraya eklemek istediginiz deger: ");
    scanf("%d", &val);
    printf("Hangi degerden sonrasina eklensin? ");
    scanf("%d", &pos);

    struct Node* temp = head;
    while (temp != NULL && temp->data != pos) temp = temp->next;

    if (temp != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL) temp->next->prev = new_node;
        temp->next = new_node;
    }
    traverse(head);


    printf("\nSilmek istediginiz deger: ");
    scanf("%d", &delVal);

    struct Node* del = head;
    while (del != NULL && del->data != delVal) del = del->next;

    if (del != NULL) {
        if (head == del) head = del->next;
        if (del->next != NULL) del->next->prev = del->prev;
        if (del->prev != NULL) del->prev->next = del->next;
        free(del);
    }
    traverse(head);

    return 0;
}
