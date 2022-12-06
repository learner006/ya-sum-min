/*******************************
00-62-ya-sum-min-source-code.cpp
*******************************/

#include <iostream>
#include <string>
#include <vector>
#include <exception>
//---------------------------------------------------------------------------
using std::vector;
using std::string;

typedef vector<int> TMyVector;

const char* E_AT_LEAST_TWO_ITEMS = "Array must contain at least two items!";

//---------------------------------------------------------------------------
void debug_saveVectorToOutputStream(const TMyVector& p_vec, std::ostream& p_ostream, bool fAddNewLine = false);
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
   const int arrayToDiscoverInput[] = {10,2,-5,4,8,-4,12,36,26};
   TMyVector arrayToDiscover(arrayToDiscoverInput,arrayToDiscoverInput + 9);

   TMyVector& v = arrayToDiscover;
   if (v.size() < 2)
      throw new std::runtime_error(E_AT_LEAST_TWO_ITEMS);

   std::cout << "Input array: ";

   const bool fAddNewLine = true;
   debug_saveVectorToOutputStream(v,std::cout,fAddNewLine);

   int twoSmallestIntegersArray[] = {std::min(v[0],v[1]),std::max(v[0],v[1])};

   for(unsigned n = 2; n < v.size(); ++n)
   {
      if (v[n] < twoSmallestIntegersArray[0])
         twoSmallestIntegersArray[0] = v[n];
      else if (v[n] < twoSmallestIntegersArray[1])
         twoSmallestIntegersArray[1] = v[n];
   }


   const int *p = twoSmallestIntegersArray;
   std::cout << "Two numbers: " << p[0] << "\t" << p[1] << std::endl;
      

   std::cin.get();
}
//---------------------------------------------------------------------------
void debug_saveVectorToOutputStream(const TMyVector& p_vec, std::ostream& p_ostream, bool fAddNewLine)
{
   // Sunset using levers (without foreach & predicates)
   for(unsigned n = 0; n < p_vec.size(); ++n)
      p_ostream << p_vec[n] << " ";

   if (fAddNewLine)
      p_ostream << "\n";
}
//---------------------------------------------------------------------------
