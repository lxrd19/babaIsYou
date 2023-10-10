#ifndef IRULE_H
#define IRULE_H
#include "box.h"
#include "composant.h"

class Irule{
protected:
    Composant m_composant;
    std::vector<Position> findAll(std::vector<std::vector<Box>>& board, Composant& toFind){
        std::vector<Position> positions;

        for(size_t i = 0; i < board.size(); ++i) {
            for(size_t j = 0; j < board[i].size(); ++j) {
                auto& box = board[i][j];
                if(!box.isEmpty()){
                    for(const auto& el : box.getObjects()){
                        if(!toFind.getName().compare(el.getName())){
                            positions.emplace_back(i, j);
                        }
                    }
                }
            }
        }
        return positions;
    }

public:
    void virtual apply(std::vector<std::vector<Box>>& board) = 0;
};

#endif // IRULE_H
