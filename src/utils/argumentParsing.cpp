#include <iostream>
#include <iomanip> // setw()
#include <cstring> // strcmp()

#include "argumentParsing.h"
#include "programmerDetails.h"

using namespace std;


namespace ArgumentParsing
{
    void printPossibleOptions()
    {
        cout << "Possible program options:\n";
        for (unsigned i=0; i < argumensCount; ++i)
        {
            cout << setw(12) << arguments[i][0] << "\t\t" << arguments[i][1] << '\n';
        }
    }

    // I know it can be done better with map and pair, but
    const char* getInformationByName(const char* informationName)
    {
        if (0 == strcmp(informationName, "firstname"))
        {
            return StudentsInfo::FIRSTNAME;
        }
        if (0 == strcmp(informationName, "surname"))
        {
            return StudentsInfo::SURNAME;
        }
        if (0 == strcmp(informationName, "mail"))
        {
            return StudentsInfo::MAIL;
        }
        if (0 == strcmp(informationName, "bookId"))
        {
            return StudentsInfo::BOOK_ID;
        }
        if (0 == strcmp(informationName, "song"))
        {
            return StudentsInfo::SUGGESTED_SONG_DURING_CHECKING;
        }

        return nullptr;
    }

    void reactToProgramArgumentsPossibilyExit(int argc, char* argv[])
    {
        bool printedStudentsInformation = false;
        for(int a=1; a<argc; ++a)
        {
            const char* argument = argv[a];
            const char* information2Print = getInformationByName(argument);
            if (information2Print)
            {
                std::cout << information2Print << ":\t" << information2Print << std::endl;
                printedStudentsInformation = true;
            }
            if (0 == strcmp("--help", argument))
            {
                printPossibleOptions();
            }
        }
        if (printedStudentsInformation)
        {
            exit(0);
        }
    }
} // namespace ArgumentParsing
