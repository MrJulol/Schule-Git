#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0; 
    int choice = 0;

    printf("_USERMANAGEMENT_\n");
    printf("[1] - List users\n");
    printf("[2] - Add user\n");
    printf("[3] - Delete user\n");
    printf("[4] - Change Password of a user\n");

    scanf("%d", &choice);

    switch
        choice
        {

        case 1:
            listuser();
            break;
        case 2:
            adduser();
            break;
        case 3:
            deluser();
            break;
        case 4:
            passwd();
            break;
        default:
            printf("Not an accepted Input\n");
            exit(0);
        }

    printf("\n");
    return 0;
}