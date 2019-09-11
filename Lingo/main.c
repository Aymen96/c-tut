#include <stdio.h>
#include <string.h>
#include <pthread.h>

// colors for stdio outputs
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

/*
    Lingo is a word game.
    You get the length and the first character of a word and you try to guess the word by inputing it
    Every correctly placed character will stay and get colored green and the not correctly placed will be shown yellow
*/

int log_out(char* str)
{
    printf("%s \n", str);
    return 0;
}

int evaluate(char* str1, char* str2, int *miss, int *shot)
{
    int i;
    int shot_count = 0;
    int miss_count = 0;
    for(i = 0; i < strlen(str1) ; i++)
    {
        if(str1[i] == str2[i]) {
            *(shot + shot_count) = i;
            shot_count++;
        }
    }
    return 0;
}

int enter_word(int len, char *inp)
{
    char input[len * 2];
    scanf("%s", input);
    if(strlen(input) > len) {
        log_out("*** word too long. RETRY");
        return -1;
    } else if(strlen(input) < len) {
        log_out("*** word too short. RETRY");
        return -1;
    } else {
        int i = 0;
        for(i = 0; i < len; i++)
        {
           *(inp + i) = input[i];
        }
    }
    return 0;
}

int print_result(char* word, int* shot, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        // TODO
    }
}

int main()
{
    log_out("Starting Game");
    // print out each color
    /*
        printf("%sred\n", KRED);
        printf("%sgreen\n", KGRN);
        printf("%syellow\n", KYEL);
        printf("%sblue\n", KBLU);
        printf("%smagenta\n", KMAG);
        printf("%scyan\n", KCYN);
        printf("%swhite\n", KWHT);
    */
    // select word to play with
    char word[] = "Forest";
    char req[] = "Forest";
    int i;
    for( i = 1; i < strlen(word); i++ )
    {
        req[i] = '_';
    }
    // start Game
    log_out(req);

    // get input of user
    char user_input[strlen(word)];
    int res = -1;
    while(res < 0) {
        res = enter_word(strlen(word), &user_input[0]);
    }

    // now we have the user input
    log_out(user_input);
    int miss[strlen(word)];
    int shot[strlen(word)];
    evaluate(word, user_input, &miss[0], &shot[0]);

    print_result(&word[0] ,&shot[0], strlen(word));
    return 0;
}