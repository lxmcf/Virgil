using SDL.Input;

namespace Virgil.Input {
    public class Key {
        public Keycode key { get; private set; }

        public bool is_down;
        public bool is_pressed;
        public bool is_released;

        public Key (Keycode key) {
            this.key = key;

            is_down = false;
            is_pressed = false;
            is_released = true;
        }
    }
}
