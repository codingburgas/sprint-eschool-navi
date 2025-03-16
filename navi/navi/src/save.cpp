#include "pch.h"
#include "save.h"

SaveSystem::SaveSystem()
{

}
void SaveSystem::GetName()
{
    Name = "Niki";
    fileName = Name + ".txt";
}
void SaveSystem::Save()
{
    ofstream outFile("saves/" + fileName);
    if (outFile.is_open()) {
        outFile << Name << endl;
        outFile.close();
        cout << "Game data saved successfully.\n";
    }
    else {
        cout << "Error opening file for saving.\n";


    }
}
void SaveSystem::Load()
{
    string loadedScore;
    ifstream inFile("saves/" + fileName);
    if (inFile.is_open()) {
        getline(inFile, loadedScore);
        inFile.close();
        cout << "Game data loaded successfully.\n";
        cout << "Player Name: " << Name << "\n";
        cout << "Player Score: " << loadedScore << "\n";
    }
    else {
        cout << "Error opening file for loading.\n";
    }
}
bool SaveSystem::fileExists(string& filename) {
    ifstream file(filename);
    return file.is_open();  // Return true if the file is open
}