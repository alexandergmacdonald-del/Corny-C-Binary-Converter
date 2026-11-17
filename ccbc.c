// ===== WELCOME TO CCBC =====
// > This is a simple application I made for fun as in ECE 101 (At the University of Maine) we are learning about binary numbers & decimals
// > This is a simple application I cleaned up and ported from python so I could do my homework easier despite needing to show work. OOPS!
// > The code is under the MIT license so anybody can freely use it. I hope you learn from it as much as I learned when I made it
// > No ai generated code is in this!
// > Created by Alexander MacDonald, November 2026

// ===== Version History ====
// > 1.0.0: Basic release with messy code and few comments. Testing the waters of what C can do.
// > 1.1.0: Modified code to be cleaner & added more comments so others can learn from what I've made
// > 1.2.0: While initially starting out as a larger update, to add other conversions, I scaled back to making a 1.1.1 that cleaned up code but did a lot of rewriting

#include <stdio.h> // Primary header file
#include <math.h> // Math header required for powers
#include <stdbool.h> // Provides defenitions for bools

int binaryPrintLoopVal; // Value used for printing the Binary Value, in place of i
int pwr; // Used the power value so we can count downwards 
int decimal; // That decimal value again, modified for the sake of the equations. not displayed
int ogDecimal; // As stated later this is purely for saving the original Decimal value inputed
bool pwrs[8]; // 8 Bool values (which can be 1 or 0, perfect for binary) that are assigned based on decimal input

void binaryConverter(void) { // Type is void as our compiler gets angry if its an int
    for (pwr = 7; pwr >= 0; pwr--) { // Loop starting @ 7, and working our way down to 0
        // This loop is made for the sake of verifaction so calculations do not lead us to a number less than, or equal, to 0
        decimal-=pow(2,pwr); // Subtracts from the decimal value by the new pwr value

        if (decimal<0) { // Check to make sure we haven't reached a number below 0 and, if we do, changes are reverted & the bool is set to 0
            decimal+=pow(2,pwr);
            pwrs[pwr] = 0; // Sets it to the default value, fail safe that may not be needed
        } else { // Condition is met
            pwrs[pwr] = 1;
        }
        
    }
} // There's probaly a standard way to format this that I don't know. Does anybody read these comments? Please give me stars and treat me right.

int main(void) { // Main function
    
    while (1) { // Simple forever loop broken if conditions are met
        printf("Your Decimal Value (between 0 & 255): "); // we don't have a \n so we can type on the same line!
        scanf("%d", &decimal); // Scans for a number in the form of our intiger (decimal)
        if (decimal <= 255 && decimal >= 0) {
            ogDecimal = decimal; // Saves the user inputed decimal for later use. We don't need to redefine it as an int
            break; // Ends the function
        } else if (decimal > 255) {
            printf("Invalid #! Greater than 255\n"); // Goes to next line to start loop again after telling user that its invalid
        } else if (decimal < 0) {
            printf("Invalid #! Less than 0\n");
        } else {
            printf("invalid input!"); // If the user sees this then something has gone terribly wrong
        }
    }


    binaryConverter(); // Runs the function we wrote earlier

    printf("Your Decimal Value is: %d\n",ogDecimal); // the %d is required for the sake of displaying number values rather than text
    
    printf("Your Binary Value Is: ");
    for (binaryPrintLoopVal = 7; binaryPrintLoopVal >= 0; binaryPrintLoopVal--)
    {
        printf("%d",pwrs[binaryPrintLoopVal]);
    }

    // Function to close the function ourselves instead of letting it close automatically
    printf("\nPress Enter Key to Close");

    getchar(); // Consumes the previous input, in this case the decimal, so we can start again
    getchar(); // Waits for user input so to exit the application

    return 0; // exits the application, once previous condition is met

}
