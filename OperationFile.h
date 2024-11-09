#pragma once
#include <string>
#include <iostream>

using namespace std;

class OperationFile : public File
{

public:
    OperationFile(string fileName) : FILE_NAME(fileName) {
    }
    vector <Operation> loadOperationsFromFile (const int loggedUserId);
    bool  addOperationToFile (const Operation &operation);
};
