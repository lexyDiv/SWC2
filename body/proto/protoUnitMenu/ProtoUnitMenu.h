#include "buttonData/ButtonData.cpp"

struct Lambda
{
    function<string(ProtoObj *unit)> fn = [](ProtoObj *unit)
    {
        return "";
    };
};

struct UpgradeData
{
    Image *image = imager.icons;
    int animX = 0;
    int animY = 0;
    int animWidth = 100;
    int animHeight = 100;
    int compliteCount = 1;
    int currentCount = 1;
};

class ProtoUnitMenu
{
public:
    ProtoUnitMenu();
    virtual ~ProtoUnitMenu();
    virtual void create();
    virtual void createShaht();
    virtual void createPeon();

    // int titleMenuX = 0;
    // int titleMenuY = 0;

    function<Point(ProtoObj *unit)> titleMenuXY = [](ProtoObj *unit)
    {
        Point point = {x : 0, y : 0};
        return point;
    };

    bool isButtons = false;

    ProtoObj *unit = nullptr;
    Array<Lambda> infoLines;
    // Array<Array<ButtonData*>> buttonsData;
    Array<Array<Array<ButtonData *>>> buttonsData;

    ///////////////////////////  upgrade
    function<UpgradeData(ProtoObj *unit)> upgrade = [](ProtoObj *unit)
    {
        UpgradeData upgradeData;
        return upgradeData;
    };
    //////////////////////////

    function<bool(ProtoObj *unit)> getIsHp = [](ProtoObj *unit)
    {
        return false;
    };

    function<bool(ProtoObj *unit)> getIsMana = [](ProtoObj *unit)
    {
        return false;
    };

    function<bool(ProtoObj *unit)> getIsUpgrade = [](ProtoObj *unit)
    {
        return false;
    };

    function<string(ProtoObj *unit)> getTitleName = [](ProtoObj *unit)
    {
        return "";
    };

    ////////////////////////// get way
    //     bool isOnGetPotentialWayGetTarget(ProtoObj *cell) override;
    // bool isNewCellOnGetWayValide(ProtoObj *cell) override;
    //////////////////////////

    //     ProtoObj *left = nullptr;
    // ProtoObj *right = nullptr;
    // ProtoObj *top = nullptr;
    // ProtoObj *bottom = nullptr;
    // ProtoObj *top_left = nullptr;
    // ProtoObj *top_right = nullptr;
    // ProtoObj *bottom_left = nullptr;
    // ProtoObj *bottom_right = nullptr;

    double speed = 0;
    double cellSize = 48;
    double degDis = 67.882251;
    double wayTaktCountForward = 0;
    double wayTaktCountDeg = 0;

   // double conor = 0;      // radToDeg(135);
    double leftDeltaX = 0; // cos(conor) * 1;
    double leftDeltaY = 0; // sin(conor) * 1;
    double conorLeft = 0;
    double rightDeltaX = 0; // cos(conor) * 1;
    double rightDeltaY = 0; // sin(conor) * 1;
    double conorRight = 0;
    double topDeltaX = 0; // cos(conor) * 1;
    double topDeltaY = 0; // sin(conor) * 1;
    double conorTop = 0;
    double bottomDeltaX = 0; // cos(conor) * 1;
    double bottomDeltaY = 0; // sin(conor) * 1;


    double conorBottom = 0;
    double top_leftDeltaX = 0; // cos(conor) * 1;
    double top_leftDeltaY = 0; // sin(conor) * 1;
    double conorTop_left = 0;
    double top_rightDeltaX = 0; // cos(conor) * 1;
    double top_rightDeltaY = 0; // sin(conor) * 1;
    double conorTop_right = 0;
    double bottom_leftDeltaX = 0; // cos(conor) * 1;
    double bottom_leftDeltaY = 0; // sin(conor) * 1;
    double conorBottom_left = 0;
    double bottom_rightDeltaX = 0; // cos(conor) * 1;
    double bottom_rightDeltaY = 0; // sin(conor) * 1;
    double conorBottom_right = 0;

    double moveDeltaX = 0;
    double moveDeltaY = 0;

    function<void(ProtoObj *unit, ProtoObj *nextCell)> getDeltasXY = [this](ProtoObj *unit, ProtoObj *nextCell)
    {
        double startDis = 0;
       // unit->wayTakts = 0;
        if (unit->cell->left == nextCell)
        {
            unit->wayDeltaX = this->leftDeltaX;
            unit->wayDeltaY = this->leftDeltaY;
            startDis = this->cellSize;
            unit->conor = this->conorLeft;
            unit->animX = 6 * unit->animGabX;
        }
        else if (unit->cell->right == nextCell)
        {
            unit->wayDeltaX = this->rightDeltaX;
            unit->wayDeltaY = this->rightDeltaY;
            startDis = this->cellSize;
            unit->conor = this->conorRight;
            unit->animX = 2 * unit->animGabX;
        }
        else if (unit->cell->top == nextCell)
        {
            unit->wayDeltaX = this->topDeltaX;
            unit->wayDeltaY = this->topDeltaY;
            startDis = this->cellSize;
            unit->conor = this->conorTop;
            unit->animX = 0 * unit->animGabX;
        }
        else if (unit->cell->bottom == nextCell)
        {
            unit->wayDeltaX = this->bottomDeltaX;
            unit->wayDeltaY = this->bottomDeltaY;
            startDis = this->cellSize;
            unit->conor = this->conorBottom;
            unit->animX = 4 * unit->animGabX;
        }
        else if (unit->cell->top_left == nextCell)
        {
            unit->wayDeltaX = this->top_leftDeltaX;
            unit->wayDeltaY = this->top_leftDeltaY;
            startDis = this->degDis;
            unit->conor = this->conorTop_left;
            unit->animX = 7 * unit->animGabX;
        }
        else if (unit->cell->top_right == nextCell)
        {
            unit->wayDeltaX = this->top_rightDeltaX;
            unit->wayDeltaY = this->top_rightDeltaY;
            startDis = this->degDis;
            unit->conor = this->conorTop_right;
            unit->animX = 1 * unit->animGabX;
        }
        else if (unit->cell->bottom_left == nextCell)
        {
            unit->wayDeltaX = this->bottom_leftDeltaX;
            unit->wayDeltaY = this->bottom_leftDeltaY;
            startDis = this->degDis;
            unit->conor = this->conorBottom_left;
            unit->animX = 5 * unit->animGabX;
        }
        else if (unit->cell->bottom_right == nextCell)
        {
            unit->wayDeltaX = this->bottom_rightDeltaX;
            unit->wayDeltaY = this->bottom_rightDeltaY;
            startDis = this->degDis;
            unit->conor = this->conorBottom_right;
            unit->animX = 3 * unit->animGabX;
        }
        
        startDis -= unit->speedTale;
        double preTakts = startDis / this->speed;
        int preTaktsFloor = floor(preTakts);
        unit->speedTale = preTakts - preTaktsFloor;
        unit->wayTakts = preTaktsFloor;
        // if (unit->speedTale) {
        //     unit->wayTakts ++;
        // };
        console.log("unit->speedTale = " + to_string(unit->speedTale));
    };
};
