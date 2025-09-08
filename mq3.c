#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int mgid, l;

    struct msgbuf {
        long mitype;
        char mtext[100];
    } msg;

    mgid = msgget((key_t)11, IPC_CREAT | 0666);
    if (mgid < 0) {
        perror("Message queue creation failed");
        exit(1);
    }

    printf("Message queue created with ID: %d\n", mgid);
    printf("Enter message:\n");

    fgets(msg.mtext, sizeof(msg.mtext), stdin);

    l = strlen(msg.mtext);

    msg.mitype = 1; 

    if (msgsnd(mgid, &msg, l + 1, 0) == -1) {
        perror("Message send failed");
        exit(1);
    }

    printf("Message sent successfully.\n");

    return 0;
}

