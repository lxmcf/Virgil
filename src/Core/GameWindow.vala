using SDL;

namespace Virgil.Core {
    public class GameWindow {
        private Video.Window _window;

        public Video.Window sdl_window {
            get { return _window; }
        }

        private int _width;
        private int _height;

        public const int CENTERED = Video.Window.POS_CENTERED;

        public string title {
            get { return _window.title; }
            set { _window.title = value; }
        }

        public int width {
            get { return _width; }
            set { set_size (value, _height); }
        }

        public int height {
            get { return _height; }
            set { set_size (width, value); }
        }

        public GameWindow (int width = 640, int height = 360) {
            _window = new Video.Window ("Virgil", CENTERED, CENTERED, width, height, 0);

            set_size (width, height);
        }

        public void set_size (int width, int height) {
            _window.set_size (width, height);
            _window.get_size (out _width, out _height);
        }
    }
}
