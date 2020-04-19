//class Scoreboard


#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Team.h"

class Scoreboard
{
  private:
    Team t1;
    Team t2;
    int toGo;
    int down;
    int qtr;
    bool pos;
  public:
    Scoreboard () 
    {
      toGo = 0;
      down = 1;
      qtr = 1;
      pos = true;
    }

    void setTeam1 (Team tm1)
      {t1 = tm1;}
    void setTeam2 (Team tm2)
      {t1 = tm2;}
    void setToGo (int tg)
      {toGo = tg;}
    void setDown (int d)
      {down = d;}
    void setQtr (int q)
      {qtr = q;}
    void setPos (bool p)
      {pos = p;}

    Team getTeam1 () const
      {return t1;}
    Team getTeam2 () const
      {return t2;}
    int getToGo () const
      {return toGo;}
    int getDown () const
      {return down;}
    int getQtr () const
      {return qtr;}
    bool getPos () const
      {return pos;}
    
    //Scoreboard OUT
    void drawSboard()
    {
      //Line 1
      cout << "|HOME|";
      cout << setw(3) << t1.getHomeCity() << "|";
      cout <<  setw(14) << left << t1.getName();
      cout << "|" << "00:00:00" << "|";
      cout << setw(14) << right << t2.getName() << "|";
      cout << setw(3) << t2.getHomeCity();
      cout << "|VISITOR|";
      //Line 2
      cout << "\n|" << setw(2) << t1.getScore(); 
      cout << " |                                                   |";
      cout << setw(2) << t2.getScore();
      cout << " |";
      //Line 3
      cout << "\n|         |";
      if(pos == true)
      {
        cout << "|<>|" << "|POS||" << "                      |" << "|POS|" << "|  ||      |";
      }
      else
      {
        cout << "|  |" << "|POS|" << "|                      " << "||POS|" << "|<>||" << "      |";
      }
      //Line 4
      cout << "\n|                       |";
      cout << "|QTR|" << " ";
      cout << getQtr() << "||                          |";
      //Line 5
      cout << "\n|  |" << "|TOL|" << "|      |";
      cout << "|DOWN|" << "|           |";
      cout << "|TO GO|" << "|       |";
      cout << "|TOL|" << "|  |";
      //Line 6
      cout << "\n|    |" << t1.getTimeoutCount();
      cout << "|          |" << getDown();
      cout << "|                 |" << setw(2) << getToGo();
      cout << "|           |" << t2.getTimeoutCount();
      cout << "|    |";
      
    }
    
    //MENU OPTIONS 
    void menu1()
    {
      cout << "\n\n\n\nMenu";
      cout << "\nA - Update Scoreboard" ;
      cout << "\nB - Update Home" ;
      cout << "\nC - Update Visitor" ;
      cout << "\nX - End Game" ;
     
    }

    void menu2()
    {
      cout << "\n\n\nScoreboard Menu"; 
      cout << "\nA - Down              " ;
      cout << "\nB - To Go             " ;
      cout << "\nC - Possession        " ;
      cout << "\nD - Quarter           " ;
      cout << "\nF - Exit              " ;
    }

    void menu3()
    {
      cout << "\n\n\nHome Menu"; 
      cout << "\nA - Team Name" ;
      cout << "\nB - City" ;
      cout << "\nC - Score" ;
      cout << "\nD - Timeout Count" ;
      cout << "\nE - Coach Name" ;
      cout << "\nF - Exit";
    }

    void menu4()
    {
      cout << "\n\n\nVisitor Menu";
      cout << "\nA - Team Name" ;
      cout << "\nB - Home City" ;
      cout << "\nC - Score" ;
      cout << "\nD - Timeout Count" ;
      cout << "\nE - Coach Name" ;
      cout << "\nF - Exit" ;
    }
    
