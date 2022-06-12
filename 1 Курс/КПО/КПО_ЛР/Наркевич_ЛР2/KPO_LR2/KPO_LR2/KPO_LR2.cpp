#include <iostream>
#include <string>

using namespace std;

class Book {

protected:
    string _isbnNumber;
    int _numberOfPages;

public:
    Book() {
        _isbnNumber = "325-35fwe5-23-543";
        _numberOfPages = 100;
    }
    Book(string isbnNumber, int numberOfPages) {
        _isbnNumber = isbnNumber;
        _numberOfPages = numberOfPages;
    }

    virtual double GetPrice() = 0;
    
    virtual void GetInfo() = 0;
    
    virtual ~Book() {
        cout << "Cработал виртуальный деструктор класса Book" << endl;
    }
};

class Treatise : public Book {
protected:
    string _theme;

public:
    Treatise() {
        _theme = "someTheme";
    }

    Treatise(string isbnNumber, int numberOfPages, string theme) : _theme(theme) {
        _isbnNumber = isbnNumber;
        _numberOfPages = numberOfPages;
    }

    double GetPrice() {
        return _numberOfPages * 0.2;
    }

    void GetInfo() {
        cout << "Научный труд с номером " << _isbnNumber << " и количеством страниц " << _numberOfPages << " рассматривающий тему " << _theme << ".Стоимость:" << GetPrice() << endl;
    }

    ~Treatise() {
        cout << "Cработал деструктор класса Treatise" << endl;
    }
};

class LightNovel : public Book {
protected: 
    int _audienceAge;

public:
    LightNovel() {
        _audienceAge = 300;
    }
    
    LightNovel(string isbnNumber, int numberOfPages, int audienceAge) : _audienceAge(audienceAge) {
        _isbnNumber = isbnNumber;
        _numberOfPages = numberOfPages;
    }

    double GetPrice() {
        return (_numberOfPages * 0.2) / 0.8;
    }

    void GetInfo() {
        cout << "Ранобэ с номером " << _isbnNumber << " и количеством страниц " << _numberOfPages << " .Как и другие романы, но написанное для людей лет " << _audienceAge << ".Стоимость:" << GetPrice() << endl;
    }

    ~LightNovel() {
        cout << "Cработал деструктор класса LightNovel" << endl;
    }
};

class Manga : public LightNovel {
protected: 
    int _numberOfImages;

public:
    Manga() {
        _numberOfImages = 1200;
    }

    Manga(string isbnNumber, int numberOfPages, int audienceAge, int numberOfImages) : _numberOfImages(numberOfImages) {
        _isbnNumber = isbnNumber;
        _numberOfPages = numberOfPages;
        _audienceAge = audienceAge;
    }

    double GetPrice() {
        return ((_numberOfPages * 0.2) / 0.8) + _numberOfImages * 0.3;
    }

    void GetInfo() {
        cout << "Манга с номером " << _isbnNumber << " и количеством страниц " << _numberOfPages << ". Для аудитории лет " << _audienceAge 
            << "." << endl << "Считай что ранобэ, но с кучей илюстраций, примерно " << _numberOfImages << ".Стоимость:" << GetPrice() << endl;
    }

    ~Manga() {
        cout << "Cработал деструктор класса Manga" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Book** arr = new Book * [3];
    arr[0] = new Treatise("hdaju-42klf-42dag", 600, "образование вселенной");
    arr[1] = new LightNovel("4gdu-65l4f-21dadg", 200, 16);
    arr[2] = new Manga("fgj9-02fsf-75fgd", 350, 16, 1200);

    arr[0]->GetInfo();
    arr[1]->GetInfo();
    arr[2]->GetInfo();

    delete arr[0];
    delete arr[1];
    delete arr[2];
}