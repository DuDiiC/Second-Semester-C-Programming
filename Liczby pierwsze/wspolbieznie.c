#include<stdio.h>
#include<math.h>
#include<pthread.h>

int max;

pthread_mutex_t mutex;

void* czyPierwsza(void *arg) {
    int numer_watku = (int) arg;
    int test;
    int i, flaga;
    do {
        flaga = 1;
        pthread_mutex_lock(&mutex);
        test = max;
        max++;
        pthread_mutex_unlock(&mutex);

        for(i=2 ; i*i<=test ; ++i) {
            if(test%i == 0 && test != 2) {
                flaga = 0;
                break;
            }
        }
        /* if(flaga == 1) printf("%d {watek: %d}\n ", test, numer_watku); */

    }
    while(test <= pow(10, 8));

    return NULL;
}

int main(void) {
    int i;
    pthread_t thread[10];
    max = 2;

    /* inicjujemy blokade */
    pthread_mutex_init(&mutex, NULL);

    /* tworzymy 10 watkow */
    for(i=0;i<10;++i){
	if(pthread_create(&thread[i], NULL, czyPierwsza, (void*)i) != 0){
	printf("pthread_create error\n");
	return 1;
	}
    }
    /* czeka az watki zostana zakonczone */
    for(i=0;i<10;++i){
	pthread_join(thread[i],NULL);
    }
    /* usuwamy blokade */
    pthread_mutex_destroy(&mutex);

    return 0;
}
