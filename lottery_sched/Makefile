all: sched fair_sched

clean:
	rm -f sched fair_sched

sched: sched.c
	gcc -o sched sched.c -Wall

fair_sched: fair_sched.c
	gcc -o fair_sched fair_sched.c -Wall
