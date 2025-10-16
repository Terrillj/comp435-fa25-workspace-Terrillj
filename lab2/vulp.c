#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    char * fn = "/tmp/XYZ";
    char buffer[60];
    FILE *fp;

    uid_t saved_id = geteuid();

    /* get user input */
    scanf("%50s", buffer );

    if (seteuid(getuid()) != 0){
        printf("Unable to drop privileges");
        return 1;
    }

   if(!access(fn, W_OK)){ 
       fp = fopen(fn, "a+"); 
       fwrite("\n", sizeof(char), 1, fp);
       fwrite(buffer, sizeof(char), strlen(buffer), fp);
       fclose(fp);
   }
   else printf("No permission \n");

   if (seteuid(saved_id) != 0){
    return 1;
   }
}

