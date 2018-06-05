#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;
char trans(int val)
{
    switch(val)
    {
    case 1:
        return 'q';
        break;
    case 2:
        return 'w';
        break;
    case 3:
        return 'e';
        break;
    case 4:
        return 'a';
        break;
    case 5:
        return 's';
        break;
    case 6:
        return 'd';
        break;
    case 7:
        return 'z';
        break;
    case 8:
        return 'x';
        break;
    case 9:
        return 'c';
        break;
    }
}
void ra(char *arr, int ti)
{
    int loso;
    for(int i=0; i<ti; i++)
    {
        loso = rand()%9+1;
        arr[i]= trans(loso);
    }
}
void anim(char val)
{
    _sleep(1000);
    system("CLS");
    switch(val)
    {
    case 'q':
        cout<<" O||\n |||\n ||| ";
        break;
    case 'w':
        cout<<" |O|\n |||\n ||| ";
        break;
    case 'e':
        cout<<" ||O\n |||\n ||| ";
        break;
    case 'a':
        cout<<" |||\n O||\n ||| ";
        break;
    case 's':
        cout<<" |||\n |O|\n ||| ";
        break;
    case 'd':
        cout<<" |||\n ||O\n ||| ";
        break;
    case 'z':
        cout<<" |||\n |||\n O|| ";
        break;
    case 'x':
        cout<<" |||\n |||\n |O| ";
        break;
    case 'c':
        cout<<" |||\n |||\n ||O ";
        break;
    default:
        cout<<" XXX\nXXX\nXXX ";
    }
}
void prog_bar(int ti)
{
    switch(ti)
    {
    case 0:
        cout<<"[#--]"<<endl;
        break;
    case 1:
        cout<<"[-#-]"<<endl;
        break;
    case 2:
        cout<<"[--#]"<<endl;
        break;
    }
}
void task(char *arr, int ti)
{
    for(int i=0; i<ti; i++)
    {

        prog_bar(i);
        anim(arr[i]);
    }
}

int main()
{
    int a;
    char tab[3];
    char b;

    srand(time(NULL));
    ra(tab,3);
    task(tab,3);
    /*
        for(int j=0; j<2; j++)
        {
            cout<<"Points: 0"<<endl;
            for(int i=0; i<30; i++)
            {
                anim(getch());
                _sleep(150);

            }
        }
    */
    return 0;
}
