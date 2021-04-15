#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define ENTER 13
#define TAB 9
#define SPACE 32
#define BKSP 8
#define USER_NAME "1"
#define PASSWORD "1"

int takeuserinput();
void invalidateUser();
void initiateProgram(int printWelcome);
void initiateSearch();
void writeHistory();
void getHistory();
void txtFile();
void pngFile();




int main(){
   int validUser = takeUserInput();
   if(validUser==1){
       initiateProgram(1);
   }else{
       invalidateUser();
   }
}

/*** USER VALIDATION FUNCTION STARTS HERE ***/
int takeUserInput(){
    char username[100];
    char password[100];
    //TAKE USER NAME
    printf("\nUsername: ");
    scanf ("%s", username);
    //TAKE PASSWORD
    printf("\nPassword: ");
    int i=0;
    while(1)
    {
        ///TAKE ONE CHARACTER AT A TIME
        char ch;
        ch = getch();
        ///IF THAT CHARACTER WAS ENTER, PASSWORD INPUT COMPLETE
        if(ch==ENTER){
            password[i]='\0';
            break;
        }else if(ch==BKSP){///IF THAT CHARACTER IS A BACKSPACE TO OMIT ONE CHARACTER,OMIT ONE
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }else if(ch==TAB||ch==SPACE){///IF THAT CHARACTER IS A SPACE OR A TAB, CONTINUE
            continue;
        }else{///IF THE CHARACTER IS AN USUAL LITERAL, CONTINUE AS WELL
            password[i]=ch;
            printf("*");
            i++;
        }
    }
    ///DEBUG PRINT TO CHECK USERNAME AND PASSWORD VALUE
    //printf("\nUserName: %s\nPassword: %s",user,password);
    ///CHECK USERNAME AND PASSWORsearchStringD VALIDITY
    if(strcmp(username,USER_NAME)==0&&strcmp(password,PASSWORD)==0){
        return 1;
    }else{
        return 0;
    }
}

void invalidateUser(){
    printf("\nUsername Or Password Incorrect");
    main();
}
/*** USER VALIDATION FUNCTION ENDS HERE ***/

/*** MAIN INTERFACE IS DRAWN BY THIS FUNCTION ***/
void initiateProgram(int printWelcome){
    ///PRINT USER CHOICES
    printf("\n*==========================================================================*");
    if(printWelcome==1) printf("\n\n\t\t\tWelcome To Cearch with C :)");
    printf("\n\nFor Search Press    :1\nFor History Press   :2\nFor Quit Press      :3");
    printf("\n*==========================================================================*");
    ///TAKE USER CHOICE
    printf("\nEnter Your Choice: ");
    int c;
    scanf("%d",&c);
    switch(c){
    case 1:
        initiateSearch();
        break;
    case 2:
        getHistory();
        break;
    case 3:
        exit(1);
    default:
        printf("/n Invalid Choice/n");
    }
}

/*** THIS FUNCTION HANDLES SEARCH REQUEST ***/
void initiateSearch(){
    int d;
    char searchString[100];
    printf("For searching png file press :1\n");
    printf("For searching jpg file press :2\n");
    printf("For searching txt file press :3\n");
    printf("For menu press               :4\n");
    printf("For exit press               :5\n");
    printf("Enter your choice:");
    scanf("%d",&d);
    switch(d)
    {

    case 1:
        pngFile();
    case 2:
        jpgFile();
    case 3:
        txtFile();
    case 4:
        initiateProgram(0);
    case 5:
        exit(1);
    default:
        printf("Invalid choice");

    }}

    //IF THE FILE EXISTS
    void pngFile()
    {
        char searchString[100];
        ///PROMPT USER TO ENTER SEARCH KEYWORD
    printf("\nSearch:(Max 100 Characters) ");
    scanf ("\n%[^\n]%*c", searchString);
    char ifFound[150] = "";
    strcat(ifFound,"IF EXIST ");
    strcat(ifFound,searchString);
    strcat(ifFound,".png");
    strcat(ifFound," mspaint ");
    strcat(ifFound,searchString);
    strcat(ifFound,".png");
    system(ifFound);

      char ifNotFound[150] = "";
    strcat(ifNotFound,"IF NOT EXIST ");
    strcat(ifNotFound,searchString);
    strcat(ifNotFound,".txt ECHO File Not Found");
    system(ifNotFound);
     writeHistory(searchString);
     initiateProgram(0);




    }

void jpgFile()
{
        char searchString[100];
        ///PROMPT USER TO ENTER SEARCH KEYWORD
    printf("\nSearch:(Max 100 Characters) ");
    scanf ("\n%[^\n]%*c", searchString);
    char ifFound[150] = "";
    strcat(ifFound,"IF EXIST ");
    strcat(ifFound,searchString);
    strcat(ifFound,".jpg");
    strcat(ifFound," mspaint ");
    strcat(ifFound,searchString);
    strcat(ifFound,".jpg");
    system(ifFound);

      char ifNotFound[150] = "";
    strcat(ifNotFound,"IF NOT EXIST ");
    strcat(ifNotFound,searchString);
    strcat(ifNotFound,".txt ECHO File Not Found");
    system(ifNotFound);
     writeHistory(searchString);
     initiateProgram(0);

}
    //IF FILE DOESN'T EXIST
    void txtFile()
    {
         char searchString[100];
         ///PROMPT USER TO ENTER SEARCH KEYWORD
    printf("\nSearch:(Max 100 Characters) ");
    scanf ("\n%[^\n]%*c", searchString);
        char ifFound[150] = "";
    strcat(ifFound,"IF EXIST ");
    strcat(ifFound,searchString);
    strcat(ifFound,".txt");
    strcat(ifFound," notepad ");
    strcat(ifFound,searchString);
    strcat(ifFound,".txt");
    system(ifFound);

    char ifNotFound[150] = "";
    strcat(ifNotFound,"IF NOT EXIST ");
    strcat(ifNotFound,searchString);
    strcat(ifNotFound,".txt ECHO File Not Found");
    system(ifNotFound);
     writeHistory(searchString);
     initiateProgram(0);

}

void writeHistory(char history[100]){
    FILE *historyFile;
    historyFile = fopen("history.txt", "a");
    fprintf(historyFile, "%s",history);
    fprintf(historyFile, "\n",history);
    fclose(historyFile);
    printf("History Saved");
}

/*** THIS FUNCTION READS PREVIOUS SEARCH HISTORY AND PRINTS IT ***/
void getHistory(){
    FILE *historyFile;
    char str[100];
    ///OPEN HISTORY FILE
    historyFile = fopen("history.txt", "r");
    ///IF ERROR OCCURED DURING FILE OPEN, EXIT PROGRAM
    if (historyFile == NULL)
       {
        printf("No History");
        exit(1);
       }
    else
       {
        printf("\n\n=============== Previous Search History ==============\n");
        char line [ 100 ];
        ///READ HISTORY FILE LINE BY LINE AND PRINT
        while (fgets(line, sizeof(line), historyFile)) {
            printf("%s", line);
        }
        printf("=================== End Of History ===================\n");
        fclose(historyFile);
        ///TAKE USER BACK TO MAIN INTERFACE
        initiateProgram(0);

    }
}
