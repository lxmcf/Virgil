using Virgil.Engine;

using SDL;
using SDL.Video;

namespace Virgil.Graphics {
    public class RenderQueueItem {
        public Texture output_texture;

        public Rect texture_rectangle { get; private set; }
        public Rect output_rectangle { get; private set; }

        public double output_angle;

        public RenderQueueItem (Texture2D texture, int x, int y, double scale_x, double scale_y, double angle) {            
            output_texture = texture.to_sdl ();
            
            output_angle = angle;
            texture_rectangle = texture.get_bounds ().to_sdl ();

            double output_width = texture_rectangle.w * scale_x;
            double output_height = texture_rectangle.h * scale_y;

            output_rectangle = new Rectangle (x, y, (int)output_width, (int)output_height).to_sdl ();
        }

        public RenderQueueItem.from_string (Font font, string text, int x, int y, Colour colour) {
            int width, height;

            SDLTTF.Font sdl_font = font.to_sdl ();
            //  output_texture = Texture.create_from_surface (
            //      Game.renderer.to_sdl (),
            //      sdl_font.render (text, colour.to_sdl ())
            //  );

            //  output_texture.query (null, null, out width, out height);

            //  output_angle = 0.0;

            //  output_rectangle = new Rectangle (0, 0, width, height).to_sdl ();
        }
    }
}
