#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


int main()
{   int balance=1000;
    srand(time(NULL));


    int bet;
    int hand []={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int deste[]={1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10};
    
    
    printf("Your Bet:");
    scanf("%d",&bet);
    balance-=bet;

    if(bet>balance)
    {
        for(int i=-100;i<0;)
        {
        printf("Insufficient Balance. Decrease your bet.\n");
        printf("Your Bet:");
        scanf("%d",&bet);
        i=balance-bet;
        }
    }
    else
    {
        printf("Bet Placed.\n");
    }

    int x;
    int r;

    for(x=0 ;x<52;x++){

        r= rand() %52;

            do{
                r=rand()%52;
            }
            while(deste[r]==0);
            int y;
            y=hand[x]=deste[r];
            deste[r]*= 0;
    }

    int c1, c2, h1, h2,next,decision;

    c1= hand[0];
    h1= hand[1];
    c2= hand[2];
    h2= hand[3];


    printf("Cashier's Cards: %d,*\n",c1);
    printf("Your Cards: %d,%d\n",h1,h2);

    if(h1+h2==21)
    {
        if(c1+c2!=21)
        {
            printf("Congratulations. You won.\n");
            balance+=bet*2.5;
        }
        else
        {
            printf("Draw.");
        }
        printf("Cashier's other card was %d\n",h2);

    }
    else if(h1+h2<=11)
    {   
        if(h1==h2)
        {
            printf("Make your decision.\n");
            printf("1. Stand\n");
            printf("2. hit\n");
            printf("3. Double\n");
            printf("4. Split\n");
        }
        else
        {
            printf("Make your decision.\n");
            printf("1. Stand\n");
            printf("2. hit\n");
            printf("3. Double\n");
        }


    }
    
    else 
    {
        if(h1==h2)
        {
            printf("Make your decision.\n");
            printf("1. Stand\n");
            printf("2. hit\n");
            printf("4. Split\n");
        }
        else
        {
            printf("Make your decision.\n");
            printf("1. Stand\n");
            printf("2. hit\n");
        }

    }
    scanf("%d",&decision);

    switch(decision)
    {
        case 1:
        
        printf("Cashier's Cards: %d,%d\n",c1,c2);

        if((c1==1 && c2==10) || (c1==10 && c2==1))
        {
            printf("You lost.");
        }
        else if(c1==1 || c2==1)
        {
            if(c1+c2+10>16)
            {
                if (h1+h2>c1+c2+10)
                {
                    printf("Congratulations. You won.\n");
                    balance +=bet*2;
                }
                else if(h1+h2<c1+c2+10)
                {
                    printf("You lost.");
                }
                else{
                    printf("Draw.");
                    balance+=bet;
                }
            }
        }
        else if(c1+c2>16)
        {
            if (h1+h2>c1+c2)
                {
                    printf("Congratulations. You won.\n");
                    balance +=bet*2;
                }
                else if(h1+h2<c1+c2)
                {
                    printf("You lost.");
                }
                else{
                    printf("Draw.");
                    balance+=bet;
                }
        }
        else if (c1+c2<=16)
        {   int t=4;
            int y=c1+c2;
            do
            {   y +=hand[t];
                printf("Next card of cashier is %d\n",hand[t]);
                t+=1;
            } while (y<=16);

            if(y<h1+h2||y>21)
            {
                printf("Congratulations. You won.\n");
                balance +=bet*2;
            }
            else if(h1+h2<y)
                {
                    printf("You lost.");
                }
                else{
                    printf("Draw.");
                    balance+=bet;
                }
          
           
           
            
        };

        break;

    return 0;
    }
    
    }