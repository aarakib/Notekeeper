#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

void addnote();

void viewnote();

void editnote();

void deletenote();

struct notes

{

    char time[6];

    char name[30];

    char place[25];

    char duration[10];

    char note[500];

} ;

int main()

{

    int option;

    printf("\n\n\t-------------------------------\n");

    printf("\t## NOTE KEEPER CONSOLE SOFTWARE ##\n");

    printf("\t-------------------------------");

    for(;;)

    {

        printf("\n\n\t\tMAIN MENU:");

        printf("\n\n\tADD NOTE\t[1]");

        printf("\n\tVIEW NOTE\t[2]");

        printf("\n\tEDIT NOTE\t[3]");

        printf("\n\tDELETE NOTE\t[4]");

        printf("\n\tEXIT\t\t[5]");

        printf("\n\n\tENTER YOUR CHOICE:");

        scanf("%d",&option);

        switch(option)

        {

        case 1:

            addnote();

            break;

        case 2:

            viewnote();

            break;

        case 3:

            editnote();

            break;

        case 4:

            deletenote();

            break;

        case 5:

            getch();

            exit(0);

        default:

            printf("\nYOU ENTERED WRONG CHOICE..");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            getch();

            break;

        }

        system("cls");

    }

    return 0;

}

void addnote()

