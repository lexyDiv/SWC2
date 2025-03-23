#include "../../protoObj/ProtoObj.cpp"

class ButtonData
{
public:
    ButtonData();
    ~ButtonData();
    int animX = 0;
    int animY = 0;
    int animGabX = 0;
    int animGabY = 0;

    string priceType = "";

    void createOut();
    void createVoid();

    function<string(ProtoObj *unit)> infoString = [](ProtoObj *unit)
    {
        return "";
    };
    function<Image *(ProtoObj *unit)> getImage = [](ProtoObj *unit)
    {
        return nullptr;
    };
    function<void(ProtoObj *unit)> onClick = [](ProtoObj *unit) {};

    function<ButtonData *(ProtoObj *unit)> update = [](ProtoObj *unit)
    {
        return nullptr;
    };

    /////////////// price

    function<bool(ProtoObj *unit)> isManaOk = [](ProtoObj *unit)
    {
        return true;
    };

    function<bool(ProtoObj *unit)> isGoldOk = [](ProtoObj *unit)
    {
        return true;
    };

    function<bool(ProtoObj *unit)> isOilOk = [](ProtoObj *unit)
    {
        return true;
    };

    function<bool(ProtoObj *unit)> isWoodOk = [](ProtoObj *unit)
    {
        return true;
    };

    function<string(ProtoObj *unit)> goldPriceInfo = [](ProtoObj *unit)
    {
        string priceInfo = "";
        return priceInfo;
    };

    function<string(ProtoObj *unit)> oilPriceInfo = [](ProtoObj *unit)
    {
        string priceInfo = "";
        return priceInfo;
    };

    function<string(ProtoObj *unit)> woodPriceInfo = [](ProtoObj *unit)
    {
        string priceInfo = "";
        return priceInfo;
    };

    function<string(ProtoObj *unit)> manaPriceInfo = [](ProtoObj *unit)
    {
        string priceInfo = "";
        return priceInfo;
    };

    function<bool(ProtoObj *unit)> isPriceOk = [this](ProtoObj *unit)
    {
        if (this->priceType == "res")
        {
            return bool(this->isGoldOk(unit) && this->isOilOk(unit) && this->isWoodOk(unit));
        }
        else if (this->priceType == "mana")
        {
            return bool(this->isManaOk(unit));
        }
        else
        {
            return true;
        }
    };
};

class ButtonDataHub
{
public:
    ButtonDataHub()
    {
        this->outButtonData->createOut();
    };
    ~ButtonDataHub()
    {
        delete this->outButtonData;
        this->outButtonData = nullptr;

        delete this->voidButtonData;
        this->voidButtonData = nullptr;
    };

    ButtonData *outButtonData = new ButtonData;
    ButtonData *voidButtonData = new ButtonData;
};

ButtonDataHub buttonDataHub;