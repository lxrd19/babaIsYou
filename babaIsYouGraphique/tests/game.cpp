#include "game.h"
#include <iterator>


Game::~Game(){}


Game::Game(const std::vector<std::vector<Box>>& board) : m_manageData(*this), m_board(board){}

std::vector<Position>& Game::getWinPosition(){
    return winPositions;
}

std::vector<Position>& Game::getBestPosition(){
    return bestPositions;
}

std::vector<Position>& Game::getStopPosition(){
    return stopPositions;
}


std::vector<Position>& Game::getKillPosition(){
    return killPositions;
}

std::vector<Position>& Game::getSinkPosition(){
    return sinkPositions;
}

std::vector<Position>& Game::getPushPosition(){
    return pushPositions;
}

std::vector<Position>& Game::getYouPosition(){
    return youPositions;
}

void Game::setPositions(std::vector<Position>& toSet, std::vector<Position>& newPositions){
    if(!toSet.empty()){
        toSet.pop_back();
    }
    toSet = newPositions;
}


void Game::detach(IObserver* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Game::clearPositions(){
    while(!pushPositions.empty()){
        pushPositions.pop_back();
    }
    while(!youPositions.empty()){
        youPositions.pop_back();
    }
    while(!sinkPositions.empty()){
        sinkPositions.pop_back();
    }
    while(!killPositions.empty()){
        killPositions.pop_back();
    }
    while(!stopPositions.empty()){
        stopPositions.pop_back();
    }
    while(!bestPositions.empty()){
        bestPositions.pop_back();
    }
    while(!winPositions.empty()){
        winPositions.pop_back();
    }
}

void Game::addRuleComponentPosition(){
    for(size_t i = 0; i < m_board.size(); ++i) {
        for(size_t j = 0; j < m_board[i].size(); ++j) {
            auto objects = m_board[i][j].getObjects();
            for(const auto& el : objects){
                if(m_manageData.isRuleComponantName(el.getName())){
                    pushPositions.emplace_back(i, j);
                }
            }
        }
    }
}

void Game::applyRules(){
    clearPositions();
    for(const auto& el : iRules){
        el->apply(m_board);
    }
}
const std::vector<std::vector<Box>>& Game::getBoard() const{
    return m_board;
}

void Game::notify() {
    for(auto& el : observers){
        el->update(this);
    }
}

void Game::attach(IObserver* observer){
    observers.push_back(observer);
}

void Game::executeCommandAndNotify(std::shared_ptr<ICommand> command) {
    if (command) {
        command->execute();
        notify();
    }
}

void Game::handleUserInputUpdated(const std::string& input) {
    auto command = m_manageData.handleUserInputUpdated(input);
    executeCommandAndNotify(command);
}

bool Game::isInside(const Position& pos) const {
    size_t x = pos.getX();
    size_t y = pos.getY();
    return x < m_board.size() && y < m_board[0].size();
}

bool Game::isRuleComponantName(const std::string& name) {
    return m_manageData.isRuleComponantName(name);
}



void Game::addComponentsToBoard(const std::vector<std::pair<Composant, Position>>& componentsPositions) {
    for (const auto& componentPositionPair : componentsPositions) {
        const Composant& component = componentPositionPair.first;
        const Position& position = componentPositionPair.second;

        Box& box = m_board[position.getX()][position.getY()];
        box.addObject(component);
    }
}

void Game::findNewRules(){
    iRules.clear();
    m_manageData.findHorizontalRules(m_board, iRules);
    m_manageData.findVerticalRules(m_board, iRules);
}

Composant Game::getPlayer(){
    return player;
}

void Game::removeFromBoard(const std::vector<std::pair<Composant, Position>>& pushableComponents) {
    for (const auto& pair : pushableComponents) {
        const Composant& component = pair.first;
        const Position& position = pair.second;
        Box& box = m_board[position.getX()][position.getY()];

        auto& objects = box.getObjects();
        for (auto it = objects.begin(); it != objects.end(); ) {
            if (*it == component) {
                it = objects.erase(it);
            } else {
                ++it;
            }
        }
    }
}

void Game::load(){
    m_board = m_fileManager.load();
}

void Game::save(){
    m_fileManager.save(m_board);
}

std::vector<std::unique_ptr<Irule>>& Game::getIrule(){
    return iRules;
}


void Game::applyDirection(std::vector<std::pair<Composant, Position>>& componentsPositions, Direction& dir) {
    std::vector<std::pair<Composant, Position>> updatedComponentsPositions;

    for (const auto& element : componentsPositions) {
        const Composant& component = element.first;
        Position position = element.second;

        auto nextPosition = dir + position;
        if(containsPosition(sinkPositions, nextPosition) || containsPosition(killPositions, nextPosition)){
            Box& currentBox = m_board[position.getX()][position.getY()];
            currentBox.removeComponent(component);
            if(containsPosition(sinkPositions, nextPosition)){
                Box& sinkBox = m_board[nextPosition.getX()][nextPosition.getY()];
                sinkBox.removeLastObject();
            }
            if(componentsPositions.size()==1){
                componentsPositions.clear();
            }
            return;
        }

        if (!isInside(nextPosition) || containsPosition(stopPositions, nextPosition)) {
            componentsPositions.clear();
            return;
        }

        updatedComponentsPositions.push_back(std::make_pair(component, nextPosition));
        componentsPositions = updatedComponentsPositions;
    }

}

void Game::setPlayer(Composant newPlayer){
    this->player = newPlayer;
}


void Game::movePlayer(Position pos, Direction dir){
    auto& startBox = m_board[pos.getX()][pos.getY()];
    startBox.removeComponent(player);
    auto nextPos = dir + pos;
    if(containsPosition(winPositions, nextPos)){
        m_board = m_fileManager.changeLevel();
        levelEnded = true;
        return;
    }
    auto& nextBox = m_board[nextPos.getX()][nextPos.getY()];
    nextBox.addObject(player);
}


void Game::move(Direction dir){
    findNewRules();
    applyRules();
    addRuleComponentPosition();
    for(const auto& pos : youPositions){
        player = m_board[pos.getX()][pos.getY()].getObjects().back();
        auto nextPos = dir + pos;
        if(isInside(nextPos)){
            if(containsPosition(pushPositions, nextPos)){
                std::vector<std::pair<Composant, Position>> toPush {};
                while(containsPosition(pushPositions, nextPos)){
                    auto component = m_board[nextPos.getX()][nextPos.getY()].getObjects().back();
                    toPush.emplace_back(component, nextPos);
                    nextPos = dir + nextPos;
                }
                auto saveToPush = toPush;
                applyDirection(toPush, dir);
                if(!toPush.empty()){
                    removeFromBoard(saveToPush);
                    addComponentsToBoard(toPush);
                    movePlayer(pos, dir);
                }
            }else if(containsPosition(sinkPositions, nextPos)){
                auto& nexBox = m_board[nextPos.getX()][nextPos.getY()];
                nexBox.removeLastObject();
                m_board[pos.getX()][pos.getY()].removeComponent(player);
            }else if(containsPosition(killPositions, nextPos)){
                m_board[pos.getX()][pos.getY()].removeComponent(player);
            }else if(!containsPosition(stopPositions, nextPos)){
                movePlayer(pos, dir);
                if(levelEnded){
                    levelEnded = false;
                    return;
                }
            }

        }
    }
}


