#include <string>
#include <iostream>
#include "forum.h"
#include <stdlib.h>
#include <time.h>


using namespace std;

///////////////////////////////////////////////////////////////////////////////////////


int Post::get_id2()
{
        return id;
}

void Post::print_post(void)
{
        cout<<"              id = "<<id<<" "<<"title = "<<title<<" "<<" creator = "<<creator<<" "<<"date = "<<D.day<<"/"<<D.month<<"/"<<D.year<<" "<<"text = "<<text<<endl;

}

Post::Post(int id1,string title1,string creator1,Date D1,string text1)
{
        id = id1;
        title = title1;
        creator = creator1;
        D = D1;
        text = text1;
        cout <<"              Post number:"<<id<<" has just been created!" << endl ;
        //print_post();

}

Post::~Post()
{
        cout <<"              Post number:"<<id<<" is about to be destroyed"<< endl ;
   
}
////////////////////////////////////////////////////////////////////////

int Thread::get_id(int j)
{
        return (*post[j]).get_id2();
}

int Thread::get_num()
{
        return n2;
}

void Thread::get_post(int j)
{
        post[j]->print_post();
}



void Thread::print_thread()
{
    cout<<"        subject = "<<subject<<" "<<"creator = "<<creator<<" "<<"date = "<<D.day<<"/"<<D.month<<"/"<<D.year<<endl;
    for(int i = 0;i < n2; i++)
    {
            post[i]->print_post();
    }
}
string Thread::get_subject()
{
        return subject;
}
Thread::Thread(string subject1,string creator1,Date D1)
{
        subject = subject1;                   //i initiallize my variables
        creator = creator1;
        D = D1;
        cout <<"        Thread with subject:'"<<subject<<"' has just been created!" << endl ;

        string titles[5]{"hello people", "programming is fun", "reference", \
        "classes", "structs"};

        string creators[5]{"James","John","Jim", \
        "Ellen","Liza"};

        Date D2[5];
        string *tit = titles;
        string *cre = creators;
        string t[7]{"Hello people","i want to ask something","is java or c++ more useful?","thank you","this forum is amazing","hello again","goodnight"};

        int id[25]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
        int *id1 = id;

        int k,l;
        string a,b,c;
        n2 = rand() % 5 + 1;

        for (int i = 0; i < 5; i++)
        {
                D2[i].day = rand() % 30 + 1;         //here i find randomly dates
                D2[i].month = rand() % 12 + 1;
                D2[i].year = 2000 + rand() % 19 + 1;
        }
       

        post = new Post*[n2];       
        for (int i = 0; i < n2; i++)
        {    
                        
                        
                        
                        k = rand() % 5;
                        if (tit[k] == "")
                        {
                                while (tit[k] == "")
                                {
                                        k = rand() % 5;            //here i find randomly a title,a creator,an id,a text
                                }                                  //i do it in a way so that they are only used once(it wasnt asked but i didnt want there to be two posts with the same title)
                                a = titles[k];
                                tit[k] = "";
                        }
                        else
                        {
                                a = titles[k];
                                tit[k] = "";
                        }
                 

                        k = rand() % 5;
                        if (cre[k] == "")
                        {
                                while (cre[k] == "")
                                {
                                        k = rand() % 5;
                                }
                                b = creators[k];
                                cre[k] = "";
                        }
                        else
                        {
                                b = creators[k];
                                cre[k] = "";
                        }

                        k = rand() % 25;
                        if (id1[k] == -1)
                        {
                                while (id1[k] == -1)
                                {
                                        k = rand() % 25;
                                }
                                l = id[k];
                                id1[k] = -1;
                        }
                        else
                        {
                                l = id[k];
                                id1[k] = -1;
                        }
                        k = rand() % 7;
                        c=t[k];
                        
                        post[i] = new Post(l,a, b, D1,c);     //here i call the constructor of Thread and i update my array of posts
                        

        }
        //print_thread();
  
}

Thread::~Thread()
{
        for (int i = 0; i < n2; i++)
                delete post[i];
        delete [] post;
        
        cout <<"        Thread with subject:'"<<subject<<"' is about to be destroyed" << endl ;



}

/////////////////////////////////////////////////////////////////////////////////












void Forum::print_forum(string title1,int id1)
{
        if (title1 == "" && id1==0)
        {
                cout<<"The threads of the forum are:"<<endl;                      //print threads
                for(int i = 0;i < n; i++)
                        cout<<thread[i]->get_subject()<<endl;
                cout<<endl;
        }
        else if (id1 == 0)                                                        //print a specific thread
        {
               for(int i = 0;i < n; i++)
                {
                        if (thread[i]->get_subject() == title1)
                              thread[i]->print_thread();
                }
        }
        else if (id1 != 0)                                                        //print a specific post(if it exists)
        {
               for(int i = 0; i < n; i++)
                {
                        for (int j = 0; j < thread[i]->get_num(); j++)
                        {
                                if (thread[i]->get_id(j) == id1)
                                {
                                        thread[i]->get_post(j);
                                        return;
                                }

                        }
                }
                cout<<"Not found"<<endl;

        }
        
    
}



Forum::Forum(string title1)
{
        title = title1;
        cout <<"Forum with title: '"<<title<<"' has just been created!" << endl ;

        int k;
        string a,b;
        srand (time(NULL));
        string subjects[5]{"Rules and useful info", "oop", "c++", \
        "java", "pointers"};
        string creators[5]{"Oscar","Tyler","Kelly", \
        "Professor","Liz"};
        string *sub = subjects;
        string *cre = creators;
        n = rand() % 5 + 1;
        

        

        Date D1[5];



        for (int i = 0; i < 5; i++)
        {
                D1[i].day = rand() % 30 + 1;
                D1[i].month = rand() % 12 + 1;
                D1[i].year = 2000 + rand() % 19 + 1;
        }

        thread = new Thread*[n];
        for (int i = 0; i < n; i++)
        {    
                if (i==0)
                {
                        a = subjects[0];
                        sub[0] = "";
                }
                else
                 { 
                        k = rand() % 5;                                           //find random elements and make sure they are not used twice
                        if (sub[k] == "")                                         //this wasnt asked but i did want there to be two threads with the same subject 
                        {
                                while (sub[k] == "")
                                {
                                        k = rand() % 5;
                                }
                                a = subjects[k];
                                sub[k] = "";
                        }
                        else
                        {
                                a = subjects[k];
                                sub[k] = "";
                        }
                 }

                k = rand() % 5;
                if (cre[k] == "")
                {
                        while (cre[k] == "")
                        {
                                k = rand() % 5;
                        }
                        b = creators[k];
                        cre[k] = "";
                }
                else
                {
                        b = creators[k];
                        cre[k] = "";
                }
                
                Date D = D1[rand() % 5];
                thread[i] = new Thread(a, b, D);



                

        }
        

        cout << endl;
        
}

Forum::~Forum()
{
        for (int i = 0; i < n; i++)
         delete thread[i];
        delete [] thread;
     
        cout <<"Forum with title: '"<<title<<"' is about to be destroyed" << endl ;
  
}



