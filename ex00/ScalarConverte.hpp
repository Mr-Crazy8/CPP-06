#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cerrno>


class ScalarConverter
{

    private:
        ScalarConverter();  //done
        ~ScalarConverter(); //done
        ScalarConverter(const ScalarConverter& org);  //done
        ScalarConverter& operator=(const ScalarConverter& org); //done
        static bool isChar(const std::string &literal); //done
        static bool isInt(const std::string &literal); //done
        static bool isFloat(const std::string &literal); //done
        static bool isDouble(const std::string &literal); //done
        static bool iswordkey(const std::string &literal); //done = should remvoe
        static void convertFromChar(char c); //done
        static void convertFromInt(long l); //done
        static void convertFromFloat(float f, const std::string &literal); //done
        static void convertFromDouble(double d); //done

        static bool isPrintableChar(int c); //done
        static bool fitsInIntRange(double l); //done
        static bool fitsInCharRange(double c); //done

        static void printChar(char c, bool possible, bool printable); //done
        static void printInt(long l, bool possible);  //done
        static void printFloat(float f, bool possible); //done
        static void printDouble(double d, bool possible); //done
    public:
        static void convert(const std::string& literal);

};



#endif