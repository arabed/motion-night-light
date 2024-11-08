# Motion Night Light

This is a simple motion detect-triggered night light using arduino compatible micro module.

![](https://github.com/arabed/motion-night-light/blob/main/docs/product.png)

## State Machine

The following is  the state machine of this device.

```mermaid
---
title: Motion Night Light State Diagram
---
stateDiagram-v2
    state if_light <<choice>>
    state if_motion <<choice>>

    [*] --> Setup
    Setup --> MainLoop
    MainLoop --> if_motion
    if_motion --> MainLoop: No motion detected
    if_motion --> if_light: Motion detected
    if_light --> Leds_ON: NO light (it's night)
    if_light --> Leds_OFF: Light (it's day)
    Leds_ON --> MainLoop    
    Leds_OFF --> MainLoop
```

## Circuitary

The following diagram is illustrated the electronic componets and the related wiring.

Fell free to change the analog or digital ports as you like. Just remember to modify the code th mach your changes.

![](https://github.com/arabed/motion-night-light/blob/main/docs/circuit-diagram.png)

[draw.io source file here](https://github.com/arabed/motion-night-light/blob/main/docs/circuit-diagram.drawio)

## enclosure

I designed a simple enclosure for this project.

![](https://github.com/arabed/motion-night-light/blob/main/docs/Motion%20Night%20Light%20v19.png)

You can find the STL files for [front cover here](https://github.com/arabed/motion-night-light/blob/main/docs/Motion%20Night%20Light%20v19.stl) and [back cover here](https://github.com/arabed/motion-night-light/blob/main/docs/Motion%20Night%20Light%20-%20cover%20v5.stl).

## Reference

The Pro Micro pinout for reference:

![](https://github.com/arabed/motion-night-light/blob/main/docs/Pro-Micro-Pin-Out.png)
