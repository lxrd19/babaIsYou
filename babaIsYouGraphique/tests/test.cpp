#include "catch.hpp"
#include "game.h"

/**
 * Checks if a box contains a specific component.
 *
 * @param box The box to check.
 * @param component The component to search for.
 * @return True if the box contains the component, false otherwise.
 */
bool boxContainsComponent(const Box& box, const Composant& component){
    const auto& objects = box.getObjects();
    for (const auto& obj : objects){
        if (obj.getName() == component.getName()){
            return true;
        }
    }
    return false;
}

/**
 * Compares two game boards for equality.
 *
 * @param board1 The first game board.
 * @param board2 The second game board.
 * @return True if the boards are equal, false otherwise.
 */
bool compareBoards(const std::vector<std::vector<Box>>& board1, const std::vector<std::vector<Box>>& board2){
    if (board1.size() != board2.size()){
        return false;
    }

    for (size_t i = 0; i < board1.size(); ++i){
        if (board1[i].size() != board2[i].size()){
            return false;
        }
        for (size_t j = 0; j < board1[i].size(); ++j){
            const auto& box1 = board1[i][j];
            const auto& box2 = board2[i][j];

            if (box1.getObjects() != box2.getObjects()){
                return false;
            }
        }
    }

    return true;
}

/**
 * Compares two maps of components and positions for equality.
 *
 * @param map1 The first map.
 * @param map2 The second map.
 * @return True if the maps are equal, false otherwise.
 */
bool compareMaps(const std::vector<std::pair<Composant, Position>>& map1, const std::vector<std::pair<Composant, Position>>& map2) {
    if (map1.size() != map2.size()) {
        return false;
    }

    for (size_t i = 0; i < map1.size(); ++i) {
        if (!(map1[i].second == map2[i].second)) {
            return false;         }
    }
    return true;
}

FileManager manager;
auto vec1 = manager.readBoardFromFile("file/level_0.txt");
auto vec2 = manager.readBoardFromFile("file/level_1.txt");



TEST_CASE("Game::IsRuleComponent") {

    Game game = Game(vec1);
    SECTION("Wrong data")
    {
        REQUIRE(false == game.isRuleComponantName("hey"));
    }
    SECTION("Valid data")
    {
        REQUIRE(true == game.isRuleComponantName("you"));
    }

}

TEST_CASE("Game::addRuleComponentPosition") {
    Game game = Game(vec1);

    game.addRuleComponentPosition();

    SECTION("Rule not applied yet")
    {
        REQUIRE(12 == game.getPushPosition().size());
    }

    SECTION("Rule applied")
    {
        game.findNewRules();
        game.applyRules();
        game.addRuleComponentPosition();
        REQUIRE(15 == game.getPushPosition().size());
    }

}


TEST_CASE("Game::addComponentsToBoard") {
    Game game = Game(vec1);
    std::vector<std::pair<Composant, Position>> map{
        {Composant("wall"), Position(2, 3)},
        {Composant("metal"), Position(5, 6)}

    };
    game.addComponentsToBoard(map);

    auto board = game.getBoard();
    SECTION("check composant in the board")
    {
        REQUIRE(Composant("wall") == board[2][3].getObjects().back());
        REQUIRE(Composant("metal") == board[5][6].getObjects().back());
    }

}

TEST_CASE("Game::removeFromBoard") {
    Game game = Game(vec1);
    std::vector<std::pair<Composant, Position>> map{
        {Composant("wall"), Position(2, 3)},
        {Composant("metal"), Position(5, 6)}

    };
    game.addComponentsToBoard(map);

    game.removeFromBoard(map);

    auto board = game.getBoard();
    SECTION("Componant cleared from the board at the given position contained in the map ")
    {
        REQUIRE(board[2][3].isEmpty());
        REQUIRE(board[5][6].isEmpty());
    }

}


TEST_CASE("Game::move") {
    Game game = Game(vec1);
    game.move(Direction::RIGHT);
    auto pos1 = game.getYouPosition().back();
    game.move(Direction::UP);
    auto pos2 = game.getYouPosition().back();

    SECTION("check player mouvement")
    {
        REQUIRE(!(pos1 == pos2));
    }

}

TEST_CASE("Game::move Player on Board bound") {
    Game game = Game(vec1);
    for(int i = 0; i <= 6 ; ++i){
        game.move(Direction::LEFT);
    }

    Position pos1 = game.getYouPosition().back();
    game.move(Direction::LEFT);
    Position pos2 = game.getYouPosition().back();

    SECTION("player on board left boundary")
    {
        REQUIRE (pos1 == pos2);
    }

}

TEST_CASE("Game::applyDirection") {
    Game game = Game(vec1);
    std::vector<std::pair<Composant, Position>> map1{
        {Composant("wall"), Position(2, 3)},
        {Composant("metal"), Position(5, 6)}

    };
    std::vector<std::pair<Composant, Position>> map2{
        {Composant("wall"), Position(2, 4)},
        {Composant("metal"), Position(5, 7)}

    };
    game.applyDirection(map1, Direction::RIGHT);

    auto board = game.getBoard();
    SECTION("check new Position in the map")
    {
        REQUIRE(compareMaps(map1, map2));
    }

}


