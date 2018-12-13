/*
Project Euler #10
Roy Lilly
Programmed in C++ with Code Blocks

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include<math.h>
#include<windows.h>
#include<iostream>

using namespace std;

struct Node
{  int num;
  struct Node *next;
};

bool isPrime(int potential, Node **head)
{
      Node *inspector; //create pointer for traversing list
      inspector = *head; //set pointer to point to head

      /*loop until pointer points to null or next number in list is greater
      than sqrt of possible next prime to limit iterations thus improving performance*/
      while(inspector->next != 0 && inspector->num <= sqrt(potential))
      {
        if(potential % (*inspector).num == 0) //check if not prime number
        {
            return false; //not a prime
        }
        inspector = inspector->next; // to next node
      }
        //if we go through the whole list then it must be a prime...
return true;
}

int main(double argc, char * const argv[])
{
    //use next 2 lines to see performance
   DWORD startTime = GetTickCount();
   DWORD endTime;

   //link list for holding primes
   Node *head = new Node;  //create head node and set it to null
   Node *traveler = head;  //create pointer and point to beginning
   head->next = 0;  //set next node to null
   head->num = 2;  //value of first node

   int potentialPrime = 2; //first prime number to be tested
   long long prime = 0; //variable to hold sum of primes

   for(int i = 2; i < 2000000; i++)
   {
       if(isPrime(potentialPrime,&head))
       {
       traveler->next = new Node; //create new node
       traveler->num = potentialPrime; //set next node to new prime
       traveler = traveler->next; //move to next node
       prime += potentialPrime; //add new prime to total
       }
       potentialPrime++;
   }
    endTime = GetTickCount();//used for performance
    cout << endTime - startTime << "milliseconds." << endl;


    cout << prime << " is the sum of all primes." << endl;
}

/* try this if number is bigger than long long int
string result = static_cast<ostringstream*>( &(ostringstream() << prime) )->str();
*/
//answer is 142913828922
