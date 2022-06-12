#include <iostream>
#include <string>
#include <complex>

using namespace std;

class BasicSize {
private:
    int width;
    int height;

public:
    BasicSize(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void display() {
        cout << "width: " << this->width << ", height: " << this->height << endl << endl;
    }
};

class BasicArray {
private:
    std::complex< double >  basicArray[2];

public:
    BasicArray(std::complex< double > element1 = 2.0 + 2.0i, std::complex< double > element2 = 2.0 + 2.0i) {
        this->basicArray[0] = element1;
        this->basicArray[1] = element2;
    }

    std::complex< double > getValue() {
        return this->basicArray[0] + this->basicArray[1];
    }

    void setValue(std::complex< double > element1 = 0, std::complex< double > element2 = 0) {
        this->basicArray[0] = element1;
        this->basicArray[1] = element2;
    }

    BasicArray& operator = (const BasicArray& other) {
        cout << "Operator = work" << endl;
        basicArray[0] = other.basicArray[0];
        basicArray[1] = other.basicArray[1];
        return *this;
    }

    std::complex< double > operator [] (int index) {
        cout << "Operator [] work" << endl;
        return this->basicArray[index];
    }

    std::complex< double > operator () (int index) {
        cout << "Operator () work" << endl;
        return this->basicArray[index];
    }

    BasicArray& operator ++ () {
        cout << "Operator ++ pre work" << endl;
        basicArray[0] += 1;
        basicArray[1] += 1;
        return *this;
    }

    BasicArray operator ++ (int) {
        cout << "Operator ++ post work" << endl;
        BasicArray prev = *this;
        ++* this;
        return prev;
    }

    BasicArray operator + (BasicArray other) {
        cout << "Operator + work for same types" << endl;
        return BasicArray(this->basicArray[0] + other.basicArray[0], this->basicArray[1] + other.basicArray[1]);
    }

    bool operator > (BasicArray other) {
        cout << "Operator > work for same types" << endl;
        return this->basicArray[0].real() + this->basicArray[1].real() > other.basicArray[0].real() + other.basicArray[1].real();
    }

    bool operator < (BasicArray other) {
        cout << "Operator < work for same types" << endl;
        return this->basicArray[0].real() + this->basicArray[1].real() < other.basicArray[0].real() + other.basicArray[1].real();
    }

    BasicArray& operator -- ();
    BasicArray operator -- (int);
    friend BasicArray operator - (const BasicArray& number1, std::complex< double > number2);
    friend BasicArray operator - (std::complex< double > number1, const BasicArray& number2);
    friend bool operator > (BasicArray number1, std::complex< double > number2);
    friend bool operator > (std::complex< double > number1, BasicArray number2);
    friend bool operator < (BasicArray number1, std::complex< double > number2);
    friend bool operator < (std::complex< double > number1, BasicArray number2);
    friend ostream& operator<<(ostream& os, const BasicArray& other);

    operator std::complex< double >() const {
        return basicArray[0] + basicArray[1];
    }

    operator string() const {
        return to_string(basicArray[0].real() + basicArray[1].real());
    }

