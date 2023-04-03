/*
 * mykill.c - Another handy routine for testing your tiny shell
 *
 * usage: mykill <n>
 * Sleeps for <n> seconds. You can kill this program by specific signal
 *
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int i, secs;
    sigset_t mask;

    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(0);
    }
    secs = atoi(argv[1]);

    for (i = 0; i < secs; i++)
    sleep(1);

    exit(0);
}
