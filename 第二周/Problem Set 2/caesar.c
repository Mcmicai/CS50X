#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if(argc!=2||!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k =atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext:");
    for(int i =0;i<strlen(plaintext);i++)
    {
        printf("%c",rotate(plaintext[i],k));
    }
    printf("\n");
    return 0;
}

//确保argv[1]里的每个字符都是数字
bool only_digits(string s)
{
    for(int i=0;i<strlen(s);i++)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if(isupper(c))
    {
        return((c-'A'+n)%26)+'A';
    }
    else if(islower(c))
    {
        return((c-'a'+n)%26)+'a';
    }
    else
    {
        return c;
    }
}
