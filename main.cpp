#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

int main()
{
  sf::RenderWindow clockWindow(sf::VideoMode(600, 600), "Clock   by Tailsray", sf::Style::Close);

  time_t cloc;
  int hour = 0;
  int minute = 0;
  int second = 0;

  sf::Font timefont;
  timefont.loadFromFile("Hack.ttf");

  sf::Text timer;
  timer.setFont(timefont);
  timer.setPosition(175.f, 515.f);
  timer.setCharacterSize(50);
  timer.setFillColor(sf::Color::White);

  sf::CircleShape outliner(205.f, 360);
  outliner.setFillColor(sf::Color::Blue);
  outliner.setOutlineThickness(5);
  outliner.setOutlineColor(sf::Color::White);
  outliner.setPosition(95.f, 95.f);

  sf::ConvexShape hourPointer;
  hourPointer.setPointCount(3);
  hourPointer.setPoint(0, sf::Vector2f(10.f, 0.f));
  hourPointer.setPoint(1, sf::Vector2f(20.f, 120.f));
  hourPointer.setPoint(2, sf::Vector2f(0.f, 120.f));
  hourPointer.setOrigin(10.f, 100.f);
  hourPointer.setPosition(300.f, 300.f);
  hourPointer.setFillColor(sf::Color::White);
  hourPointer.setOutlineThickness(1);
  hourPointer.setOutlineColor(sf::Color::Black);

  sf::ConvexShape linee;
  linee.setPointCount(2);
  linee.setPoint(0, sf::Vector2f(50.f, 50.f));
  linee.setPoint(1, sf::Vector2f(200.f, 200.f));
  linee.setFillColor(sf::Color::White);

  sf::ConvexShape minutePointer;
  minutePointer.setPointCount(3);
  minutePointer.setPoint(0, sf::Vector2f(20.f, 0.f));
  minutePointer.setPoint(1, sf::Vector2f(40.f, 180.f));
  minutePointer.setPoint(2, sf::Vector2f(0.f, 180.f));
  minutePointer.setOrigin(20.f, 160.f);
  minutePointer.setPosition(300.f, 300.f);
  minutePointer.setFillColor(sf::Color::White);
  minutePointer.setOutlineThickness(1);
  minutePointer.setOutlineColor(sf::Color::Black);

  sf::RectangleShape secondPointer(sf::Vector2f(6.f, 210.f));
  secondPointer.setOrigin(3.f, 190.f);
  secondPointer.setPosition(300.f, 300.f);
  secondPointer.setFillColor(sf::Color::White);
  secondPointer.setOutlineThickness(1);
  secondPointer.setOutlineColor(sf::Color::Black);

  while(clockWindow.isOpen())
  {
    sf::Event checker;
    while (clockWindow.pollEvent(checker))
      if (checker.type == sf::Event::Closed)
        clockWindow.close();

    cloc = time(NULL);
    hour = ((cloc % 86400) / 3600 + 3) % 24; //+3 надо поменять на +часовой_пояс, сами часовые пояса потом добавить
    minute = (cloc % 3600) / 60;
    second = cloc % 60;
    hourPointer.setRotation(hour * 30.f);
    minutePointer.setRotation(minute * 6.f);
    secondPointer.setRotation(second * 6.f);
    timer.setString((hour < 10 ? "0" : "") + std::to_string(hour) + ":" +
                    (minute < 10 ? "0" : "") + std::to_string(minute) + ":" +
                    (second < 10 ? "0" : "") + std::to_string(second));

    clockWindow.clear(sf::Color::Blue);
    clockWindow.draw(timer);
    clockWindow.draw(outliner);
    clockWindow.draw(secondPointer);
    clockWindow.draw(minutePointer);
    clockWindow.draw(hourPointer);
    clockWindow.display();
  }
}
