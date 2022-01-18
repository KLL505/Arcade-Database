#include <iostream>
#include <string>
#ifndef Game_h_
#define Game_h_

class Game
{
    private:
        std::string name, initials;
        int highscore, plays;
        double revenue; 
    public:
        Game(){name = initials = ""; highscore = plays =0; revenue = 0;}
        Game(std::string n, int hs, std::string ini, int p){name = n; initials = ini; highscore = hs; plays = p; revenue = p * .25;}
        Game(std::string n){name = n; initials = ""; highscore = plays = 0; revenue = 0;}
        Game(const Game& g){name = g.name; initials = g.initials; highscore = g.highscore; plays = g.plays; revenue = g.revenue;}
        void setName(std::string n){name = n;}
        void setInitials(std::string ini){initials = ini;}
        void setHighScore(int hs){highscore = hs;}
        void setPlays(int p){plays = p; revenue = p * .25;}
        std::string getName(){return name;}
        std::string getInitials(){return initials;}
        int getHighScore(){return highscore;}
        int getPlays(){return plays;}
        void print();
        bool operator> (Game g){return (name > g.name)?true:false;}
        bool operator< (Game g){return (name < g.name)?true:false;}
        bool operator> (std::string str){return (name > str)?true:false;}
        bool operator< (std::string str){return (name < str)?true:false;}
        void operator= (Game g){name = g.name; initials = g.initials; highscore = g.highscore; plays = g.plays; revenue = g.revenue;}
        bool operator== (std::string str){return (name == str)?true:false;}
        bool operator== (Game g){return (name == g.name)?true:false;}
        friend std::ostream& operator<<(std::ostream& out, const Game& g);
    
};
#endif