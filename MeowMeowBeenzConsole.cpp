
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

bool signedIn = false;
bool on = false;
bool first = true;
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
int voteInt = 0;
string userName;
string password;
string name;

void vote() {
    float jordanFromNate, landonFromNate;
    ifstream inFileNatesRatings("documents/nateVotes.txt");
    if (inFileNatesRatings) {
        inFileNatesRatings >> jordanFromNate >> landonFromNate;
        inFileNatesRatings.close();
    }
    float nateFromJordan, landonFromJordan;
    ifstream inFileJordansRatings("documents/jordanVotes.txt");
    if (inFileJordansRatings) {
        inFileJordansRatings >> nateFromJordan >> landonFromJordan;
        inFileJordansRatings.close();
    }
    float nateFromLandon, jordanFromLandon;
    ifstream inFilelandonsRatings("documents/landonVotes.txt");
    if (inFilelandonsRatings) {
        inFilelandonsRatings >> nateFromLandon >> jordanFromLandon;
        inFilelandonsRatings.close();
    }
    if (userName == "Nate") {

        if (voteInt == 2) {
            if (jordanRating != 0) {
                jordanFromNate = jordanRating;
            }
            else{
                jordanFromNate = jordanFromNate;
            }
            if (landonRating != 0) {
                landonFromNate = landonRating;
            }
            else{
                landonFromNate = landonFromNate;
            }

            jordanValue = ((jordanFromNate * nate3Weight) + (jordanFromLandon * landonWeight)) / (nate3Weight + landonWeight);
            jordanValue = roundf(jordanValue * 100) / 100;
            jordanPrint = roundf(jordanValue * 2) / 2;
            cout << "Boxing's rating is now | " << jordanPrint << "\n";
        }
        else if (voteInt == 3) {
            if (jordanRating != 0) {
                jordanFromNate = jordanRating;
            }
            else{
                jordanFromNate = jordanFromNate;
            }
            if (landonRating != 0) {
                landonFromNate = landonRating;
            }
            else{
                landonFromNate = landonFromNate;
            }

            landonValue = ((landonFromNate * nate3Weight) + (landonFromJordan * jordanWeight)) / (nate3Weight + jordanWeight);
            landonValue = roundf(landonValue * 100) / 100;
            landonPrint = roundf(landonValue * 2) / 2;
            cout << "Hockey's rating is now | " << landonPrint << "\n";
        }
        voteInt = 0;

        ofstream outFileNatesRating("documents/nateVotes.txt");

        if (outFileNatesRating) {
            outFileNatesRating << jordanFromNate << " " << landonFromNate << endl;
            outFileNatesRating.close();
        }      
    }
    else if (userName == "Jordan") {

        if (voteInt == 1) {
            if (nate3Rating != 0) {
                nateFromJordan = nate3Rating;
            }
            else {
                nateFromJordan = nateFromJordan;
            }
            if (landonRating != 0) {
                landonFromJordan = landonRating;
            }
            else {
                landonFromJordan = landonFromJordan;
            }

            nate3Value = ((nateFromJordan * jordanWeight) + (nateFromLandon * landonWeight)) / (jordanWeight + landonWeight);
            nate3Value = roundf(nate3Value * 100) / 100;
            nate3Print = roundf(nate3Value * 2) / 2;
            cout << "Cycling's rating is now | " << nate3Print << "\n";
        }
        else if (voteInt == 3) {
            if (nate3Rating != 0) {
                nateFromJordan = nate3Rating;
            }
            else {
                nateFromJordan = nateFromJordan;
            }
            if (landonRating != 0) {
                landonFromJordan = landonRating;
            }
            else {
                landonFromJordan = landonFromJordan;
            }

            landonValue = ((landonFromNate * nate3Weight) + (landonFromJordan * jordanWeight)) / (nate3Weight + jordanWeight);
            landonValue = roundf(landonValue * 100) / 100;
            landonPrint = roundf(landonValue * 2) / 2;
            cout << "Hockey's rating is now | " << landonPrint << "\n";
        }
        voteInt = 0;

        ofstream outFileJordanRating("documents/jordanVotes.txt");

        if (outFileJordanRating) {
            outFileJordanRating << nateFromJordan << " " << landonFromJordan << endl;
            outFileJordanRating.close();
        }
    }
    else if (userName == "Landon") {

        if (voteInt == 1) {
            if (nate3Rating != 0) {
                nateFromLandon = nate3Rating;
            }
            else {
                nateFromLandon = nateFromLandon;
            }
            if (jordanRating != 0) {
                jordanFromLandon = jordanRating;
            }
            else {
                jordanFromLandon = jordanFromLandon;
            }

            nate3Value = ((nateFromJordan * jordanWeight) + (nateFromLandon * landonWeight)) / (jordanWeight + landonWeight);
            nate3Value = roundf(nate3Value * 100) / 100;
            nate3Print = roundf(nate3Value * 2) / 2;
            cout << "Cycling's rating is now | " << nate3Print << "\n";
        }
        else if (voteInt == 2) {
            if (nate3Rating != 0) {
                nateFromLandon = nate3Rating;
            }
            else {
                nateFromLandon = nateFromLandon;
            }
            if (jordanRating != 0) {
                jordanFromLandon = jordanRating;
            }
            else {
                jordanFromLandon = jordanFromLandon;
            }

            jordanValue = ((jordanFromNate * nate3Weight) + (jordanFromLandon * landonWeight)) / (nate3Weight + landonWeight);
            jordanValue = roundf(jordanValue * 100) / 100;
            jordanPrint = roundf(jordanValue * 2) / 2;
            cout << "Boxing's rating is now | " << jordanPrint << "\n";
        }
        voteInt = 0;

        ofstream outFileLandonRating("documents/landonVotes.txt");

        if (outFileLandonRating) {
            outFileLandonRating << nateFromLandon << " " << jordanFromLandon << endl;
            outFileLandonRating.close();
        }
    }
    if (voteInt == 0){
        nate3Value = ((nateFromJordan * jordanWeight) + (nateFromLandon * landonWeight)) / (jordanWeight + landonWeight);
        nate3Value = roundf(nate3Value * 100) / 100;
        nate3Print = roundf(nate3Value * 2) / 2;

        jordanValue = ((jordanFromNate * nate3Weight) + (jordanFromLandon * landonWeight)) / (nate3Weight + landonWeight);
        jordanValue = roundf(jordanValue * 100) / 100;
        jordanPrint = roundf(jordanValue * 2) / 2;

        landonValue = ((landonFromNate * nate3Weight) + (landonFromJordan * jordanWeight)) / (nate3Weight + jordanWeight);
        landonValue = roundf(landonValue * 100) / 100;
        landonPrint = roundf(landonValue * 2) / 2;
    }
}

