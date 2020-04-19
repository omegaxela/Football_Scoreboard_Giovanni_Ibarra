//Class Team

#ifndef TEAM_H
#define TEAM_H

#include "Input_Validation_Extended.h"

class Team 
{
  private:
    char name[100] = {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','\0'};
    char coachName[100];
    char homeCity[100] = {'X','X','X','\0'};
    bool homeStatus;
    short int score;
    short int timeoutCount;
  public:
    Team()
    {
      homeStatus = true;
      score = 0;
      timeoutCount = 3;
    }

    void setName()
      {
        char n[100];
        cin.getline(n, 100);
        for (int i = 0; i < 14; i++) 
            name[i] = n[i];
      }
    void setCoachName()
      {cin.getline(coachName, 100);}
    void setHomeCity()
      {
        char n[100];
        cin.getline(n, 100);
        for (int i = 0; i < 3; i++)
          homeCity[i] = n[i];
      }
    void setHomeStatus(bool hs)
      {homeStatus = hs;}
    void setScore(short int s)
      {score = s;}
    void setTimeoutCount(short int toc)
      {timeoutCount = toc;}
    
    string getName() const
      {
        string n = name;
        return n;
      }
    string getCoachName() const
      {
        string cn = coachName;
        return cn;
      }   
    string getHomeCity() const
      {
        string hc = homeCity;
        return hc;
      }
    bool getHomeStatus() const
      {return homeStatus;}
    short int getScore() const
      {return score;}
    short int getTimeoutCount() const
      {return timeoutCount;}
}; 
#endif