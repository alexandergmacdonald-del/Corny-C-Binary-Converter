#include <stdio.h>
#include <math.h> // needed for powers
#include <stdbool.h>
// no ai was used for this. This prob isn't the most professional. Idc.

bool entrLoop = 1; // Loop used for entering in a function
int pwr = 7; // Used the power so we can count downwatrds 
bool pwr7 = 0, pwr6 = 0, pwr5 = 0, pwr4 = 0, pwr3 = 0, pwr2 = 0, pwr1 = 0, pwr0 = 0; // Alright so instead of doing clever code we just set these from 0s to 1s and print them together. Idk how to do it better.
// Bools can be true or false. Prob more optimized. idc. I won't ask ai. I MADE THIS 
int decimal; // User inputed value


int binaryConverter(void) {
    while (pwr >= 0) // Hey we gotta make sure its not negative
    {
        decimal-=pow(2,pwr);
        if (decimal<0) {
            decimal+=pow(2,pwr);
        } else if (pwr == 7) {
            pwr7 = 1;
        } else if (pwr == 6) {
            pwr6 = 1;
        } else if (pwr == 5) {
            pwr5 = 1;
        } else if (pwr == 4) {
            pwr4 = 1;
        } else if (pwr == 3) {
            pwr3 = 1;
        } else if (pwr == 2) {
            pwr2 = 1;
        } else if (pwr == 1) {
            pwr1 = 1;
        } else if (pwr == 0) {
            pwr0 = 1;
        }
        pwr -= 1;
    }
}


int main(void) {  

printf("Your Binary Value (between 0 & 255): ");

    while (entrLoop == 1) {
        scanf("%d", &decimal);
        if (decimal <= 255 && decimal >= 0) { // both conditions msut be met. Theres prob something I could do to have it be a whole number but this
            entrLoop = 0;
        } else {
            printf("MORON\n");
        }
    }

    binaryConverter();
    printf("Your Decimal Value is: ");
    printf("%d",decimal);
    printf("/n");
    printf("Your binary value is: " );
    printf("%d%d%d%d%d%d%d%d", pwr7,pwr6,pwr5,pwr4,pwr3,pwr2,pwr1,pwr0);

    getchar(); // Waits for the user to press a key like enter
    getchar(); // For some reason we have to do this twice. idk why and frankly I'm too tired rn to care.
    return 0;
}
