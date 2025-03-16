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

    void createOut();

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
};