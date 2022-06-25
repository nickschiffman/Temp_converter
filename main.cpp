#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string strings[2]; // Temp Array to hold both the City and the temp


// Get the length of each string
int len(string strTemp){
    int strLength = 0;
    for (int i = 0; strTemp[i] != '\0'; i++){
        strLength++;
    }
    return strLength;
}

// Splits the string based on our selected character
void split (string strInput, char seperator){
    int currentIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(strInput)){
        if (strInput[i] == seperator || i == len(strInput)){
            endIndex = i;
            string subStr = "";
            subStr.append(strInput, startIndex, endIndex - startIndex);
            strings[currentIndex] = subStr;
            currentIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int main() {


    // Open both files (read and write)
    ifstream fFile ("FahrenheitTemperature.txt");
    ofstream cFile;
    cFile.open ("CelsiusTemperature.txt"); // This will write over any previous data
    string line; // Each temp input
    int conversion; // Holds the temp conversion from F to C per each line^


    // Check for the file
    if (fFile.is_open()){
        while ( getline (fFile,line) ){

            split(line, ' ');

            // Convert temps
            conversion = (stoi(strings[1]) - 32) / 1.8; // Not using double to easily keep whole Numbers

            // Outputting to the file
            cFile << strings[0] << " " << conversion << endl;
        }
        fFile.close();
    }

    // If the file cannot be open display the USER with an ERROR
    else cout << "Unable to open the requested file";

    cFile.close(); // Closing C temp file

    return 0;
}
