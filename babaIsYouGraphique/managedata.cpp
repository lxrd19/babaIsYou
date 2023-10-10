#include "managedata.h"
#include <string>
#include <unordered_set>
#include "ispush.h"
#include "issink.h"
#include "isstop.h"
#include "iswin.h"
#include "isyou.h"
#include "iskill.h"
#include "movecommand.h"

ManageData::ManageData(Game& game): m_game(game){}

std::vector<Position> ManageData::getIsPositions(const std::vector<std::vector<Box>>& board)  {
    std::vector<Position> positions;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            auto box = board[i][j];
            auto objects = box.getObjects();
            for(const auto& obj : objects){

                if (obj.getName() == "is") {
                    positions.push_back(Position(i, j));
                }
            }
        }
    }

    return positions;
}

std::shared_ptr<ICommand> ManageData::handleUserInputUpdated(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    std::shared_ptr<ICommand> command;
    if(!isUppercase(tokens[0])){
        turnToUpperCase(tokens[0]);
    }
    if(tokens[0] != "MOVE"){
        throw std::invalid_argument("First token invalid : Enter \" move or MOVE\"\n\n");
    }
    if (tokens.size() >= 2 && tokens[0] == "MOVE") {
        if(!isUppercase(tokens[1])){
            turnToUpperCase(tokens[1]);
        }
        checkDirection(tokens[1], "Last token invalid : Enter one of the following \"UP, or up\", \"RIGHT or right\", \"DOWN or down\", \"LEFT, left\".\n\n");
        command =  std::make_shared<MoveCommand>(tokens, m_game);
    }
    return command;
}

bool ManageData::isRuleComponantName(const std::string& name) {
    if(name.empty()){
        return false;
    }

    if (name.substr(0, 5) == "text_") {
        return true;
    }

    if (name == "is") {
        return true;
    }

    const std::vector<std::string> effects = {"push", "kill", "sink", "win", "stop", "you"};
    for (const std::string& effect : effects) {
        if (name == effect) {
            return true;
        }
    }
    return false;
}

void ManageData::findVerticalRules(const std::vector<std::vector<Box>>& board,
                                   std::vector<std::unique_ptr<Irule>>& rules){
    std::unordered_set<std::string> validEffects{"push", "stop", "sink", "kill", "you", "win"};
    auto isPosition = getIsPositions(board);
    for(const auto& pos : isPosition){
        std::vector<Position> positions{};
        auto up = Direction::UP + pos;
        auto down = Direction::DOWN + pos;
        auto& box1 = board[up.getX()][up.getY()];
        auto& box2 = board[down.getX()][down.getY()];
        if(isInside(board, up) && isInside(board, down) && box1.isOccupied() && box2.isOccupied()){
            const std::string& elem1 = box1.getObjects().back().getName();
            const std::string& elem2 = box2.getObjects().back().getName();
            std::string element = (elem1.substr(0, 4) == "text") ? generateElementName(elem1) : generateElementName(elem2);
            std::string effect = (elem1.substr(0, 4) == "text") ? elem2 : elem1;
            if(!element.empty()){
                if(effect == "you"){
                    rules.emplace_back(std::make_unique<IsYou>(element, m_game));
                }else if (effect == "push"){
                    rules.emplace_back(std::make_unique<IsPush>(element, m_game));
                }else if (effect == "kill"){
                    rules.emplace_back(std::make_unique<IsKill>(element, m_game));
                }else if (effect == "sink"){
                    rules.emplace_back(std::make_unique<IsSink>(element, m_game));
                }else if (effect == "win"){
                    rules.emplace_back(std::make_unique<IsWin>(element, m_game));
                }else if (effect == "stop"){
                    rules.emplace_back(std::make_unique<IsStop>(element, m_game));
                }
            }

        }
        if(rules.size() == isPosition.size()){
            return;
        }
    }
}



void ManageData::findHorizontalRules(const std::vector<std::vector<Box>>& board,
                                     std::vector<std::unique_ptr<Irule>>& rules){
    std::unordered_set<std::string> validEffects{"push", "stop", "sink", "kill", "you", "win"};
    auto isPosition = getIsPositions(board);
    for(const auto& pos : isPosition){
        std::vector<Position> positions{};
        auto right = Direction::RIGHT + pos;
        auto left = Direction::LEFT + pos;
        auto& box1 = board[right.getX()][right.getY()];
        auto& box2 = board[left.getX()][left.getY()];
        if(isInside(board, right) && isInside(board, left) && box1.isOccupied() && box2.isOccupied()){
            const std::string& elem1 = box1.getObjects().back().getName();
            const std::string& elem2 = box2.getObjects().back().getName();
            std::string element = (elem1.substr(0, 4) == "text") ? generateElementName(elem1) : generateElementName(elem2);
            std::string effect = (elem1.substr(0, 4) == "text") ? elem2 : elem1;
            if(!element.empty()){
                if(effect == "you"){
                    rules.emplace_back(std::make_unique<IsYou>(element, m_game));
                }else if (effect == "push"){
                    rules.emplace_back(std::make_unique<IsPush>(element, m_game));
                }else if (effect == "kill"){
                    rules.emplace_back(std::make_unique<IsKill>(element, m_game));
                }else if (effect == "sink"){
                    rules.emplace_back(std::make_unique<IsSink>(element, m_game));
                }else if (effect == "win"){
                    rules.emplace_back(std::make_unique<IsWin>(element, m_game));
                }else if (effect == "stop"){
                    rules.emplace_back(std::make_unique<IsStop>(element, m_game));
                }
            }

        }
        if(rules.size() == isPosition.size()){
            return;
        }
    }
}
