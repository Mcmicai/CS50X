#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool has_26_letters(string s);
char rotate(char c,string plaintext);

int main(int argc, string argv[])
{
    //是子母字符串，但没有26位
    if(argc!=2||!has_26_letters(argv[1]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        //只要不是子母字符串，就返回“key”
    for(int i=0;i<26;i++)
    {
         if(!isalpha(argv[1][i]))
        {
            printf("key.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int i =0;i<strlen(plaintext);i++)
    {
        printf("%c",rotate(plaintext[i],argv[1]));
    }
    printf("\n");
    return 0;

}


bool has_26_letters(string plaintext)
{
    if(strlen(plaintext)!=26)
    {
        return false;
    }
    int count = 0;
    for(int i=0;i<strlen(plaintext);i++)
        {
            if(isalpha(plaintext[i]))
            {
                ++count;
            }
        } return count ==26;

}
char rotate(char c,string plaintext)
{
        if(isupper(c))
            {
            return toupper(plaintext[c - 'A']);
            }
        else if(islower(c))
            {
                return tolower(plaintext[c - 'a']);
            }
        else
            {
                return c;
            }
}
