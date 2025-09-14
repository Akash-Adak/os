s.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>stdlib.h>
#include <string.h>

int main() {
    int mgid, l;

    struct msgbuf {
        long mitype;
    } msg;
    mgid = msgget((key_t)11, IPC_CREAT | 0666);
    if (mgid < 0) {
        perror("Message queue creation failed");
        exit(1);
    }

    printf("Message queue created with ID: %d\n", mgid);
    printf("Enter message:\n")

    fgets(msg.mtext, sizeof(msg.mtext), stdin);

    // Remove trailing newline from f = strlen(msg.mtext);
    if (msg.mtext[l - 1] == '\n') {
        msg.mtext[l - 1] = '\0';
        l--;
    }
    msg.mitype = 1; // Set message type

    if (msgsnd(mgid, &msg, l + 1, 0) == -1) {
        perror("Message send failed");
        exit(1);
    }

    printf("Message sent successfull
