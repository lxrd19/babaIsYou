#include "game.h"
#include "movecommand.h"
#include "movecommandnoposition.h"


Game::~Game(){}

void Game::findCurrentPlayer(){
    std::string currentPlayerName;

    for (const Rule& rule : rules) {
        if (rule.getEffect() == "you") {
            currentPlayerName = rule.getElement();
            break;
        }
    }

    if (currentPlayerName.empty()) {
        return;
    }

    for (size_t row = 0; row < m_board.size(); ++row) {
        for (size_t col = 0; col < m_board[row].size(); ++col) {
            const Box& box = m_board[row][col];
            if (box.isOccupied()) {
                const std::vector<Composant>& objects = box.getObjects();
                for (const Composant& object : objects) {
                    if (object.getName() == currentPlayerName) {
                        player = object;
                        playerX = row;
                        playerY = col;
                        return;
                    }
                }
            }
        }
    }
}

Game::Game(const std::vector<std::vector<Box>>& board) : m_board(board)
{
    rules = extractRules();
    findCurrentPlayer();
}

void Game::detach(IObserver* observer){
    observers.pop_back();
}


const std::vector<std::vector<Box>>& Game::getBoard() const{
    return m_board;
}

void Game::notify() {
    for(auto& el : observers){
        el->update(this);
    }
}

