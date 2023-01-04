#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

/**
 * check if str1 is substring of str2
*/
int substring( char * str1, char * str2)
{
    if(strstr(str2, str1) != NULL){
        return 1;
    }
    return 0;

    // int len1 = strlen(str1);
    // int len2 = strlen(str2);

    // if(len1 > len2 ) //check it they have the same length
    // {
    //     return 0;
    // }

    // char *ps1 = str1;// make a copy
    // char *ps2 = str2;
    // int count = 0; //check if the word s include all the the letters from t 
    // for (size_t i = 0; i < len2; i++)
    // {
    //     if(*ps1 == *ps2)
    //     {
    //         while(count < len1 && i <len2)
    //         {
    //             if(*ps1 != *ps2){
    //                 ps1 = str1;
    //                 break;
    //             }
    //             else
    //             {
    //                 i++;
    //                 count++;
    //                 ps1++;
    //                 ps2++;
    //             }
    //         }
    //         if(count == len1){
    //             return 1;
    //         }
    //     }
    //     ps2++;
    //

    //return 0;
}

/**
 * check if s is similar to t (s is longer by n)
 * 
*/
int similar (char *s, char *t, int n)
{
    if(n == 0) // if they are have 0 diffrence
    {
        return (strcmp(s, t) == 0); //check if they are equals
    }

    int lens = strlen(s);
    int lent = strlen(t);

    if(lens != lent + n) //check it hey have the same length
    {
        return 0;
    }

    char *ps = s;// make a copy
    char *pt = t;
    int count = 0; //check if the word s include all the the letters from t 
    for (size_t i = 0; i < lens; i++)
    {
        if(*pt == *ps)
        {
            count++;
            pt++;
        }
        ps++;
    }

    if(count == lent)
    {
        return 1;
    }
    return 0;
}

int getLine(char *s)
{
    printf("start read\n");
    int count = 0;
    char *c = s;
    char ch = '0'; 
    ch = getchar();
    while (ch != '\n' && count < LINE)
    {
        c = strncat(c , &ch , 1);
        ch = getchar();
        count++;
    }
    s = c;
    return count;
}

int getWord(char *w)
{
    int count = 0;
    char *c = w;
    char ch = '0'; 
    ch = getchar();
    while (ch != '\n' && ch != '\t' && ch != ' '  && count < LINE)
    {
        c = strncat(c , &ch , 1);
        ch = getchar();
        count++;
    }
    w = c;
    return count;
}

void print_lines(char * str) 
{
    char line[LINE];
    printf("call line\n");
    getLine(line);
    printf("the line is: %s\n" , line);
    if(substring(str , line) == 1)
    {
        printf("%s is it the line\n" , str);
    }
    else{
        printf("%s is #not# it the line\n" , str);
    }
}

void print_similar_words(char * str)
{
    char word[WORD];
    printf("call word\n");
    int i = 0;
    while(i < 10)
    {
        memset(word , '\0' , WORD);
        getWord(word);
        printf("the word is: %s\n" , word);
        if(similar(str , word , 1) == 1)
        {
            printf("%s is similar the word %s\n" ,word , str);
        }
        else
        {
            printf("%s is #not# similar the word %s\n" ,word , str);
        }
    }
}

int main()
{
    char *str = "cat";
    print_similar_words(str);
    // char *str2 = "ccsatt aaa";
    // printf("return is: %d\n" , substring(str , str2));
    return 0;
}
