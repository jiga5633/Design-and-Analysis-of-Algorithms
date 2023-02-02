#include <fstream>
#include <iostream>
#include <string>
using namespace std;
/*
@Name :Gangjun Jiang
@Student ID :23795633
@date 1/31/2023
@file name : JiangG_Project02_Main
* */
class JiangG_Project02_Main {
public:
    string data;
    int total, count;
    void processString(ifstream& inFile2, ofstream& outFile2) {
        outFile2 << "In processString method:" << endl;
        total = 0;
        count = 0;
        while (inFile2 >> data) {
            outFile2 << data << " ";
            count++;
            if (count >= 5) {
                outFile2 << endl;
                count = 0;
            }total++;
        }
        outFile2 << "\n the total string count is " << total << endl;
    }
};
int main( int argc, char* argv[]) {
// Open the input text file
    ifstream inFile2;
    ofstream outFile2;
    JiangG_Project02_Main JiangG_Project02_Main;
    inFile2.open(argv[1]);
    outFile2.open(argv[2]);
    JiangG_Project02_Main.processString(inFile2, outFile2);
    inFile2.close();
    outFile2.close();
    return 0;
}