#include "Component.h"
#include "MomentaryPushButton.h"
#include "Pin.h"
#include "RadioTransmitter.h"
#include "RgbLed.h"

SerialPin   txinput(1);
PowerPin    txpower(2);
GroundPin   txground(3);
RadioTransmitter transmitter(txinput, txpower, txground);

InputPin  buttonInput(5);
PowerPin  buttonPower(6);
GroundPin buttonGround(7);
MomentaryPushButton button(buttonInput, buttonPower, buttonGround);

OutputPin   red(8);
PowerPin    ledPower(9);
OutputPin   green(10);
OutputPin   blue(11);
RgbLed<PowerPin> led(red, ledPower, green, blue);

void setup()
{
    led.setup();
    button.setup();
    transmitter.setup();
    Pin::ValidateSingleUsage();
    Component::CheckSetup();
}

void loop()
{
    if (button.high())
    {
        transmitter.send(1);
        led.red();
    }
    else
    {
        led.green();
    }
}
