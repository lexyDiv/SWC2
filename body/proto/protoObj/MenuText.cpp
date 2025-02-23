#include "../protoGameField/ProtoGameField.cpp"

struct LiteraData
{
  int x = 0;
  int y = 0;
  int gabX = 12;
  int gabY = 12;
  string lit;
};

class MenuText
{
public:
  Image *font = new Image("images/font/all.png");
  MenuText();
  ~MenuText();
  Array<LiteraData *> data;

  void draw(string s, int x, int y, int gab, int R, int G, int B)
  {
    for (int i = 0; i < s.size(); i++)
    {
      int lit = s[i];
      LiteraData *litD = this->data.getItem2(lit);
      int dx = x + i * (gab * 0.7);
      ctx.DrawImage(this->font, litD->x, 0, litD->gabX, litD->gabY, dx, y, gab, gab, SDL_FLIP_NONE, 0.0, 255, 0, 0, R, G, B);
    }
  }
};

MenuText::MenuText()
{
  for (int i = 0; i <= 122; i++)
  {
    this->data.push(new LiteraData);
  };

  string s = "!#$%&(),-;@+=0123456789ABCDEFGHIJKLMNOP.:QRS/TUV?WXYZabcdefghijklmnopqrstuvwxyz' ";
  for (int i = 0; i < s.size(); i++)
  {
    int lit = s[i];
    LiteraData *ld = this->data.getItem2(lit);
    ld->x = i * 12;
  }
}

MenuText::~MenuText()
{
  delete this->font;
  this->font = nullptr;
  this->data.forEach([](LiteraData *ld)
                     {
    if (ld) {
      delete ld;
      ld = nullptr;
    } });
}

MenuText menuText;