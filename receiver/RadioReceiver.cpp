#include "RadioReceiver.h"


RadioReceiver::RadioReceiver(
    const SerialPin& s, const PowerPin& p, const GroundPin& g, int baudrate, int serialid)
    : m_s(s), m_p(p), m_g(g), m_baudrate(baudrate), m_serialid(serialid)
{
}

void RadioReceiver::setup() const
{
    Component::setup();
    switch (m_serialid)
    {
        case 0:
            Serial.begin(m_baudrate);
            break;
        // These cases are for Arduino Mega (more than one Serial pin pair).
        // case 1:
        //     Serial1.begin(m_baudrate);
        //     break;
        // case 2:
        //     Serial2.begin(m_baudrate);
        //     break;
        // case 3:
        //     Serial3.begin(m_baudrate);
        //     break;
        default:
            break;
    }
    m_s.setup();
    m_p.setup();
    m_g.setup();
}

bool RadioReceiver::available() const
{
    switch (m_serialid)
    {
        case 0:
            return Serial.available() > 0;
        // These cases are for Arduino Mega (more than one Serial pin pair).
        // case 1:
        //     return Serial1.available() > 0;
        // case 2:
        //     return Serial2.available() > 0;
        // case 3:
        //     return Serial3.available() > 0;
        default:
            return false;
    }
}

int RadioReceiver::read() const
{
    switch (m_serialid)
    {
        case 0:
            return Serial.read();
        // These cases are for Arduino Mega (more than one Serial pin pair).
        // case 1:
        //     return Serial1.read();
        // case 2:
        //     return Serial2.read();
        // case 3:
        //     return Serial3.read();
        default:
            return -1;
    }
}