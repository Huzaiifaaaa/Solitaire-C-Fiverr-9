//INCLUDING RESPECTIVE HEADER FILES
#include <stdio.h>
#include <stdlib.h>

//DEFINING THE REQUIRED CONSTANT DATA
#define SEED 7;
#define DIFFICULTY 3;
#define ROWS 12;
#define HOLDROWS 2;

#define MSGWIN "YOU WON!!"
#define MSGLOOSE "YOU LOST!!"

//MAIN FUNCTION
//EXECUTION STARTS HERE
//TAKES COMMAND LINE ARGUMENTS
//RETURN INT ON SUCCESSFUL COMPILATION
int main()
{
    int sum=10;
    int seed=SEED;
    int rows=ROWS;
    int holdrows=HOLDROWS;

    srand(time(0));

    /*int *RIGHT=(int*) malloc(rows * sizeof(int));
    int *LEFT=(int*) malloc(rows * sizeof(int));
    int *HOLDRIGHT=(int*) malloc(holdrows * sizeof(int));
    int *HOLDLEFT=(int*) malloc(holdrows * sizeof(int));*/

    print(rows,holdrows,sum,seed);

    return 0;
}

//FUNCTION TO PRINT/PLAY GAME
//TAKES NUMBER OF ROWS,SUM & SEED AS ARGUMENTS
//RETURN NOTHING
void print(int rows,int holdrows,int sum,int seed){
    int i=0;
    int count=1;
    int leftcounter=0;
    int rightcounter=0;
    int leftholdcounter=0;
    int rightholdcounter=0;
    int leftcount=1;
    int rightcount=1;
    char input;
    char stars[rows];
    int right[rows+1];
    int left[rows];
    int holdright[rows];
    int holdleft[rows];
    int lefttemp;
    int righttemp;
    int leftremovetemp;
    int rightremovetemp;
    int turn=rows+rows;
    int turncounter=0;
    int akeycounter=0;
    int skeycounter=0;
    //DECLARING VARIBALES

    for(int i=0;i<rows+1;i++){
        left[i]=getrandom(21,-21);//ASSIGNING RANDOM VALUES TO LEFT LIST
        right[i]=getrandom(21,-21);//ASSIGNING RANDOM VALUES TO RIGHT LIST
        //stars[i]='*';//ASSIGNING STARS TO HIDE NUMBERS
    }

    for(int i=0;i<rows;i++){
        stars[i]='*';//ASSIGNING STARS TO HIDE NUMBERS
    }

    right[12]=getrandom(21,-21);

    for(int i=0;i<rows+1;i++)
    {
        holdleft[i]=0;//ASSIGNING 0 TO LEFT HOLD COLUMN
        holdright[i]=0;//ASSIGNING 0 TO RIGHT HOLD COLUMN
    }

    printheader();//CALLING FUNCTION TO PRINT HEADER
    printmiddle(left,right,stars,count,rows);//CALLING FUNCTION TO PRINT MIDDLE SECTION
    printfooter(sum,turn,turncounter);//CALLING FUNCTION TO PRINT FOOTER
    here://GOTO STATEMENT LABEL

    while(1){//LOOPING INFINITE TIMES

        printf("> ");//PRINTING
        scanf("%c",&input);//ASKING FOR INPUT(CHARACTER)
        getchar();//GETCHAR TO STOP CONSOLE

        if(input=='e' || input=='E')//IF INPUT IS 'e' OR 'E'-> EXIT
        {
            exit(0);
        }
        else if(input=='a'|| input=='A')//IF INPUT IS 'a' OR 'A'-> SELECT LEFT COLUMN
        {
            if(akeycounter>rows+1)
            {
                exit(0);
            }

            lefttemp=0;//ASSIGNING VALUE
            printheader();//CALLING FUNCTION TO PRINT HEADER

            for(int i=0;i<rows-leftcount-1;i++)
            {
                printf("|  %d   |    %c    | /// |   %c     |  %d  |\n",holdleft[i],stars[i],stars[i],holdright[i]);
            }

            lefttemp=rows-leftcount;

            for(i=leftcount+1;i>0;i--)
            {
                printf("|  %d  |    %d    | /// |   %c     |   %d  |\n",holdleft[lefttemp-1],left[i],stars[i-1],holdright[i-1]);
                lefttemp++;
            }

            sum=sum+left[leftcount];
            leftcount++;//INCREMENTING
            turncounter++;//INCREMENTING
            akeycounter++;//INCREMENTING
            printfooter(sum,turn,turncounter);//PRINTING FOOTER
        }
        else if(input=='s'|| input=='S')//IF INPUT IS 's' OR 'S'-> SELECT RIGHT COLUMN
        {
            if(skeycounter>rows+1)
            {
                exit(0);
            }

            righttemp=0;//ASSIGNING VALUE
            printheader();//PRINTING HEADER

            for(int i=0;i<rows-rightcount-1;i++)
            {
                printf("|  %d  |    %c    | /// |   %c     |  %d  |\n",holdleft[i],stars[i],stars[i],holdright[i]);
            }

            righttemp=rows-rightcount;

            for(i=rightcount+1;i>0;i--)
            {
                printf("|  %d  |    %c    | /// |   %d     |  %d  |\n",holdleft[i],stars[i-1],right[i],holdright[righttemp-1]);
                righttemp++;//INCREMENTING
            }

            sum=sum+right[rightcount];
            rightcount++;//INCREMENTING
            turncounter++;//INCREMENTING
            skeycounter++;//INCREMENTING
            printfooter(sum,turn,turncounter);//PRINTING FOOTER
        }
        else if(input=='q'|| input=='Q'){//IF INPUT IS 'q' OR 'Q'-> ADD CARD TO LEFT HOLD COLUMN
            leftcounter=0;//ASSIGNING VALUE
            rightcounter=0;//ASSIGNING VALUE
            holdleft[leftholdcounter]=left[leftcount];
            printheader();//PRINTING HEADER

            for(int i=0;i<rows-leftcount-1;i++)
            {
                printf("|  %d   |    %c    | /// |   %c     |  %d  |\n",holdleft[leftcounter],stars[i],stars[i],holdright[rightcounter]);
                leftcounter++;//INCREMENTING
                rightcounter++;//INCREMENTING
            }

            for(i=leftcount+1;i>0;i--)
            {
                printf("|  %d  |    %d    | /// |   %c     |   %d  |\n",holdleft[leftcounter],left[i],stars[i],holdright[rightcounter]);
                leftcounter++;//INCREMENTING
                rightcounter++;//INCREMENTING
            }

            leftholdcounter++;//INCREMENTING
            leftcount++;//INCREMENTING
            turncounter++;//INCREMENTING
            printfooter(sum,turn,turncounter);//PRINTING FOOTER
        }
        else if(input=='w'|| input=='W')//IF INPUT IS 'w' OR 'W'-> ADD CARD TO RIGHT HOLD COLUMN
        {
            leftcounter=0;//ASSIGNING VALUE
            rightcounter=0;//ASSIGNING VALUE
            holdright[rightholdcounter]=right[rightcount];
            printheader();//PRINTING HEADER

            for(int i=0;i<rows-rightcount-1;i++)
            {
                printf("|  %d   |    %c    | /// |   %c     |  %d  |\n",holdleft[leftcounter],stars[i],stars[i],holdright[rightcounter]);
                leftcounter++;//INCREMENTING
                rightcounter++;//INCREMENTING
            }

            for(i=rightcount+1;i>0;i--)
            {
                printf("|  %d  |    %c    | /// |   %d     |   %d  |\n",holdleft[leftcounter],stars[i],right[i],holdright[rightcounter]);
                leftcounter++;//INCREMENTING
                rightcounter++;//INCREMENTING
            }

            rightholdcounter++;//INCREMENTING
            rightcount++;//INCREMENTING
            turncounter++;//INCREMENTING
            printfooter(sum,turn,turncounter);//PRINTING FOOTER
        }
        else if(input=='z'|| input=='Z')//IF INPUT IS 'z' OR 'Z'-> REMOVE CARD FROM LEFT HOLD COLUMN
        {
            lefttemp=0;//ASSIGNING VALUE
            printheader();//PRINTING HEADER

            leftremovetemp=leftholdcounter-1;
            sum=sum+holdleft[leftremovetemp];
            holdleft[leftremovetemp]=0;

            for(int i=0;i<rows-leftcount-1;i++)
            {
                printf("|  %d   |    %c    | /// |   %c     |  %d  |\n",holdleft[i],stars[i],stars[i],holdright[i]);
            }

            lefttemp=rows-leftcount;

            for(i=leftcount;i>0;i--)
            {
                printf("|  %d  |    %d    | /// |   %c     |   %d  |\n",holdleft[lefttemp-1],left[i],stars[i],holdright[i]);
                lefttemp++;//INCREMENTING
            }

            leftholdcounter--;//DECREMENTING
            printfooter(sum,turn,turncounter);//PRINTING FOOTER
        }
        else if(input=='x'|| input=='X')//IF INPUT IS 'x' OR 'X'-> REMOVE CARD FROM RIGHT HOLD COLUMN
        {
            righttemp=0;//ASSIGNING VALUE
            printheader();//PRINTING HEADER

            rightremovetemp=rightholdcounter-1;
            sum=sum+holdright[rightremovetemp];
            holdright[rightremovetemp]=0;

            for(int i=0;i<rows-rightcount-1;i++)
            {
                printf("|  %d   |    %c    | /// |   %c     |  %d  |\n",holdleft[i],stars[i],stars[i],holdright[i]);
            }

            righttemp=rows-rightcount;

            for(i=rightcount;i>0;i--)
            {
                printf("|  %d  |    %c    | /// |   %d     |   %d  |\n",holdleft[i],stars[i],right[i],holdright[righttemp-1]);
                righttemp++;//INCREMENTING
            }

            rightholdcounter--;//DECREMENTING
            printfooter(sum,turn,turncounter);//PRINTING FOOTER
        }
        else//IF ANY OTHER KEY IS PRESSED
        {
            goto here;
        }
    }//END OF WHILE LOOP
}//END OF FUNCTION

