#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

bool LoginVerification()
    {
        string username, password, us, pw;
        cout << "Enter Username: "; cin >> username;
        cout << "Enter Password: "; cin >> password;


    ifstream read("c:" + username + ".txt");
    getline(read, us);
    getline(read, pw);

    if (us == username && pw == password)
        {
            return true;
        }
    else
        {
            return false;
        }
    }

int main()
    {
        int Option;
        cout << "1: Register\n2: Login" <<endl;
        cout << "Please Choose Your Option (1/2): "; cin >> Option;
        if (Option == 1)
            {
                string username, password;

                cout << "Type Username: "; cin >> username;
                cout << "Type Password: ";cin  >> password;

                ofstream file;
                file.open("c:"+ username + ".txt");
                file << username << endl << password;
                file.close();

                cout << endl;
                main();

            }
        else if (Option == 2 )
            {
                string Answer;
                bool LoginStatus = LoginVerification();

                if(!LoginStatus)
                    {
                     cout << "Incorrect Username or Password! "<< endl << endl;
                     cout << "Do you want try again? (y/n): "; cin >> Answer;
                             if (Answer=="y")
                             {
                                 cout << endl;
                                 main();
                             }
                             else if(Answer=="n")
                             {
                                 system("PAUSE");
                                 return 0;
                             }
                    }
                else
                    {
                     cout << "Successfully Logged In! " << endl << endl;
                     cout << "Do you want try again? (y/n): "; cin >> Answer;
                             if (Answer=="y")
                             {
                                cout << endl;
                                main();
                             }
                             else if(Answer=="n")
                             {
                                 system("PAUSE");
                                 return 0;
                             }
                    }


            }

    }
