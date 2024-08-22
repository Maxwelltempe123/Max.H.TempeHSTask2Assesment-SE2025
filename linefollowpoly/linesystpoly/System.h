#ifndef SYSTEM_H
#define SYSTEM_H

class System {
public:
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif