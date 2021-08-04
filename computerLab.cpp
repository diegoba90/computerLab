/*
Diego Acuna
03/07/20
*/

/*
This program will display a computer lab with all the status of the computers.
Then it will display a 5 option menu that will ask user if they want to log into the computer.
It will then display the new status of the computers. Program will contain several functions.
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

//function prototypes
int userMenu(); //this will contain menu and will return choice
void wholeProgram(); //this will be the core of the program
void printLab(); //prints out the lab initially to show "free status"
void signature();//programmer signature


int main() {
    //display current status of labs
    printLab();
    //call program with the menu
    wholeProgram();
    //call signature function

    system("pause");
    return 0;
}

void printLab() {
    //declare variables
    const int numberLabs = 4; //number of labs
    int compInLabs[] = { 10,6,3,12 }; //each lab contains # of computers
    string* labs[4]; //string of pointers

    //load array
    //use a for loop to load labs
    for (int i = 0; i < numberLabs; i++) {
        labs[i] = new string[compInLabs[i]]; // string of pointers, pointing to comp in lab in heap
        //assign free to computers using for loop
        for (int j = 0; j < compInLabs[i]; j++) {
            labs[i][j] = "free";
        }
    }

    cout << "Current status of computer labs: \n\n";
    //use for loop to display the labs
    for (int i = 0; i < numberLabs; i++) {
        cout << "Lab #" << (i + 1) << ": \n";
        //use for loop to display pc status
        for (int j = 0; j < compInLabs[i]; j++) {
            cout << "\tComputer " << (j + 1) << ": " << labs[i][j] << endl;
        }
        cout << endl;
    }
}

//menu function
int userMenu() {
    //declare variable
    int choice;

    
        //Display menu choices
        cout << "Please choose from one of the following options:\n"
            << "1. Print current status of computers in all labs\n"
            << "2. Log in a new student to a computer inside a lab\n"
            << "3. Log out a student from his/her computer inside a lab\n"
            << "4. Add new computers to an existing computer lab\n"
            << "5. Exit Program\n\n";

        cout << "Enter menu option: ";
        cin >> choice;

            //ensure user enters only 1-5
            while (choice < 1 || choice>5) {
                cout << "Invalid option. Please enter a choice between 1-5: ";
                cin >> choice;
            }
    

    return choice;
}

void wholeProgram() {

    //declare variables
    int labNum, compNum, choice;
    const int numberLabs = 4;
    int compInLabs[] = { 10,6,3,12 }; //each lab contains # of computers
    string* labs[4]; //string of pointers
    string firstName;

    //load array
    //use a for loop to load labs
    for (int i = 0; i < numberLabs; i++) {
        labs[i] = new string[compInLabs[i]]; // string of pointers, pointing to comp in lab in heap
        //assign free to computers using for loop
        for (int j = 0; j < compInLabs[i]; j++) {
            labs[i][j] = "free";
        }
    }

    //use a do/while loop to repeat program until user exits
    do {
        choice = userMenu(); //this will assign menu choice from menu func
        //since it's a menu interface use a swich and case statement
        switch (choice) {
            //Menu option 1: Print current and updated labs status
        case 1:
            
            cout << "Current status of computer labs: \n\n";
            //use for loop to display the labs
            for (int i = 0; i < numberLabs; i++) {
                cout << "Lab #" << (i + 1) << ": \n";
                //use for loop to display pc status
                for (int j = 0; j < compInLabs[i]; j++) {
                    cout << "\tComputer " << (j + 1) << ": " << labs[i][j] << endl;
                }
                cout << endl;
            }
            break;
            
            //menu option 2: log in student
        case 2:
            
            cout << "Please enter your first name: ";//request user input
            cin >> firstName;
            cout << "Enter your lab number: ";//request user input
            cin >> labNum;

            //ensure user enters value 1-4
            while (labNum < 1 || labNum > 4) {
                cout << "Enter lab number 1-4: ";
                cin >> labNum;
            }
            cout << "Enter computer number (1-" << compInLabs[labNum - 1] << "): "; //request user input
            cin >> compNum;
            cout << endl;
                
            //ensure user enters value that matches number of computers in lab
            while (compNum<1 || compNum > compInLabs[labNum - 1]) {
                cout << "Invalid computer number. Please enter computer between (1-" << compInLabs[labNum - 1] << "): ";
                cin >> compNum;
            }
            //check to see if computer is empty. If empty log in student, else display error
            if (labs[labNum - 1][compNum - 1]==("free")) {
                //replace "free" with firstName
                labs[labNum - 1][compNum - 1] = firstName;
                cout << firstName << " is now logged into computer #" << compNum << " in lab #" << labNum << "." << endl;
                cout << endl;
            }
            else {
                cout << "Computer #" << compNum << " in lab #" << labNum << " is not free";
                cout << endl;
            }
            break;
            
            //menu option 3: Logout Student
        case 3:
            cout << "Enter lab number: ";//request user input
            cin >> labNum;
            
            //ensure user enters value 1-4
            while (labNum < 1 || labNum > 4) {
                cout << "Enter lab number 1-4: ";
                cin >> labNum;
            }
            cout << "Enter computer number (1-" << compInLabs[labNum - 1] << "): ";//request user input
            cin >> compNum;
            cout << endl;
            //ensure user enters value that matches number of computers in lab
            while (compNum<1 || compNum>compInLabs[labNum - 1]) {
                cout << "Invalid computer number. Please enter computer between (1-" << compInLabs[labNum - 1] << "): ";
                cin >> compNum;
            }
            //if lab is not "free" log out student. else computer is already free
            if (labs[labNum - 1][compNum - 1] != ("free")) {
                firstName = labs[labNum - 1][compNum - 1];
                labs[labNum - 1][compNum - 1] = "free";
            }
            else {
                cout << "Computer #" << compNum << " in lab #" << labNum << " is already free";
                cout << endl;
            }
                cout << firstName << " is now logged out of the computer." <<endl;
                cout << endl;
            break;

            //menu option 4: add computers to labs
            case 4: {

            cout << "Which lab will you like to add computers to? ";//request user input
            cin >> labNum;
            //ensure user enters value 1-4
            while (labNum < 1 || labNum > 4) {
                cout << "Enter lab number 1-4: ";
                cin >> labNum;
            }
            
            //declare new variable for number of new computers
            int numNewComp;
                
            cout << "How many computers would you like to add? "; //request user input
            cin >> numNewComp;
            
            //declare new variable pointer in the heap and ADD new new computers number
            string* newLabs = new string[compInLabs[labNum - 1] + numNewComp];

            //use a for loop to load new values to the lab array
            for (int i = 0; i < compInLabs[labNum - 1]; i++)
                newLabs[i] = labs[labNum - 1][i];
            
            //add new computers
            compInLabs[labNum - 1] += numNewComp;
            //make sure new labs are free
            for (int i = 0; i < compInLabs[labNum - 1]; i++){
                newLabs[i] = "free";
            }
                cout << endl;
                cout << "You have now added " << numNewComp << " computers in lab #" << labNum << endl;
                cout << endl;
           
            //assign new lab values
            labs[labNum - 1] = newLabs;
            
            break;
            }

            //menu option 5: display signature and exit
        case 5:
                signature();
            break;

        }
    }while (choice != 5);
    
}

void signature(){
    
    //create programmer signature
    cout << "Thanks for using my program. Have a nice day" << endl;
    cout << endl;
    
    vector<string> signature;
    signature.push_back("Programmed");
    signature.push_back(" by");
    signature.push_back(" Diego Acuna");
    
    for (string sig: signature){
        cout << sig;
    }
    cout << endl;
}
