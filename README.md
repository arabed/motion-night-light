# motion-night-light

This is a simple motion detect-triggered night light using arduino compatible micro module.

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

Fell free to chnage the analog or digital ports as you like. Just remember to modify the code th mach your changes.

## enclosure

I designed a simple enclosure for this project here. Please feel free to use it as you like.
