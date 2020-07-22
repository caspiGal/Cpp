/*
*/

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of lower-case and upper-case")
{
      string text = "Happi xxx yyy";
      CHECK(find(text, "happi") == string("Happi"));
      CHECK(find(text, "Happi") == string("Happi"));
      CHECK(find(text, "HAPPI") == string("Happi"));
      CHECK(find(text, "HaPpI") == string("Happi"));
      CHECK(find(text, "hAPpi") == string("Happi"));

      string text2 = "xaxa  yyy AaAa";
      CHECK(find(text2, "AaAa") == string("AaAa"));
      CHECK(find(text2, "AAAA") == string("AaAa"));
      CHECK(find(text2, "aaaa") == string("AaAa"));
      CHECK(find(text2, "aAaA") == string("AaAa"));
      CHECK(find(text2, "aaAA") == string("AaAa"));
}

TEST_CASE("Test replacement of v and w")
{
      string text = "xxx VvWw yyy";
      CHECK(find(text, "VvWw") == string("VvWw"));
      CHECK(find(text, "vVvV") == string("VvWw"));
      CHECK(find(text, "wWwW") == string("VvWw"));
      CHECK(find(text, "wwvv") == string("VvWw"));
      CHECK(find(text, "vvww") == string("VvWw"));
      CHECK(find(text, "vWvW") == string("VvWw"));
      CHECK(find(text, "wVwV") == string("VvWw"));
      CHECK(find(text, "vVvw") == string("VvWw"));
      CHECK(find(text, "wWwv") == string("VvWw"));
      CHECK(find(text, "wWvV") == string("VvWw"));
}

TEST_CASE("Test replacement of p,f and b")
{
      string text = "xxx fpb yyy";
      CHECK(find(text, "fpb") == string("fpb"));
      CHECK(find(text, "fff") == string("fpb"));
      CHECK(find(text, "ppp") == string("fpb"));
      CHECK(find(text, "bbb") == string("fpb"));
      CHECK(find(text, "fpp") == string("fpb"));
      CHECK(find(text, "fbb") == string("fpb"));
      CHECK(find(text, "bff") == string("fpb"));
      CHECK(find(text, "bpp") == string("fpb"));
      CHECK(find(text, "pff") == string("fpb"));
      CHECK(find(text, "pbb") == string("fpb"));

      CHECK(find(text, "FbF") == string("fpb"));
      CHECK(find(text, "PfP") == string("fpb"));
      CHECK(find(text, "BpB") == string("fpb"));
      CHECK(find(text, "fPf") == string("fpb"));
      CHECK(find(text, "pBp") == string("fpb"));
}

TEST_CASE("Test replacement of g and j")
{
      string text = "xxx ggjj yyy";
      CHECK(find(text, "ggjj") == string("ggjj"));
      CHECK(find(text, "gjgj") == string("ggjj"));
      CHECK(find(text, "jgjg") == string("ggjj"));
      CHECK(find(text, "jjgg") == string("ggjj"));
      CHECK(find(text, "gggg") == string("ggjj"));
      CHECK(find(text, "jjjj") == string("ggjj"));
      CHECK(find(text, "GgJj") == string("ggjj"));
      CHECK(find(text, "jJgG") == string("ggjj"));
      CHECK(find(text, "JggJ") == string("ggjj"));
      CHECK(find(text, "GjjG") == string("ggjj"));
}

TEST_CASE("Test replacement of c, k and q")
{
      string text = "xxx ckq yyy";
      CHECK(find(text, "ckq") == string("ckq"));
      CHECK(find(text, "ccc") == string("ckq"));
      CHECK(find(text, "kkk") == string("ckq"));
      CHECK(find(text, "qqq") == string("ckq"));
      CHECK(find(text, "cqk") == string("ckq"));
      CHECK(find(text, "kcq") == string("ckq"));
      CHECK(find(text, "kqc") == string("ckq"));
      CHECK(find(text, "qck") == string("ckq"));
      CHECK(find(text, "qkc") == string("ckq"));
      CHECK(find(text, "qcq") == string("ckq"));

      CHECK(find(text, "CKQ") == string("ckq"));
      CHECK(find(text, "CCC") == string("ckq"));
      CHECK(find(text, "KKK") == string("ckq"));
      CHECK(find(text, "QQQ") == string("ckq"));
      CHECK(find(text, "QKC") == string("ckq"));
}

