#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string str = get_string(" ");
    //将str转换为Ascii码

    int len = strlen(str);
    int ascii[len];
    for(int i=0;i<strlen(str);i++)
    {
        ascii[i]=str[i];//ascii为十进制数组
    }


    //将ascii码转换为二进制码
    int ASCII[len][8];
    int j,k;
    for(int i=0;i<strlen(str);i++)
    {
        int decimal =ascii[i];
        for(j=0;j<8;j++)
        {
            ASCII[i][j]=decimal%2;
            decimal/=2;
        }
    }

    for(int i=0;i<strlen(str);i++)
    {
        for(j=7;j>=0;j--)
        {
            print_bulb(ASCII[i][j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
