#include <vector>  // STL vector header. There is no ".h"
#include <iostream>  // for cout
using namespace std;  // Ensure that the namespace is set to std

char* szHW = "Hello World";  
// This is - as we all know - a character array, 
// terminated with a null character

int main(int argc, char* argv[])
{
  vector <char> vec;  // A vector (STL array) of characters

  // Define an iterator for a vector of characters - this is always 
  // scoped to within the template
  vector <char>::iterator vi;

  // Initialize the character vector, loop through the string, 
  // placing the data in the vector character by character until 
  // the terminating NULL is reached
  char* cptr = szHW;  // Start a pointer on the Hello World string
  while (*cptr != '\0')
  {  vec.push_back(*cptr);  cptr++;  }
  // push_back places the data on the back of the vector 
  // (otherwise known as the end of the vector)

  // Print each character now stored in the STL array to the console
  for (vi=vec.begin(); vi!=vec.end(); vi++)  
  // This is your standard STL for loop - usually "!=" 
  // is used in stead of "<"
  // because "<" is not defined for some containers. begin() 
  // and end() retrieve iterators 
  // (pointers) to the beginning of the vector and to the end of vector
  {  cout << *vi;  }  // Use the indirection operator 
           // (*) to extract the data from the iterator
  cout << endl;  // No more "\n"
 for (vector<char>::iterator it = vec.begin(); it != vec.end(); it++)
	cout << *it;
  return 0;
}