    explicit operator BasicSize() const {
        int width = basicArray[0].real();
        int height = basicArray[1].real();
        return BasicSize(width, height);
    }
};

BasicArray& BasicArray::operator -- () {
    cout << "Operator -- pre work" << endl;
    basicArray[0] -= 1;
    basicArray[1] -= 1;
    return *this;
}

BasicArray BasicArray::operator -- (int) {
    cout << "Operator -- post work" << endl;
    BasicArray prev = *this;
    --* this;
    return prev;
}

BasicArray operator - (const BasicArray& number1, std::complex< double > number2) {
    cout << "Operator - work for different types" << endl;
    return BasicArray(number1.basicArray[0] - number2, number1.basicArray[1] - number2);
}

BasicArray operator - (std::complex< double > number1, const BasicArray& number2) {
    cout << "Operator - work for different types" << endl;
    return BasicArray(number1 - number2.basicArray[0], number1 - number2.basicArray[1]);
}

bool operator > (BasicArray number1, std::complex< double > number2) {
    cout << "Operator > work for different types" << endl;
    return number1.basicArray[0].real() + number1.basicArray[1].real() > number2.real();
}

bool operator > (std::complex< double > number1, BasicArray number2) {
    cout << "Operator > work for different types" << endl;
    return number1.real() > number2.basicArray[0].real() + number2.basicArray[1].real();
}

bool operator < (BasicArray number1, std::complex< double > number2) {
    cout << "Operator < work for different types" << endl;
    return number1.basicArray[0].real() + number1.basicArray[1].real() < number2.real();
}

bool operator < (std::complex< double > number1, BasicArray number2) {
    cout << "Operator < work for different types" << endl;
    return  number1.real() < number2.basicArray[0].real() + number2.basicArray[1].real();
}

ostream& operator << (ostream& os, const BasicArray& other) {
    cout << "Operator << work " << endl;
    return os << other.basicArray[0] << other.basicArray[1];
}

int main() {
    // Default constructor
    cout << "-- Default constructor --" << endl;
    BasicArray number1;
    cout << "number1: " << number1.getValue() << endl << endl;

    // Operator '='
    cout << "-- Operator '=' --" << endl;
    BasicArray number2(7);
    number2 = number1;
    cout << "number2: " << number2.getValue() << endl << endl;

    // Operator '[]'
    cout << "-- Operator '[]' --" << endl;
    cout << "number1[0]: " << number1[0] << endl << endl;

    // Operator '()'
    cout << "-- Operator '()' --" << endl;
    cout << "number2(2): " << number2(2) << endl << endl;

    // Operator '++'
    cout << "-- Operator '++' post --" << endl;
    number2++;
    cout << "number2: " << number2.getValue() << endl << endl;

    cout << "-- Operator '++' pre --" << endl;
    ++number2;
    cout << "number2: " << number2.getValue() << endl << endl;

    // Operator '+'
    cout << "-- Operator '+' --" << endl;
    BasicArray number3 = number1 + number2;
    cout << "number3: " << number3.getValue() << endl << endl;

    // Operator '>'
    cout << "-- Operator '>' --" << endl;
    cout << "number1 > number2: " << (number1 > number2) << endl << endl;

    // Operator '<'
    cout << "-- Operator '<' --" << endl;
    cout << "number1 < number2: " << (number1 < number2) << endl << endl;

    // Operator '--'
    cout << "-- Operator '--' post --" << endl;
    number2--;
    cout << "number2: " << number2.getValue() << endl << endl;

    cout << "-- Operator '--' pre --" << endl;
    --number2;
    cout << "number2: " << number2.getValue() << endl << endl;

    // Operator '-' for different types
    cout << "-- Operator '-' for different types --" << endl;
    BasicArray number4 = number1 - 2;
    cout << "number4: " << number4.getValue() << endl << endl;

    // Operator '>' for different types
    cout << "-- Operator '>' for different types --" << endl;
    cout << "number1 > 2: " << (number1 > 2) << endl;
    cout << "3 > number1: " << (3 > number1) << endl << endl;

    // Operator '<' for different types
    cout << "-- Operator '<' for different types --" << endl;
    cout << "number1 < 2: " << (number1 < 2) << endl;
    cout << "1 < number1: " << (1 < number1) << endl << endl;

    // Operator '<<'
    cout << "-- Operator '<<' --" << endl;
    cout << "number2: " << number2 << endl << endl;

    // (int)
    cout << "-- (int) --" << endl;
    cout << "(int)number1: " << (std::complex< double >)number1 << endl << endl;

    // (string)
    cout << "-- (string) --" << endl;
    cout << "(string)number1: " << (string)number1 << endl << endl;

    // (BasicSize)
    cout << "-- (BasicSize) --" << endl;
    BasicSize basicSize = (BasicSize)number1;
    basicSize.display();

    return 0;
}
