#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

const int MAX_FILES = 100;
const int MAX_DIRECTORIES = 100;
const int MAX_NAME_LENGTH = 100;


struct FileManager {
    char files[MAX_FILES][MAX_NAME_LENGTH];
    int fileCount;
    
    char directories[MAX_DIRECTORIES][MAX_NAME_LENGTH];
    int dirCount;
    
    char currentDirectory[MAX_NAME_LENGTH];

    
    FileManager() {
        
        strcpy(files[0], "file1.txt");
        strcpy(files[1], "file2.cpp");
        strcpy(files[2], "report.doc");
        strcpy(files[3], "image.jpg");
        fileCount = 4;
        
      
        strcpy(directories[0], "Documents");
        strcpy(directories[1], "Projects");
        strcpy(directories[2], "NewFolder");
        dirCount = 3;
        
        strcpy(currentDirectory, "C:\\Users\\UserName\\Documents");
    }

    void displayFiles() {
        int listChoice;
        cout << "\nLIST FILE DETAIL\n";
        cout << "1. List All Files\n";
        cout << "Enter the Number: ";
        cin >> listChoice;

        if (listChoice == 1) {
            cout << "\nList of All (*.*) Files:\n";
            for (int i = 0; i < fileCount; i++) {
                cout << files[i] << endl;
            }
            cout << "Total Files: " << fileCount << endl;
        } else {
            cout << "This option is not implemented in this sample.\n";
        }
    }
    
    void createDirectory() {
        char dirName[MAX_NAME_LENGTH];
        cout << "\nEnter the Directory name: ";
        cin >> dirName;

        if (dirCount < MAX_DIRECTORIES) {
            strcpy(directories[dirCount], dirName);
            dirCount++;
            cout << "Current directory: " << currentDirectory << endl;
            cout << dirName << " Directory Successfully Created (simulated)\n";
        } else {
            cout << "Directory limit reached. Cannot create new directory.\n";
        }
    }
    
    void changeDirectory() {
        int changeChoice;
        cout << "\nCurrent Directory: " << currentDirectory << endl;
        cout << "Change Directory\n";
        cout << "1. Step by Step Backward\n";
        cout << "2. Goto Root Directory\n";
        cout << "3. Forward Directory\n";
        cout << "Enter the Number: ";
        cin >> changeChoice;

        if (changeChoice == 1) {
            
            char* lastBackslash = strrchr(currentDirectory, '\\');
            if (lastBackslash != NULL && lastBackslash != currentDirectory) {
                *lastBackslash = '\0';
                cout << "Current Directory: " << currentDirectory << endl;
            } else {
                cout << "Already at the root directory.\n";
            }
        } else if (changeChoice == 2) {
            strcpy(currentDirectory, "C:\\");
            cout << "Current Directory: " << currentDirectory << endl;
        } else if (changeChoice == 3) {
            char dirName[MAX_NAME_LENGTH];
            cout << "Please enter the Directory Name: ";
            cin >> dirName;
            strcat(currentDirectory, "\\");
            strcat(currentDirectory, dirName);
            cout << "Current Directory: " << currentDirectory << endl;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
};

int main() {
    FileManager fileManager; 
    int choice;

    while (true) {
        
        cout << "\nMAIN MENU\n";
        cout << "1. To Display List of Files\n";
        cout << "2. To Create New Directory\n";
        cout << "3. To Change the Working Directory\n";
        cout << "4. Exit\n";
        cout << "Enter the Number: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fileManager.displayFiles();
                break;
            case 2:
                fileManager.createDirectory();
                break;
            case 3:
                fileManager.changeDirectory();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        cout << "\nPress any key to continue...";
        getch();  
    }
    return 0;
}


