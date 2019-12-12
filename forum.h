#include <string>
using namespace std;


struct Date{
    int day;
    int month;
    int year;
};



class Post {
private:
        int id;
        string title;
        string creator;
        Date D;
        string text; 
public:
        Post(int,string,string,Date,string);
        ~Post();
        void print_post(void);
        int get_id2();
        



};


class Thread {
private:
        string subject;
        string creator;
        Date D;
        Post** post;
        int n2;
public:
        
        Thread(string,string,Date);
        ~Thread();
        void print_thread(void);
        string get_subject(void);
        int get_id(int);
        int get_num();
        void get_post(int);


  
};




class Forum {
private:
        string title;
        Thread** thread;
        int n;
public:
        Forum(string);
        ~Forum();
       void print_forum(string,int);



};