    //SCOREBOARD CONTROL
    void sboardControl()
    {
      drawSboard();
      char decision = '\0';
      
      do
      {
        cout << cClear;
        drawSboard();
        menu1();

        cout << "\n\nINPUT: ";
        validateChar(decision);

        //Scoreboard
        if (decision == 'a' || decision == 'A')
        {
          do
          {
            cout << cClear;
            drawSboard();
            menu2();

            cout << "\n\nINPUT: ";
            validateChar(decision);

            //DOWN
            if (decision == 'a' || decision == 'A')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu2();
                cout << "\n\nDown?: ";
                validateInt(d);

                if (d < 5 && d > 0)
                {
                  setDown(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu2();
                  cout << "\n\nMAX 4, TRY AGAIN";
                  cin.ignore(10000, '\n');
                }
              }while (d >= 5 || d <= 0);   
            }

            //TOGO 
            else if (decision == 'b' || decision == 'B')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu2();
                cout << "\n\nHow many yards to go: ";
                validateInt(d);

                if (d < 100 && d > 0)
                {
                  setToGo(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu2();
                  cout << "\n\n 99 yards to go max";
                  cin.ignore(10000, '\n');
                }
              }while (d >= 100 || d <= 0);
            }

            //Possession 
            else if (decision == 'c' || decision == 'C')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu2();
                cout << "\n\nPossession (1 = Home | 0 = Visitors: ";
                validateInt(d);

                if (d == 1)
                {
                  setPos(d);
                }
                else if (d == 0)
                {
                  setPos(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu2();
                  cout << "\n\n2 MAX";
                  cin.ignore(10000, '\n');
                }
              }while (d != 1 && d != 0);
            }

            //QUARTER 
            else if (decision == 'd' || decision == 'D')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu2();
                cout << "\n\nQuarter: ";
                validateInt(d);

                if (d == 1)
                {
                  setQtr(d);
                }
                else if (d == 2)
                {
                  setQtr(d);
                }
                else if (d == 3)
                {
                  setQtr(d);
                }
                else if (d == 4)
                {
                  setQtr(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu2();
                  cout << "\n\n4 MAX";
                  cin.ignore(10000, '\n');
                }
              }while (d <= 0 && d >= 5);
            }


          }while (decision != 'f' && decision != 'F');
        }

        //HOME TEAM OPTIONS
        else if (decision == 'b' || decision == 'B')
        {
          do
          {
            cout << cClear;
            drawSboard();
            menu3();

            cout << "\n\nINPUT: ";
            validateChar(decision);
            
            //TEAM NAME 
            if (decision == 'a' || decision == 'A')
            {
                cout << cClear;
                drawSboard();
                menu3();
                cout << "\n\nTeam name (15 letters MAX): ";
                t1.setName();  
            }
            
            //CITY NAME 
            else if (decision == 'b' || decision == 'B')
            {
                cout << cClear;
                drawSboard();
                menu3();
                cout << "\n\nCity name (3 letters MAX): ";
                t1.setHomeCity();
            }

            //TEAM SCORE 
            else if (decision == 'c' || decision == 'C')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu3();
                cout << "\n\nNew Score: ";
                validateInt(d);

                if (d >= 0 && d < 100)
                {
                  t1.setScore(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu3();
                  cout << "\n\n99 max";
                  cin.ignore(10000, '\n');
                }
              }while (d < 0 || d >= 100);
            }

            //TIMEOUT COUNT
            else if (decision == 'd' || decision == 'D')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu3();
                cout << "\n\nRemaining timeouts: ";
                validateInt(d);

                if (d == 0)
                {
                  t1.setTimeoutCount(d);
                }
                else if (d == 1)
                {
                  t1.setTimeoutCount(d);
                }
                else if (d == 2)
                {
                  t1.setTimeoutCount(d);
                }
                else if (d == 3)
                {
                  t1.setTimeoutCount(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu3();
                  cout << "\n\n3 MAX";
                  cin.ignore(10000, '\n');
                }
              }while (d < 0 || d >= 5);
            }

            //COACH NAME 
            else if (decision == 'e' || decision == 'E')
            {
                cout << cClear;
                drawSboard();
                menu3();
                cout << "\n\nCoach name: ";
                t1.setCoachName();
            }
          }while (decision != 'f' && decision != 'F');
        }

        //VISITORS TEAM OPTIONS
        else if (decision == 'c' || decision == 'C')
        {
          do
          {
            cout << cClear;
            drawSboard();
            menu4();

            cout << "\n\nINPUT: ";
            validateChar(decision);
            
            //TEAM NAME 
            if (decision == 'a' || decision == 'A')
            {
                cout << cClear;
                drawSboard();
                menu4();
                cout << "\n\nTeam name (15 letters MAX): ";
                t2.setName();  
            }
            
            //CITY NAME 
            else if (decision == 'b' || decision == 'B')
            {
                cout << cClear;
                drawSboard();
                menu4();
                cout << "\n\nCity name (3 letters MAX): ";
                t2.setHomeCity();
            }

            //TEAM SCORE 
            else if (decision == 'c' || decision == 'C')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu4();
                cout << "\n\nNew score: ";
                validateInt(d);

                if (d >= 0 && d < 100)
                {
                  t2.setScore(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu4();
                  cout << "\n\n99 MAX";
                  cin.ignore(10000, '\n');
                }
              }while (d < 0 || d >= 100);
            }

            //TIMEOUT COUNT 
            else if (decision == 'd' || decision == 'D')
            {
              int d = -1;

              do
              {
                cout << cClear;
                drawSboard();
                menu4();
                cout << "\n\nRemaining timeouts: ";
                validateInt(d);

                if (d == 0)
                {
                  t2.setTimeoutCount(d);
                }
                else if (d == 1)
                {
                  t2.setTimeoutCount(d);
                }
                else if (d == 2)
                {
                  t2.setTimeoutCount(d);
                }
                else if (d == 3)
                {
                  t2.setTimeoutCount(d);
                }
                else 
                {
                  cout << cClear;
                  drawSboard();
                  menu4();
                  cout << "\n\n3 MAX";
                  cin.ignore(10000, '\n');
                }
              }while (d < 0 || d >= 5);
            }

            //COACH NAME 
            else if (decision == 'e' || decision == 'E')
            {
                cout << cClear;
                drawSboard();
                menu4();
                cout << "\n\nCoach name: ";
                t2.setCoachName();
            }
          }while (decision != 'f' && decision != 'F');
        }
      } while (decision != 'x' && decision != 'X'); //GAME OVER
      cin.clear();
    }
};
#endif