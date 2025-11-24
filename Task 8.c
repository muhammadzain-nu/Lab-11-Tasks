#include <stdio.h>

#define METER_TO_KM 0.001  

float convert(float meters) {
    static int callCount = 0;  // static variable
    callCount++;

    printf("Function called %d times\n", callCount);

    return meters * METER_TO_KM;
}

int main() {
    float m;

    printf("Enter distance in meters: ");
    scanf("%f", &m);

    float km = convert(m);
    printf("%.2f meters = %.4f kilometers\n", m, km);

    convert(100);  
    convert(200);

    return 0;
}

