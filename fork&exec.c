#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc , char** argv){
    printf("[%s] %s saniye boyunca %s calistirilacak ... \n",argv[0],argv[2],argv[1]);
    fflush(stdout);
    int saniye = atoi(argv[2]);
    int a = fork();
    if(a == 0){
        execv(argv[1],argv);
    }else{
        sleep(saniye);
        kill(a,9);
        printf("\n[%s] %s saniye sona erdi %s kapatiliyor ... ",argv[0],argv[2],argv[1]);
    }
    return 0 ;
}
