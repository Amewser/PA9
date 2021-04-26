/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#pragma once

#include <iostream>
#include <string>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Player.h"
#include "Menu.h"
#include "MainMenu.h"

class Game
{
public:
    // Constructor
    Game();

    /*
        Function: runGame()
        Author: Alex Carbajal
        Date Created: 04/23/2021
        Date Last Modified: 04/24/2021
        Description: Runs the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The game runs.
    */
    void runGame(void);
private:
    sf::RenderWindow gameWindow;
    sf::Event event;
    Player player;
    Menu* currentMenu;
    MainMenu mainMenu;
    bool changingMenu; // Whether the game will be changing to another menu
    std::string menuName; // The menus name
    sf::Sound beep; // Blip sound in the menu
    sf::SoundBuffer beepUp;
    sf::SoundBuffer beepDown;
    sf::SoundBuffer beepSelect;

    /*
        Function: startGame()
        Author: Alex Carbajal
        Date Created: 04/23/2021
        Date Last Modified: 04/23/2021
        Description: Starts the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The game starts.
    */
    void startGame(void);

    /*
        Function: loadMenu()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/24/2021
        Description: Loads all the assets for the current menu in the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: All the assets for the current menu are loaded.
    */
    void loadMenu(void);

    /*
        Function: drawMenuText()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/24/2021
        Description: Draws all the text for the current menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: All the text for the current menu is displayed.
    */
    void drawMenuText(void);

    /*
        Function: drawBackground()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/24/2021
        Description: Draws the background for the current menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The background for the current menu gets draw.
    */
    void drawBackground(void);

    /*
        Function: drawRectangleArtMainMenu()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/25/2021
        Description: Draws rectangle art on the main menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Rectangle art is drawn on the main menu.
    */
    void drawRectangleArtMainMenu(void);

    /*
        Function: drawMarker()
        Author: Alex Carbajal
        Date Created: 04/25/2021
        Date Last Modified: 04/25/2021
        Description: Draws the marker on the menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Marker is drawn on the menu.
    */
    void drawMarker(void);

    /*
        Function: markerMovementMainMenu()
        Author: Alex Carbajal
        Date Created: 04/25/2021
        Date Last Modified: 04/25/2021
        Description: Allows for marker movement on the main menu.
                     Plays sounds for the marker.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Marker movement is allowed on the main menu.
    */
    void markerMovementMainMenu(void);
};