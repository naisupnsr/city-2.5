#include <iostream>
#include <cstdlib>
#include <graphics.h>
#include <windows.h>
#include <vector>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include "LL.h"
#include "player.h"
#include "player_s.h"
#include <fstream>
#include <iomanip>
#include "function_g.h"
using namespace std;

#define textcolor(txt,back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

typedef struct
{
    int rankmoney,rankscore,rankpm;
    string rankname;
} ranking;

bool cmp(ranking a, ranking b)
{
    if (a.rankscore != b.rankscore)
        return a.rankscore > b.rankscore;
    else
    {
        return a.rankmoney < b.rankmoney;
        return a.rankpm > b.rankpm;
    }
}

int main(int argc, char *argv[])
{
    system("mode 500,800");
    int mode,a=0;
    do
    {
        LL A;
        player *t;
        string name;
        int sc,m,p;
        string n;
        fstream fout;
        fstream fin;
        fin.open ("Player.txt",ios::in);

        if (fin.is_open())
        {
            vector<string> row;
            string line, word, temp;

            while (fin >> temp)
            {

                row.clear();
                getline(fin, line);

                stringstream s(line);

                while (getline(s,word, ','))
                {
                    row.push_back(word);
                }

                istringstream(row[2]) >> m;
                istringstream(row[3]) >> p;
                istringstream(row[4]) >> sc;

                t=new player_s(row[1],m,p,sc);
                A.add_player(t);
            }
            fin.close();
        }


        try
        {
            project_name();
            menu();
            cin.clear();
            cin>>mode;

            if(!cin.fail())
            {
                if(mode==1)
                {
                    readimagefile("newgame.jpg",0,0,1530,370);
                    new_game();
                    cout<<endl<<endl;
                    cout<<"\t\t\t\t\t\t\t\t\t\tPLEASE ENTER YOUR NAME : ";
                    cin.clear();
                    cin>>name;
                    loadbar();
                    fout.open ("Player.txt",ios::out |ios::app);

                    if (fout.is_open())
                    {
                        fout <<"Player "<<",";
                        fout << name <<", ";
                        fout << "0" <<", ";
                        fout << "0" <<", ";
                        fout << "0" ;
                        t=new player_s(name);

                        A.add_player(t);

                        fout.close();

                    }
                    else
                        cout << "Unable to open file";

                    int p;
                    p=game_1();
                    A.save_all_data();

                    A.savefile();
                    renamefile();
                    system("cls");
                    //A.show_all();
                    //system("pause");

                    if(p!=99)
                    {

                        p=game_2();
                        A.savefile();
                        renamefile();
                        A.save_all_data();

                        system("cls");
                        //A.show_all();
                        if(p!=99)
                        {
                            p=game_3();
                            A.save_all_data();

                            A.savefile();
                            renamefile();
                            system("cls");
                            //A.show_all();
                            if(p!=99)
                            {
                                p=game_4();
                                A.save_all_data();

                                A.savefile();
                                renamefile();
                                system("cls");
                                //A.show_all();
                                if(p!=99)
                                {
                                    p=game_5();
                                    A.savefile();
                                    A.save_all_data();
                                    renamefile();
                                    system("cls");
                                    //A.show_all();
                                    if(p!=99)
                                    {
                                        p=game_6();
                                        A.savefile();
                                        A.save_all_data();
                                        renamefile();
                                        system("cls");
                                        //A.show_all();
                                        if(p!=99)
                                        {
                                            p=game_7();
                                            A.savefile();
                                            A.save_all_data();
                                            renamefile();
                                            system("cls");
                                            //A.show_all();
                                            if(p!=99)
                                            {
                                                p=game_8();
                                                A.savefile();
                                                A.save_all_data();
                                                renamefile();
                                                system("cls");
                                                //A.show_all();
                                                if(p!=99)
                                                {
                                                    p=game_9();
                                                    A.savefile();
                                                    A.save_all_data();
                                                    renamefile();
                                                    system("cls");
                                                    //A.show_all();

                                                    if(p!=99)
                                                    {
                                                        p=game_10();
                                                        A.savefile();
                                                        A.save_all_data();
                                                        renamefile();
                                                        system("cls");
                                                        //A.show_all();
                                                        next_ep10_rank();
                                                        int men;
                                                        do
                                                        {
                                                            cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [0] to go to MENU : ";
                                                            cin>>men;
                                                        }
                                                        while(men!=0);
                                                        if(men==0)
                                                        {
                                                            closegraph();
                                                        }
                                                        a=2;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    a=2;
                }


                else if(mode==2)
                {
                    system("cls");
                    readimagefile("rank.jpg",0,0,1530,370);
                    ranking arr[1000];
                    fstream fout;
                    fstream fin;
                    int i=0,counter=0;
                    fin.open ("Player.txt",ios::in);
                    if (fin.is_open())
                    {
                        vector<string> row;
                        string line, word, temp;

                        while (fin >> temp)
                        {

                            row.clear();
                            getline(fin, line);

                            stringstream s(line);

                            while (getline(s,word, ','))
                            {
                                row.push_back(word);
                            }

                            arr[counter].rankname = row[1];

                            arr[counter].rankmoney = atoi(row[2].c_str());
                            arr[counter].rankpm = atoi(row[3].c_str());
                            arr[counter].rankscore = atoi(row[4].c_str());
                            counter++;

                        }
                        fin.close();
                    }
                    sort(arr, arr + counter, cmp);
                    int men=1;
                    while(men!=0)
                    {
                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t----------------------------------------------------"<<endl;
                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tNAME                           SCORE"<<endl;
                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t----------------------------------------------------"<<endl;
                        for (int i = 0; i < counter; i++)
                        {
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t"<<arr[i].rankname;
                            cout<<"\t\t\t\t\t"<<arr[i].rankscore<<endl;
                        }
                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [0] if you want to go to MENU : ";
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cin>>men;
                        if(cin.fail())
                        {
                            system("cls");
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            men=1;
                        }
                        else
                        {
                            system("cls");
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                    }
                    while(men!=0);

                    if(men==0)
                    {
                        closegraph();
                    }
                    a=2;
                }
                else if(mode==3)
                {
                    int men;
                    do
                    {
                        system("cls");
                        readimagefile("history.jpg",0,0,1530,370);
                        A.show_history();
                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [0] if you want to go to MENU : ";
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cin>>men;
                        if(cin.fail())
                        {
                            system("cls");
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            men=1;
                        }
                        else
                        {
                            system("cls");
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                    }
                    while(men!=0);
                    if(men==0)
                    {
                        closegraph();
                    }
                    a=2;
                }
                else if(mode==0)
                {
                    readimagefile("bye.jpg",0,0,1530,370);
                    system("cls");
                    cout<<"BYE_BYE"<<endl;
                    Sleep(2000);
                    exit(0);
                }
                else
                {
                    throw "     **Announce >> Please choose again! ";

                }

            }

            else if(mode!=1||mode!=2||mode!=3||mode!=0)
            {
                throw "     **Announce >> Please choose again! ";
            }
        }
        catch(const char* error)
        {
            system("cls");
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            Sleep(1000);
            closegraph();
            a=2;
        }
    }
    while(a==2);
    return EXIT_SUCCESS;

}







