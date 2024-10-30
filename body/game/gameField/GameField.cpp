#include "GameField.h"

GameField::GameField(string *path, int type)
{
    this->path = *path;
    this->type = type;
    this->create();
}

GameField::~GameField()
{
    this->drawCell = nullptr;
    
    if (this->miniMap != nullptr)
    {
        delete this->miniMap;
        this->miniMap = nullptr;
    }
    this->field.forEach([](Array<ProtoObj *> arr)
                        {
        arr.forEach([](ProtoObj *cell){
            delete cell;
            cell = nullptr;
        });
        arr.clear(); });
    this->field.clear();
}
