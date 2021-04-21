#include <iostream>
#include <fstream>
#include <vector>


class NotUnderstandableFile{

private:
    std::fstream file;
    std::string filepath;

public:

    NotUnderstandableFile(const std::string filepath){
        this->filepath = filepath;
    }

    std::string getFilePath()const{ return this->filepath; }
    NotUnderstandableFile &operator=(const NotUnderstandableFile &f);
    NotUnderstandableFile &operator--();
    NotUnderstandableFile &operator-=(const NotUnderstandableFile &f);
    NotUnderstandableFile &operator==(const NotUnderstandableFile &f);
    friend std::ostream &operator<<(std::ostream &stm, const NotUnderstandableFile &f);
    friend std::istream &operator>>(std::istream &stm, const NotUnderstandableFile &f);
};

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

std::ostream &operator <<(std::ostream &stm, const NotUnderstandableFile &f){
    std::string content;
    std::fstream tmpStream;
    tmpStream.open(f.getFilePath(), std::ios::in);
    while(std::getline(tmpStream, content)){
        stm << content << '\n';
    }
    tmpStream.close();
    return stm;
}

std::istream &operator >>(std::istream &stm, NotUnderstandableFile &f){
    std::string content;
    std::fstream tmp;
    tmp.open(f.getFilePath(), std::ios::app);
    stm >> content;
    tmp << content;
    return stm;
}

int main() {

    NotUnderstandableFile a("C:\\Users\\Marcin\\Desktop\\Studia\\PP2\\04.20\\tekst1.txt");
    NotUnderstandableFile b("C:\\Users\\Marcin\\Desktop\\Studia\\PP2\\04.20\\tekst2.txt");
    a = b;
    --a;
    a-=b;
    std::cout << a;
    std::cin >> a;

    return 0;
}
