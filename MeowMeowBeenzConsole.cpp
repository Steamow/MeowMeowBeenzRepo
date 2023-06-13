#include <fstream>  // Include necessary libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;  // Import the std namespace for easier access to its members

bool signedIn = false;  // Declare and initialize boolean variables
bool on = false;
bool first = true;

float nate3Rating;  // Declare float variables
float jordanRating;
float landonRating;
float nate3Value;
float jordanValue;
float landonValue;
float nate3Print;
float jordanPrint;
float landonPrint;
float nate3Weight;
float jordanWeight;
float landonWeight;

int voteInt = 0;  // Declare and initialize an integer variable

string userName;  // Declare string variables
string password;
string name;

void vote() {
    // Variables to store ratings from different sources
    float jordanFromNate, landonFromNate;
    float nateFromJordan, landonFromJordan;
    float nateFromLandon, jordanFromLandon;

    // Read ratings from files
    ifstream inFileNateRating("documents/nateVotes.txt");
    if (inFileNateRating) {
        inFileNateRating >> jordanFromNate >> landonFromNate;
        inFileNateRating.close();
    }

    ifstream inFileJordanRating("documents/jordanVotes.txt");
    if (inFileJordanRating) {
        inFileJordanRating >> nateFromJordan >> landonFromJordan;
        inFileJordanRating.close();
    }

    ifstream inFileLandonRating("documents/landonVotes.txt");
    if (inFileLandonRating) {
        inFileLandonRating >> nateFromLandon >> jordanFromLandon;
        inFileLandonRating.close();
    }


    // User-specific voting and rating calculations

    // Check the current user (userName) to determine which user is voting
    if (userName == "Nate") {
        // Nate's voting scenario

        // Check the voting scenario (voteInt) and update the corresponding ratings based on the vote

        // Scenario 1: Nate votes for Jordan's sport
        if (voteInt == 1) {
            // Check if Nate has already voted for Jordan, and if so, use that rating; otherwise, keep the existing rating
            if (jordanRating != 0) {
                nateFromJordan = jordanRating;
            }
            else {
                nateFromJordan = nateFromJordan;
            }

            // Check if Nate has already voted for Landon, and if so, use that rating; otherwise, keep the existing rating
            if (landonRating != 0) {
                nateFromLandon = landonRating;
            }
            else {
                nateFromLandon = nateFromLandon;
            }

            // Calculate new rating values based on weighted average and print the result
            nate3Value = ((nateFromJordan * jordanWeight) + (nateFromLandon * landonWeight)) / (jordanWeight + landonWeight);
            nate3Value = roundf(nate3Value * 100) / 100;
            nate3Print = roundf(nate3Value * 2) / 2;
            cout << "Cycling's rating is now | " << nate3Print << "\n";
        }
        // Scenario 2: Nate votes for Landon's sport
        else if (voteInt == 2) {
            // Check if Nate has already voted for Landon, and if so, use that rating; otherwise, keep the existing rating
            if (landonRating != 0) {
                nateFromLandon = landonRating;
            }
            else {
                nateFromLandon = nateFromLandon;
            }

            // Check if Nate has already voted for Jordan, and if so, use that rating; otherwise, keep the existing rating
            if (jordanRating != 0) {
                nateFromJordan = jordanRating;
            }
            else {
                nateFromJordan = nateFromJordan;
            }

            // Calculate new rating values based on weighted average and print the result
            nate3Value = ((nateFromJordan * jordanWeight) + (nateFromLandon * landonWeight)) / (jordanWeight + landonWeight);
            nate3Value = roundf(nate3Value * 100) / 100;
            nate3Print = roundf(nate3Value * 2) / 2;
            cout << "Football's rating is now | " << nate3Print << "\n";
        }

        // Update ratings in the file
        ofstream outFileNateRating("documents/nateVotes.txt");
        if (outFileNateRating) {
            outFileNateRating << jordanFromNate << " " << landonFromNate << endl;
            outFileNateRating.close();
        }
    }
    else if (userName == "Jordan") {
        // Jordan's voting scenario

        // Check the voting scenario (voteInt) and update the corresponding ratings based on the vote

        // Scenario 1: Jordan votes for Nate's sport
        if (voteInt == 1) {
            // Check if Jordan has already voted for Nate, and if so, use that rating; otherwise, keep the existing rating
            if (nate3Rating != 0) {
                jordanFromNate = nate3Rating;
            }
            else {
                jordanFromNate = jordanFromNate;
            }

            // Check if Jordan has already voted for Landon, and if so, use that rating; otherwise, keep the existing rating
            if (landonRating != 0) {
                jordanFromLandon = landonRating;
            }
            else {
                jordanFromLandon = jordanFromLandon;
            }

            // Calculate new rating values based on weighted average and print the result
            jordanValue = ((jordanFromNate * nate3Weight) + (jordanFromLandon * landonWeight)) / (nate3Weight + landonWeight);
            jordanValue = roundf(jordanValue * 100) / 100;
            jordanPrint = roundf(jordanValue * 2) / 2;
            cout << "Boxing's rating is now | " << jordanPrint << "\n";
        }
        // Scenario 2: Jordan votes for Landon's sport
        else if (voteInt == 2) {
            // Check if Jordan has already voted for Landon, and if so, use that rating; otherwise, keep the existing rating
            if (landonRating != 0) {
                jordanFromLandon = landonRating;
            }
            else {
                jordanFromLandon = jordanFromLandon;
            }

            // Check if Jordan has already voted for Nate, and if so, use that rating; otherwise, keep the existing rating
            if (nate3Rating != 0) {
                jordanFromNate = nateRating;
            }
            else {
                jordanFromNate = jordanFromNate;
            }

            // Calculate new rating values based on weighted average and print the result
            jordanValue = ((jordanFromNate * nate3Weight) + (jordanFromLandon * landonWeight)) / (nate3Weight + landonWeight);
            jordanValue = roundf(jordanValue * 100) / 100;
            jordanPrint = roundf(jordanValue * 2) / 2;
            cout << "Boxing's rating is now | " << jordanPrint << "\n";
        }

        // Update ratings in the file
        ofstream outFileJordanRating("documents/jordanVotes.txt");
        if (outFileJordanRating) {
            outFileJordanRating << nateFromJordan << " " << landonFromJordan << endl;
            outFileJordanRating.close();
        }
    }
    else if (userName == "Landon") {
        // Landon's voting scenario

        // Check the voting scenario (voteInt) and update the corresponding ratings based on the vote

        // Scenario 1: Landon votes for Nate's sport
        if (voteInt == 1) {
            // Check if Landon has already voted for Nate, and if so, use that rating; otherwise, keep the existing rating
            if (nate3Rating != 0) {
                landonFromNate = nateRating;
            }
            else {
                landonFromNate = landonFromNate;
            }

            // Check if Landon has already voted for Jordan, and if so, use that rating; otherwise, keep the existing rating
            if (jordanRating != 0) {
                landonFromJordan = jordanRating;
            }
            else {
                landonFromJordan = landonFromJordan;
            }

            // Calculate new rating values based on weighted average and print the result
            landonValue = ((landonFromNate * nate3Weight) + (landonFromJordan * jordanWeight)) / (nate3Weight + jordanWeight);
            landonValue = roundf(landonValue * 100) / 100;
            landonPrint = roundf(landonValue * 2) / 2;
            cout << "Cycling's rating is now | " << landonPrint << "\n";
        }
        // Scenario 2: Landon votes for Jordan's sport
        else if (voteInt == 2) {
            // Check if Landon has already voted for Jordan, and if so, use that rating; otherwise, keep the existing rating
            if (jordanRating != 0) {
                landonFromJordan = jordanRating;
            }
            else {
                landonFromJordan = landonFromJordan;
            }

            // Check if Landon has already voted for Nate, and if so, use that rating; otherwise, keep the existing rating
            if (nate3Rating != 0) {
                landonFromNate = nate3Rating;
            }
            else {
                landonFromNate = landonFromNate;
            }

            // Calculate new rating values based on weighted average and print the result
            landonValue = ((landonFromNate * nate3Weight) + (landonFromJordan * jordanWeight)) / (nate3Weight + jordanWeight);
            landonValue = roundf(landonValue * 100) / 100;
            landonPrint = roundf(landonValue * 2) / 2;
            cout << "Football's rating is now | " << landonPrint << "\n";
        }

        voteInt = 0;

        // Update ratings in the file
        ofstream outFileLandonRating("documents/landonVotes.txt");
        if (outFileLandonRating) {
            outFileLandonRating << nateFromLandon << " " << jordanFromLandon << endl;
            outFileLandonRating.close();
        }
    }

    }
    nate3Print = roundf(nate3Value * 2) / 2;
    jordanPrint = roundf(jordanValue * 2) / 2;
    landonPrint = roundf(landonValue * 2) / 2;
    cout << "Welcome to MeowMeowBeenz " << userName << "!\nRate the following Sports on which one is the best!\nCycling | " << nate3Print << "\nBoxing | " << jordanPrint << "\nHockey | " << landonPrint << endl;
    // Print the rounded ratings for each sport
    nate3Print = roundf(nate3Value * 2) / 2; // Round Nate's rating to the nearest 0.5
    jordanPrint = roundf(jordanValue * 2) / 2; // Round Jordan's rating to the nearest 0.5
    landonPrint = roundf(landonValue * 2) / 2; // Round Landon's rating to the nearest 0.5
    cout << "Welcome to MeowMeowBeenz " << userName << "!\nRate the following Sports on which one is the best!\nCycling | " << nate3Print << "\nBoxing | " << jordanPrint << "\nHockey | " << landonPrint << endl;

    // Start the voting loop
    while (on)
    {
        // Update the weights based on the rounded ratings
        nate3Weight = roundf(nate3Print - .49); // Calculate the weight for Nate's rating
        jordanWeight = roundf(jordanPrint - .49); // Calculate the weight for Jordan's rating
        landonWeight = roundf(landonPrint - .49); // Calculate the weight for Landon's rating

        // Prompt the user for their vote
        cout << "Who would you like to vote for (Cycling, Boxing, or Hockey)? or you can (Sign-Out or Quit). ";
        cin >> name;

        // Handle user votes and ratings for Cycling
        if (name == "Cycling" && userName != "Nate") {
            cout << "What is your rating (out of 5) for Cycling? ";
            while (!(cin >> nate3Rating) || nate3Rating < 1 || nate3Rating > 5) {
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            voteInt = 1;
            vote(); // Call the vote function to update the ratings
        }
        // Handle user votes and ratings for Boxing
        else if (name == "Boxing" && userName != "Jordan") {
            cout << "What is your rating (out of 5) for Boxing? ";
            while (!(cin >> jordanRating) || jordanRating < 1 || jordanRating > 5) {
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            voteInt = 2;
            vote(); // Call the vote function to update the ratings
        }
        // Handle user votes and ratings for Hockey
        else if (name == "Hockey" && userName != "Landon") {
            cout << "What is your rating (out of 5) for Hockey? ";
            while (!(cin >> landonRating) || landonRating < 1 || landonRating > 5) {
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            voteInt = 3;
            vote(); // Call the vote function to update the ratings
        }
        // Handle quitting the program
        else if (name == "Quit") {
            cout << "Exiting MeowMeowBeenz!" << endl;
            voteInt = 0;
            vote(); // Call the vote function to update the ratings
            on = false; // Set on to false to exit the loop
        }
        // Handle signing out
        else if (name == "Sign-Out") {
            cout << "Logging out." << endl;
            voteInt = 0;
            vote(); // Call the vote function to update the ratings
            userName = "";
            password = "";
            on = false; // Set on to false to exit the loop
            signedIn = false; // Set signedIn to false to indicate the user is signed out
            nate3Rating = 0; // Reset Nate's rating
            landonRating = 0; // Reset Landon's rating
            jordanRating = 0; // Reset Jordan's rating
        }
        // Handle invalid input
        else {
            cout << "Invalid input. You cannot vote for yourself, or if you made a typo, please refer to your possible options: \nCycling, Boxing, Hockey, Sign-Out, or Quit." << endl;
        }

        // Update the ratings in the file
        ofstream outFile("documents/.values.txt");
        if (outFile) {
            outFile << nate3Value << " " << jordanValue << " " << landonValue << endl;
            outFile.close();
        }
    }

    // Check if the user is signed in and the loop is finished
    if (signedIn == true && on == false) {
        return 0; // Exit the program if the user is still signed in
    }
    else {
        main(); // Restart the main function if the user is signed out
    }

}