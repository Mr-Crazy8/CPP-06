#include "ScalarConverte.hpp"
#include <iostream>
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& org) {(void)org;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& org)
{
    (void)org;
    return *this;
}

bool ScalarConverter::isPrintableChar(int c)
{
    if (c >= 32 && c <= 126)
        return true;
    return false;
}


bool ScalarConverter::fitsInIntRange(double l)
{
    if ((l == l) && (l != 1.0/0.0 && l != -1.0/0.0))
    {
        if (l >= INT_MIN && l <= INT_MAX)
        {
            if (l == std::floor(l))
                return true;
        }
    }
    return false;
}


bool ScalarConverter::fitsInCharRange(double c)
{
    if (ScalarConverter::fitsInIntRange(c))
    {
        if (c >= CHAR_MIN && c <= CHAR_MAX)
            return true;
    }
    return false;

}




void ScalarConverter::printInt(long l, bool possible)
{
    if (possible == false)
        std::cout << "int: impossible" << std::endl;
    else 
        std::cout << "int: " << l << std::endl;
}

void ScalarConverter::printFloat(float f, bool possible)
{
    if (possible == false)
       std::cout << "float: impossible" << std::endl;
    else if ((f != f))
        std::cout << "float: nanf" << std::endl;
    else if (f == 1.0f/0.0f)
        std::cout << "float: inff" << std::endl;
    else if (f == -1.0f/0.0f)
        std::cout << "float: -inff" << std::endl;
    else 
    {
        //len calcul
        std::ostringstream h;
        h  << std::fixed << std::setprecision(1) << f;
        std::string s = h.str();
        if (s.find('.') == std::string::npos)
            std::cout << "float: "  << s << ".0f" << std::endl;
        else
            std::cout << "float: "  << s << "f" << std::endl;
    }

}


void ScalarConverter::printDouble(double d, bool possible)
{
    if (possible == false)
       std::cout << "double: impossible" << std::endl;
    else if ((d != d))
        std::cout << "double: nan" << std::endl;
    else if (d == 1.0/0.0)
        std::cout << "double: inf" << std::endl;
    else if (d == -1.0/0.0)
        std::cout << "double: -inf" << std::endl;
    else 
    {
        std::ostringstream h;
        h  << std::fixed << std::setprecision(1) << d;
        std::string s = h.str();
        if (s.find('.') == std::string::npos)
            std::cout << "double: "  << s << ".0" << std::endl;
        else
            std::cout << "double: " << s << std::endl;
    }

}


void ScalarConverter::printChar(char c, bool possible, bool printable)
{
    if (possible == false)
        std::cout << "char: impossible" << std::endl;
    else if (possible == true && printable == false)
        std::cout << "char: Non displayable" << std::endl;
    else if (possible == true && printable == true) 
        std::cout << "char: " << "'" << c << "'" << std::endl;
}



void ScalarConverter::convertFromChar(char c)
{
    int v = static_cast<int>(c);
    printChar(c, true, isPrintableChar(c));
    printInt(v, true);
    printFloat(static_cast<float>(v), true);
    printDouble(static_cast<double>(v), true);

}

void ScalarConverter::convertFromInt(long l)
{
    bool inrange = fitsInIntRange(static_cast<double>(l));
    bool char_range = fitsInCharRange(static_cast<double>(l));
    bool printable;
    if (char_range)
        printable = isPrintableChar(static_cast<int>(l));
    else
        printable = false;
    printChar(static_cast<int>(l), char_range , printable);
    printInt(l, inrange);
    printFloat(static_cast<float>(l), true);
    printDouble(static_cast<double>(l), true);

}

void ScalarConverter::convertFromFloat(float f, const std::string &literal)
{
    bool inrange = fitsInIntRange(static_cast<double>(f));
    bool char_range = fitsInCharRange(static_cast<double>(f));
    bool printable;
    if (char_range)
        printable = isPrintableChar(static_cast<int>(f));
    else
        printable = false;
    printChar(static_cast<int>(f), char_range , printable);
    printInt(static_cast<long>(f), inrange);
    printFloat(f, true);
    printDouble(strtod(literal.c_str(), NULL), true);
}


void ScalarConverter::convertFromDouble(double d)
{
    bool inrange = fitsInIntRange(d);
    bool char_range = fitsInCharRange(d);
    bool printable;
    if (char_range)
        printable = isPrintableChar(static_cast<int>(d));
    else
        printable = false;
    printChar(static_cast<int>(d), char_range , printable);
    printInt(static_cast<long>(d), inrange);
    printFloat(static_cast<float>(d), true);
    printDouble(d, true);

}


bool ScalarConverter::isChar(const std::string &literal)
{
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::iswordkey(const std::string &literal)
{
    std::string keys[] = {"nan", "nanf", "inf", "inff", "+inf", "+inff", "-inf", "-inff"};

    int i = 0;
    while (i < 8)
    {  
        if (keys[i] == literal)
            return true;
        i++;
    }
    return false;
}

bool ScalarConverter::isFloat(const std::string & literal)
{
    if (literal.empty())
        return false;

    int lent = literal.length();
    char *end;
    char last;
    if (literal[lent - 1] == 'f' || literal[lent - 1] == 'F')
    {
        last = literal[lent - 1];
        strtof(literal.c_str(), &end);
        if (end != literal.c_str())
        {
            if (((*end == last) && (*(end + 1) == '\0')) || (*end == '\0'))
                return true;

        }
    }
    return false;
}



bool ScalarConverter::isDouble(const std::string & literal)
{
    if (literal.empty() || literal[0] == '.' || literal[literal.length() - 1] == '.')
        return false;

    int lent = literal.length();
    char *end;
    
    strtod(literal.c_str(), &end);
    if (end != literal.c_str())
    {
        if (*end == '\0')
            return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
    if (literal.empty() || literal[0] == '.' || literal[literal.length() - 1] == '.')
        return false;
    char *end;
    errno = 0;
    long v = strtol(literal.c_str(), &end, 10);
    if (end != literal.c_str())
    {
        if ((*end == '\0') && (errno != ERANGE))
            return true;
    }
    return false;
}


void ScalarConverter::convert(const std::string& literal)
{
    char *end;
    if(isChar(literal))
        convertFromChar(literal[0]);
    else if (isInt(literal))
        convertFromInt(strtol(literal.c_str(), &end, 10));
    else if (isFloat(literal))
        convertFromFloat(strtof(literal.c_str(), &end), literal);
    else if (isDouble(literal))
        convertFromDouble(strtod(literal.c_str(), &end));
    else 
        std::cout << "Error: invalid format" << std::endl;
}
