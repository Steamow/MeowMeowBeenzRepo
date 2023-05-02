// MeowMeowBeenzConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool signedIn = false;
bool on = false;
float nate3Rating;
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
int voteInt;
string userName;
string password;
string name;

void vote() {
    ifstream inFileNatesRatings("documents/nateVotes");
    float jordanFromNate{}, landonFromNate{};
    if (inFileNatesRatings) {
        inFileNatesRatings >> jordanFromNate >> landonFromNate;
        inFileNatesRatings.close();
    }
    ifstream inFilejordansRatings("documents/jordanVotes");
    float nateFromJordan, landonFromJordan{};
    if (inFilejordansRatings) {
        inFilejordansRatings >> nateFromJordan >> landonFromJordan;
        inFilejordansRatings.close();
    }
    ifstream inFilelandonsRatings("documents/landonVotes");
    float nateFromLandon, jordanFromLandon{};
    if (inFilelandonsRatings) {
        inFilelandonsRatings >> nateFromLandon >> jordanFromLandon;
        inFilelandonsRatings.close();
    }
    if (userName == "Nate") {

        if (voteInt == 2) {
            if (jordanRating != 0) {
                jordanFromNate = jordanRating;
            }
            else
            {
                jordanFromNate = jordanFromNate;
            }
            if (landonRating != 0) {
                landonFromNate = landonRating;
            }
            else
            {
                landonFromNate = landonFromNate;
            }

            ofstream outFileNatesRating("documents/nateVotes");

            if (outFileNatesRating) {
                outFileNatesRating << jordanFromNate << " " << landonFromNate << endl;
                outFileNatesRating.close();
            }
            jordanValue = ((jordanFromNate * nate3Weight) + (jordanFromLandon * landonWeight)) / nate3Weight + landonWeight;
        }
        else if (voteInt == 3) {
            if (jordanRating != 0) {
                jordanFromNate = jordanRating;
            }
            else
            {
                jordanFromNate = jordanFromNate;
            }
            if (landonRating != 0) {
                landonFromNate = landonRating;
            }
            else
            {
                landonFromNate = landonFromNate;
            }
            
            landonFromNate = landonRating;
            ofstream outFileNatesRating("documents/nateVotes");

            if (outFileNatesRating) {
                outFileNatesRating << jordanFromNate << " " << landonFromNate << endl;
                outFileNatesRating.close();
            }
            landonValue = ((landonFromNate * nate3Weight) + (landonFromJordan * jordanWeight)) / nate3Weight + jordanWeight;
        }
    }
}

