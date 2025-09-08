
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int mgid;

    struct msgbuf {
        long mitype;
        char mtext[100];
    } msg;

    mgid = msgget((key_t)11, 0666); 
    if (mgid < 0) {
        perror("Failed to access message queue");
        exit(EXIT_FAILURE);
    }

    printf("Waiting to receive message...\n");

    if (msgrcv(mgid, &msg, sizeof(msg.mtext), 1, 0) == -1) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", msg.mtext);

    return 0;
}
