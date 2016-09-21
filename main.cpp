
// program npisany w  godzine zeby zapelnic czyms profil na githubie


#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include <fstream>
#include <cstdlib>


using namespace std;


void winn(string word, int licz){

        system("cls");
    cout << "Congratulation!!!"<< endl<<endl;
    cout << "You win!!! "<< endl<<endl;
    cout<<"You had: "<<licz<<" guesses left."<<endl;

    Sleep(5000);
return;

}

void loose(){

        system("cls");
    cout << "You loose!"<< endl<<endl;
    cout << "You are a HANGMAN"<< endl<<endl;


cout <<"#     |       |"<<endl;
cout <<"#     |      (_)"<<endl;
cout <<"#     |     ??|??"<<endl;
cout <<"#     |       |"<<endl;
cout <<"#     |     ?? ??"<<endl;
cout <<"#     |"<<endl;
cout <<"#     |___"<<endl;

    Sleep(5000);
return;

}

void newgame()
{

string word;
string line;


// wybieram losowo slowo z pliku
int c = 0;
int los = rand()%16;

ifstream myfile ("words.txt");


    if (myfile.is_open())
        {

            while(getline(myfile, line))
                {

                    ++c;

                    if(c == los)
                    {
                        word=line;
                    }

                }

        }
        else
        word="hangman";




    int n = word.size();

    char A[n-1];
    bool B[n-1];

    char g;

    int licz = 10;
    int win = 0;
    int k=0;

    for(int i = 0;i<n;i++)
    {
        A[i] = toupper(word.at(i));
        B[i] = false;

    }



do{
        system("cls");
    cout << "Game - Hangman"<< endl<<endl;
    cout << "You have only:  "<<licz<< endl<<endl;

for(int i=0;i<n;i++){

    if (B[i]==false)
        cout<<"_ ";
    else
        cout<<A[i]<<" ";

}
    cout << endl;
    cout << "Your guess:  "<< endl;
    cin>>g;

    g=toupper(g);


    // sprawdzam wystepowanie wybranej litery

    k=0;
    for(int i=0;i<n;i++){

        if (g==A[i])
        {
            B[i]=true;
            k++;
        }
    }
    if (k==0)
        licz--;




    // sprawdzam ilosc odgadnietych znakow:
        win=0;

    for(int i=0;i<n;i++){

        if (B[i])
        {
            win++;
        }
    }

    if (win==n)
        return winn(word, licz);





}while (licz!=0);



    return loose();
}


void openwords()
{
cout <<"In this place I will make tool for reading your own word files"<<endl;

    Sleep(5000);
    return;

}

void makewords()
{
    cout <<"In this place I will make tool for making your own word files"<<endl;

    Sleep(5000);
    return;
}




int main()
{

   int m;


do{

    m=1;
        system("cls");

    cout << "Menu - Hangman"<< endl<<endl;
    cout << "1- New Game"<< endl;
    cout << "2- Open words file"<< endl;
    cout << "3- Make words file"<< endl;
    cout << "4- Exit"<< endl;
    cout <<  endl;
    cout << "Your choice:  " ;
    cin >> m;

    switch( m )
    {
    case 1:

        newgame();
        break;

    case 2:

        openwords();
        break;

    case 3:

        makewords();
        break;

    case 4:
        break;

    default:

        cout <<endl<<"You typed wrong wrong number!"<< endl;
        Sleep(1000);
        break;




    }

} while(m != 4 );



    return 0;

}
