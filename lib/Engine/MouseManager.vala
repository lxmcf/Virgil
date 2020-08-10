using Virgil.Input;

namespace Virgil {
    public class MouseManager {
        private List<MouseItem> _button_list;

        public int x { get; private set; }
        public int y { get; private set; }

        public MouseManager () {
            _button_list = new List<MouseItem> ();

            _button_list.append (new MouseItem (MouseButton.LEFT));
            _button_list.append (new MouseItem (MouseButton.RIGHT));
            _button_list.append (new MouseItem (MouseButton.MIDDLE));
            _button_list.append (new MouseItem (MouseButton.BACK));
            _button_list.append (new MouseItem (MouseButton.FORWARD));
        }

        public bool check_button (uint8 button) {
            bool button_down = false;

            foreach (MouseItem item in _button_list) {
                if (item.button == button) {
                    if (item.is_down) {
                        button_down = true;

                        break;
                    }
                }
            }

            return button_down;
        }

        public void update_position (SDL.MouseMotionEvent mouse) {
            x = mouse.x;
            y = mouse.y;
        }

        public void update_button (uint8 button, bool down) {
            foreach (MouseItem item in _button_list) {
                if (item.button == button) {
                    item.is_down = down;
                }
            }
        }

        public void get_position (out int position_x, out int position_y) {
            position_x = x;
            position_y = y;
        }
    }
}
