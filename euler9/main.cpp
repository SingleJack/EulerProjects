/*
Project Euler #9
Roy Lilly
Programmed in C++ with Code Blocks.

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a sq + b sq = c sq   For example, 3sq + 4sq = 9 + 16 = 25 = 5sq.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
When m and n are any two positive integers (m < n):
a = n2 - m2
b = 2nm
c = n2 + m2
Then, a, b, and c form a Pythagorean Triple.

http://www.mathsisfun.com/numbers/pythagorean-triples.html
*/

#include <iostream>

using namespace std;

int main()
{
    int a=0, b=0, c=0, y=1, x = 0, n;
    bool check = true;

    for(int m = 1; check; m++)
    {
        n = m;  //set n = m so that n can start out one more than m in next for loop
        for(int i = 1; i < 301; i++)
        {
            n += i; //increment so n is more than m.
            //formula for finding a Pythagorean triplet.
            a = (n*n)-(m*m);
            b = 2*n*m;
            c = (n*n)+(m*m);

            while(check && a+b+c <= 1000)
            {
                if(a+b+c == 1000) //found numbers that sum to 1000 -> jumps out of while loop
                {
                    check = false;  //gets out of while loop w/o changing a b or c
                    x = a*b*c;
                    cout << x << endl;
                    return 0;
                }
                else //set each variable to the next proper value
                {
                     a *= y;
                    b *= y;
                    c *= y;
                    y++;
                }
            }
        }

        if(!check)//if check = false
        {
    cout << "breaking out of for loop" << endl;
            break;  //if number already found get out of for loop
        }
        else
        {
            check = true;
            y=1;  //reset y
        }
    }
}
/*
a= 375
b= 200
c= 425
answer is 31875000
*/
