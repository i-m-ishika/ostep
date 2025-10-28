# Run
    make sched
    ./sched <seed> <loops>

# Context
The proportional-share scheduler, also know as a fair-share scheduler. Scheduler tries to guarantee that each job obtains a certain percentage of CPU time.

## TICKETS
The underlying basic concept for lottery scheduling. Tickets are used to represent the share of a resource that a process should receive. The lottery scheduler then picks winning tickets, and jobs are run accordingly. Example:

Total : 100 tickets
Jobs: A, B
A: 75 tickets (0 - 74)  - 75% CPU share
B: 25 tickets (75 - 99) - 25% CPU share
Output of lottery scheduler's winning tickets: 63 85 70 => Jobs run: A B A

## Ticket Mechanisms

Mechanisms to manipulate tickets in various ways:

### Ticket Currency
User allocates a set of tickets among their own jobs in a local currency. System automatically converts this local currency to a correct global values. Example:

Global currency: 200 tickets
Users: A (100 G), B (100 G)
A Local currency: 1000 tickets; Jobs A1, A2
A1: 500 L = 50 G, A2: 500 L = 50 G
B Local currency: 10 tickets; Job B1
B1: 10L = 100 G

### Ticket Transfer
Common in client/server setting, one process can temporarily transfer its tickets to another process.

### Ticket Inflation
In a system where processes trust each other, a process can temporarily raise/lower the number of tickets it owns.

