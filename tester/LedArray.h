 // #ifndef LED_ARRAY_H
 // #define LED_ARRAY_H

  //#include <Arduino.h>
  //#include "Arduino_LED_Matrix.h" 
  //#include "ArduinoGraphics.h"

  //class LedArray {
  //public:
    //  LedArray();

      //void init();

      //void displayHappyFace();
      //void displaySadFace();
      //void displayLeftArrow();
      //void displayRightArrow();

  //private:
    //  ArduinoLEDMatrix ledArray; 

      //const uint8_t happyFace[8][12] = {
        //  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
          //{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
          //{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
          //{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
          //{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
          //{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
          //{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
          //{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
      //};

      //const uint8_t sadFace[8][12] = {
        //  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
          //{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
          //{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
          //{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
          //{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
          //{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
          //{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
          //{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
      //};

      //const uint8_t leftArrow[8][12] = {
        //  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
          //{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
          //{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
          //{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          //{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          //{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        //  {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
          //{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
      //};

      //const uint8_t rightArrow[8][12] = {
   //       {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
     //     {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
       //   {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
         // {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          //{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     //     {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
       //   {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
         // {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
     // };

      //void drawBitmap(const uint8_t bitmap[8][12]);
  //};

  //#endif