TEST_CASE("Game::findNewRules") {
    Game game = Game(vec1);
    for(int i = 0; i < 3; ++i){
        game.move(Direction::LEFT);
    }
    for(int i = 0; i < 3 ; ++i){
        game.move(Direction::UP);
    }
    for(int i = 0; i < 2; ++i){
        game.move(Direction::RIGHT);
    }
    game.move(Direction::UP);
    game.findNewRules();
    SECTION("One Rule destroyed")
    {
        REQUIRE (3 == game.getIrule().size());
    }
}


TEST_CASE("Game::load") {
    Game game = Game(vec1);
    auto board = game.getBoard();
    game.load();
    auto boardAfterLoading = game.getBoard();
    SECTION("Checking board after loading")
    {
        REQUIRE(!compareBoards(board, boardAfterLoading));
    }

}

TEST_CASE("Game::clearPosition"){
    Game game = Game(vec1);
    std::vector<Position>positions{Position(2, 3),Position(4, 4)};

    game.getBestPosition() = positions;

    game.getSinkPosition() = positions;

    game.getYouPosition() = positions;

    game.getKillPosition() = positions;

    game.getWinPosition() = positions;

    game.getPushPosition() = positions;

    game.getStopPosition() = positions;

    game.clearPositions();

    bool sameSize = game.getBestPosition().size() == 0 &&
                    game.getYouPosition().size() == 0 &&
                    game.getStopPosition().size() == 0 &&
                    game.getPushPosition().size() == 0 &&
                    game.getSinkPosition().size() == 0 &&
                    game.getWinPosition().size() == 0;
    SECTION("All cleared"){
        REQUIRE(true == sameSize);
    }
}


TEST_CASE("FileManager::changeLevel"){
    auto expected = manager.changeLevel();
    SECTION("update to level1"){
        REQUIRE(compareBoards(vec2, expected));
    }
}

TEST_CASE("FileManager::save"){
    Game game = Game(vec1);
    for(int i = 0; i < 3; ++i){
        game.move(Direction::LEFT);
    }

    auto expected = game.getBoard();
    manager.save(expected);

    auto loaded = manager.load();
    SECTION("saving current level"){
        REQUIRE(compareBoards(loaded, expected));
    }
}

TEST_CASE("Box::isEmpty"){

    Box box;
    SECTION("Empty box created"){
        REQUIRE(box.isEmpty());
    }
}

TEST_CASE("Box::removeFront"){
    Box box;
    box.addObject(Composant("wall"));
    box.addObject(Composant("metal"));
    auto size1 = box.getObjects().size();
    box.removeFront();
    auto size2 = box.getObjects().size();
    SECTION("Front object removed"){
        REQUIRE(size1 == 2);
        REQUIRE(size2 == 1);
    }
}

TEST_CASE("Box::removeLastObject"){
    Box box;
    box.addObject(Composant("wall"));
    box.addObject(Composant("metal"));
    box.addObject(Composant("baba"));
    box.addObject(Composant("rock"));
    auto size1 = box.getObjects().size();
    box.removeLastObject();
    auto size2 = box.getObjects().size();
    SECTION("Back object removed"){
        REQUIRE(size1 == 4);
        REQUIRE(size2 == 3);
    }
}

TEST_CASE("Box::removeComponent"){
    Box box;
    box.addObject(Composant("wall"));
    box.addObject(Composant("metal"));
    box.addObject(Composant("baba"));
    box.addObject(Composant("rock"));
    SECTION("removing specified component"){
        REQUIRE(boxContainsComponent(box, Composant("metal")));
        box.removeComponent(Composant("metal"));
        REQUIRE(!boxContainsComponent(box, Composant("metal")));
    }
}

TEST_CASE("Box::=="){
    Box box;
    box.addObject(Composant("wall"));
    box.addObject(Composant("metal"));
    box.addObject(Composant("baba"));
    box.addObject(Composant("rock"));
    Box box2;
    box2.addObject(Composant("wall"));
    box2.addObject(Composant("metal"));
    box2.addObject(Composant("baba"));
    box2.addObject(Composant("rock"));
    SECTION("Comparing two box"){
        REQUIRE(box == box2);
        box2.addObject(Composant("flag"));
        REQUIRE(!(box == box2));
    }
}

TEST_CASE("Box::clearObjects"){
    Box box;
    box.addObject(Composant("wall"));
    box.addObject(Composant("metal"));
    box.addObject(Composant("baba"));
    box.addObject(Composant("rock"));
    SECTION("clearing the box"){
        REQUIRE(box.getObjects().size() > 0);
        box.clearObjects();
        REQUIRE(box.isEmpty());
    }
}
