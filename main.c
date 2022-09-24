#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>


int main()
{
    srand(time(0));


    int x,y;
    int t1,t2,tl1,tl2; //dozd

    printf("Tool zamin: ");
    scanf("%d" ,&y);
    printf("Arze zamin: ");
    scanf("%d" ,&x);



    int array[200][200];
    int array2[200][200];


    int i, j;

    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            array[i][j]=0;



    t1=rand()%x;
    t2=rand()%y;
    array[t1][t2]=-1;


    int tedad_kalantari;
    printf("Tedede kalantari: ");
    scanf("%d",&tedad_kalantari);


    int check_kalantari[100];
    int tedad_police[100];

    for(i=1;i<=tedad_kalantari;i++)
    {
        printf("Tedad police kalantari %d: ", i);
        scanf("%d", &tedad_police[i]);
    }

    int t3,t4;
    for(i=1;i<=tedad_kalantari;i++)
    {
        for(j=0;j<tedad_police[i];j++)
        {
            t3=rand()%x;
            t4=rand()%y;
            while(array[t3][t4] != 0)
            {
                t3 = rand()%x;
                t4 = rand()%y;
            }
            array[t3][t4]=i;
        }
    }



    system("cls");
    printf("\n\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(i==t1 && j==t2 && array[t1][t2] > 0)
            {
                printf("T*D%d", array[i][j]);
            }
            else
                            while(t3<0 || t4<0 || t3>x-1 || t4>y-1)
                            {
                                t3=i+(rand()%3)-1;
                                t4=j+(rand()%3)-1;
                            }
            {
                if(array[i][j] == 0)
                    printf("  . ");
                else if(array[i][j] == -1)
                    printf("  T ");
                else
                    printf("  D%d", array[i][j]);
            }
        }
        printf("\n\n");
    }
    Sleep(1500);

    while(array[t1][t2]==-1)
    {
        tl1=t1;
        tl2=t2;
        t1+=((rand()%3)-1);
        t2+=((rand()%3)-1);
        t1 = fmax(t1, 0);
        t1 = fmin(t1, x-1);
        t2 = fmax(t2, 0);
        t2 = fmin(t2, y-1);


        if(array[t1][t2]>0)
        {
            array[tl1][tl2] = 0;
            system("cls");
            printf("\n\n");
            for(i=0;i<x;i++)
            {
                for(j=0;j<y;j++)
                {
                    if(i==t1 && j==t2)
                    {
                        printf("T*D%d", array[i][j]);
                    }
                    else
                    {
                        if(array[i][j] == 0)
                            printf("  . ");
                        else if(array[i][j] == -1)
                            printf("  T ");
                        else
                            printf("  D%d", array[i][j]);
                    }
                }
                printf("\n\n");
            }
            break;
        }
        array2[t1][t2] = -1;

        for(i=1;i<=tedad_kalantari;i++)
            check_kalantari[i] = 0;

        for(i = fmax(0, tl1-2) ; i<=fmin(x-1, tl1+2) ; i++)
            for(j = fmax(0, tl2-2) ; j<=fmin(y-1, tl2+2) ; j++)
            {
                if(array[i][j]>0)
                    check_kalantari[array[i][j]] = 1;
            }

        for(i=0;i<=x-1;i++)
            for(j=0;j<=y-1;j++)
            {
                if(array[i][j]>0)
                {
                    if(check_kalantari[array[i][j]] == 1)
                    {
                        int s,t;
                        int I=i,J=j;
                        for(s = fmax(0, i-1) ; s<=fmin(x-1, i+1) ; s++)
                            for(t = fmax(0, j-1) ; t<=fmin(y-1, j+1) ; t++)
                            {
                                double Dx1 = s-tl1;
                                double Dy1 = t-tl2;
                                double Dx2 = I-tl1;
                                double Dy2 = J-tl2;
                                if(array2[s][t]<=0)
                                {
                                    if(Dx1*Dx1 + Dy1*Dy1 < Dx2*Dx2 + Dy2*Dy2 )
                                    {
                                        I = s;
                                        J = t;
                                    }
                                }
                            }
                        array2[I][J] = array[i][j];
                    }
                    else
                    {
                        t3=i+(rand()%3)-1;
                        t4=j+(rand()%3)-1;
                        while(t3<0 || t4<0 || t3>x-1 || t4>y-1 || array2[t3][t4]>0)
                        {
                            t3=i+(rand()%3)-1;
                            t4=j+(rand()%3)-1;
                        }
                        array2[t3][t4] = array[i][j];
                    }
                }
            }

        for(i=0;i<=x-1;i++)
            for(j=0;j<=y-1;j++)
            {
                array[i][j]=array2[i][j];
                array2[i][j]=0;
            }

        system("cls");
        printf("\n\n");
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(i==t1 && j==t2 && array[t1][t2] > 0)
                {
                    printf("T*D%d", array[i][j]);
                }
                else
                {
                    if(array[i][j] == 0)
                        printf("  . ");
                    else if(array[i][j] == -1)
                        printf("  T ");
                    else
                        printf("  D%d", array[i][j]);
                }
            }
            printf("\n\n");
        }
        Sleep(1500);
    }

    return 0;
}
