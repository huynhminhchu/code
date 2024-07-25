#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[3], time_str[6], msg_str[MSG_LEN + 1];
    int day, hour, min, i, j, num_remind = 0;

    for (;;){
        if (num_remind == MAX_REMIND){
            printf("-- No Space left --\n");
            break;
        }
        printf("Enter day and reminder: ");
        scanf("%2d", &day);

        if (day < 0){
            printf("Error reminder, ignored...\n");
            continue;
        }

        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);

        scanf("%2d:%2d", &hour, &min);
        printf("Hour: %d, Min: %d\n", hour, min);
        sprintf(time_str, "%2d:%2d", hour,min);

        printf("Time str: %s\n", time_str);

        read_line(msg_str, MSG_LEN);

        //Search the array to determine where the day belongs, usingstrcmp to do comparisons
        for (i = 0; i < num_remind; i++){
            if (strcmp(day_str, reminders[i]) == 0){
                if (strcmp(time_str))
            }
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        }

        //move all strings below that point down one position
        for (j = num_remind; j > i; j--){
            strcpy(reminders[j], reminders[j-1]);
        }



        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n'){
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}