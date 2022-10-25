#include <stdio.h>

void vulnerable(char *user_input)
{
        char vulnbuffer[256];

        printf("\n [+] Memory Address of vulnbuffer string:  %p \n", vulnbuffer);
        
        strcpy(vulnbuffer, user_input);         // Bad idea ... no bounds checking!
        
        printf("Contents of user_input is: %s \n", user_input);
        printf("Contents of vulnbuffer is: %s \n", vulnbuffer);
        return 0;
}


int main(int argc, char *argv[])
{
        printf("\n [+] Commandline Input Received Was: \n");
        printf("%s \n", argv[1]);
        printf("\n [+] Memory Address of Commandline Input:  %p \n", argv[1]);
        vulnerable(argv[1]);
        return 0;
}
