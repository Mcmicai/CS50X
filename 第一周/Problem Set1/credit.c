#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long l;
    do
    {
        l= get_long("Number: ");
    }
    while(l<=0);

    int cs = 0;
    long cn = l/10;
    while(cn>0)
    {
        int r = cn%10*2;
        if(r<10)
        {
            cs+=r;
        }
        else
        {
            cs+=r%10;
            r/=10;
            cs+=r;
        }
        cn/=100;
    }

    cn=l;
    while(cn>0)
    {
        cs+=cn%10;
        cn/=100;
    }

    if(cs%10!=0)
    {
        printf("INVALID\n");
    }
    else
    {
         int length = 2;
        while(l>=100)
        {
            l/=10;
            length++;
        }


        if((l==34||l==37)&&length==15)
        {
            printf("AMEX\n");
        }
        else if((l>=51&&l<=55)&&length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if((l>=40&&l<=49)&&(length==13||length==16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
