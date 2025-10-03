#include "getCurrentTargetCell.cpp"

void Peon::updateCurrentTarget()
{
    if (this->profession == "w")
    {
        ProtoObj *newTree = this->getAnyTree();
        if (newTree)
        {
            this->orderOnWay->isComplite = false;
            this->orderOnWay->cell = newTree->cell;
        }
        else
        {
            this->profession = "";
            this->targetObj.unit = nullptr;
            console.log("no tree 2");
        }
    }
    else if (this->profession == "g")
    {
        ProtoObj *newShaht = this->getAnyShaht();
        if (newShaht)
        {
            this->orderOnWay->isComplite = false;
            this->orderOnWay->cell = newShaht->cell;
        }
        else
        {
            this->profession = "";
            this->targetObj.unit = nullptr;
            console.log("no shaht");
        }
    }
    else
    {

       // this->profession = "";
        console.log("??? " + this->profession);
       // this->targetObj.unit = nullptr;
    }
};