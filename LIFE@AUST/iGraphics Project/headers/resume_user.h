#include<iostream>
using namespace std;
#define FILENAME3 "user_data.txt"

int resume_user_number;
int resume_total_user;

struct resume_details {
    char resume_name [10];
    int  resume_left_chances;
    int  resume_game_level;
    int  resume_game_point;
} resume_details [20]; 

struct resume_string_details{
    char  resume_name [10];
    char  resume_left_chances[10];
    char  resume_game_level[10];
    char  resume_game_point[10];
} resume_string_details [20];


void resume_user_counter(){  // counts the line of a file

   FILE *fp;
   char ch;
   int linesCount=0;
   //open file in read more
   fp=fopen(FILENAME3,"r");
   if(fp==NULL) {
      printf("File \"%s\" does not exist!!!\n",FILENAME3);
   }
   //read character by character and check for new line
   while((ch=fgetc(fp))!=EOF) {
      if(ch=='\n')
         linesCount++;
   }
   //close the file
   fclose(fp);

   int total_attributes =4; 
   int total_lines =linesCount+1;
   resume_total_user = total_lines / total_attributes; 
}





void resume_file_scanner()  //scans the data of the file
{

    FILE *user_file = fopen ("user_data.txt", "r");  //opening the file in reading mode

    if (user_file == NULL){
        printf("Resume File not found \n");
    } else {
        for (int i = 0; i < resume_total_user ; i++){ 
                 
                    fscanf(user_file, "%s %s", &resume_string_details[i].resume_name,&resume_details[i].resume_name);
                    fscanf(user_file, "%s %d", &resume_string_details[i].resume_left_chances,&resume_details[i].resume_left_chances);
                    fscanf(user_file, "%s %d", &resume_string_details[i].resume_game_level,&resume_details[i].resume_game_level);
                    fscanf(user_file, "%s %d", &resume_string_details[i].resume_game_point,&resume_details[i].resume_game_point);
                          
        }
        fclose(user_file);
    }        
}

void file_data_printer()  //prints the data of the file
{
    for (int i =0 ; i < resume_total_user ; i ++)
    {

        printf("%s\t\t %s\n", resume_string_details[i].resume_name,resume_details[i].resume_name);
        printf("%s\t\t %d\n", resume_string_details[i].resume_left_chances,resume_details[i].resume_left_chances);
        printf("%s\t\t %d\n", resume_string_details[i].resume_game_level,resume_details[i].resume_game_level);
        printf("%s\t\t %d\n", resume_string_details[i].resume_game_point,resume_details[i].resume_game_point);

        printf("\n\n");
    }
}

bool user_authenticator ()  //checking if the user is new or old return a true or false value
{   
    char user_name[10];
    bool old_user_value = false;
    printf("Enter your user name : \n");
    scanf ("%s",&user_name);

    for (int i = 0 ; i < resume_total_user ; i++)
        {
            if( !strcmp(resume_details[i].resume_name,user_name) )
            {
                old_user_value = true; 
                resume_user_number=i;
                break;  
            }     
        }

        return old_user_value;
}

void resume_data_assigner()
{

      
    if ( user_authenticator() )
    {
        printf("Old user\n");  //determines a user is new or old

        printf("%s\t\t %s\n", resume_string_details[resume_user_number].resume_name,resume_details[resume_user_number].resume_name);
        printf("%s\t\t %d\n", resume_string_details[resume_user_number].resume_left_chances,resume_details[resume_user_number].resume_left_chances);
        printf("%s\t\t %d\n", resume_string_details[resume_user_number].resume_game_level,resume_details[resume_user_number].resume_game_level);
        printf("%s\t\t %d\n", resume_string_details[resume_user_number].resume_game_point,resume_details[resume_user_number].resume_game_point);

    }  
    else           printf("New user\n");
}