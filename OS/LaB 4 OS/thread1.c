#include <stdio.h>
#include <string.h>
#include <pthread.h>


void* func(){
  
  printf("This is a statement from thread and thread id %ld\n",pthread_self());
  pthread_exit(NULL);
}
int main(void){
  pthread_t id;

  pthread_create(&id, NULL, func, NULL);


  pthread_join(id,NULL);
  printf("A statement from parent process\n");
  return 0;
  
}
