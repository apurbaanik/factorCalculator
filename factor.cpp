/*
Title: 1.2 Finding non-trivial divisors for a sequence of integers from a file, writing results to another file.
Author: Anik Barua
Version: 1.0
Date: 02-16-2021

Description: This C++ program reads in integers from a text file "input.txt", finds the non-trivial divisors 
other than 1 and itself, and output all the factors in a separate file, "output.txt". In the class example, 
it goes through all possible values less than the number itself, so to increase its efficiency this time I 
do it till the sqrt(num) to find all factors and then divide those factors with the number to get the 
remaining factors. But since when I put the remaining factors in an array it puts the values in descending 
order so I call the reverse array function to reverse my array in ascending order that uses the swap 
function. Then it puts all the values in a single array, and we got factors in a more efficient way. 
*/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

//The reverseArray fuction takes an array and the length of it, reverses the array by calling the
//swap fuction so the factors are in ascending order in the array.
void reverseArray(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - i - 1]); //Calls the swap fuction
    }
}

//Swap fuction takes the memeory address of the int elements and swaps their contents.
void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    try
    {
        ifstream inFile("input.txt"); //inFile object is created to open the input.txt file
        if (!inFile.good())
        {
            throw string("Failure opening the input.txt");
        }
        ofstream outFile("output.txt"); //outFile object is created to create the output.txt file
        if (!outFile.good())
        {
            throw string("Failure opening the output.txt");
        }

        int num;
        while (inFile >> num)
        {
            int factors[num]; //Array for factors <= sqrt(num)
            int j = 0;        //Couter for factor array

            int otherFactors[num]; //Array created for other factors > sqrt(num)
            int z = 0;             // Counter for otherFactor array

            outFile << num << " : ";
            bool isFirst = true;

            //Gets all divisors other than 1 and itself but less than or equal to sqrt of the number.
            for (int i = 2; i <= sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    if (isFirst)
                    {
                        outFile << "";
                    }
                    else
                    {
                        outFile << ", ";
                    }
                    outFile << i;

                    //Divides the number by the small factor to get largest factor for the
                    //same number an puts it in the array.
                    int c = num / i;

                    //Checks if the factor is already in the array if not add it.
                    if (i != c)
                    {
                        otherFactors[z++] = c;
                    }

                    //Puts the smaller factors in the array.
                    factors[j++] = i;

                    if (isFirst)
                    {
                        isFirst = false;
                    }
                }
            }

            //At this moment, the values in the otherFactors array is in descending order.
            //So I call the reverse array fuction to put the values in ascending order.
            reverseArray(otherFactors, z);

            //Add the otherFactors array values in the factors array so that we have every values in one array.
            for (int i = 0; i < z; i++)
            {
                factors[j + i] = otherFactors[i];
            }

            //Prints out the otherFactors array values in the output file
            for (int i = 0; i < z; i++)
            {
                outFile << ", " << factors[j + i];
            }

            //If it's prime number then it prints the word "None"
            if (isFirst)
            {
                outFile << "None\n";
            }
            else
            {
                outFile << "" << endl;
            }
        }
        inFile.close();  //Closing the input.txt
        outFile.close(); //Closing the output.txt
        return 0;
    }
    catch (string message)
    {
        cerr << message << endl; //Prints out the error message
        exit(1);
    }
}