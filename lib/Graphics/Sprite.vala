using Virgil.FileSystem;

using SDL.Video;
using SDLImage;

namespace Virgil.Graphics {
    public class Sprite {
        private Texture? _sdl_texture;
        private Rectangle _rectangle;

        private int _width;
        private int _height;

        public Sprite (Asset asset) {
            _width = 0;
            _height = 0;

            if (asset.length != 0) {
                _sdl_texture = load_texture_rw (Game.renderer.to_sdl (), asset.rwops, false);
                _sdl_texture.query (null, null, out _width, out _height);
            } else {
                _sdl_texture = null;
                _rectangle = new Rectangle.empty ();

                string file = asset.filename;

                warning (@"The file ?$file? has a length of 0");
            }
        }

        public void get_size (out int width, out int height) {
            width = this._width;
            height = this._height;
        }

        public unowned Rectangle get_bounds () {
            return _rectangle;
        }

        public unowned Texture? get_sdl_texture () {
            return _sdl_texture;
        }
    }
}
