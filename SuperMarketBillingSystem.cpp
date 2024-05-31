#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string pname;
    
    string admin_email;
    string admin_password;
    string admin_phone;


    public:
    	
    	shopping() {
        admin_email = "np@gmail.com";
        admin_password = "nitesh";
        admin_phone = "8887544920";
    }
    
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
        void reset_password();
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

    cout<<"\n\t\t\t     Please Select! ";
     
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login  \n";
            cout<<"\t\t\t  Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t  Enter Password  \n";
            cin>>password;

            if(email ==admin_email && password ==admin_password){
                    administrator();
            }else{
                cout<<"Invalid email/password";
                 cout << "\nDo you want to reset your password? (y/n): ";
                char reset_choice;
                cin >> reset_choice;
                if (reset_choice == 'y') {
                    reset_password();
                }
            }
            break;

        case 2:{
            buyer();
            
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
    cout<<"\n\n\n\t\t\t     Administrator menu \n";
    cout<<"\n\t\t\t|_____1)Add the product__________|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____2)Modify the product_______|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____3)Delete the product_______|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____4)Show all products________|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____5)Back to main Menu _______|\n\n";

    cout<<"\n\t\t\t  Please enter your choice ";
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
            list();
            break;
        case 5:
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
    cout<<"\n\n\t\t\t\t\t  Buyer Menu \n\n";
    cout<<"                    ";
    cout<<"\n\t\t\t|_____1)Buy Product___________|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|_____2)Back To Main Menu_____|";
    cout<<"\n\t\t\t|                             |";

    cout<<"                    ";
    cout<<"\n\t\t\t Enter your choice :";

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


void shopping::reset_password() {
    string phone;
    cout << "\n\nEnter your registered phone number: ";
    cin >> phone;

    if (phone == admin_phone) {
        cout<<"Phone number verified \n";
        cout<<"Enter your new Email : ";
        string new_email;
        cin>>new_email;
        admin_email = new_email;
        cout << "\nEnter your new password : ";
        string new_password;
        cin >> new_password;
        admin_password = new_password;
        cout << "\nEmail and Password has been reset successfully.\n";
    } else {
        cout << "\nIncorrect phone number.\n";
    }
}


void shopping::add() {
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new product ";
    cout << "\n\n\t Product code of the product: ";
    cin >> pcode;

    cout << "\n\n\t Name of the product: ";
    cin >> pname;

    cout << "\n\n\t Price of the product: ";
    cin >> price;

    cout << "\n\n\t Discount on product: ";
    cin >> dis;

    // Open the file in read mode to check for duplicates
    data.open("database.txt", ios::in);
    if (!data) {
        // If the file does not exist, create it and write the product details
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    } else {
        while (data >> c >> n >> p >> d) {
            if (c == pcode) {
                token++;
                cout << "\n\n Product code already exists. \n";
                break;
            }
        }
        data.close();

        // If no duplicate was found, append the new product details to the file
        if (token == 0) {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
            cout << "\n\n\t\t Record Inserted !";
        }
    }
}


void shopping ::edit(){

    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist!";
    }else{

        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\n\t\t Record Edited";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0){
            cout<<" \n\n Record not found sorry !";
        }
    }

}

void shopping :: rem(){

    fstream data,data1;
    int pkey;
    int token =0;
    cout<<"\n\n\t Delete Product  ";
    cout<<"\n\n\t Enter the product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\t File does't exixt";
    }else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode ==pkey){
                cout<<"\n\n\t Product Deleted Succesfully";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token ==0){
            cout<<"\n\n\t Record not found ";
        }
    }

}


void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n|______________________________________|\n";
    cout<<"ProNo\t\tName\t\tPrice";
    cout<<"\n|______________________________________|\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){

        cout<<pcode<<setw(20)<<setiosflags(ios::right)<<pname<<setw(20)<<price<<"\n";
        data>>pcode>>pname>>price>>dis;

    }
    data.close();
}


void shopping::receipt() {
    fstream data;
    int arrCodes[100];
    int arrQuantity[100];
    char choice;
    int counter = 0;
    float amount = 0;
    float discountAmount = 0;
    float total = 0;

    cout << "\n\n\t\t|______________RECEIPT__________|\n";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty Database";
        return;
    }
    data.close();

    list();
    cout << "\n|______________________________________|\n";
    cout << "|                                      |\n";
    cout << "|           Please place the Order     |\n";
    cout << "|______________________________________|\n";

    do {
        m:
        cout << "\n\n Enter Product Code :";
        cin >> arrCodes[counter];
        cout << "\n\n Enter the quantity :";
        cin >> arrQuantity[counter];
        for (int i = 0; i < counter; i++) {
            if (arrCodes[counter] == arrCodes[i]) {
                cout << "\n\n Duplicate product code. Please try again!";
                goto m;
            }
        }
        counter++;
        cout << "\n\n Do you want to buy another Product? if yes then press y else n: ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\n\n\t\t\t___________________Receipt__________\n";
    cout << setw(10) << "Product No  " << setw(20) << " Product Name  " << setw(20) << "Product Quantity"  << setw(20) << "Price" << setw(20) << "Amount " << setw(20) << "  Amount with Discount\n";

    for (int i = 0; i < counter; i++) {
        data.open("database.txt", ios::in);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (arrCodes[i] == pcode) {
                amount = price * arrQuantity[i];
                discountAmount = amount - (amount * dis / 100);
                total += discountAmount;
                cout << setw(10) << pcode << setw(20)<<setiosflags(ios::right) << pname << setw(20) << arrQuantity[i] << setw(20) << price << setw(20) << amount << setw(20) << discountAmount << '\n';
          
			     }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }

    cout << "\n\n________________________________________";
    cout << "\n Total Amount : " << total;
    cout << "\n\n";
}

int main(){
    shopping s;
    s.menu();
    return 0;
}