int main()
{
    ifstream inFile("documents/.values.txt");
    if (inFile) {
        inFile >> nate3Value >> jordanValue >> landonValue;
        inFile.close();
    }
    cout << "Now opening MeowMeowBeenz" << endl;
    
    while (signedIn == false)
    {
        cout << "enter your user name: ";
        cin >> userName;
        ifstream inFileLogin("documents/.login.txt");
        string usernameFromFile, passwordFromFile;
        bool userFound = false;
        while (inFileLogin >> usernameFromFile >> passwordFromFile) {
            if (userName == usernameFromFile) {
                userFound = true;
                string enteredPassword;
                cout << "enter your password: ";
                cin >> enteredPassword;
                if (enteredPassword == passwordFromFile) {
                    signedIn = true;
                    on = true;
                    cout << "Login successful." << endl;
                    break; // exit the loop as soon as a matching user is found
                }
                else {
                    cout << "Incorrect password. Please try again." << endl;
                }
            }
        }
        if (!userFound) {
            cout << "User not found. Please sign up." << endl;
            // Add code to create a new user account if desired
        }
    }
    
    nate3Print = roundf(nate3Value * 2) / 2;
    jordanPrint = roundf(jordanValue * 2) / 2;
    landonPrint = roundf(landonValue * 2) / 2;
    cout << "Welcome to MeowMeowBeenz " << userName << "!\nRate the following people on how you feel about them!\nNate 3 | " << nate3Print << "\nJordan | " << jordanPrint << "\nLandon | " << landonPrint << endl;
    while (on)
    {
        if (userName == "Nate") {
            nate3Weight = roundf(nate3Print - .49);

        }
        else if (userName == "Jordan") {
            jordanWeight = roundf(jordanPrint - .49);
        }
        else if (userName == "Landon") {
            landonWeight = roundf(landonPrint - .49);
        }
        cout << "Who would you like to vote for (Nate3, Jordan, or Landon)? or you can (Sign-Out or Quit). ";
        cin >> name;
        if (name == "Nate3" && userName != "Nate") {
            // Update Nate3's rating
            cout << "What is your rating (out of 5) for Nate3? ";
            while (!(cin >> nate3Rating) || nate3Rating < 1 || nate3Rating > 5) { // check if input is a number between 1 and 5
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input buffer
            }
            /*
            nate3Value = (nate3Value * 4 + nate3Rating) / 5;
            nate3Value = roundf(nate3Value * 100) / 100;
            nate3Print = roundf(nate3Value * 2) / 2;
            cout << "Nate 3's rating is now | " << nate3Print << "\n";
            */
            voteInt = 1;
            vote();

        }
        else if (name == "Jordan" && userName != "Jordan") {
            // Update Jordan's rating
            cout << "What is your rating (out of 5) for Jordan? ";
            while (!(cin >> jordanRating) || jordanRating < 1 || jordanRating > 5) { // check if input is a number between 1 and 5
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input buffer
            }
            jordanValue = (jordanValue * 4 + jordanRating) / 5;
            jordanValue = roundf(jordanValue * 100) / 100;
            jordanPrint = roundf(jordanValue * 2) / 2;
            cout << "Jordan's rating is now | " << jordanPrint << "\n";
        }
        else if (name == "Landon" && userName != "Landon") {
            // Update Landon's rating
            cout << "What is your rating (out of 5) for Landon? ";
            while (!(cin >> landonRating) || landonRating < 1 || landonRating > 5) { // check if input is a number between 1 and 5
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input buffer
            }
            landonValue = (landonValue * 4 + landonRating) / 5;
            landonValue = roundf(landonValue * 100) / 100;
            landonPrint = roundf(landonValue * 2) / 2;
            cout << "landon's rating is now | " << landonPrint << "\n";
        }
        else if (name == "Quit") {
            // Exit the program if the user types "quit"
            cout << "Exiting MeowMeowBeenz!" << endl;
            on = false;
        }
        else if (name == "Sate3") {
            // Update Nate3's rating
            cout << "What is your rating (out of 5) for Nate3? ";
            cin >> nate3Value;
            nate3Value = roundf(nate3Value * 100) / 100;
            nate3Print = roundf(nate3Value * 2) / 2;
            cout << "Nate 3's rating is now | " << nate3Print << "\n";
        }
        else if (name == "Sordan") {
            // Update Jordan's rating
            cout << "What is your rating (out of 5) for Jordan? ";
            cin >> jordanValue;
            jordanValue = roundf(jordanValue * 100) / 100;
            jordanPrint = roundf(jordanValue * 2) / 2;
            cout << "Jordan's rating is now | " << jordanPrint << "\n";
        }
        else if (name == "Sandon") {
            // Update Landon's rating
            cout << "What is your rating (out of 5) for Landon? ";
            cin >> landonValue;
            landonValue = roundf(landonValue * 100) / 100;
            landonPrint = roundf(landonValue * 2) / 2;
            cout << "landon's rating is now | " << landonPrint << "\n";
        }
        else if (name == "Sign-Out") {
            cout << "loging out \n";
            userName = "";
            password = "";
            on = false;
            signedIn = false;
            nate3Rating = 0;
            landonRating = 0;
            jordanRating = 0;

        }
        
        else {
            // Invalid input
            cout << "Invalid input, you cannot vote for yourself, or if you made a type please refer you your possible options: \n Nate3, Jordan, Landon, Sign-Out or Quit." << endl;
        }

        ofstream outFile("documents/.values.txt");
        if (outFile) {
            outFile << nate3Value << " " << jordanValue << " " << landonValue << endl;
            outFile.close();
        }
    }
    
    if (signedIn == true && on == false) {
        return 0;
    }
    else {
        main();
    }
}


