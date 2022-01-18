#include "Game.h"
#include <iomanip>


//print method for game that displays its data in a specific format 
void Game::print()
{
    std::cout << "High Score: " << highscore << std::endl;
    std::cout << "Initials: " << initials << std::endl;
    std::cout << "Plays: " << plays << std::endl;
    std::cout << "Revenue: $" << std::setprecision(2) << std::fixed << revenue << std::endl;
}

//overloaded insertion operator that displays the objects data in a single line 
std::ostream& operator<< (std::ostream& out, const Game& g)
{

    out << g.name << ", " << g.highscore << ", " << g.initials << ", " << g.plays << ", $" << std::setprecision(2) << std::fixed << g.revenue;
  return out;
}

