/**
 * Extends DisplayTouchKeypad to create a 4x5 TouchKeypad to enter g5x
 * offsets.
 * 
 * GPLv2 Licence https://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
 * 
 * Copyright (c) 2022 Philip Fletcher <philip.fletcher@stutchbury.com>
 * 
 */


class OffsetKeypad : public DisplayTouchKeypad {

  public:
    OffsetKeypad(Adafruit_GFX& d, const GFXfont* f, TouchScreen& touchscreen, State_s& state)
        : DisplayTouchKeypad(d, f, touchscreen, DisplayArea(0,50,320,240-50), 4, 5), _state(state) {
      setKeyLabels();
    }


    void update(uint16_t touchUpdateMs = 10) {
      //Set if we're enabled - be careful DisplayTouchKeypad::enable() redraws the DisplayArea
       //eg: this will blow up the Teensy! : enable(_state.isScreen(SCREEN_OFFSET_KEYPAD));
      if ( enabled() && !_state.isScreen(SCREEN_OFFSET_KEYPAD) ) {
        enable(false);
      } else if ( _state.isScreen(SCREEN_OFFSET_KEYPAD) && !enabled() )  {
        enable();        
      }
      DisplayTouchKeypad::update(touchUpdateMs);    
    }


    void draw(uint16_t displayRefreshMs=100) {
      //Call parent class
      DisplayTouchKeypad::draw(displayRefreshMs);
      //Draw the valueBuffer
      if ( enabled() ) {
        drawValue();
        drawLabel();
      }
    }


    void updateAndDraw(uint16_t displayRefreshMs=100, uint16_t touchUpdateMs = 10) {
      update(touchUpdateMs);
      draw(displayRefreshMs);
    }
    

    void getValueBuffer(char* outBuffer) {
      strcpy(outBuffer, valueBuffer);
    }

    void enable(bool b=true) {
      DisplayTouchKeypad::enable(b);
      //We have to clear the whole screen, not just the keypad area.
      gfx.fillScreen(bgColour);
      strcpy(drawnValueBuffer, ""); //Force a redraw
      drawnAxis = AXIS_NONE;
    }


  protected:

    /**
     * Overriding the onKeyTouched. 
     * When a custom callback is not defined/called, update
     * the valueBuffer.
     */
    virtual bool onKeyTouched(TouchKey& key) {
      if ( !key.fireKeyTouchedCallback() ) {
        uint8_t len = strlen(valueBuffer);
        if ( strchr("0123456789.", labels[key.row()][key.col()][0]) != NULL ) {
          // 0-9 or '.' touched
          char digit = labels[key.row()][key.col()][0];
          if ( digit == '.' && strchr(valueBuffer, '.') != NULL ) {
            //Do not repeat decimal point
            return true;
          } else if ( strcmp(valueBuffer, "0") == 0 || strcmp(valueBuffer, "-0") == 0 ) {
            //buffer is just '0'
            if ( digit == '.' ) {
              valueBuffer[len] = digit;
              valueBuffer[len + 1] = '\0';
            } else {
              valueBuffer[len - 1] = digit;
            }
          } else if ( digit != '-' ) {
            valueBuffer[len] = digit;
            valueBuffer[len + 1] = '\0';
          }
          //--
        } else if ( key.row() == 3 && key.col() == 1 ) {
          //+/-
          //if already -ve
          if ( valueBuffer[0] == '-' ) {
            for (int i = 1; i <= len; i++ ) {
              valueBuffer[i - 1] = valueBuffer[i];
            }
            //valueBuffer[len - 1] = '\0';
          } else { //currently +ve
            for (int i = len - 1; i >= 0; i-- ) {
              valueBuffer[i + 1] = valueBuffer[i];
            }
            valueBuffer[0] = '-';
          }
        } else if ( key.row() == 2 && key.col() == 0 ) {
          //Clear (reset to zero)
          valueBuffer[0] = '0';
          valueBuffer[1] = '\0';
        } else if ( key.row() == 2 && key.col() == 4 ) {
          //Backspace
          if ( len == 1 ) {
            valueBuffer[0] = '0';
            valueBuffer[1] = '\0';
          } else {
            valueBuffer[len - 1] = '\0';
          }
        }
      }
      return true;  
    }

  
  private:

    State_s& _state;

    char valueBuffer[20] = "0";
    char drawnValueBuffer[20] = "";
    Axis_e drawnAxis = AXIS_NONE;
    DisplayArea valueArea = DisplayArea(0, 0, 320, 50);
    // An array holing the key labels
    char keyLabels[4][5][5] = {
      { "F1","7", "8", "9", "F3"  },
      { "F2","4", "5", "6", "F4" },
      { "Clr","1", "2", "3", "<==" },
      { "Can","+/-", "0", ".", "OK" }
    };

    void setKeyLabels() {
      for ( uint8_t row=0; row<rows; row++ ) {
        for ( uint8_t col=0; col<cols; col++ ) {
          setLabel(row, col, keyLabels[row][col]);
        }
      }      
    }

    void drawValue() {
      if ( strcmp(drawnValueBuffer, valueBuffer) != 0 ) {
        //Serial.println(valueBuffer);
        int16_t  x, y;
        uint16_t w, h;
        gfx.setFont(&FreeMonoBold18pt7b);
        gfx.setTextColor(fgColour);
        gfx.getTextBounds(valueBuffer, valueArea.x(), valueArea.b(), &x, &y, &w, &h);
        gfx.setCursor(valueArea.r()-w-5, valueArea.yCl() + (h / 2));
        gfx.fillRect(valueArea.x()+85, valueArea.y(), valueArea.w()-85, valueArea.h(), bgColour);
        gfx.print(valueBuffer);
        strcpy(drawnValueBuffer, valueBuffer);
      }      
    }

    void drawLabel() {
      if ( drawnAxis != _state.currentAxis ) {
        gfx.setTextColor(fgColour);
        gfx.setCursor(valueArea.x()+4, valueArea.y()+32);
        gfx.setFont(&FreeSansBold12pt7b);
        gfx.print(AXIS_NAME[_state.currentAxis]);        
        gfx.setFont(&FreeSansBold9pt7b);
        gfx.print(" offset:");
        drawnAxis = _state.currentAxis;
      }      
    }

};
