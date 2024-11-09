#include "Utilities.h"

string Utilities::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char Utilities::getCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "Its not a single character, type in again." << endl;
    }
    return character;
}
