/**
Author - Gal Caspi
Date - 2020-7
***/

#include "PhoneticFinder.hpp"

using namespace std;

bool isEquals(char a, char b, const char x, const char y)
{
      return (a == x || a == y) && (b == x || b == y);
}

bool isEquals(char a, char b, const char x, const char y, const char z)
{
      return (a == x || a == y || a == z) && (b == x || b == y || b == z);
}

bool isEquals(char a, char b)
{
      if ('A' <= a && a <= 'Z')
            a = a - 'A' + 'a';
      if ('A' <= b && b <= 'Z')
            b = b - 'A' + 'a';
      return a == b ||
             isEquals(a, b, 'v', 'w') ||
             isEquals(a, b, 'b', 'f', 'p') ||
             isEquals(a, b, 'g', 'j') ||
             isEquals(a, b, 'c', 'k', 'q') ||
             isEquals(a, b, 's', 'z') ||
             isEquals(a, b, 'd', 't') ||
             isEquals(a, b, 'u', 'o') ||
             isEquals(a, b, 'i', 'y');
}

bool isEquals(string s, string t)
{
      if (s.length() != t.length())
            return false;
      for (size_t i = 0; i < s.length(); i++)
      {
            if (!isEquals(s.at(i), t.at(i)))
                  return false;
            return true;
      }
}

string phonetic::find(string s, string word)
{
      if (word == "" || word == " ")
            throw runtime_error("Can't search for an empty word!");

      string tmp = "";
      for (size_t i = 0; i < s.length(); i++)
      {
            if (i == s.length() || s.at(i) == ' ')
            {
                  if (isEquals(tmp, word))
                        return tmp;

                  tmp = "";
            }
            else
                  tmp += s.at(i);
      }
      throw runtime_error("Did not find the word "  + word + " ""in the text ");
}
