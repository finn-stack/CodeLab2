//---------------------------------------------------------
// Carbon Footprint Calculator
// Challenge 1 - Programming Skills Portfolio
//---------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

//---------------------------------------------------------
// Calculate Total Emissions section.
//---------------------------------------------------------
// Calculates the user's total monthly carbon emissions
// using the emission formula provided in the brief. The
// result combines emissions from both car travel and
// electricity usage before returning the final value.
double calculateEmissions(double miles, double kwh)
{
    return (miles * 0.25) + (kwh * 0.20);
}

//---------------------------------------------------------
// DESIGN DECISION
//---------------------------------------------------------
// The calculateEmissions() function was created to
// separate calculations from user input and output.
// This follows modular programming principles and
// makes the program easier to read, test and maintain.
//
// PURPOSE:
// Calculate total monthly emissions from car mileage
// and electricity usage using the assessment formula.
//---------------------------------------------------------


//---------------------------------------------------------
// Classify Total Emissions section.
//---------------------------------------------------------
// Classifies the calculated emissions value into one of
// three categories: Low, Moderate or High. The category
// is determined using the thresholds specified within
// the assessment requirements.
string classifyEmission(double total)
{
    if (total < 100) // calc if it is less than 100, then it is low
    {
        return "Low";
    }
    else if (total >= 100 && total <=300) //calc if it bvetween 100 and 300, then it is moderate
    {
        return "Moderate";
    }
    else
    {
        return "High"; // satated function for if it is greater than 300, then it is high
    }
}

//---------------------------------------------------------
// DESIGN DECISION - CLASSIFICATION
//---------------------------------------------------------
// A separate classification function was created to
// convert the calculated emission value into a meaningful
// category (Low, Moderate or High). Separating the
// classification logic from the calculation improves
// readability, modularity and maintenance. If emission
// thresholds change in the future, only this function
// needs to be updated.
//---------------------------------------------------------

//---------------------------------------------------------
// Emission Advice section.
//---------------------------------------------------------
// Provides feedback based on the user's emission
// classification. Different advice is displayed for
// Low, Moderate and High emission categories.
void emissionAdvice(string classification)
{
    if (classification == "Low") //Low emission feedback
    {
        cout << "Great job! Your carbon footprint is low."
            << endl;
        cout << "Keep up the good work."
            << endl;
    }
    else if (classification == "Moderate") // Moderate emission feedback
    {
        cout << "Your carbon footprint is moderate."
            << endl;
        cout << "There is room for improvement."
            << endl;
    }
    else // High emission feedback
    {
    cout << "Your carbon footprint is high.\n"
    << "Have you considered the new Tesla roadster?\n"
    << "It now comes with a complimentary hydrogen bomb sized CO2 canister.\n";
    }
}

//---------------------------------------------------------
// ADDITIONAL FEATURE
//---------------------------------------------------------
// This function was added beyond the core calculation
// requirements to provide users with meaningful feedback
// based on their emission classification. Separating the
// advice into its own function improves readability and
// keeps output logic independent from calculations and
// classification logic.
//
// PURPOSE:
// Improve user experience by providing personalised
// feedback for Low, Moderate and High emission levels.
//
// DESIGN DECISION:
// A separate function was used so feedback can be modified
// without affecting the rest of the program.
//---------------------------------------------------------

//---------------------------------------------------------
// Main Program
//---------------------------------------------------------
// Controls the overall execution of the Carbon
// Footprint Calculator. The program collects user
// input, validates values, performs calculations
// and displays a summary report.
int main()
{ 

    //-----------------------------------------------------
    // Variable Declaration Section
    //-----------------------------------------------------
    // Stores the user's inputs, calculated emissions
    // value and the resulting emission classification.
    double carMiles, electricityUsage, totalEmissions;

    string classification;

//---------------------------------------------------------
// PROGRAM WORKFLOW / IMPLEMENTATION
//---------------------------------------------------------
// PURPOSE:
// Coordinates the overall execution of the program.
//
// IMPLEMENTATION:
// Input
// ↓
// Validation
// ↓
// Emission Calculation
// ↓
// Classification
// ↓
// Report Output
// ↓
// User Feedback
//
// DESIGN DECISION:
// main() acts as the controller of the program while
// individual functions perform specific tasks. This
// improves organisation, readability and maintenance.
//---------------------------------------------------------

//-------------------------------------------------------------------------
//prorgam bnanner.
//-------------------------------------------------------------------------
    // Displays the program title and identifies the
    // purpose of the application to the user.
    cout << "==================================" << endl;
    cout << "     Carbon Footprint Calculator" << endl;
    cout << "==================================" << endl;

//------------------------------------------------------------------------
// user input and validation section.
//-------------------------------------------------------------------------    
// Collects the user's monthly car mileage and electricity
// usage values. Validation is implemented using do-while
// loops to ensure negative numbers cannot be entered,
// preventing invalid emission calculations.
    do
    {
        cout << "Enter Monthly Car Miles Travelled: ";
        cin >> carMiles;

        if (carMiles < 0)
        {
            cout << "Miles cannot be negative." << endl;
        }

    } while (carMiles < 0);

    do
    {
        cout << "Enter Monthly Electricity Usage (kWh): ";
        cin >> electricityUsage;

        if (electricityUsage < 0)
        {
            cout << "Electricity usage cannot be negative." << endl;
        }

    } while (electricityUsage < 0);

//-------------------------------------------------------------------------
// emmision calculation section.
//-------------------------------------------------------------------------
    // Uses the validated input values to calculate total
    // carbon emissions and determine the appropriate
    // emission classification based on the calculated
    // result.
    totalEmissions =
        calculateEmissions(carMiles, electricityUsage);

    // Calls the classification function to determine
    // whether the user's emissions are Low, Moderate
    // or High.
    classification =
    classifyEmission(totalEmissions);

    // Formats numerical output to two decimal places.
    cout << fixed << setprecision(2); 

//-------------------------------------------------------------------------
// report output section.
//-------------------------------------------------------------------------
// Displays a summary report containing the user's
// input values, total carbon emissions and emission
// classification. This allows the user to review the
// results of the emission calculations.
cout << "\n==================================" << endl; 
cout << "         Carbon Report" << endl;
cout << "==================================" << endl;

    // Displays the monthly car mileage entered by the user.
    cout << "Car Miles Travelled: "
        << carMiles 
        << endl;

    // Displays the monthly electricity usage entered
    // by the user.
    cout << "Electricity Usage: "
        << electricityUsage 
        << " kWh"
        << endl;

    // Displays the calculated emission results.
    cout << "\nEmission Breakdown" << endl;
    cout << "------------------" << endl;

    // Displays the total carbon emissions calculated
    // using the emission formula.
    cout << "Total Emissions: "
        << totalEmissions 
        << endl;

    // Displays the user's emission classification.
    cout << "\nClassification: "
        << classification 
        << endl;        

    //-------------------------------------------------------------------------
    // Emission Advice Section
    //-------------------------------------------------------------------------
    // Calls the emissionAdvice() function to display
    // feedback based on the user's emission classification.
    emissionAdvice(classification); // Call the emissionAdvice function to provide advice based on the classification of the carbon footprint.

    cout << "==================================" << endl;

    return 0; // End of the program, returns 0 to indicate successful execution.
}
//---------------------------------------------------------
// Main Program end.
//---------------------------------------------------------


//97 lines of exacutiobale code no comments or spacing 
//with comments and spaces 196
