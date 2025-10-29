#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>

int g_tickets = 0;

typedef struct node {
    int tickets;
    struct node* next;
} node;

node* fair_insert(node* head, int tickets){
    node* tmp = malloc(sizeof(node));
    assert(tmp);

    tmp->tickets = tickets;
    tmp->next = NULL;
    g_tickets += tickets;

    if (!head || tickets <= head->tickets) {
        tmp->next = head;
        head = tmp;
        return head;
    }

    node *curr = head, *prev = head;
    
    while(curr) {
        if (curr->tickets < tickets) {
            prev = curr;
            curr = curr->next;
        } else {
            break;
        }
    }
    prev->next = tmp;
    tmp->next = curr;
    return head;
}

void print(node* head) {
    node* tmp = head;
    while(tmp) {
        printf("[%d]\t", tmp->tickets);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: fair_sched <seed> <loops>\n");
        exit(1);
    }

    int seed = atoi(argv[1]);
    int loops = atoi(argv[2]);

    srandom(seed);

    node* head = NULL;
    head = fair_insert(head, 10);
    head = fair_insert(head, 100);
    head = fair_insert(head, 2);
    head = fair_insert(head, 75);
    head = fair_insert(head, 101);

    print(head);

    for (int i = 0; i < loops; ++i) {
        int counter = 0;
        int winner = random() % g_tickets;

        node* curr = head;
        while(curr) {
            counter += curr->tickets;
            if (counter > winner) {
                break;
            }
            curr = curr->next;
        }

        printf("Winner: (%d) [%d]\n", winner, curr->tickets);
    }

    return 0;
}

