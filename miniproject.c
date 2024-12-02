#include <stdio.h>

#include <string.h>

#define MAXMESSAGES 100

#define MAXMESSAGELEN 100

struct Message {

char message[MAXMESSAGELEN];

char sender[MAXMESSAGELEN];

};

struct Message messages[MAXMESSAGES];

int messageCount = 0;

void displayMessages() {

for (int i=0;i<messageCount;i++)

printf("%s: %s\n", messages[i].sender, messages[i].message);

}



void sendMessage(char sender, char message) {

if (messageCount < MAXMESSAGES) {

strcpy(messages[messageCount].sender, sender);

strcpy(messages[messageCount].message, message);

messageCount++;

} else {

printf("Message limit reached.\n");

}

}

int main() {

char sender[MAXMESSAGELEN];

char message[MAXMESSAGELEN];

printf("Enter your name: ");

fgets(sender, MAXMESSAGELEN, stdin);

sender[strcspn(sender, "\n")] = '\0';

while (1) {

displayMessages();

printf("%s: ", sender);

fgets(message, MAXMESSAGELEN, stdin);

message[strcspn(message, "\n")] = '\0';

sendMessage(sender, message);

}

return 0;

}
