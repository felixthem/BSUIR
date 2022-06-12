#include <iostream>
#include <string>
#include <iterator>

using namespace std;

#include <boost/regex.hpp>

int main() {
    std::string str = "-asd.asd.a0.23.asdfj234d.12334++23.";
    boost::regex rgx("\\-?\\d+(\\.\\d+)");
    std::copy(
        boost::sregex_token_iterator(str.begin(), str.end(), rgx),
        boost::sregex_token_iterator(),
        std::ostream_iterator <std::string>(std::cout, " ")
    );
}