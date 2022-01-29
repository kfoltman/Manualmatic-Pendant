/**
 * The various icons used on the button row.
 * 
 * GPLv2 Licence https://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
 * 
 * Copyright (c) 2022 Philip Fletcher <philip.fletcher@stutchbury.com>
 * 
 */


/** ***************************************************************

*/
void fillOctagon(Coords_s cp, uint8_t r, uint16_t colour) {
  float a = 22.5;
  Coords_s c1 = { round(r * cos(degree2radian(a)) + cp.x), round(r * sin(degree2radian(a)) + cp.y) };
  Coords_s c2 = {0, 0};
  for (uint8_t i = 0; i < 8; i++ ) {
    a += 45;
    c2 = { round(r * cos(degree2radian(a)) + cp.x), round(r * sin(degree2radian(a)) + cp.y) };
    tft.fillTriangle(cp.x, cp.y, c1.x, c1.y, c2.x, c2.y, colour);
    c1.x = c2.x;
    c1.y = c2.y;
  }

}


void drawIconCancel(Coords_s cp, uint16_t fgColour=ILI9341_RED, uint8_t r=14, uint8_t t=4 ) {
    tft.fillCircle(cp.x, cp.y, r, fgColour);
    tft.fillCircle(cp.x, cp.y, r - t, ILI9341_WHITE);
    int8_t h = floor(t/2); //half thickness
    r = round(r*0.7);
    //      '/'                BL                   TR                     BR  
    tft.fillTriangle(cp.x-r-h, cp.y+r-h,     cp.x+r+h, cp.y-r+h,    cp.x-r+h, cp.y+r+h, fgColour);
    //      '/'                BL                   TR                     TL  
    tft.fillTriangle(cp.x-r-h, cp.y+r-h,     cp.x+r+h, cp.y-r+h,    cp.x+r-h, cp.y-r-h, fgColour);    
}


/**
   Draw an 'X' centred at Coords, approx radius r, thickness t
*/
void drawIconX(Coords_s cp, uint16_t c=ILI9341_RED, uint8_t r=10, uint8_t t=5 ) {  
  int8_t h = t/2; //half thickness
  r = round(r*1.3);
  //      '/'                BL                   TR                     BR  
  tft.fillTriangle(cp.x-r-h, cp.y+r-h,     cp.x+r+h, cp.y-r+h,    cp.x-r+h, cp.y+r+h, c);
  //      '/'                BL                   TR                     TL  
  tft.fillTriangle(cp.x-r-h, cp.y+r-h,     cp.x+r+h, cp.y-r+h,    cp.x+r-h, cp.y-r-h, c);  
  //      '\'                BR                   TL                     BL  
  tft.fillTriangle(cp.x+r+h, cp.y+r-h,     cp.x-r-h, cp.y-r+h,    cp.x+r-h, cp.y+r+h, c);
  //      '\'                BR                   TL                     TR  
  tft.fillTriangle(cp.x+r+h, cp.y+r-h,     cp.x-r-h, cp.y-r+h,    cp.x-r+h, cp.y-r-h, c);
}


void drawIconTick(Coords_s cp, uint8_t r=10, uint8_t t=4, uint16_t c=ILI9341_DARKGREEN ) {  
  uint8_t h = t/2; //half thickness
  r = round(r*1.3);
  Coords_s tr = {cp.x+r, cp.y-r-(h/2)};
  Coords_s b = { cp.x-r+t+h, cp.y+r+h };
  Coords_s tl = { cp.x-r-h, cp.y+h };
//  //      '/'       B               TR                V  
  tft.fillTriangle(b.x, b.y+h,     tr.x, tr.y,    b.x, b.y-t-h, c);
  //                   V               T
  tft.fillTriangle(b.x, b.y-t-h,     tr.x, tr.y,    tr.x-h, tr.y-h, c);
  //      '\'         B
  tft.fillTriangle(b.x, b.y+h,  tl.x-h, tl.y+h,   tl.x+h, tl.y-h, c);
  //                  B             V
  tft.fillTriangle(b.x, b.y+h,  b.x, b.y-t-h,    tl.x+h, tl.y-h,     c);
}

void drawIconTap(Coords_s cp, uint16_t c=ILI9341_WHITE) {
  //uint8_t w = 63;
  uint8_t h = 37;
  //tft.drawRect(cp.x-(w/2), cp.y-(h/2), w, h, c);
  tft.fillRect(cp.x-5-5, cp.y-13, 10, 3, c); //handle
  tft.fillCircle(cp.x-5+7, cp.y-12, 3, c); //end
  tft.fillCircle(cp.x-5-7, cp.y-12, 3, c); //end
  tft.fillRect(cp.x-5-1, cp.y-13, 3, 8, c); //shaft
  tft.fillCircle(cp.x-5, cp.y, 7, c); //valve body
  tft.fillRect(cp.x-19, cp.y-4, 30, 8, c); //body
  tft.fillRect(cp.x+9, cp.y, 8, 8, c); //spout
  tft.fillCircle(cp.x+11, cp.y, 4, c); //curve
  tft.fillCircle(cp.x+12, cp.y+(h/2)-3, 3, c); //drip
  tft.fillCircle(cp.x+12, cp.y+(h/2)-6, 1, c); //drip top
}
//void drawTouchIconTap(TouchKey& tk) {
//  Coords_s cp = { tk.xCl(), tk.yCl()};
//  drawIconTap(cp);
//}

