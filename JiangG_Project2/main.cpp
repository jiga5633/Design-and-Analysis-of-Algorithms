//Gangjun
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class listNode {
public:
    int data;
    listNode* next;

    listNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LLQueue {
public:
    listNode* head;
    listNode* tail;

    LLQueue() {
        listNode* dummy = new listNode(-999);
        head = dummy;
        tail = dummy;
    }

    void insertQ(listNode* newNode) {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    listNode* deleteQ() {
        if (this->isEmpty()) {
            return nullptr;
        }
        listNode* result = this->head->next;
        this->head->next = result->next;
        if (this->tail == result) {
            this->tail = this->head;
        }
        result ->next = nullptr ;// 123 delete 2 1 -> 3
        return result;
    }

    bool isEmpty() {
        return (this->head == this->tail);
    }

    void printQueue(int whichTable, int index, ofstream& file) {
        listNode* current = this->head->next;

        file << "Table[" << whichTable << "][" << index << "]: ";
        while (current != nullptr) {
            file << "(" << current->data <<") -> ";
            current = current->next;
        }
        file << "NULL" << endl;
    }
};

class RadixSort {
public:
    const int tableSize = 10;
    LLQueue hashTable[2][10];
    int data;
    int currentTable;
    int previousTable;
    int maxDigits;
    int offSet;
    int digitPosition;
    int currentDigit;

    RadixSort() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < tableSize; j++) {
                hashTable[i][j] = LLQueue();
            }
        }
    }


    void preProcessing(ifstream& inFile, ofstream& deBugFile) {
        deBugFile << "***Performing firstReading***" << endl;
        int negativeNum = 0;
        int positiveNum = 0;
        while (inFile >> data) {
            if (data < negativeNum) {
                negativeNum = data;
            }
            if (data > positiveNum) {
                positiveNum = data;
            }
        }
        if (negativeNum < 0) {
            offSet = abs(negativeNum);
        }
        else {
            offSet = 0;
        }
        positiveNum += offSet;
        maxDigits = getLength(positiveNum);
        deBugFile << "NegativeNum: " << negativeNum << endl;
        deBugFile << "PositiveNum: " << positiveNum << endl;
        deBugFile << "OffSet: " << offSet << endl;
        deBugFile << "MaxDigits: " << maxDigits << endl;
    }

    void RSort(ifstream& inFile, ofstream& outFile1, ofstream& deBugFile) {
        deBugFile << "***Performing RSort***" << endl;
        digitPosition = 0;
        currentTable = 0;

        inFile.clear();
        inFile.seekg(0);
        while (inFile >> data) {
            data += offSet;
            listNode* newNode = new listNode(data);
            int hashIndex = getDigit(data, digitPosition);
            hashTable[currentTable][hashIndex].insertQ(newNode);
        }
        while (digitPosition < maxDigits) {
            digitPosition++;
            previousTable = currentTable;
            currentTable = (currentTable + 1) % 2;
            deBugFile << "Digit Position: " << digitPosition << " "
                      << "Current Table: " << currentTable   << " "
                      << "Previous Table: " << previousTable << endl;
            // Print the entire linked list in the previous table.
            outFile1 << "***Printing hashTable[" << previousTable << "]***" << endl;
            for (int i = 0; i < tableSize; i++) {
                if (!hashTable[previousTable][i].isEmpty()) {
                    hashTable[previousTable][i].printQueue(previousTable, i, outFile1);
                }

            }
            outFile1 << endl;

            // Move nodes from the previous table to the current table.
            int tableIndex = 0;
            while (tableIndex < tableSize &&!hashTable[previousTable][tableIndex].isEmpty() ) {
                while(!hashTable[previousTable][tableIndex].isEmpty()){

                    listNode* newNode = hashTable[previousTable][tableIndex].deleteQ();
                    int hashIndex = getDigit(newNode->data, digitPosition);

                    hashTable[currentTable][hashIndex].insertQ(newNode);

                }
                tableIndex++;
            }
        }

        // Print the sorted data in the current table.
        outFile1 << "***Printing Sorted Data***" << endl;

        printSortedData(currentTable, outFile1);

        // Print the non-empty queues in the hash table.


    }


    int getLength(int data) {
        return to_string(data).length();
    }

    int getDigit(int data, int position) {
        if (position >= getLength(data)) {
            return 0;
        }
        string str = to_string(data);
        int index = str.length() - position - 1;
        char digit = str[index];
        return (digit - '0');
    }
    void printTable(LLQueue* hashTable, int previousTable,ofstream &File){

        for(int j=0;j<10;j++){
            if(hashTable[j].isEmpty()) continue;
            hashTable[j].printQueue(previousTable,j,File);

        }

    }
    void printSortedData(int whichTable, ofstream& outFile1) {
        int count = 0;
        for (int i = 0; i < tableSize; i++) {
            listNode* current = hashTable[whichTable][i].head->next;
            while (current != nullptr) {
                outFile1 << current->data - offSet << "          ";
                count++;
                if (count == 10) {
                    outFile1 << endl;
                    count = 0;
                }
                current = current->next;
            }
        }
        if (count > 0) {
            outFile1 << endl;
        }
    }
};
int main(int argc, char* argv[]) {
    ifstream inFile(argv[1]);
    ofstream outFile1(argv[2]);
    ofstream deBugFile(argv[3]);
    RadixSort rs = RadixSort();
    rs.preProcessing(inFile, deBugFile);
    inFile.close();
    inFile.open(argv [1]);
    rs.RSort(inFile, outFile1, deBugFile);
    inFile.close();
    outFile1.close();
    deBugFile.close();
    return 0;
}