//FUNCTION TO PRINT MIDDLE
//TAKES ARRAYS AS ARGUMENTS
//RETURN NOTHING
void printmiddle(int left[],int right[],char stars[],int count,int rows){

    for(int i=0;i<rows-count;i++)
    {
        printf("|  0  |    %c    | /// |   %c     |  0  |\n",stars[i],stars[i]);
    }

    for(int i=count;i>0;i--)
    {
        printf("|  0  |    %d    | /// |   %d     |   0 |\n",left[i],right[i]);
    }

}//END OF FUNCTION

//FUNCTION TO PRINT HEADER
//TAKES NO ARGUMENTS
//RETURN NOTHING
void printheader()
{
    printf("+-----+---------+-----+---------+-----+\n");
    printf("|HOLD |  LEFT   | /// |  RIGHT  | HOLD|\n");
    printf("+-----+---------+-----+---------+-----+\n");
}//END OF FUNCTION

//FUNCTION TO PRINT FOOTER
//TAKES INT SUM AS
//RETURNS NOTHING
void printfooter(int sum,int turn,int turncounter)
{
    printf("+-----+---------+-----+---------+-----+\n");
    printf("|SUM = %d                             |\n",sum);
    printf("+-----+---------+-----+---------+-----+\n");

    if(sum>21 || sum<0)
    {
        printf(MSGLOOSE);
        exit(0);
    }

    if(turncounter==turn)
    {
        if(sum>21 || sum<0)
        {
            printf(MSGWIN);
            exit(0);
        }
        else
        {
            printf(MSGLOOSE);
            exit(0);
        }

    }

}//END OF FUNCTION


//FUNCTION TO GENERATE RANDOM NUMBERS
//TAKES UPPER & LOWER LIMIT AS ARGUMENT
//RETURNS NUMBER BETWEEN PROVIDED LIMITS
int getrandom(int upper,int lower)
{
    int random=(rand() % (upper - lower + 1)) + lower;
    return random;
}//END OF FUNCTION


/*int integerlength(int number){
    int length;
    do {
        number /= 10;
        ++length;
    }while (number != 0);

    return length;
}*/