void drawIconTouchOff(Coords_s cp, uint16_t c=ILI9341_WHITE) {
  //tft.drawRect(cp.x-(w/2), cp.y-(h/2), w, h, c);
  tft.fillRect(cp.x-4, cp.y-15, 9, 8, c); //shaft
  tft.fillRect(cp.x-1, cp.y-12, 3, 20, c); //shaft
  tft.fillCircle(cp.x, cp.y+7, 3, c); //ruby
  tft.drawLine(cp.x-6, cp.y+9, cp.x-10, cp.y+5, c);
  tft.drawLine(cp.x+6, cp.y+9, cp.x+10, cp.y+5, c);
  tft.drawRect(cp.x-15, cp.y+12, 30, 5, c); //stock
}

void drawIconHalf(Coords_s cp, int c=ILI9341_WHITE) {
    tft.setTextColor(c);
    tft.setFont(&FreeSansBold12pt7b);
    tft.setCursor(cp.x-19, cp.y+3);
    tft.print("1");
    tft.setFont(&FreeSansBold18pt7b);
    tft.setCursor(cp.x-6, cp.y+12);
    tft.print("/");
    tft.setFont(&FreeSansBold12pt7b);
    tft.setCursor(cp.x+3, cp.y+12);
    tft.print("2");
}


void drawIconHalt(Coords_s cp, uint16_t c=ILI9341_RED ) {
    uint8_t r = 15;
    fillOctagon(cp, r, c);
    drawIconX(cp, ILI9341_WHITE, 5, 3);
}


void drawIconOneStep(Coords_s cp, uint16_t c=ILI9341_WHITE) {
    uint16_t x = cp.x - 12;
    uint8_t y = cp.y - 14;
    uint8_t s = 8; //step size
    tft.setFont(&FreeMonoBold18pt7b);
    tft.setTextColor(c);
    tft.setCursor(x - 10, cp.y+12);
    tft.print("1");
    for ( uint8_t i = 0; i < 4; (i++) ) {
      tft.drawLine(x + (s * i), y + (s * i), x + (s * i) + s, y + (s * i), c);
      tft.drawLine(x + (s * i) + s, y + (s * i), x + (s * i) + s, y + (s * i) + s, c);
    }
    tft.setTextColor(ILI9341_WHITE);
}



void drawIconPause(Coords_s cp, uint16_t c=ILI9341_WHITE, uint8_t h=27) {
    uint8_t w = round(h / 3);
    uint16_t x = cp.x - floor(w * 1.3);
    uint8_t y = cp.y - floor(h / 2);
    tft.fillRect(x, y, w, h, c);
    tft.fillRect(x + (w * 1.8), y, w, h, c);
}

void drawIconPlay(Coords_s cp, uint16_t c=ILI9341_WHITE, uint8_t h=26) {
    uint8_t w = h / 1.5;
    tft.fillTriangle(
      cp.x-(w/2)+3, cp.y-(h/2),
      cp.x+(w/2)+3, cp.y,
      cp.x-(w/2)+3, cp.y+(h/2),
      c
    );
}

void drawIconStop(Coords_s cp, int c=ILI9341_WHITE, uint8_t h=24) {
    tft.fillRect((cp.x-floor(h / 2)), (cp.y-floor(h / 2)), h, h, c);
}


const unsigned char stop_hand [] PROGMEM = {
  // 'stop-hand, 128x160px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xfc, 0x01, 0xff, 0xfe, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xff, 0x01, 0xff, 0xfe, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xff, 0x01, 0xff, 0xfe, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xff, 0x03, 0xff, 0xfe, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xff, 0xc3, 0xff, 0xfe, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0x80, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0xc0, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0xe0, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0xf0, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x0f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x0f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x0f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x06, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x7f, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xfe, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x1f, 0xfe, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x1f, 0xfe, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0xfe, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xfc, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xfc, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xfc, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x01, 0xff, 0xf8, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xff, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x01, 0xff, 0xf8, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0xe3, 0xef, 0xfe, 0x1f, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xf8, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xf0, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xf0, 0x00, 
  0x00, 0x7f, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x0f, 0xff, 0xf0, 0x00, 
  0x00, 0x7f, 0xfc, 0x38, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x7f, 0x80, 0x00, 0x0f, 0xff, 0xe0, 0x00, 
  0x00, 0x7f, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0x80, 0x7f, 0x80, 0x00, 0x1f, 0xff, 0xe0, 0x00, 
  0x00, 0x7f, 0xfc, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xe0, 0x00, 
  0x00, 0x7f, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xf8, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xc0, 0x00, 
  0x00, 0x7f, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0x80, 0x00, 
  0x00, 0x7f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 
  0x00, 0x7f, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80, 0x00, 
  0x00, 0x7f, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x00, 0x00, 
  0x00, 0x7e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0x00, 0x00, 
  0x00, 0x7c, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xfe, 0x00, 0x00, 
  0x00, 0x7e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xfe, 0x00, 0x00, 
  0x00, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfc, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


/** ***************************************************************

*/
void drawEstopped(bool forceRefresh = false) {
  if ( forceRefresh ) {
    tft.fillScreen(ILI9341_BLACK);
    uint8_t r = 110;
    Coords_s cp = { 160, 120 }; //centre point
    uint8_t lw = 7;
    //Could put this on a canvas first but I quite like the 'animation'.
    fillOctagon(cp, r, ILI9341_RED);
    fillOctagon(cp, r - lw, ILI9341_WHITE);
    fillOctagon(cp, r - (lw * 2), ILI9341_RED);
    tft.drawBitmap(cp.x - 55, cp.y - 80, stop_hand, 128, 160, ILI9341_WHITE);

  }
}
