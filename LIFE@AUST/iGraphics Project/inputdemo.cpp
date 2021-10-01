#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "resume_user.h" //this header file counts the lines in a file and according to that creates some variables

int main ()
{ 
    resume_user_counter();
    resume_file_scanner();
    file_data_printer();  // prints the data of the file in the console
    resume_data_assigner();

return 0;
}
