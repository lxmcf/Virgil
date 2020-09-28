using Virgil.Engine;

namespace Virgil {
    public class Game {
        public bool is_running;

        public static GameWindow window { get; private set; }
        public static GameRenderer renderer { get; private set; }

        public static EventHandler event { get; private set; }
        public static KeyboardHandler keyboard { get; private set; }
        public static MouseHandler mouse { get; private set; }

        public Game () {
            int sdl_init = SDL.init (SDL.InitFlag.EVERYTHING);

            if (sdl_init == 0) {
                window = new GameWindow () {
                    title = @"$PROJECT_NAME v$PROJECT_VERSION"
                };

                renderer = new GameRenderer (window);

                event = new EventHandler ();
                keyboard = new KeyboardHandler ();
                mouse = new MouseHandler ();

                _link_events ();

                is_running = true;
            } else {
                error (SDL.get_error ());
            }
        }

        public int run () {
            start ();

            while (is_running) {
                renderer.clear ();

                event.update ();

                update ();

                draw ();

                renderer.present ();
            }

            SDL.quit ();

            return EXIT_SUCCESS;
        }

        // Default runtime methods
        public virtual void start () { }
        public virtual void update () { }
        public virtual void draw () { }

        public void quit () {
            is_running = false;
        }

        private void _link_events () {
            event.on_close.connect (() => {
                quit ();
            });

            event.on_key_update.connect ((key, is_down) => {
                keyboard.update_key (key.keysym.sym, is_down);
            });

            event.on_mouse_update.connect ((button, is_down) => {
                mouse.update_button (button, is_down);
            });
        }
    }
}
