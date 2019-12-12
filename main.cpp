#include <iostream>
#include "forum.h"
#include <time.h>



using namespace std;

int main()
{
        Forum f("Object-Oriented Programming ");   //create the forum
        f.print_forum("",0);                       //print the forum
        f.print_forum("Rules and useful info",0);  //print the thread
        int n = rand() % 25;                       //random post
        //cout<<n<<endl;
        f.print_forum("",n);                       //print random post if it exists
        
        return 0;

}

