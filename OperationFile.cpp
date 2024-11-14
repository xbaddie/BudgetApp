#include "OperationFile.h"



vector <Operation> OperationFile::loadOperationsFromFile (const int loggedUserId)
{
    Operation operation;
    vector <Operation> operations;

    if (!xmlFile.Load(getFileName()))
    {
        return operations;
    }

    xmlFile.FindElem("Operations");
    xmlFile.IntoElem();

    while (xmlFile.FindElem("Operation"))
    {
        xmlFile.IntoElem();

        xmlFile.FindElem("ID");
        operation.id = stoi(xmlFile.GetData());

        xmlFile.FindElem("UserID");
        operation.userId = stoi(xmlFile.GetData());

        xmlFile.FindElem("Date");
        operation.date = stoi(xmlFile.GetData());

        xmlFile.FindElem("Item");
        operation.item = xmlFile.GetData();

        xmlFile.FindElem("Amount");
        operation.amount = stod(xmlFile.GetData());

        operations.push_back(operation);
        xmlFile.OutOfElem();
    }

    return operations;
}

bool  OperationFile::addOperationToFile (const Operation &operation)
{
    ifstream infile(getFileName());
    bool fileExists = infile.good();
    infile.close();

    if (fileExists)
    {
        xmlFile.Load(getFileName());
    }
    else
    {
        xmlFile.AddElem("Operations");
    }

    xmlFile.FindElem("Operations");
    xmlFile.IntoElem();

    xmlFile.AddElem("Operation");
    xmlFile.IntoElem();
    xmlFile.AddElem("ID", operation.id);

    xmlFile.AddElem("UserID", operation.userId);
    xmlFile.AddElem("Date", operation.date);
    xmlFile.AddElem("Item", operation.item);
    xmlFile.AddElem("Amount", to_string(operation.amount));
    cout << "Operationfile operation amount: " << operation.amount << endl;
    system("pause");
    xmlFile.OutOfElem();

    if (!xmlFile.Save(getFileName()))
    {
        cout << "Failed to save the operation to the file." << endl;
        return false;
    }


    return true;
}

int OperationFile::getLastId()
{
    int lastId = 0;

    try {
        if (!xmlFile.Load(getFileName())) {
            return lastId;
        }

        xmlFile.FindElem("Operations");
        xmlFile.IntoElem();

        while (xmlFile.FindElem("Operation")) {
            xmlFile.IntoElem();
            xmlFile.FindElem("ID");
            lastId = stoi(xmlFile.GetData());
            xmlFile.OutOfElem();
        }

    } catch (const exception &caughtException) {
        cerr << "Error getting last user ID: " << caughtException.what() << endl;
    }

    return lastId;
}
