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

    public void setState(PinState state) {
        this.state = state;
    }

    public void setState(int state) {
        if (state == 0) {
            this.state = PinState.LOW;
        } else if (state == 1) {
            this.state = PinState.HIGH;
        }
    }

}

