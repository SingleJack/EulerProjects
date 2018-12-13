
/*
Project Euler #8
Roy Lilly
Programmed in C++ with Code Blocks

Find the greatest product of five consecutive digits in the 1000-digit number.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450
*/

#include<iostream>
#include <fstream> //used for file access

using namespace std;

int main()
{
    //char c;
    int x = 1, r = 0, y=1;
    char consecNum[1000]; // array for storing numbers
    ifstream numbers; //variable for file
    //numbers have been put into a file test.txt
    numbers.open("test.txt", ios::in);

    if(!numbers) //Test the file to see if it opened.
    {
                cout<<"Error opening output file"<<endl;
                return -1;
    }

    //loop through until all numbers are put into the array
    while(numbers.good() && r < 1000)
    {
        consecNum[r] = numbers.get();
        //cout << (int)consecNum[r] - 48; //test to see if complete number is there
        r++;
    }

//cout << endl;

    for(int i = 0; i < 5; i++) //first number is assigned to x
    {
        //subtract ascii value for 0 from array result because numbers are entered as ascii.
        x *= (int)consecNum[i] - 48; //array casted into int (x is int type)
    }

    for(r = 0; r < 995; r++) //tests all other products, if bigger replaces x
    {
        y = 1;
        for(int ii = 0; ii < 5; ii++)
        {
            //subtract ascii value for 0 from array result because numbers are entered as ascii.
            y *= ((int)consecNum[r + ii] - 48); //array casted into int (y is int type)
        }
        if(y > x)//replace x if y is larger
        {
            x = y;
        }
    }

        cout << "The answer is: " << x << endl;

        numbers.close();
}

//answer is 40824
