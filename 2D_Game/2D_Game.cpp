#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.cpp"

int main()
{
    //create game
    float gridSizeF = 32.f;
    unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
    float dt = 0.f;
    sf::Clock dtClock;

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Adventure");
    
    //character moving speed
    float shapeSpeed = 100.f;

    // define the level with an array of tile indices
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 3, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 2, 3, 3, 3, 0, 0, 3, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 3, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 3, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 2, 3, 2, 2, 2, 0, 3, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 2, 3, 2, 2, 2, 0, 3, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 3, 3, 2, 0, 3, 2, 0, 1, 1, 1, 1,
        0, 0, 1, 2, 0, 2, 3, 2, 0, 3, 2, 2, 1, 1, 1, 1,
        0, 2, 1, 0, 2, 2, 3, 3, 3, 3, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 2, 2, 2, 2, 2, 0, 0, 2, 0, 1, 1, 1, 1,
        2, 0, 1, 0, 0, 2, 2, 2, 0, 2, 0, 0, 1, 1, 1, 1,
        0, 2, 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("Textures/tileset.png", sf::Vector2u(32, 32), level, 16, 16))
        return -1;
        
    //create a character
    sf::Texture playerTex;
    sf::Sprite player;

    if (!playerTex.loadFromFile("Textures/character.png"))
       throw "Could not load character.png";

    player.setTexture(playerTex);
    player.setScale(sf::Vector2f(0.3f, 0.3f));

    std::vector<sf::Sprite> characters;

    // run the main loop
    while (window.isOpen())
    {
        //update dt
        dt = dtClock.restart().asSeconds();


        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //update input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Left 
        {
            player.move(-shapeSpeed * dt, 0.f);
            player.setScale(sf::Vector2f(-0.3f, 0.3f));
            
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Right 
        {
            player.move(shapeSpeed * dt, 0.f);
            player.setScale(sf::Vector2f(0.3f, 0.3f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //up 
        {
            player.move(0.f, -shapeSpeed * dt);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //down 
        {
            player.move(0.f, shapeSpeed * dt);
        }

        //render
        window.clear();
        
        // draw the map
        window.draw(map);

        //draw player
        window.draw(player);

        window.display();
    }

    return 0;




    /*sf::RenderWindow window(sf::VideoMode(1280, 768), "Monopoly Demo");
    window.setFramerateLimit(60);

    //draw an object
    sf::RectangleShape rect;
    sf::Vector2f rectanglePosition(600, 350);

    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(128, 128));

    //position for the object
    float xVelocity = 3;
    float yVelocity = 3;

    //start field
    sf::Texture startTex;
    sf::Sprite start;

    if (!startTex.loadFromFile("Textures/start.png")) {
    
        throw "Could not load start.png";
    }

    start.setTexture(startTex);

    std::vector<sf::Sprite> fields;

    //close window with escape or click on x with mouse
    while (window.isOpen()) {
    
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        }

        //click on left mouse button and the object is moving in one pixel
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                //"physics"
                if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 128) xVelocity *= -1;
                if (rectanglePosition.y < 0 || rectanglePosition.y > 768 - 128) yVelocity *= -1;

                rectanglePosition.x += xVelocity;
                rectanglePosition.y += yVelocity;
                rect.setPosition(rectanglePosition);

                
            }
        }

        //render
        window.clear();

        window.draw(start);

        window.display();
    }

    return 0;*/
}