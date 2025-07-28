#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;
public:
    Item(const std::string& name);
    virtual ~Item() = default;
    void setName(const std::string& newName);
    std::string getName() const;
};

#endif // ITEM_H

