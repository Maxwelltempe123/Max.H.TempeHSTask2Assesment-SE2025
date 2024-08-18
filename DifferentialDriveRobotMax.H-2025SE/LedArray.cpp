#include "LedArray.h"

LedArray::LedArray() : ledMatrix(LedMatrix()) {}

void LedArray::init() {
    ledMatrix.begin();
    ledMatrix.setBrightness(15); 
}

void LedArray::displayHappyFace() {
    drawBitmap(happyFace);
}

void LedArray::displaySadFace() {
    drawBitmap(sadFace);
}

void LedArray::displayLeftArrow() {
    drawBitmap(leftArrow);
}

void LedArray::displayRightArrow() {
    drawBitmap(rightArrow);
}

void LedArray::drawBitmap(const uint8_t bitmap[8][12]) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 12; x++) {
            ledMatrix.drawPixel(x, y, bitmap[y][x] ? HIGH : LOW);
        }
    }
    ledMatrix.show();
}