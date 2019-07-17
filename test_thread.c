#include <pthread.h>
#include <stdio.h>


#define  NUM_THREADS 40

void *say_hello(void *args)
{
    int a = *(int*)args;
    printf("hello Run this way %d\n", a);
    return 0;
}

int main()
{
    pthread_t  tids[NUM_THREADS];
    int index[NUM_THREADS];
    for(int i =0; i < NUM_THREADS; i++){
        index[i] = i;
        int ret = pthread_create(&tids[i], NULL, say_hello, (void*)&index[i]);
        if(ret != 0){
            printf("pthread_create error , error code is %d\n", ret);
        }
    }

    pthread_exit(NULL);
    return 0;
}
