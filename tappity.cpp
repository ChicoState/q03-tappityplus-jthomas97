#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
 : reference(reference), input("")
{

}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  this->input = input;

}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{

  //case when exact same length
  if(reference.length() == input.length())
  {
    return 0;
  }
  //Not same length, do advanced checking
  else 
  {
    int diff = reference.length() - input.length();
    //Convert to absolute val
    if(diff < 0)
    {
      return diff * -1;
    }
    //otherwise already positive
    else{
      return diff;
    }
  }

  return -1;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  int numDiff = 0;

  //This block is when exact same length of both strings
  if(reference.length() == input.length())
  {
    if(reference.length() == 0)
    {
      return 100.0;
    }
     
    numDiff = reference.length();
    for(int i=0; i<reference.length();i++)
    {
      if(reference[i] != input[i])
      {
        numDiff--;
      }
    }
    return (numDiff/reference.length()) * 100.0;
  }


  //This block when reference not equal input
  else 
  {
      int lenReference = reference.length();
      int lenInput = input.length();
      double numRight = 0.0;

      if(lenInput > lenReference)
      {
        numRight = lenInput-lenReference;
        for(int i=0; i<reference.length(); i++)
        {
          if(reference[i] != input[i])
          {
            numRight--;
          }
        }
        // std::cout << "WE IN input longer than ref\n";
        return (numRight/input.length()) * 100.0;
      }else {

        //check when input not changed
        if(input.length() == 0)
        {
          return 0.0;
        }
        numRight = lenReference-lenInput;
        for(int i=0; i<input.length(); i++)
        {
          if(reference[i] != input[i])
          {
            numRight--;
          }
        }
  
        // std::cout << "WE IN ref longer than input\n";
        double accuracy = (numRight/reference.length()) * 100.0;
        return accuracy;
      }
  }


  return -1.0;
}
