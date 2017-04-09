#include "RadioTransmitter.h"

RadioTransmitter::RadioTransmitter(
    const SerialPin& s, const PowerPin& p, const GroundPin& g, int baudrate, int serialid)
    : m_s(s), m_p(p), m_g(g), m_baudrate(baudrate), m_serialid(serialid)
{
}

void RadioTransmitter::setup() const
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

void RadioTransmitter::send(byte b) const
{
    switch (m_serialid)
    {
        case 0:
            Serial.print(b);
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
}