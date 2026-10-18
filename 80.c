#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

struct Stream {
    int x;
    int y;
    int speed;
    int length;
};

void init_stream(struct Stream *s) {
    s->x = rand() % WIDTH;
    s->y = -(rand() % HEIGHT);
    s->speed = 1 + rand() % 3;
    s->length = 5 + rand() % 15;
}

int main() {
    char grid[HEIGHT][WIDTH];
    struct Stream streams[40];
    int i, x, y, frame;
    
    srand((unsigned int)time(NULL));
    
    for (i = 0; i < 40; i++) {
        init_stream(&streams[i]);
    }
    
    printf("\033[2J");
    
    for (frame = 0; frame < 300; frame++) {
        memset(grid, ' ', sizeof(grid));
        
        for (i = 0; i < 40; i++) {
            for (int j = 0; j < streams[i].length; j++) {
                int curr_y = streams[i].y - j;
                if (curr_y >= 0 && curr_y < HEIGHT) {
                    if (j == 0) {
                        grid[curr_y][streams[i].x] = 'A' + rand() % 26;
                    } else {
                        grid[curr_y][streams[i].x] = '0' + rand() % 10;
                    }
                }
            }
            
            streams[i].y += streams[i].speed;
            if (streams[i].y - streams[i].length >= HEIGHT) {
                init_stream(&streams[i]);
            }
        }
        
        printf("\033[H");
        for (y = 0; y < HEIGHT; y++) {
            for (x = 0; x < WIDTH; x++) {
                if (grid[y][x] != ' ') {
                    printf("\033[1;32m%c", grid[y][x]);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 60000000;
        nanosleep(&ts, NULL);
    }
    
    printf("\033[0m\033[2J");
    return 0;
}