{

    system("cls");

    FILE *fp ;

    char another = 'Y' ,time[10];

    struct notes diary ;

    char filename[15];

    int choice;

    printf("\n\n\t\t-------------------------------\n");

    printf("\t\t# YOU ARE IN ADD MENU #");

    printf("\n\t\t-------------------------------\n\n");

    printf("\n\n\tENTER DATE OF YOUR NOTE:[yyyy-mm-dd]:");

    fflush(stdin);

    gets(filename);

    fp = fopen (filename, "ab+" ) ;

    if ( fp == NULL )

    {

        fp=fopen(filename,"wb+");

        if(fp==NULL)

        {

            printf("\nSYSTEM ERROR...");

            printf("\nPRESS ANY KEY TO EXIT");

            getch();

            return ;

        }

    }

    while ( another == 'Y'|| another=='y' )

    {

        choice=0;

        fflush(stdin);

        printf ( "\n\tENTER TIME:[hh:mm]:");

        scanf("%s",time);

        rewind(fp);

        while(fread(&diary,sizeof(diary),1,fp)==1)

        {

            if(strcmp(diary.time,time)==0)

            {

                printf("\n\tTHE NOTE ALREADY EXISTS.\n");

                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(diary.time,time);

            printf("\tENTER NAME:");

            fflush(stdin);

            gets(diary.name);

            fflush(stdin);

            printf("\tNOTE:");

            gets(diary.note);

            fwrite ( &diary, sizeof ( diary ), 1, fp ) ;

            printf("\nYOUR NOTE IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER NOTE...(Y/N) " ) ;

        fflush ( stdin ) ;

        another = getchar( ) ;

    }

    fclose ( fp ) ;

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();

}

void viewnote( )

{

    FILE *fpte ;

    system("cls");

    struct notes person ;

    char time[6],choice,filename[14];

    int ch;

    printf("\n\n\t\t-------------------------------\n");

    printf("\t\t# YOU ARE IN VIEW MENU #");

    printf("\n\t\t-------------------------------\n\n");

    if(choice!=0)

    {

        return ;

    }

    do

    {

        printf("\n\tENTER THE DATE OF NOTE TO BE VIEWED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);

        fpte = fopen ( filename, "rb" ) ;

        if ( fpte == NULL )

        {

            puts ( "\nTHE NOTE DOES NOT EXIST...\n" ) ;

            printf("PRESS ANY KEY TO EXIT...");

            getch();

            return ;

        }

        system("cls");

        printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");

        printf("\n\t1.ALL NOTE OF THE DAY.");

        printf("\n\t2.NOTE OF FIX TIME.");

        printf("\n\t\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:

            printf("\nTHE WHOLE NOTE FOR %s IS:",filename);

            while ( fread ( &person, sizeof ( person ), 1, fpte ) == 1 )

            {

                printf("\n");

                printf("\nTIME: %s",person.time);

                printf("\nNOTE: %s",person.note);

                printf("\n");

            }

            break;

        case 2:

            fflush(stdin);

            printf("\nENTER TIME:[hh:mm]:");

            gets(time);

            while ( fread ( &person, sizeof ( person ), 1, fpte ) == 1 )

            {

                if(strcmp(person.time,time)==0)

                {

                    printf("\nYOUR RECORD IS:");

                    printf("\nTIME: %s",person.time);

                    printf("\nNOTE: %s",person.note);

                }

            }

            break;

        default:
            printf("\nYOU TYPED SOMETHING ELSE...\n");

            break;

        }

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    return ;

}

void editnote()

{

    system("cls");

    FILE *fpte ;

    struct notes customer ;

    char time[6],choice,filename[14];

    int num,count=0;

    printf("\n\n\t\t-------------------------------\n");

    printf("\t\t# YOU ARE IN EDIT MENU #");

    printf("\n\t\t-------------------------------\n\n");


    do

    {

        printf("\n\tENTER THE DATE OF NOTE TO BE EDITED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);

        printf("\n\tENTER TIME:[hh:mm]:");

        gets(time);

        fpte = fopen ( filename, "rb+" ) ;

        if ( fpte == NULL )

        {

            printf( "\NOTE DOES NOT EXISTS:" ) ;

            printf("\nPRESS ANY KEY TO GO BACK");

            getch();

            return;

        }

        while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

        {

            if(strcmp(customer.time,time)==0)

            {

                printf("\nYOUR OLD NOTE WAS AS:");

                printf("\nTIME: %s",customer.time);

                printf("\nMEETING WITH: %s",customer.name);

                printf("\nMEETING AT: %s",customer.place);

                printf("\nDURATION: %s",customer.duration);

                printf("\nNOTE: %s",customer.note);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n1.TIME.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE NOTE.");

                printf("\n7.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\tENTER YOUR CHOICE:");

                    fflush(stdin);

                    scanf("%d",&num);

                    fflush(stdin);

                    switch(num)

                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(customer.time);

                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PERSON:");

                        gets(customer.name);

                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PLACE:");

                        gets(customer.place);

                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nDURATION:");

                        gets(customer.duration);

                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nNOTE:");

                        gets(customer.note);

                        break;

                    case 6:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(customer.time);

                        printf("\nNOTE:");

                        gets(customer.note);

                        break;

                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");

                        getch();

                        return ;

                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                        break;

                    }

                }
                while(num<1||num>8);

                fseek(fpte,-sizeof(customer),SEEK_CUR);

                fwrite(&customer,sizeof(customer),1,fpte);

                fseek(fpte,-sizeof(customer),SEEK_CUR);

                fread(&customer,sizeof(customer),1,fpte);

                choice=5;

                break;

            }

        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW NOTE IS:\n");

            printf("--------------------\n");

            printf("\nTIME: %s",customer.time);

            printf("\nNOTE: %s",customer.note);

            fclose(fpte);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER NOTE.(Y/N)");

            scanf("%c",&choice);

            count++;

        }

        else

        {

            printf("\nTHE NOTE DOES NOT EXIST::\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

            scanf("%c",&choice);

        }

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    if(count==1)

        printf("\n%d FILE IS EDITED...\n",count);

    else if(count>1)

        printf("\n%d FILES ARE EDITED..\n",count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");

    getch();

}



void deletenote( )

{

    system("cls");

    FILE *fp,*fptr ;

    struct notes file ;

    char filename[15],another = 'Y' ,time[10];;

    int choice,check;

    printf("\n\n\t\t----------------------------\n");

    printf("\t\t# YOU ARE IN DELETE MENU #");

    printf("\n\t\t-------------------------------\n\n");

    if(check==1)

    {

        return ;

    }

    while ( another == 'Y' )

    {

        printf("\n\n\tHOW WOULD YOU LIKE TO DELETE.");

        printf("\n\n\t#DELETE WHOLE NOTE\t\t\t[1]");

        printf("\n\t#DELETE A PARTICULAR NOTE BY TIME\t[2]");

        do

        {

            printf("\n\t\tENTER YOU CHOICE:");

            scanf("%d",&choice);

            switch(choice)

            {

            case 1:

                printf("\n\tENTER THE DATE OF NOTE TO BE DELETED:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "wb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    getch();

                    return ;

                }

                fclose(fp);

                remove(filename);

                printf("\nDELETED SUCCESFULLY...");

                break;

            case 2:

                printf("\n\tENTER THE DATE OF NOTE:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "rb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    getch();

                    return ;

                }

                fptr=fopen("temp","wb");

                if(fptr==NULL)

                {

                    printf("\nSYSTEM ERROR");

                    printf("\nPRESS ANY KEY TO GO BACK");

                    getch();

                    return ;

                }

                printf("\n\tENTER THE TIME OF NOTE TO BE DELETED:[hh:mm]:");

                fflush(stdin);

                gets(time);

                while(fread(&file,sizeof(file),1,fp)==1)

                {

                    if(strcmp(file.time,time)!=0)

                        fwrite(&file,sizeof(file),1,fptr);

                }

                fclose(fp);

                fclose(fptr);

                remove(filename);

                rename("temp",filename);

                printf("\nDELETED SUCCESFULLY...");

                break;

            default:

                printf("\n\tYOU ENTERED WRONG CHOICE");

                break;

            }

        }
        while(choice<1||choice>2);

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER NOTE.(Y/N):");

        fflush(stdin);

        scanf("%c",&another);

    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();

}
