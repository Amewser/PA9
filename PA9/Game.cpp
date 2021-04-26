/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Game.h"

Game::Game()
{
    gameWindow.create(sf::VideoMode(1920, 1080), "Square Lanes", sf::Style::Default);
    changingMenu = true;
    menuName = "main";
    beepUp.loadFromFile("Assets/Sound/up.flac");
    beepDown.loadFromFile("Assets/Sound/down.flac");
    beepSelect.loadFromFile("Assets/Sound/select.flac");
}

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
void Game::runGame(void)
{
    // Prevents tearing in the game
    gameWindow.setVerticalSyncEnabled(true);

    // Set the game window in the middle of the screen (assumes windows taskbar is at the bottom)
    gameWindow.setPosition(sf::Vector2i(
        (sf::VideoMode::getDesktopMode().width / 2) - (gameWindow.getSize().x / 2),
        (sf::VideoMode::getDesktopMode().height / 2) - (gameWindow.getSize().y / 2) - 45));

    while (gameWindow.isOpen())
    {
        startGame();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            runMenuProcesses();
        }
    }
}

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
void Game::startGame(void)
{
    // Execute a menu change if there is a new menu to be displayed
    if (changingMenu)
    {
        loadMenu();
        changingMenu = false;
    }

    // Menu is main
    if (menuName == "main")
    {
        gameWindow.clear();
        drawBackground();
        drawMenuText();
        drawRectangleArtMainMenu();
        gameWindow.draw(currentMenu->getMarker());
        gameWindow.display();
    }
}

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
void Game::loadMenu(void)
{
    // Set the current menu to be the next menu to be displayed
    if (menuName == "main")
    {
        currentMenu = &mainMenu;

        // Load all the assets
        currentMenu->loadFont();
        currentMenu->loadText();
        currentMenu->loadMusic();
        currentMenu->loadBackground();
        currentMenu->loadRectangles();
        currentMenu->loadMarker();
    }
}

void Game::runMenuProcesses(void)
{
    if (menuName == "main")
    {
        markerMovementMainMenu();
        selectMainMenuOption();
    }
}

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
void Game::drawMenuText(void)
{
    // Draw all the text for the current menu
    for (int i = 0; i < currentMenu->getMenuText().size(); ++i)
    {
        gameWindow.draw(currentMenu->getMenuText()[i]);
    }
}

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
void Game::drawBackground(void)
{
    gameWindow.draw(currentMenu->getBackground());
}

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
void Game::drawRectangleArtMainMenu(void)
{
    // Draw all the rectangles for the main menu
    for (int i = 0; i < currentMenu->getMenuRectangles().size(); ++i)
    {
        currentMenu->getMenuRectangles()[i].rotate(0.05f);
        gameWindow.draw(currentMenu->getMenuRectangles()[i]);
    }
}

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
void Game::markerMovementMainMenu(void)
{
    // A key press
    if (event.type == sf::Event::KeyPressed)
    {
        // Marker goes down when 'S' is pressed
        if ((event.key.code == sf::Keyboard::S) &&
            currentMenu->getMarkerPosition() < currentMenu->getMaxMarkerPosition())
        {
            currentMenu->getMarker().setPosition(sf::Vector2f(25.f,
                currentMenu->getMarker().getPosition().y + 97.f));

            beep.setBuffer(beepDown);
            beep.play();

            currentMenu->setMarkerPosition(currentMenu->getMarkerPosition() + 1);
        }

        // Marker goes up when 'W' is pressed
        if ((event.key.code == sf::Keyboard::W) &&
            currentMenu->getMarkerPosition() > currentMenu->getMinMarkerPosition())
        {
            currentMenu->getMarker().setPosition(sf::Vector2f(25.f,
                currentMenu->getMarker().getPosition().y - 97.f));

            beep.setBuffer(beepUp);
            beep.play();

            currentMenu->setMarkerPosition(currentMenu->getMarkerPosition() - 1);
        }
    }
}

/*
    Function: selectMainMenuOption()
    Author: Alex Carbajal
    Date Created: 04/25/2021
    Date Last Modified: 04/25/2021
    Description: Allows for selection of a main menu option.
                 Plays sounds for the selection.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Selection of a main menu option is allowed.
*/
void Game::selectMainMenuOption(void)
{
    if (event.type == sf::Event::KeyPressed)
    {
        // Select a menu option ('Enter')
        if (event.key.code == sf::Keyboard::Enter)
        {
            switch (currentMenu->getMarkerPosition())
            {
            case 1: // Play
                break;
            case 2: // Instructions
                break;
            case 3: // Exit
                gameWindow.close();
                break;
            default:
                std::cout << "Error: Invalid marker position in main menu" << std::endl;
                break;
            }

            beep.setBuffer(beepSelect);
            beep.play();
        }
    }
}