#include "Component.h"
#include "Pin.h"
#include "RadioReceiver.h"
#include "RgbLed.h"

SerialPin   rxinput(0);
PowerPin    rxpower(2);
GroundPin   rxground(3);
RadioReceiver receiver(rxinput, rxpower, rxground);

OutputPin   red(8);
PowerPin    ledPower(9);
OutputPin   green(10);
OutputPin   blue(11);
RgbLed<PowerPin> led(red, ledPower, green, blue);

void setup()
{
    led.setup();
    receiver.setup();
    Pin::ValidateSingleUsage();
    Component::CheckSetup();
}

void loop()
{
    if (receiver.available())
    {
        led.red();
        if (receiver.read() == 1)
        {
            led.red();
        }
    }
    else
    {
        led.green();
    }
    delay(1000);
}
