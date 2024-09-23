#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
This program calculates the probability that a randomly thrown toothpick will touch the lines
on a hard wood floor

This program assumes that the tooth pick and the space between the lines on the hardwood floor
are equal
*/
int main() {
    // set seed to time
    srand(time(NULL));
    double pi = M_PI;
    int i, it, touch;
    long int n = 10000000;

    int lines_touched = 0;
    for (i = 0; i < n; i++) {
        // calculate y coordinate of one of the stick end points
        // between 0 and 1
        double stick_start_point = (double)rand() / RAND_MAX;
        // printf("start %f\n", stick_start_point);

        // tooth pick orientation is between 0 and 2pi
        double tooth_pick_angle = (double)rand() / RAND_MAX;
        tooth_pick_angle = (double)tooth_pick_angle * (2.0*pi);
        
        double sine_tooth_pick = sin(tooth_pick_angle);
        // printf("sin%f\n", sine_tooth_pick);

        // calculate the y axis component of the other end point of the stick
        double stick_end_point = stick_start_point + sine_tooth_pick;
        // printf("end%f\n", stick_end_point);

        if (stick_start_point == 0 || stick_start_point == 1) {
            lines_touched++;
        }
        if (stick_end_point <=0 || stick_end_point >= 1) {
            lines_touched++;
        }
    }
    printf("hits: %d\n", lines_touched);
    printf("misses: %ld\n", n-lines_touched);
    printf("ratio %f\n", (double)lines_touched / n);


    return 0;
}
