# factorCalculator
Finding non-trivial divisors for a sequence of integers from a file, writing results to another file.

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
