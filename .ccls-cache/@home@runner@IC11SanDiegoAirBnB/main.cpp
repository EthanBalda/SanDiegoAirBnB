#include <iostream>
#include <fstream>
#include <cfloat>
#include <string>
#include <iomanip>
using namespace std;

//Make constants for the file names
const string FILE_NAME = "2023SanDiegoAirBnBListings.txt";
int main() {
  
int totalListings = 0;
double average, min = DBL_MAX, max = DBL_MIN, sum = 0.0, price;
  
//Data type for reading files
ifstream inFile;
//Tries to open the file
  inFile.open(FILE_NAME);
  //Check to see if the file was NOT found
  if (!inFile.is_open()){
    cout << "File: " << FILE_NAME << " cannot be found.\n"; 
      return EXIT_FAILURE;
  }

  while(!inFile.eof()){
    inFile >> price;
    totalListings++;
    sum += price;
    if (price < min)
      min = price;
    if (price > max)
      max = price;
  }
  average = sum / totalListings;
  inFile.close();

   cout <<"*******************************************************\n"
       << "**                                                   **\n"
       << "**                  2023 San Diego                   **\n"
       << "**             AirBnB Listing Statistics             **\n"
       << "**                                                   **\n"
       << "*******************************************************\n"
       << "Total Listings = " << totalListings << endl << fixed << setprecision(0)
       << "Average nightly price = $" << average << endl
       << "Minimum nightly price = $" << min << endl
       << "Maximum nightly price = $" << max << endl
       << "Sum of all prices     = $" << sum << endl;
  
}