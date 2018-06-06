#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <cctype>

using namespace std;

void display_points(int &points)
{
    cout<<"Points: "<<points<<endl<<endl;
}

void add_points(int &points)
{
    points +=10;
}

//translates ints to characters required by animate func
char trans_rand_ints_to_chars(int val)
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

//draws 3 numbers
void randomize(char *arr)
{
    int drawn_num;
    for(int i=0; i<3; i++)
    {
        drawn_num = rand()%9+1;
        arr[i]= trans_rand_ints_to_chars(drawn_num);
    }
}

//display "board"
void animate(char val)
{
    switch(val)
    {
    case 'q':
        cout<<" O||\n |||\n ||| "<<endl<<endl;
        break;
    case 'w':
        cout<<" |O|\n |||\n ||| "<<endl<<endl;
        break;
    case 'e':
        cout<<" ||O\n |||\n ||| "<<endl<<endl;
        break;
    case 'a':
        cout<<" |||\n O||\n ||| "<<endl<<endl;
        break;
    case 's':
        cout<<" |||\n |O|\n ||| "<<endl<<endl;
        break;
    case 'd':
        cout<<" |||\n ||O\n ||| "<<endl<<endl;
        break;
    case 'z':
        cout<<" |||\n |||\n O|| "<<endl<<endl;
        break;
    case 'x':
        cout<<" |||\n |||\n |O| "<<endl<<endl;
        break;
    case 'c':
        cout<<" |||\n |||\n ||O "<<endl<<endl;
        break;
    default:
        cout<<" XXX\n XXX\n XXX "<<endl<<endl;
    }
}

//display progress bar
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

//pause app for a while and clear console window
void wait_and_clear(int milisec)
{
    _sleep(milisec);
    system("CLS");
}

//preparing task for user
void task(char *arr, int &points)
{
    randomize(arr);
    wait_and_clear(1000);
    display_points(points);
    for(int i=0; i<3; i++)
    {
        wait_and_clear(1000);
        display_points(points);
        prog_bar(i);
        animate(arr[i]);

    }
    wait_and_clear(1000);
}

//it's user round, if user will make a mistake function will assign false to the "luck" variable
void round(char *arr, int &points, bool &luck)
{
    char user_choice;
    cout<<"Your turn:";
    for(int i=0; i<3; i++)
    {
        //display_points(points);
        user_choice = tolower(getch());
        if(user_choice!=arr[i])
        {
            luck = false;
            wait_and_clear(0);
            display_points(points);
            prog_bar(i);
            animate('l'); //passed wrong value
            break;
        }
        prog_bar(i);
        wait_and_clear(0);
        add_points(points);
        display_points(points);
        prog_bar(i);
        animate(user_choice);
    }
}

void instruction()
{
    char buttons[10] = {'q','w','e','a','s','d','z','x','c','l'};
    cout<<"Player must repeat computer moves. Each correct move will add 10 points. \nAvailable moves and buttons assigned to them are presented below:"<<endl<<endl;
    for(int i =0; i<10; i++)
    {
        if (i!=9)
        {
            cout<<"  "<<(char)toupper(buttons[i])<<endl;
            animate(buttons[i]);
        }
        else
        {
            cout<<"If you press wrong button game ends."<<endl;
            animate(buttons[i]);
        }
    }
cout<<"Press any button if you want back to the main menu."<<endl<<endl;
    getch();
}
void game_over(int &points)
{
    wait_and_clear(1000);
    cout<<"You loose!"<<endl<<endl;
    cout<<"Your points: "<<points<<endl<<endl;
    cout<<"Press any button.";
    getch();
}

void game()
{
    bool luck=true;
    char tab[3];
    int points = 0;
    do
    {
        task(tab,points);
        round(tab,points,luck);
    }
    while(luck);

    game_over(points);

}
int main()
{
    srand(time(NULL));
    instruction();
    game();

    return 0;
}
