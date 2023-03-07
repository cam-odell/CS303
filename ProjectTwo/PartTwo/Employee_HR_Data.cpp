#include "Employee_HR_Data.h"

int main() {
    // Create a professional employee object
    Professional professional("Bjarne Stroustrup", 75000, 10, 40);
    // Print out the professional employee's information
    professional.printInformation();

    // Create a nonprofessional employee object
    Nonprofessional nonprofessional("Guido van Rossum", 15, 30);
    // Print out the nonprofessional employee's information
    nonprofessional.printInformation();

    return 0;
}
