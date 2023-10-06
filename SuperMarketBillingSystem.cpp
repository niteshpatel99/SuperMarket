#include<iostream>
#include<fstream>
using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string name;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t\t                                           \n";
    cout<<"\t\t\t\t\t           Supermarket Main Menu           \n";
    cout<<"\t\t\t\t\t                                           \n";
    cout<<"\t\t\t\t\t___________________________________________\n";
    cout<<"\t\t\t\t\t                                           \n";

    cout<<"\t\t\t\t\t       1) Administrator    \n";
    cout<<"\t\t\t\t\t                           \n";
    cout<<"\t\t\t\t\t       2) Buyer            \n";
    cout<<"\t\t\t\t\t                           \n";
    cout<<"\t\t\t\t\t       3) Exit             \n";
    cout<<"\t\t\t\t\t                           \n";

    cout<<"\n\t\t\t     Please Select!";
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login  \n";
            cout<<"\t\t\t  Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t  Enter Password  \n";
            cin>>password;

            if(email =="niteshpatel@gmail.com" && password =="niteshpatel"){
                    administrator();
            }else{
                cout<<"Invalid email/password";
            }
            break;

        case 2:{
            buyer();
            break;
        }
        case 3:
        {
            exit(0);
        }
        default :
            {
                cout<<"Please select from the given options";
            }
    }
    goto m;
}

void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t     Administrator menu ";
    cout<<"\n\t\t\t|_____1)Add the product__________|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____2)Modify the product_______|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____3)Delete the product_______|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____4)Back to ain Menu ________|";

    cout<<"\n\t\t\  Please enter your choice";
    cin>>choice;

    switch(choice){

        case 1:
           add();
           break;
        
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        
        case 4:
            menu();
            break;

        default:
            cout<<"Invalid choice";

    }
    goto m;
}

void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t  Buyer  \n";
    cout<<"________________";
    cout<<"                    ";
    cout<<"\t\t\t 1) Buy Product  \n";
    cout<<"                    ";
    cout<<"\t\t\t 1) GO Back \n";
    cout<<"                    ";
    cout<<"\t\t\t Enter your choice :";

    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();

        default :
            cout<<"invalid choice ";

    }
    goto m;

}

void shopping::add(){

    fstream data;
    int c;
    int token =0;
    float p;
    float d;
    string n;
    string pname;

    cout<<"\n\n\t\t\t Add new product ";
    cout<<"\n\n\t Product code og the profuct ";
    cin>>pcode;

    cout<<"\n\n\t Name of the product ";
    cin>>pname;

}