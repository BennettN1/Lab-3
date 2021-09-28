/*
 Nick Bennett
 C++ Fall 2021 / Sept 29,2021
 Lab 3
 This lab is using the fstream, inFile, outFile to pull and put inforamtion into a file that has a calculation to give the popular standard deviation and the mean of the integers/values. Once the code is done calcuating the PSD and mean, the result will be put into another file that is outputted into the Lab 3 file and also have the PSD and mean outputted to the screen to show that the code did run and correctly got the answer with the integers that were given.
 */

#include <iostream>
#include <fstream> // needed to input and output files
#include <string>
#include <cmath> // using for the "pow" and "sqrt"
using namespace std;

float meanc(float, float, float, float); //the mean function has 4 float values
float psd(float, float, float, float); //the psd function has 4 float values , psd stands for population standard deviation

int main()
{
    
    float input1;
    float input2;
    float input3;
    float input4;
    string inputFileName = "/Users/benne/Desktop/C++ - XCode/Lab 3/Lab 3/Lab 3/inMeanStd.dat"; //input file location
    string outputFileName = "outMeanStd.dat";    // output file name
    ifstream inFile;
    ofstream outFile;

    inFile.open(inputFileName);  // opens file that we told the computer to open
    outFile.open(outputFileName); // opens file that will have all of the calculated values in it
    
    //Pulling the 4 integers from the .dat file into the code
    inFile >> input1 >> input2 >> input3 >> input4; // taking the integers from inMeanStd.dat
    cout << "The mean of the 4 integers from the file were: " << meanc(input1, input2, input3, input4) <<endl;
    cout << "The population standard deviation of the 4 integers from the file were: " << psd(input1,input2,input3,input4) << endl << endl << endl; // showing to the screen that the calclations and the values that it calclauted
    outFile << "The mean of the 4 integers from the file were: " << meanc(input1, input2, input3, input4) << endl;
    outFile << "The population standard deviation of the 4 integers from the file were: "<< psd(input1,input2,input3,input4) <<endl; // placed the calculated values into the file
    
    
    //Putting the 4 integars into the code as integers
    cout << "Place 4 integer values. Press enter after each valve has been put in."<< endl; //outputs to the screen
    cin >> input1 >> input2 >> input3 >> input4; // putting in integers and saving them as values/integers
    cout << "The numbers that you have chosen were: " << input1 << ", " << input2 << ", " << input3 << ", and " << input4 << endl; // stating the values/integers that the person put into the computer
    cout << "The mean of the 4 values are: " << meanc(input1, input2, input3, input4) << endl; //outputting to the screen to see if the calculations are correct.
    cout << "The popular standard deviation of the 4 values is: " << psd(input1, input2, input3, input4)<< endl; // outputting to the screen the psd
    outFile << "The 4 integers that were chosen were: "<< input1<< input2<< input3<< input4; //outputs to the out file that was stated for this line and the next 2 lines
    outFile << "The mean of the 4 values are: " << meanc(input1, input2, input3, input4) << endl;
    outFile << "The population standard deviation of the 4 values is: " << psd(input1, input2, input3, input4)<< endl;
    cout << "The calculated mean and psd were saved into the file that is named: "<< outputFileName << endl; //outputting where the calculated values were stored
    
    
    return 0;
    
}
//Calculating the mean
float meanc(float input1a, float input2b, float input3c, float input4d) // input values that taken from main function that were cin at the beginning of the code
{
    float mean = ((input1a + input2b + input3c + input4d)/4); //calculating the mean
    return mean;// returning the mean to the main function
}
//Calculating the population standard deviation
// psd = population standard deviation
float psd(float input1e, float input2f,float input3g, float input4h)
{
    float mean = meanc(input1e, input2f, input3g, input4h); // calling mean function above
    float psd = sqrt((pow(input1e - mean,2) + pow(input2f - mean, 2) + pow(input3g - mean, 2) + pow(input4h - mean, 2))/4); //pow is used to square the (input valve - mean) , calculating the psd
    return psd; // returning
}
