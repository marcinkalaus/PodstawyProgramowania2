#include <iostream>
#include <cstring>

class String {

    char* data;
    size_t stringSize;
public:

    String() : data (new char[0]), stringSize(0) {}

    String(const char* txt) {
        if (txt == nullptr) throw std::invalid_argument("No text!");
        stringSize = strlen(txt);
        data = new char[stringSize + 1];
        std::copy(txt, txt + stringSize + 1, data);
    }

    String(const String &source){
        stringSize = source.stringSize;
        data = new char[stringSize];
        std::copy(source.data, source.data + stringSize, data);
    }

    ~String(){ delete [] data; }

    String & operator=(const char* newText){
        if (newText == nullptr) throw std::invalid_argument("No text!");
        stringSize = strlen(newText);
        data = new char[stringSize + 1];
        std::copy(newText, newText + stringSize + 1, data);
        //strcpy(data, newText);
        return *this;
    }

    size_t size() const{ return stringSize; }

    char* text() const{ return data; }

    String & operator=(const String& newText) {
        if(&newText!=this){
            delete[] data;

            if (newText.data == nullptr) throw std::invalid_argument("No text!");
            stringSize = newText.stringSize;
            data = new char[stringSize + 1];
            std::copy(newText.data, newText.data + stringSize + 1, data);
        }
        return *this;
    }

    String & operator+=(const char* text2Append){
        if (text2Append == nullptr) throw std::invalid_argument("No text!");

        char *buffer = new char[stringSize];
        strcpy(buffer, data);
        delete[] data;

        data = new char[strlen(data) + strlen(text2Append) + 1];
        strcpy(data, buffer);
        strcat(data, text2Append);
        delete[] buffer;
        return *this;
    }

    String operator+(const char* text2Append){
        if (text2Append == nullptr) throw std::invalid_argument("No text!");
        String ret(*this);
        ret += text2Append;
        return ret;
    }

    friend std::ostream& operator<<(std::ostream &stm, const String &str){
        stm << str.text() << std::endl;
        return stm;
    }

    friend std::istream& operator>>(std::istream& is, String& str){
        char* buffer = new char[1000];
        is >> buffer;
        str = buffer;
        delete[] buffer;
        return is;
    }
};

int main() {
    // a) konstruktor bezargumentowy
    String tekst1();

    // b) konstruktor z const char*
    String tekst2("Tekst do konstruktora const char*");
    std::cout << tekst2;

    // d) konstruktor kopiujący
    String tekst3(tekst2);
    std::cout << tekst3;

    // f) operator=(const char*)
    String tekst4;
    tekst4 = "Tekst do operatora = const char*";
    std::cout << tekst4;

    // g) size() i text()
    String tekst5("size() i text()");
    std::cout << tekst5.size() << " " << tekst5.text() << std::endl;

    // h) operator=(const& newText)
    String tekst6("const& newText");
    tekst5 = tekst6;
    std::cout << tekst5;

    // i) operator +=
    tekst5 += "tekst";
    std::cout << tekst5;

    // j) operator +
    std::cout << tekst5 + "tekst";

    // k) >>
    //std::cin >> tekst5;
    //std::cout << tekst5;
    return 0;
}
