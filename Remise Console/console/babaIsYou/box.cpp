#include "box.h"

const std::vector<Composant>& Box::getObjects()const{
    return objects;
};

bool Box::isEmpty() const {
    return objects.empty();
}

void Box::removeFront(){
    if (!objects.empty()) {
        objects.erase(objects.begin());
    }
}

void Box::removeLastObject() {
    if (!objects.empty()) {
        objects.pop_back();
    }
}

void Box::setObjects(const std::vector<Composant>& newObjects) {
    objects = newObjects;
}

void Box::addObject(Composant el){
    objects.push_back(el);
}

bool Box::isOccupied() const {
    return objects.size()!= 0;
}

// In the Box class definition
bool Box::operator==(const Box& other)  {
    if (isOccupied() != other.isOccupied()|| objects.size() != other.objects.size()) {
        return false;
    }
    return std::equal(objects.begin(), objects.end(), other.objects.begin(), other.objects.end(),
                      [](const Composant& a, const Composant& b) {
        return a.getName() == b.getName();
    });
}

void Box::clearObjects(/*Box& box*/) {
    std::vector<Composant> newObjects;
    for (auto& obj : this->getObjects()) {
        if (isObjectRuleComponent(obj)) {
            newObjects.push_back(obj);
        }
    }
    this->setObjects(newObjects);
}

std::vector<Composant>& Box::getObjects() {
    return objects;
}

// this->objects.push_back(std::make_unique<GameObject>(*obj));
// this->objects.push_back(std::unique_ptr<GameObject>(obj));



/*
void Box::removeObject(GameObject* obj){
    if(std::find(this->objects.begin(), this->objects.end(),  obj) != this->objects.end()){
        this->objects.erase(std::find(this->objects.begin(), this->objects.end(),  obj));
    }
}
*/