Composant Game::getAt(const Position& pos){
    Composant res;
    if(!m_board[pos.getX()][pos.getY()].getObjects().empty()){

        res = m_board[pos.getX()][pos.getY()].getObjects().front();

    }
    return res;
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

Position Game::findComponentPosition(const std::string& componentName) {
    for (size_t i = 0; i < m_board.size(); ++i) {
        for (size_t j = 0; j < m_board[i].size(); ++j) {
            const Box& box = m_board[i][j];
            const auto& objects = box.getObjects();
            for (const auto& object : objects) {
                if (!componentName.compare(object.getName())) {
                    return Position(i, j);
                }
            }
        }
    }
    return Position(-1, -1);
}


bool Game::isElementInRules(const std::string& destElement) {
    for (const Rule& rule : rules) {
        if (rule.getElement() == destElement) {
            return true;
        }
    }
    return false;
}

Position Game::getBoxPosition(const Box& targetBox) const {
    for (size_t i = 0; i < m_board.size(); ++i) {
        for (size_t j = 0; j < m_board[i].size(); ++j) {
            if (&m_board[i][j] == &targetBox) {
                return Position(i, j);
            }
        }
    }
    return Position(-1, -1);
}



Box& Game::getBoxAtPosition(size_t x, size_t y) {
    if (x >= 0 && x < m_board.size() && y >= 0 && y < m_board[0].size()) {
        return m_board[x][y];
    } else {
        throw std::out_of_range("Invalid position");
    }
}


void Game::updateCurrentPlayer() {
    rules.clear();
    extractRules();
    for (const Rule& rule : rules) {
        if (rule.getEffect() == "you") {
            std::string newPlayerName = rule.getElement();
            if (newPlayerName == "baba") {
                if(!playerPositions.empty()){
                    playerPositions.clear();
                }
                for (size_t i = 0; i < m_board.size(); ++i) {
                    for (size_t j = 0; j < m_board[i].size(); ++j) {
                        Box& box = m_board[i][j];
                        if (box.isOccupied()) {
                            const Composant& composant = box.getObjects()[0];
                            if (composant.getName() == newPlayerName) {
                                player = box.getObjects()[0];
                                playerX = i;
                                playerY = j;
                                return;
                            }
                        }
                    }
                }
            } else {
                player = Composant(newPlayerName);
                playerPositions.clear();
                for (size_t i = 0; i < m_board.size(); ++i) {
                    for (size_t j = 0; j < m_board[i].size(); ++j) {
                        Box& box = m_board[i][j];
                        if (box.isOccupied()) {
                            for(const auto& composant : box.getObjects()){
                                if (composant.getName() == newPlayerName) {
                                    playerPositions.emplace_back(i, j);
                                }

                            }

                        }
                    }
                }
                playerX = -1;
                playerY = -1;
                return;
            }
        }
    }
}



void Game::handleUserInput(const std::string& input) {
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
    if (tokens.size() >= 4 && tokens[0] == "MOVE") {
        if(!isUppercase(tokens[3])){
            turnToUpperCase(tokens[3]);
        }
        checkInteger(tokens[1], "Second token invalid : Enter integer between 0 and 18.\n\n");
        checkInteger(tokens[2], "Third token invalid : Enter integer between 0 and 18.\n\n");

        checkDirection(tokens[3], "Last token invalid : Enter one of the following \"UP, or up\", \"RIGHT or right\", \"DOWN or down\", \"LEFT, left\".\n\n");
        command = std::make_shared<MoveCommand>(tokens, Direction::generateDir(tokens[3]), *this);
    }else if(tokens.size() == 2 && tokens[0] == "MOVE"){
        if(!isUppercase(tokens[1])){
            turnToUpperCase(tokens[1]);
        }
        checkDirection(tokens[1], "Last token invalid : Enter one of the following \"UP, or up\", \"RIGHT or right\", \"DOWN or down\", \"LEFT, left\".\n\n");
        command = std::make_shared<MoveCommandNoPosition>(tokens, *this);
    }

    executeCommandAndNotify(command);
}

bool Game::isInside(const Position& pos) const {
    size_t x = pos.getX();
    size_t y = pos.getY();

    return x >= 0 && x < m_board.size() && y >= 0 && y < m_board[0].size();
}

bool Game::areAllObjectsRuleComponents(const Box& box) {
    const std::vector<Composant>& objects = box.getObjects();

    if(objects.empty()){
        return false;
    }

    for (auto& obj : objects) {
        std::string name = obj.getName();

        if (name.compare("push") != 0 && name.compare("stop") != 0 && name.compare("is") != 0 &&
                name.compare("you") != 0 && name.compare("win") != 0 && name.compare("best") != 0 &&
                name.substr(0, 5).compare("text_") != 0) {
            return false;
        }
    }
    return true;
}


bool Game::isRuleComponantName(const std::string& name) {
    if(name.empty()){
        return false;
    }

    if (name.substr(0, 5) == "text_") {
        return true;
    }

    if (name == "is") {
        return true;
    }

    const std::vector<std::string> effects = {"push", "kill", "sink", "win", "stop"};
    for (const std::string& effect : effects) {
        if (name == effect) {
            return true;
        }
    }

    return false;
}


bool Game::isRuleApplicable(const std::string& element, const std::string& effect) const {

    for (const Rule& rule : rules) {
        if (rule.getElement() == element && rule.getEffect() == effect) {
            return true;
        }
    }
    return false;
}

bool Game::isBoxApplicable(const Box& box, const std::string& effect) const {
    for (const auto& obj : box.getObjects()) {
        const std::string& objName = obj.getName();

        for (const auto& rule : rules) {
            if (rule.getElement() == objName && rule.getEffect() == effect) {
                return true;
            }
        }
    }

    return false;
}

bool Game::isLastBoxApplicable(Box& startBox, const std::string& effect, Direction& dir) {
    std::string objectName = startBox.getObjects().back().getName();

    Position curPos = getPosition(startBox);

    while (true) {
        auto nextPos = dir + curPos ;

        if (!isInside(nextPos)) {
            break;
        }

        Box& nextBox = getBoxAtPosition(nextPos.getX(), nextPos.getY());

        if (nextBox.isOccupied() && (nextBox.getObjects().back().getName() == objectName || isRuleComponantName(nextBox.getObjects().back().getName()))) {
            curPos = nextPos;
        } else {
            break;
        }
    }

    curPos = dir + curPos;
    Box& endBox = getBoxAtPosition(curPos.getX(), curPos.getY());

    return isBoxApplicable(endBox, effect);
}


void Game::clearObjects(Box& box) {
    std::vector<Composant> newObjects;
    for (auto& obj : box.getObjects()) {
        if (isRuleComponantName(obj.getName())) {
            newObjects.push_back(obj);
        }
    }
    box.setObjects(newObjects);
}

void Game::pushRuleComponentBoxes(int startX, int startY, Direction dir) {
    Position currentPos(startX, startY);
    Position nextPos = dir + currentPos;

    while (isInside(nextPos)) {
        if (areAllObjectsRuleComponents(m_board[nextPos.getX()][nextPos.getY()])) {
            pushRuleComponentBoxes(nextPos.getX(), nextPos.getY(), dir);
        }

        for (const auto& obj : m_board[currentPos.getX()][currentPos.getY()].getObjects()) {
            m_board[nextPos.getX()][nextPos.getY()].addObject(obj);
        }
        m_board[currentPos.getX()][currentPos.getY()].clearObjects();

        currentPos = nextPos;
        nextPos =  dir + currentPos;
    }
    playerX = currentPos.getX();
    playerY = currentPos.getY();

    m_board[playerX][playerY].addObject(player);
    m_board[startX][startY].removeLastObject();
}

std::vector<std::pair<Composant, Position>> Game::getPushableComponentsInDirection(int startX, int startY, Direction dir) {

    std::vector<std::pair<Composant, Position>> pushableComponents{};

    Position currentPos(startX, startY);
    Position nextPos = dir + currentPos;

    Box& initialBox = m_board[startX][startY];
    auto  objects  =  initialBox.getObjects();
    for (const auto& obj : objects) {
        if (isRuleComponantName(obj.getName())) {
            pushableComponents.emplace_back(obj, currentPos);
        }
    }

    while (isInside(nextPos)) {
        Box& nextBox = m_board[nextPos.getX()][nextPos.getY()];

        if (nextBox.isEmpty()) {
            break;
        }
        if(nextBox.getObjects().size() == 1 && !areAllObjectsRuleComponents(nextBox)){
            break;
        }

        if (areAllObjectsRuleComponents(nextBox)) {
            for (const auto& obj : nextBox.getObjects()) {
                pushableComponents.emplace_back(obj, nextPos);
            }
        } else {
            bool hasRuleComponent = false;
            for (const auto& obj : nextBox.getObjects()) {
                if (isRuleComponantName(obj.getName())) {
                    hasRuleComponent = true;
                }
            }

            if (hasRuleComponent) {
                for (const auto& obj : nextBox.getObjects()) {
                    if (isRuleComponantName(obj.getName())) {
                        pushableComponents.emplace_back(obj, nextPos);
                    }
                }
            } else {
                for (const auto& obj : nextBox.getObjects()) {
                    if (isRuleApplicable(obj.getName(), "push")) {
                        pushableComponents.emplace_back(obj, nextPos);
                    }
                }
            }
        }

        currentPos = nextPos;
        nextPos = dir + currentPos;
    }

    return pushableComponents;

}



void Game::clearPushableComponentsFromBoard(const std::vector<std::pair<Composant, Position>>& pushableComponents) {
    for (const auto& componentPositionPair : pushableComponents) {
        const Position& position = componentPositionPair.second;

        Box& box = m_board[position.getX()][position.getY()];
        auto it = box.getObjects().begin();

        while (it != box.getObjects().end()) {
            if (isRuleComponantName(it->getName()) || isRuleApplicable(it->getName(), "push")) {
                it = box.getObjects().erase(it);
            } else {
                ++it;
            }
        }
    }
}



void Game::updatePositionsInMapWithDirection(std::vector<std::pair<Composant, Position>>& componentsPositions, Direction& dir) {
    std::vector<std::pair<Composant, Position>> updatedComponentsPositions;

    for (const auto& componentPositionPair : componentsPositions) {
        const Composant& component = componentPositionPair.first;
        Position position = componentPositionPair.second;

        position = dir + position;

        if (!isInside(position)) {
            componentsPositions.clear();
            return;
        }

        updatedComponentsPositions.push_back(std::make_pair(component, position));
    }

    componentsPositions = updatedComponentsPositions;
}



void Game::addComponentsToBoard(const std::vector<std::pair<Composant, Position>>& componentsPositions) {
    for (const auto& componentPositionPair : componentsPositions) {
        const Composant& component = componentPositionPair.first;
        const Position& position = componentPositionPair.second;

        Box& box = m_board[position.getX()][position.getY()];
        box.addObject(component);
    }
}



void Game::handleEffectsAfterPushingRuleComponents(int lastX, int lastY, Direction& dir, std::vector<std::vector<Box>>& board) {
    Position nextPos = dir + Position(lastX, lastY);

    if (!isInside(nextPos)) {
        return;
    }

    Box& nextBox = board[nextPos.getX()][nextPos.getY()];

    if (nextBox.isOccupied() && isRuleApplicable(nextBox.getObjects().back().getName(), "push")) {
        pushRuleComponentBoxes(lastX, lastY, dir);
    }
    else if (!nextBox.isOccupied()) {
        pushRuleComponentBoxes(lastX, lastY, dir);
    }
    else if (!areAllObjectsRuleComponents(nextBox)) {
        Box& lastBox = board[lastX][lastY];

        for (const auto& obj : lastBox.getObjects()) {
            if (isRuleComponantName(obj.getName())) {
                nextBox.addObject(obj);
            }
        }
        lastBox.clearObjects();
    }
}



int Game::getPlayerX(){
    return playerX;
}

int Game::getPlayerY(){
    return playerY;
}

Composant Game::getPlayer(){
    return player;
}

std::vector<Position> Game::getPlayerPositions(){
    return playerPositions;
}



void Game::movePlayerToNewPosition(const Position& pos, const Position& destPos) {
    m_board[destPos.getX()][destPos.getY()].addObject(m_board[pos.getX()][pos.getY()].getObjects().back());
    m_board[pos.getX()][pos.getY()].removeLastObject();
    if (playerPositions.empty()) {
        playerX = destPos.getX();
        playerY = destPos.getY();
    }
}

void Game::sinkPlayer(const Position& pos, const Position& destPos) {
    m_board[pos.getX()][pos.getY()].removeLastObject();
    m_board[destPos.getX()][destPos.getY()].getObjects().clear();
    playerX = -1;
    playerY = -1;
}


void Game::movePlayerToRuleComponentPosition(const Position& pos, const Position& destPos, Direction& dir) {
    auto nextRulePos = dir + Position(destPos.getX(), destPos.getY());
    auto& nextBox = m_board[nextRulePos.getX()][nextRulePos.getY()];
    nextBox.addObject(m_board[destPos.getX()][destPos.getY()].getObjects().back());
    m_board[destPos.getX()][destPos.getY()].removeLastObject();
    m_board[destPos.getX()][destPos.getY()].addObject(m_board[pos.getX()][pos.getY()].getObjects().back());
    m_board[pos.getX()][pos.getY()].removeLastObject();
    if (playerPositions.empty()) {
        playerX = destPos.getX();
        playerY = destPos.getY();
    }
}



void Game::pushRuleComponents(const Position& pos, const Position& destPos, Direction& dir, std::vector<std::pair<Composant, Position>>& pushables) {
    clearPushableComponentsFromBoard(pushables);
    updatePositionsInMapWithDirection(pushables, dir);
    if (!pushables.empty()) {
        addComponentsToBoard(pushables);
        m_board[destPos.getX()][destPos.getY()].addObject(m_board[pos.getX()][pos.getY()].getObjects().back());
        m_board[pos.getX()][pos.getY()].removeLastObject();
        if (playerPositions.empty()) {
            playerX = destPos.getX();
            playerY = destPos.getY();
        }
    }
}



void Game::applyEffectsAndMove(const Position& pos, const Position& destPos, int lastBoxX, int lastBoxY, Direction& dir, bool encountouredEmptyBox, bool ruleNotApplicableToLastBox) {
    auto playerBox = getBoxAtPosition(pos.getX(), pos.getY());
    auto playerComposant = playerBox.getObjects().back();

    if (isBoxApplicable(m_board[destPos.getX()][destPos.getY()], "win")) {
        this->fileManager.changeLevel(this->m_board);
        auto newPlayerPos = findComponentPosition("baba");
        if(!(player == m_board[newPlayerPos.getX()][newPlayerPos.getY()].getObjects().back())){
            player = m_board[newPlayerPos.getX()][newPlayerPos.getY()].getObjects().back();
        }
        playerX = newPlayerPos.getX();
        playerY = newPlayerPos.getY();
        return;
    } else if (isBoxApplicable(m_board[destPos.getX()][destPos.getY()], "kill") || isBoxApplicable(m_board[destPos.getX()][destPos.getY()], "sink")) {
        playerBox.removeLastObject();
    } else if (!isBoxApplicable(m_board[destPos.getX()][destPos.getY()], "stop")) {
        m_board[destPos.getX()][destPos.getY()].addObject(playerComposant);
        m_board[pos.getX()][pos.getY()].removeLastObject();
        if (playerPositions.empty()) {
            playerX = destPos.getX();
            playerY = destPos.getY();
        }
    }

    if (!ruleNotApplicableToLastBox && !encountouredEmptyBox) {
        auto posEnd = dir + Position(lastBoxX, lastBoxY);
        const std::string nextElement = m_board[posEnd.getX()][posEnd.getY()].isOccupied() ? m_board[posEnd.getX()][posEnd.getY()].getObjects().back().getName() : "";

        if (!nextElement.empty()) {
            if (isRuleApplicable(nextElement, "kill") || isRuleApplicable(nextElement, "sink")) {
                m_board[lastBoxX][lastBoxY].removeLastObject();
            } else if (!isRuleApplicable(nextElement, "kill") && !isRuleApplicable(nextElement, "sink")) {
                m_board[posEnd.getX()][posEnd.getY()].addObject(m_board[lastBoxX][lastBoxY].getObjects().back());
                m_board[lastBoxX][lastBoxY].removeLastObject();
            }
        }
    }
}


void Game::moveNonRuleComponent(const Position& pos, const Position& destPos, Direction& dir) {
    auto lastBoxX = destPos.getX();
    auto lastBoxY = destPos.getY();
    bool encountouredEmptyBox = false;
    bool ruleNotApplicableToLastBox = false;
    Direction curDir = dir;

    while (isRuleApplicable(m_board[lastBoxX][lastBoxY].getObjects().back().getName(), "push")) {
        auto nextPos = curDir + Position(lastBoxX, lastBoxY);

        if (!isInside(nextPos)) {
            break;
        }

        Box& nextBox = getBoxAtPosition(nextPos.getX(), nextPos.getY());
        if (!nextBox.isOccupied()) {
            nextBox.addObject(m_board[lastBoxX][lastBoxY].getObjects().back());
            m_board[lastBoxX][lastBoxY].removeLastObject();
            encountouredEmptyBox = true;
            break;
        }

        if (isRuleApplicable(nextBox.getObjects().back().getName(), "sink")||isRuleApplicable(nextBox.getObjects().back().getName(), "kill")) {
            m_board[lastBoxX][lastBoxY].getObjects().clear();
            nextBox.getObjects().clear();
            break;
        }else if (!isRuleApplicable(nextBox.getObjects().back().getName(), "push")) {
            if (isRuleApplicable(m_board[lastBoxX][lastBoxY].getObjects().back().getName(), "push")) {
                nextBox.addObject(m_board[lastBoxX][lastBoxY].getObjects().back());
                m_board[lastBoxX][lastBoxY].removeLastObject();
                ruleNotApplicableToLastBox = true;
            }
            break;
        }

        nextBox.addObject(m_board[lastBoxX][lastBoxY].getObjects().back());
        m_board[lastBoxX][lastBoxY].removeLastObject();
        lastBoxX = nextPos.getX();
        lastBoxY = nextPos.getY();
        curDir = dir;
    }

    applyEffectsAndMove(pos, destPos, lastBoxX, lastBoxY, dir, encountouredEmptyBox, ruleNotApplicableToLastBox);
}

void Game::handleNonRuleComponentName(const Position& pos, const Position& destPos, Direction& dir) {
    updateCurrentPlayer();
    auto destinationBox = getBoxAtPosition(destPos.getX(), destPos.getY());
    Composant nextComposant = destinationBox.getObjects().back();
    int lastBoxX = destPos.getX();
    int lastBoxY = destPos.getY();

    if (!isLastBoxApplicable(m_board[lastBoxX][lastBoxY], "stop", dir)) {
        moveNonRuleComponent(pos, destPos, dir);
    }
}


void Game::handleRuleComponentName(const Position& pos, const Position& destPos, Direction& dir) {
    auto startPosX = destPos.getX();
    auto startPosY = destPos.getY();
    if (!isLastBoxApplicable(m_board[startPosX][startPosY], "stop", dir)) {
        std::vector<std::pair<Composant, Position>> pushables{};
        pushables = getPushableComponentsInDirection(startPosX, startPosY, dir);
        if (pushables.empty()) {
            movePlayerToRuleComponentPosition(pos, destPos, dir);
        } else {
            pushRuleComponents(pos, destPos, dir, pushables);
        }
        updateCurrentPlayer();
    }
}




void Game::move(const Position& pos, Direction& dir) {
    rules.clear();
    rules = extractRules();

    if (!m_board[pos.getX()][pos.getY()].isEmpty()) {
        auto toMove = m_board[pos.getX()][pos.getY()].getObjects().back();

        if (toMove == player) {
            std::string destElement = "";
            auto playerBox = getBoxAtPosition(pos.getX(), pos.getY());
            auto destPos = dir + Position(pos.getX(), pos.getY());
            Composant playerComposant = playerBox.getObjects().back();
            if (!m_board[destPos.getX()][destPos.getY()].isEmpty()) {
                destElement = m_board[destPos.getX()][destPos.getY()].getObjects().back().getName();
            }

            if (destElement.empty() || (!isElementInRules(destElement) && !isRuleComponantName(destElement))) {
                movePlayerToNewPosition(pos, destPos);
                return;
            }

            if (!isRuleApplicable(destElement, "stop") && !m_board[destPos.getX()][destPos.getY()].isEmpty()) {
                if (isRuleApplicable(destElement, "sink")) {
                    sinkPlayer(pos, destPos);
                    return;
                }
                if (isRuleComponantName(destElement)) {
                    handleRuleComponentName(pos, destPos, dir);
                } else {
                    handleNonRuleComponentName(pos, destPos, dir);
                }
            }
        } else {
            std::cout << "You can only move the current player object: " << player.getName() << std::endl;
            return;
        }
    }
}

