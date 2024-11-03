#include "GameField.cpp"

void recAroundCellsCont(Array<ProtoObj *> frash, ProtoGameField *gf)
{
   Array<ProtoObj *> reFrash;
   for (int i = 0; i < frash.length; i++)
   {
      ProtoObj *cell = frash.getItem(i);
      for (int k = 0; k < cell->aroundCells.length; k++)
      {
         ProtoObj *ac = cell->aroundCells.getItem(k);
         if (ac->litera != 'w' && ac->litera != '9' && !ac->plane)
         {
            ac->plane = cell->plane;
            ac->plane->cells.push(ac);
            reFrash.push(ac);
         }
      }
   }
   if (!reFrash.length)
   {
      return;
   }
   recAroundCellsCont(reFrash, gf);
};

void recAroundCellsSea(Array<ProtoObj *> frash, ProtoGameField *gf)
{
   Array<ProtoObj *> reFrash;
   for (int i = 0; i < frash.length; i++)
   {
      ProtoObj *cell = frash.getItem(i);
      for (int k = 0; k < cell->aroundCells.length; k++)
      {
         ProtoObj *ac = cell->aroundCells.getItem(k);
         if ((ac->litera == 'w' || ac->litera == '9') && !ac->plane)
         {
            ac->plane = cell->plane;
            ac->plane->cells.push(ac);
            reFrash.push(ac);
         }
      }
   }
   if (!reFrash.length)
   {
      return;
   }
   recAroundCellsSea(reFrash, gf);
};

int gCont = 1;
int gSea = 1;

void GameField::getContinents()
{
   for (int ver = 0; ver < this->field.length; ver++)
   {
      Array<ProtoObj *> arr = this->field.getItem(ver);
      for (int hor = 0; hor < arr.length; hor++)
      {
         ProtoObj *cell = arr.getItem(hor);
         if (cell->litera != 'w' && cell->litera != '9' && !cell->plane)
         {
            ProtoPlane *plane = new ProtoPlane;
            plane->type = "ground";
            this->planes.push(plane);
            cell->plane = plane;
            cell->plane->cells.push(cell);
            plane->number = gCont;
            gCont++;
            Array<ProtoObj *> frash;
            for (int i = 0; i < cell->aroundCells.length; i++)
            {
               ProtoObj *ac = cell->aroundCells.getItem(i);
               if (ac->litera != 'w' && ac->litera != '9')
               {
                  ac->plane = cell->plane;
                  ac->plane->cells.push(ac);
                  frash.push(ac);
               }
            }
            if (frash.length)
            {
               recAroundCellsCont(frash, this);
            }
         }
         else if ((cell->litera == 'w' || cell->litera == '9') && !cell->plane)
         {
            ProtoPlane *plane = new ProtoPlane;
            plane->type = "sea";
            this->planes.push(plane);
            cell->plane = plane;
            cell->plane->cells.push(cell);
            plane->number = gSea;
            gSea++;
            Array<ProtoObj *> frash;
            for (int i = 0; i < cell->aroundCells.length; i++)
            {
               ProtoObj *ac = cell->aroundCells.getItem(i);
               if (ac->litera == 'w' || ac->litera == '9')
               {
                  ac->plane = cell->plane;
                  ac->plane->cells.push(ac);
                  frash.push(ac);
               }
            }
            if (frash.length)
            {
               recAroundCellsSea(frash, this);
            }
         }
      }
   }
   // console.log(to_string(this->planes.length));
   // this->planes.forEach([](ProtoPlane *plane){
   //    console.log(plane->type);
   // });

   this->planes.forEach([this](ProtoPlane *plane)
                        { plane->cells.forEach([this, plane](ProtoObj *cell)
                                               {
         int aclength = cell->aroundCells.length;
         for (int i = 0; i < aclength; i++) {
            ProtoObj *ac = cell->aroundCells.getItem(i);
            if (ac->plane != cell->plane) {
               ToOtherPlane *op = plane->contactPlanes.find([ac](ToOtherPlane *item){
                  return item->otherPlane == ac->plane;
               });
               if (op == nullptr) {
                  op = new ToOtherPlane;
                  op->otherPlane = ac->plane;
                  plane->contactPlanes.push(op);
               }
               op->cellsToOther.push(cell);
               break;
            }
         } }); });

   // console.log(to_string(this->planes.getItem(0)->contactPlanes.getItem(0)->cellsToOther.length));
}