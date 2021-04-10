using Virgil;
using Virgil.Debug;

using SDL.Video;

namespace Virgil.Graphics {
    public class DynamicTexture2D : Texture2D {
        private bool _locked;

        public DynamicTexture2D (uint width, uint height) {
            base (width, height, TextureType.STREAMING);

            print_warning ("DynamicTexture2D is currently not fully functional, please use StaticTexture2D");

            _locked = false;
        }

        public DynamicTexture2D.from_file (string filename) {
            base.from_file (filename, TextureType.STREAMING);

            print_warning ("DynamicTexture2D is currently not fully functional, please use StaticTexture2D");

            _locked = false;
        }

        public DynamicTexture2D.from_texture_raw (TextureRaw raw) {
            base.from_texture_raw (raw, TextureType.STREAMING);

            print_warning ("DynamicTexture2D is currently not fully functional, please use StaticTexture2D");

            _locked = false;
        }

        // NOTE: Experimental, unsure if function will work as expected
        // IDEA: Impliment a dedicated pixel update method to avoid EU needing to use memset
        public int @lock (Rectangle rect, out void* pixels, out int pitch) {
            pitch = 0;
            pixels = null;

            if (_locked) {
                print_error (@"DynamicTexture2D { $texture_id } already locked!");

                return EXIT_FAIL;
            }

            sdl_texture.do_lock (
                { rect.x, rect.y, rect.width, rect.height },
                out pixels,
                out pitch
            );

            _locked = true;

            return EXIT_SUCCESS;
        }

        public int @unlock () {
            if (!_locked) {
                print_error (@"DynamicTexture2D { $texture_id } already unlocked!");
            }

            sdl_texture.unlock ();
            _locked = false;

            return EXIT_SUCCESS;
        }
    }
}