int main()
{
    if (first) {
        vote();
        first = false;
    }
    nate3Rating = 0;
    jordanRating = 0;
    landonRating = 0;
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
                    break;
                }
                else {
                    cout << "Incorrect password. Please try again." << endl;
                }
            }
        }
        if (!userFound) {
            cout << "User not found. Please sign up." << endl;
            // Add code to create a new user account
        }
    }
    
    nate3Print = roundf(nate3Value * 2) / 2;
    jordanPrint = roundf(jordanValue * 2) / 2;
    landonPrint = roundf(landonValue * 2) / 2;
    cout << "Welcome to MeowMeowBeenz " << userName << "!\nRate the following Sports on which one is the best!\nCycling | " << nate3Print << "\nBoxing | " << jordanPrint << "\nHockey | " << landonPrint << endl;
    while (on)
    {

        nate3Weight = roundf(nate3Print - .49);
        jordanWeight = roundf(jordanPrint - .49);
        landonWeight = roundf(landonPrint - .49);

        cout << "Who would you like to vote for (Cycling, Boxing, or Hockey)? or you can (Sign-Out or Quit). ";
        cin >> name;
        if (name == "Cycling" && userName != "Nate") {
            cout << "What is your rating (out of 5) for Cycling? ";
            while (!(cin >> nate3Rating) || nate3Rating < 1 || nate3Rating > 5) { 
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }

            voteInt = 1;
            vote();

        }
        else if (name == "Boxing" && userName != "Jordan") {
            cout << "What is your rating (out of 5) for Boxing? ";
            while (!(cin >> jordanRating) || jordanRating < 1 || jordanRating > 5) {
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }

            voteInt = 2;
            vote();
        }
        else if (name == "Hockey" && userName != "Landon") {
            cout << "What is your rating (out of 5) for Hockey? ";
            while (!(cin >> landonRating) || landonRating < 1 || landonRating > 5) {
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }

            voteInt = 3;
            vote();
        }
        else if (name == "Quit") {
            cout << "Exiting MeowMeowBeenz!" << endl;
            voteInt = 0;
            vote();
            on = false;
        }
        else if (name == "Sign-Out") {
            cout << "loging out \n";
            voteInt = 0;
            vote();
            userName = "";
            password = "";
            on = false;
            signedIn = false;
            nate3Rating = 0;
            landonRating = 0;
            jordanRating = 0;

        }
        
        else {
            cout << "Invalid input, you cannot vote for yourself, or if you made a typo please refer you your possible options: \n Cycling, Boxing, Hockey, Sign-Out or Quit." << endl;
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