#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int number;
    struct node* p_next;
} NODE;

void main() {
    NODE* p_head = NULL;
    NODE* p_tail = NULL;
    NODE* temp = NULL;
    NODE* temp2 = NULL;
    int input = 0;
    int sum = 0;
    int value = 0;
    // scanf("%d", &input);
    for(int i = 0; i < 5; i ++) {
        scanf("%d", &input);
        if(p_head == NULL) {
        p_head = (NODE*)malloc(sizeof(NODE));
        p_head->number = input;
        p_head->p_next = NULL;
        p_tail = p_head;
        printf("value = %d\n", p_head->number);
        sum += 1;
        }
        else if(p_head != NULL) {
        p_tail->p_next = (NODE*)malloc(sizeof(NODE));
        p_tail = p_tail->p_next;
        p_tail->number = input;
        p_tail->p_next = NULL;
        printf("value = %d\n", p_tail->number);
        sum += 1;
        }
    }
    printf("Replace between : ");
    scanf("%d%d", &value, &input);
    temp = p_head;
    while(temp != NULL) {
        if(temp->number == value) {
            temp2 = (NODE*)malloc(sizeof(NODE));
            temp2->number = input;
            temp2->p_next = temp->p_next ;
            temp->p_next = temp2;
            printf("Succeed\n");
            break;
        }
        else {
            temp = temp->p_next;
            printf("Find next\n");
        }
    }
    while(p_head != NULL) {
            printf("%p\t%d\t%p\n", p_head, p_head->number, p_head->p_next);
            p_head = p_head->p_next;
    }
    free(p_head);
    free(p_tail);
}