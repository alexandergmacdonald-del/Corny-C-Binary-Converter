// ===== WELCOME TO CCBC =====
// > This is a simple application I made for fun as in ECE 101 (At the University of Maine) we are learning about binary numbers & decimals
// > This is a simple application I cleaned up and ported from python so I could do my homework easier despite needing to show work. OOPS!
// > The code is under the MIT license so anybody can freely use it. I hope you learn from it as much as I learned when I made it
// > No ai generated code is in this!

#include <stdio.h> // Primary header file
#include <math.h> // Math header required for powers
#include <stdbool.h> // Provides defenitions for bools


int pwr = 7; // Used the power value so we can count downwards 
bool pwr7 = 0, pwr6 = 0, pwr5 = 0, pwr4 = 0, pwr3 = 0, pwr2 = 0, pwr1 = 0, pwr0 = 0; // Bool values used for the individual numbers of the final Binary value. By default they are 0;
// Bools are used as they are either true or false, 1 or 0 
int decimal; // User intiger input


int binaryConverter(void) {
    while (pwr >= 0) // Verification that the calculations do not lead us to a number less than, or equal, to 0
    {
        decimal-=pow(2,pwr); // Subtracts from the decimal value by the new pwr value
        if (decimal<0) { // Check to make sure we haven't reached a number below 0 and a fix if we do
            decimal+=pow(2,pwr);

        } else if (pwr == 7) { // This is used repeatedly but what it does is set the pwr to 1 to show it works
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
        pwr -= 1; // Subtracts from the exponet so we can go to the next one
    }
}

// Main function
int main(void) {  

printf("Your Binary Value (between 0 & 255): "); // we don't have a /n so we can type on the same line!

    while (1) { // Simple while true
        scanf("%d", &decimal);
        if (decimal <= 255 && decimal >= 0) { // Check for the conditions that its between 255 & 0. I am unsure how to check if it is an intiger though.
            break; // Ends the function
        } else {
            printf("Invalid #!\n"); // Goes to next line to start loop again after telling user that its invalid
        }
    }

    binaryConverter(); // Runs the function we wrote earlier

    printf("Your Decimal Value is: ");
    printf("%d",decimal); // the %d is required for the sake of displaying number values rather than text
    printf("/n");
    printf("Your binary value is: " );
    printf("%d%d%d%d%d%d%d%d", pwr7,pwr6,pwr5,pwr4,pwr3,pwr2,pwr1,pwr0); // there is likely a cleaner solution for this

    getchar(); // Consumes the previous input, in this case the decimal, so we can start again
    getchar(); // Waits for user input so to exit the application

    return 0; // exits the application, once previous condition is met
}
