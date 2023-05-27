#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    int price;
    float dis;
    string pname;

public:
    void menu();
    void adminstrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_______________________________________\n";
    cout << "\t\t\t\t                                       \n";
    cout << "\t\t\t\t         Supermarket main menu         \n";
    cout << "\t\t\t\t                                       \n";
    cout << "\t\t\t\t_______________________________________\n";
    cout << "\t\t\t\t                                       \n";
    cout << "\t\t\t\t 1) Adminstrator  \n";
    cout << "\t\t\t\t                  \n";
    cout << "\t\t\t\t 2) Buyer         \n";
    cout << "\t\t\t\t                  \n";
    cout << "\t\t\t\t 1) Exit          \n";
    cout << "\t\t\t\t Please Select:   \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t  Please Login  \n";
        cout << "\t\t\t\t  Enter Email   \n";
        cin >> email;
        cout << "\t\t\t\t  Enter Your Password  \n";
        cin >> password;

        if (email == "soni@email.com" && password == "soni1234@")
        {
            adminstrator();
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select from the given options";
    }
    break;
    }
    goto m;
}

void shopping::adminstrator()
{
m:
    int choice;
    cout << "\t\t\t\t   Adminstrator Menu     |";
    cout << "\t\t\t\t                         |";
    cout << "\t\t\t\t   1) Add Product        |";
    cout << "\t\t\t\t                         |";
    cout << "\t\t\t\t   2) Remove Product     |";
    cout << "\t\t\t\t                         |";
    cout << "\t\t\t\t   3) Delete Product     |";
    cout << "\t\t\t\t                         |";
    cout << "\t\t\t\t   4) Back to Main Menu  |";

    cout << "\t\t\t\t Please enter your choice ";
    cin >> choice;

    switch (choice)
    {
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
        cout << "Invalid choice!";
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t   Buyer Menu            |";
    cout << "\t\t\t\t                         |";
    cout << "\t\t\t\t   1) Buy Product        |";
    cout << "\t\t\t\t                         |";
    cout << "\t\t\t\t   4) Go Back            |";

    cout << "\t\t\t\t Please enter your choice ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();

    default:
        cout << "Invalid Choice";
        break;
    }
    goto m;
}

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new Product";
    cout << "\n\n\t Product code Of the Product";
    cin >> pcode;
    cout << "\n\n\t Name of the Product";
    cin >> pname;
    cout << "\n\n\t Price of the Product";
    cin >> price;
    cout << "\n\n\t Discount on the Product";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::in | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
        goto m;
    else
    {
        data.open("database.txt", ios::in | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "\n\n\t\t  Record Inserted!! ";
}
void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t   Modify the Records";
    cout << "\n\t\t\t   Product Code ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File Doesn't Exist ";
    }
    else
    {
        data1.open("database.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product New code";
                cin >> c;
                cout << "\n\t\t Name of the product";
                cin >> n;
                cout << "\n\t\t Price";
                cin >> p;
                cout << "\n\t\t Discount";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record Edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found Lmao!!";
        }
    }
}
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Enter Product code";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "file Doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product Deleted Succusfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n\t Record can't be Found";
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt,ios::in");
    cout << "\n\n|__________________________________\n";
    cout << "ProNo\t\tPrice\n";
    cout << "\n\n|__________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping ::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t Receipt";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty Database";
    }
    else
    {
        data.close();
        list();
        cout << "\n|______________________________|\n";
        cout << "\n|                              |\n";
        cout << "\n|    Please place the order    |\n";
        cout << "\n|                              |\n";
        cout << "\n|______________________________|\n";
        do
        {
        m:
            cout << "\n Enter Product Code";
            cin >> arrc[c];
            cout << "\n Enter Product quantity";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate Product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to Buy another product? if yes press Y else no";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t_________________RECEIPT__________________";
        cout << "\nProduct No\t Product\t Product quantity\tprice\tAmount with discount\n";

        for (int i = 0; i, c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n____________________________________";
    cout << "\n\n total Amount : " << total;
}
int main()
{
    shopping s;
    s.menu();
}