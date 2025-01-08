#include "../protoGameField/ProtoGameField.cpp"

class ProtoPlane;
struct Water;

class ProtoObj
{
public:
    ProtoObj();
    virtual ~ProtoObj();
    virtual void draw();
    virtual Color getMapColor();
    
    /////////
    virtual void create(ProtoObj* cell);
    ////////

    // all
    ProtoGameField *gf = nullptr;
    ProtoGame *game = nullptr;
    ProtoPlane *plane = nullptr;

    string type;
    float x = 0.0f;
    float y = 0.0f;
    float drawX = 0.0f;
    float drawY = 0.0f;
    float ver = 0;
    float hor = 0;

    int animX = 0;
    int animY = 0;
    int animGabX = 0;
    int animGabY = 0;
    int animStepX = 0;
    int animStepY = 0;
    int gabX = 0;
    int gabY = 0;
    int drawGabaritX = 120;
    int drawGabaritY = 120;
    int centerX = 0;
    int centerY = 0;

    Image *image = nullptr;

    // units
    bool isActive = false;
    bool isAddOnDraw = false;
    int speed = 0;
    int hp = 0;
    int attack = 0;
    int armor = 0;
    int mana = 0;
    ProtoObj *cell = nullptr;
    Array<ProtoObj *> enemys;
    Array<ProtoObj *> myWay;
    Array<ProtoObj *> cells2X2;
    Array<ProtoObj *> contactCells;
 

    // cells

    ProtoObj *groundUnit = nullptr;
    ProtoObj *flyUnit = nullptr;
    Array<ProtoObj *> aroundCells;
    Array<ProtoObj *> maxAroundCells;
    Array<double> maxAroundCellsDis;
    Array<ProtoObj *> drawCells;
    Array<Array<ProtoObj *>> cellsOnDraw;
    Array<ProtoObj *> ripUnits;
    Array<ProtoObj *> landDecorationObjs;

    ProtoObj* left = nullptr;
    ProtoObj* right = nullptr;
    ProtoObj* top = nullptr;
    ProtoObj* bottom = nullptr;
    ProtoObj* top_left = nullptr;
    ProtoObj* top_right = nullptr;
    ProtoObj* bottom_left = nullptr;
    ProtoObj* bottom_right = nullptr;

   // Array<ProtoObj *> guardCells;
    Array<ProtoObj *> booms;
    Array<ProtoObj *> bullets;
    ProtoObj *continent = nullptr;
    Color mapColor = {R : 0, G : 0, B : 0};
    char litera;
    int lineToOtherPlaneNumber = 0;
    int lineToTreeNumber = 0;
    int LineToMountNumber = 0;
    int lineToDarckGround = 0;
    int cellDrawIndex = 0;
    Array<Water *> waters;
    Image *cellImage = nullptr;
    Image *cellImage2 = nullptr;
    Image *cellImage3 = nullptr;

    // bullets

    // flying units
    float z = 0.0f;

    // sea units

    // buildings
    Array<ProtoObj *> myCells;

    // land objects

    // wall

private:
};

struct Water
{
    int animX = 0;
    int animY = 0;
    int alpha = 255;
    bool alphaVector = true;
    double conor = 0.0f;
    int conorVector = intRand(0, 2);
    int takt = 0;
    int checkTakt = 0;
    int drawGabPro = intRand(1, 20);
    bool drawGabProVector = true;
    void drawControlBasic(int i)
    {

        if (!i)
        {

            if (this->takt % (this->checkTakt + 5) == 0)
            {
                if (this->drawGabPro <= 0 || this->drawGabPro >= 20)
                {
                    this->drawGabProVector = !this->drawGabProVector;
                }
                if (this->drawGabProVector)
                {
                    this->drawGabPro++;
                }
                else
                {
                    this->drawGabPro--;
                }
            }
        }
        else
        {
            if (this->conorVector)
            {
                this->conor += 0.05;
            }
            else
            {
                this->conor -= 0.05;
            }
            if (this->conor >= 360 || this->conor <= -360)
            {
                this->conor = 0;
                conorVector = intRand(0, 2);
            }
        }
        if (this->takt % this->checkTakt == 0)
        {
            if (this->alpha == 255 || !this->alpha)
            {
                this->alphaVector = !this->alphaVector;
                if (!this->alpha)
                {
                    this->animX = 100 * intRand(0, 8);
                    // this->conor = (double)intRand(0, 360);
                }
            }

            if (!this->alphaVector)
            {
                this->alpha++;
            }
            else
            {
                this->alpha--;
            }
        }
        this->takt++;
        if (this->takt == 1000)
        {
            this->takt = 0;
        }
    };

    void draw(ProtoObj *cell, int i)
    {
        float drawDeltaX = cell->gf->drawDeltaX;
        float drawDeltaY = cell->gf->drawDeltaY;

        ctx.DrawImage(
            cell->cellImage, this->animX, this->animY,
            cell->animGabX, cell->animGabY,
            cell->x + drawDeltaX - 40, cell->y + drawDeltaY - 40,
            cell->drawGabaritX + this->drawGabPro, cell->drawGabaritY + this->drawGabPro,
            SDL_FLIP_NONE, this->conor, this->alpha);
    };
};
