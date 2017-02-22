package org.wpilibpi.gpio;

/**
 * @author thatging3rkid
 */
public class GPIOPin {

    public enum PinState {
        HIGH,
        LOW
    }

    public final int pin;
    private PinState state;

    public GPIOPin(int pin) {
        this.pin = pin;
    }

    public PinState getState() {
        return this.state;
    }

}