TEST_CASE("Test replacement of s and z")
{
      string text = "xxx szsz yyy";
      CHECK(find(text, "szsz") == string("szsz"));
      CHECK(find(text, "ssss") == string("szsz"));
      CHECK(find(text, "zzzz") == string("szsz"));
      CHECK(find(text, "sszz") == string("szsz"));
      CHECK(find(text, "zzss") == string("szsz"));
      CHECK(find(text, "zszs") == string("szsz"));
      CHECK(find(text, "SzzS") == string("szsz"));
      CHECK(find(text, "ZssZ") == string("szsz"));
      CHECK(find(text, "ZZZs") == string("szsz"));
      CHECK(find(text, "SSSz") == string("szsz"));
}

TEST_CASE("Test replacement of d and t")
{
      string text = "xxx dtdt yyy";
      CHECK(find(text, "dtdt") == string("dtdt"));
      CHECK(find(text, "dddd") == string("dtdt"));
      CHECK(find(text, "tttt") == string("dtdt"));
      CHECK(find(text, "ddtt") == string("dtdt"));
      CHECK(find(text, "ttdd") == string("dtdt"));
      CHECK(find(text, "tdtd") == string("dtdt"));
      CHECK(find(text, "TddT") == string("dtdt"));
      CHECK(find(text, "DttD") == string("dtdt"));
      CHECK(find(text, "DDDt") == string("dtdt"));
      CHECK(find(text, "TTTd") == string("dtdt"));
}

TEST_CASE("Test replacement of o and u")
{
      string text = "xxx ouou yyy";
      CHECK(find(text, "ouou") == string("ouou"));
      CHECK(find(text, "oooo") == string("ouou"));
      CHECK(find(text, "uuuu") == string("ouou"));
      CHECK(find(text, "oouu") == string("ouou"));
      CHECK(find(text, "uuoo") == string("ouou"));
      CHECK(find(text, "uouo") == string("ouou"));
      CHECK(find(text, "UooU") == string("ouou"));
      CHECK(find(text, "OuuO") == string("ouou"));
      CHECK(find(text, "OOOu") == string("ouou"));
      CHECK(find(text, "UUUo") == string("ouou"));
}

TEST_CASE("Test replacement of i and y")
{
      string text = "xxx iyiy yyy";
      CHECK(find(text, "iyiy") == string("iyiy"));
      CHECK(find(text, "iiii") == string("iyiy"));
      CHECK(find(text, "yyyy") == string("iyiy"));
      CHECK(find(text, "iiyy") == string("iyiy"));
      CHECK(find(text, "yyii") == string("iyiy"));
      CHECK(find(text, "yiyi") == string("iyiy"));
      CHECK(find(text, "YiiY") == string("iyiy"));
      CHECK(find(text, "IyyI") == string("iyiy"));
      CHECK(find(text, "YYYi") == string("iyiy"));
      CHECK(find(text, "IIIy") == string("iyiy"));
}

TEST_CASE("Test excetion throwing")
{
      string text = "abcd efgh ijk lmnop qrs tu vw xyz";
      bool thrown;
      try
      {
            find(text, "abc");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "ebcd");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "efhg");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "ygz");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "lmnoq");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "rqss");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "tb");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "va");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);

      try
      {
            find(text, "xye");
            thrown = false;
      }
      catch (exception &ex)
      {
            thrown = true;
      }
      CHECK(thrown);
}
