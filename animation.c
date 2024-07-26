#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

volatile int FLAG_STOP = 0; 
volatile int SLEEP_DURATION = 200000; 
void* animation(void *arg) {
    int pinguim[25][30] = { 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11,10,10, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 6, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0,11, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < 1000000; i++) {
        // printf("\033[H\033[J");
        // printf("\r");
        for (int k = 0; k < 25; k++) {
            for (int j = 0; j < 30; j++) {
                printf ("\033[%d;%dH", k, j+50 ); 
                switch (pinguim[k][(j + i) % 30]) {
                    case 0: printf(" "); break;
                    case 1: printf("_"); break;
                    case 2: printf("("); break;
                    case 3: printf("o"); break;
                    case 4: printf("`"); break;
                    case 5: printf("-"); break;
                    case 6: printf("/"); break;
                    case 7: printf("\\"); break;
                    case 8: printf("|"); break;
                    case 9: printf("^"); break;
                    case 10: printf("="); break;
                    case 11: printf("<"); break;
                    default: break;
                }
            }
            // printf("\n");
        }


        fflush(stdout);

        for (int k = 0; k < SLEEP_DURATION; k += 10000) {
            if (FLAG_STOP == 1) {
                printf("\033[2J\033[0;0H");
                fflush(stdout);
                return NULL;
            }
            usleep(10000);
        }
    }

    return NULL;
}

void* stopAnimation(void* arg) {
    int command;
    while (1) {
        printf("\033[25;0HEnter 1 to stop, 2 to speed up: ");
        fflush(stdout);

        if (scanf("%d", &command) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            continue;
        }

        if (command == 1) {
            FLAG_STOP = 1;
            break;
        } else if (command == 2) {

            printf("\033[2J");
            fflush(stdout);
            SLEEP_DURATION = SLEEP_DURATION > 10000 ? SLEEP_DURATION / 2 : 10000;
        }
    }
    return NULL;
}


int main(int argc, char* argv[]) {
    pthread_t threads[2];

    printf("\033[2J");
    // printf ("\033[10;1HEnter 1 to stop, 2 to speed up: "); 
    // printf("\033[1;1H teste");
    // fflush(stdout);


    pthread_create(&threads[0], NULL, animation, NULL);
    pthread_create(&threads[1], NULL, stopAnimation, NULL);

    for (int i = 0; i < 2; i++)
        pthread_join(threads[i], NULL);

    return 0;
}
