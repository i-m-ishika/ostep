#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

int g_tickets = 0; // global tickets

typedef struct process_t {
    int tickets;
    struct process_t* next;
} process_t;

process_t* head = NULL;

void insert(int tickets){
    process_t* tmp = malloc(sizeof(process_t));
    assert(tmp);
    tmp->tickets = tickets;
    tmp->next = head;
    head = tmp;
    g_tickets += tickets;
}

void print(){
    process_t* tmp = head;
    while(tmp) {
        printf("[%d]\t", tmp->tickets);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: sched <seed> <loops>\n");
        exit(1);
    }
    int seed = atoi(argv[1]);
    int loops = atoi(argv[2]);

    // Taking seed as input to control randomly generated sequence.
    srandom(seed);

    // Populate list with jobs.
    insert(10);
    insert(100);
    insert(25);
    insert(75);

    print();

    for(int i = 0; i < loops; ++i) {
        int counter = 0;
        int winner = random() % g_tickets; // get winner

        process_t* curr = head;
        
        while(curr) {
            counter += curr->tickets;
            if (counter > winner) break; // found winner
            curr = curr->next;
        }

        printf("winner:(%d) [%d]\n", winner, curr->tickets);
    }
    return 0;
}
