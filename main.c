#include <stdio.h>
#include <regex.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio_ext.h>

// ^(([0-9]|[a-fA-F]){2}(:|-)?){5}([0-9]|[a-f]){2}$

int check(char * addr) {
    regex_t regex;
    int r;
    if(regcomp(&regex, "^(([0-9]|[a-fA-F]){2}(:|-)?){5}([0-9]|[a-f]){2}$", REG_EXTENDED)) {
        printf("ERROR!");
        exit(1);
    }

    r = regexec(&regex, addr, 0, NULL, 0);

    if(r == 0)
        return 1;
    else if(r == REG_NOMATCH)
        return 0;
    else
        return -1;

}

int main(int argc, const char * argv[]) {

    char addr[255];
    char ans;
    int repeat = 0;

    printf("Validacion de direcciones MAC\n");

    do {
        printf("Ingrese una direccion MAC para validar > ");
        __fpurge(stdin);
        scanf("%[^\n]s", addr);

        printf("%s", addr);
        if (check(addr))
            printf("\t\tVALIDA");
        else
            printf("\t\tINVALIDA");

        printf("\nContinuar? (Y) > ");
        __fpurge(stdin);
        scanf("%c", &ans);

        if(toupper(ans) == 'Y')
            repeat = 1;
        else
            repeat = 0;

    } while(repeat);

    scanf("%[^\n]s", addr);

}