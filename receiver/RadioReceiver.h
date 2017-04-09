#pragma once


#include "Component.h"
#include "Pin.h"

class RadioReceiver : public Component
{
public:
    RadioReceiver(const SerialPin&, const PowerPin&, const GroundPin&,
        int baudrate = 2400, int serialid = 0);
    void setup() const;
    bool available() const;
    int  read() const;
private:
    const SerialPin&    m_s;
    const PowerPin&     m_p;
    const GroundPin&    m_g;
    const int           m_baudrate;
    const int           m_serialid;
};