#include <iostream>
#include <fstream>
#include <vector>


class NotUnderstandableFile{

private:
    std::fstream file;
    std::string filepath;

public:
    NotUnderstandableFile(){
        this->filepath = "Brak sciezki";
    }
    NotUnderstandableFile(const std::string filepath){
        this->filepath = filepath;
    }
    ~NotUnderstandableFile(){};
    std::string getFilePath()const{ return this->filepath; }
    NotUnderstandableFile &operator=(const NotUnderstandableFile &f);
    NotUnderstandableFile &operator--();
    NotUnderstandableFile &operator-=(const NotUnderstandableFile &f);
    bool operator==(const NotUnderstandableFile &f);
    friend std::ostream &operator<<(std::ostream &stm, const NotUnderstandableFile &f);
    friend std::istream &operator>>(std::istream &, NotUnderstandableFile &f);

    void * operator new(size_t size);
    void operator delete(void *ptr) noexcept;
    void * operator new[](size_t size);
    void operator delete[](void *ptr) noexcept;

    char operator ()(char (*function)(std::string));
};
/*! \class NotUnderstandableFile
 *  \brief operator=
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
NotUnderstandableFile &NotUnderstandableFile::operator=(const NotUnderstandableFile &f) {

    if(this == &f) return *this;
    std::string line;
    this->file.open(filepath, std::ios::out | std::ios::trunc);

    if (this->file.good()) {
        std::cout << "Plik otwarto pomyslnie!";
    } else {
        throw std::fstream::failure("Blad odczytu!");
    }

    std::fstream tmpFile;
    tmpFile.open(f.getFilePath(), std::ios::in | std::ios::out);
    while(std::getline(tmpFile, line)){
        this->file << line << '\n';
    }
    this->file.close();
    tmpFile.close();

    return *this;
}
/*! \class NotUnderstandableFile
 *  \brief operator--
 *  \details This function removes the last line of object member file.
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
NotUnderstandableFile & NotUnderstandableFile::operator--() {
    std::vector<std::string> content;
    this->file.open(filepath, std::ios::in | std::ios::out);
    std::string line;
    while(std::getline(this->file,line)){
        content.push_back(line);
    }
    this->file.close();

    this->file.open(filepath, std::ios::out);
    if(content.size() > 1) {
        for (int i = 0; i < content.size() - 1; ++i) {
            this->file << content[i] << '\n';
        }
    }
    this->file.close();

    return *this;
}

/*! \class NotUnderstandableFile
 *  \brief operator--
 *  \details This function removes word from left operand object file if found in right operand object.
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
NotUnderstandableFile & NotUnderstandableFile::operator-=(const NotUnderstandableFile &f) {

    std::fstream tmpFile;
    std::string word;
    std::string line;
    std::vector<std::string> tmpContent;

    this->file.open(filepath, std::ios::in);
    while(std::getline(this->file, line)){
        tmpContent.push_back(line);
    }
    this->file.close();

    tmpFile.open(f.getFilePath(), std::ios::in);
    while(tmpFile >> word){
        for (int i=0; i < tmpContent.size(); ++i){
            if(tmpContent[i].find(word) != std::string::npos) tmpContent[i].replace(tmpContent[i].find(word), word.length() +1, "");
        }
    }
    tmpFile.close();

    this->file.open(filepath, std::ios::out);
    if(tmpContent.size() > 1) {
        for (int i = 0; i < tmpContent.size(); ++i) {
            this->file << tmpContent[i] << '\n';
        }
    }
    this->file.close();

    return *this;
}
/*! \class NotUnderstandableFile
 *  \brief operator==
 *  \details This function compares lengths of files in objects and returns bool.
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
bool NotUnderstandableFile::operator==(const NotUnderstandableFile &f) {
    std::fstream tmp;
    std::string str1;
    std::string str2;

    this->file.open(filepath, std::ios::in);
    this->file >> str1;
    this->file.close();

    tmp.open(f.getFilePath(), std::ios::in);
    tmp >> str2;
    tmp.close();

    return str1.length() == str2.length();
}
/*! \class NotUnderstandableFile
 *  \brief operator<<
 *  \details This function returns stream with object file content.
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
std::ostream &operator<<(std::ostream &stm, const NotUnderstandableFile &f){
    std::string content;
    std::fstream tmpStream;
    tmpStream.open(f.getFilePath(), std::ios::in);
    while(std::getline(tmpStream, content)){
        stm << content << '\n';
    }
    tmpStream.close();
    return stm;
}

/*! \class NotUnderstandableFile
 *  \brief operator>>
 *  \details This function appends the object file with given stream.
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
std::istream &operator>>(std::istream &stm, NotUnderstandableFile &f){
    std::string content;
    std::fstream tmp;
    tmp.open(f.getFilePath(), std::ios::app);
    stm >> content;
    tmp << content;
    return stm;
}
/*! \class NotUnderstandableFile
 *  \brief operator new
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
void * NotUnderstandableFile::operator new(size_t size) {
    return (::new char[size]);
}
/*! \class NotUnderstandableFile
 *  \brief operator delete
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
void NotUnderstandableFile::operator delete(void *ptr) noexcept {
    if (ptr != nullptr)
        ::delete[] static_cast<char *> (ptr);
}
/*! \class NotUnderstandableFile
 *  \brief operator new[]
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
void * NotUnderstandableFile::operator new[](size_t size) {
    return (new char[size]);
}
/*! \class NotUnderstandableFile
 *  \brief operator delete[]
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
void NotUnderstandableFile::operator delete[](void *ptr) noexcept {
    if (ptr != nullptr)
        ::delete[] static_cast<char *> (ptr);
}
/*! \class NotUnderstandableFile
 *  \brief operator ()
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
char NotUnderstandableFile::operator()(char (*function)(std::string)) {
    return function(filepath);
}
/*! \brief function getDrive
 *  \details This function returns drive where the object file is saved.
 *  \author Marcin Kalaus
 *  \version 1.0
 *  \date    25.04.2021
 */
char getDrive(std::string filepath) {
    return filepath[0];
}

int main() {

    NotUnderstandableFile a("C:\\Users\\Marcin\\Desktop\\Studia\\PP2\\04.20\\tekst1.txt");
    NotUnderstandableFile b("C:\\Users\\Marcin\\Desktop\\Studia\\PP2\\04.20\\tekst2.txt");
    a = b; // przypisanie
    --a; // usun linie w a
    a-=b; // usun slowo w a jesli wystapi w b
    std::cout << a; // wypisz a
    //std::cin >> a; // zapisz do pliku ze strumienia
    char (*ptrFunction)(std::string);
    ptrFunction = getDrive;
    std::cout << "Zapisane na dysku: " << a(ptrFunction);
    printf("Czy ilosc znakow w plikach jest rowna: %d\n", a==b);


    return 0;
}
