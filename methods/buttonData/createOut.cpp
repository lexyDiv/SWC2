#include "../button/create.cpp"

void ButtonData::createOut()
{

    this->infoString = [](ProtoObj *unit)
    {
        return "Close menu";
    };

    this->getImage = [](ProtoObj *unit)
    {
        return imager.close;
    };

    this->onClick = [](ProtoObj *unit)
    {
        unit->gf->game->objMenu->defaultData();
    };

    this->update = [this](ProtoObj *unit)
    {
        return this;
    };

    this->priceType = "";

    this->animGabX = 256;
    this->animGabY = 256;
};