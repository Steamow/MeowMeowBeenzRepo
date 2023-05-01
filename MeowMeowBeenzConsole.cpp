// MeowMeowBeenzConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool on = true;
float nate3Rating;
float jordanRating;
float landonRating;
float nate3Value;
float jordanValue;
float landonValue;
string name;

int main()
{
    ifstream inFile("values.txt");
    if (inFile) {
        inFile >> nate3Value >> jordanValue >> landonValue;
        inFile.close();
    }
    cout << "Welcome to MeowMeowBeenz!\nRate the following people on how you feel about them!\nNate 3 | " << nate3Value << "\nJordan | " << jordanValue << "\nLandon | " << landonValue << endl;

    while (on)
    {
        cout << "Who would you like to vote for (Nate3, Jordan, or Landon)? ";
        cin >> name;
        if (name == "Nate3") {
            // Update Nate3's rating
            cout << "What is your rating (out of 5) for Nate3? ";
            while (!(cin >> nate3Rating) || nate3Rating < 1 || nate3Rating > 5) { // check if input is a number between 1 and 5
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input buffer
            }
            nate3Value = (nate3Value * 4 + nate3Rating) / 5;
            cout << "Nate 3's rating is now | " << nate3Value << "\n";
        }
        else if (name == "Jordan") {
            // Update Jordan's rating
            cout << "What is your rating (out of 5) for Jordan? ";
            while (!(cin >> jordanRating) || jordanRating < 1 || jordanRating > 5) { // check if input is a number between 1 and 5
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input buffer
            }
            jordanValue = (jordanValue * 4 + jordanRating) / 5;
            cout << "Jordan's rating is now | " << jordanValue << "\n";
        }
        else if (name == "Landon") {
            // Update Landon's rating
            cout << "What is your rating (out of 5) for Landon? ";
            while (!(cin >> landonRating) || landonRating < 1 || landonRating > 5) { // check if input is a number between 1 and 5
                cout << "Invalid rating. Please enter a number between 1 and 5: ";
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input buffer
            }
            landonValue = (landonValue * 4 + landonRating) / 5;
            cout << "landon's rating is now | " << landonValue << "\n";
        }
        else if (name == "quit") {
            // Exit the program if the user types "quit"
            cout << "Exiting MeowMeowBeenz!" << endl;
            on = false;
        }
        else if (name == "Sate3") {
            // Update Nate3's rating
            cout << "What is your rating (out of 5) for Nate3? ";
            cin >> nate3Value;
            cout << "Nate 3's rating is now | " << nate3Value << "\n";
        }
        else if (name == "Sordan") {
            // Update Jordan's rating
            cout << "What is your rating (out of 5) for Jordan? ";
            cin >> jordanValue;
            cout << "Jordan's rating is now | " << jordanValue << "\n";
        }
        else if (name == "Sandon") {
            // Update Landon's rating
            cout << "What is your rating (out of 5) for Landon? ";
            cin >> landonValue;
            cout << "landon's rating is now | " << landonValue << "\n";
        }
        
        else {
            // Invalid input
            cout << "Invalid input. Please enter Nate3, Jordan, Landon, or quit." << endl;
        }

        ofstream outFile("values.txt");
        if (outFile) {
            outFile << nate3Value << " " << jordanValue << " " << landonValue << endl;
            outFile.close();
        }
    }

    return 0;
}
