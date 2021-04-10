namespace Virgil {
    public class Colour {
        public uint8 red;
        public uint8 green;
        public uint8 blue;
        public uint8 alpha;

        public Colour (uint8 red = 0, uint8 green = 0, uint8 blue = 0, uint8 alpha = 255) {
            set_values (red, green, blue, alpha);
        }

        public Colour.float (float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f) {
            set_values_float (red, green, blue, alpha);
        }

        public Colour.from_colour (Colour colour) {
            red = colour.red;
            green = colour.green;
            blue = colour.blue;
            alpha = colour.alpha;
        }

        public void set_values (uint8 red = 0, uint8 green = 0, uint8 blue = 0, uint8 alpha = 255) {
            this.red = red;
            this.green = green;
            this.blue = blue;
            this.alpha = alpha;
        }

        public void set_values_float (float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f) {
            this.red = (uint8)(red * 255.999f);
            this.green = (uint8)(green * 255.999f);
            this.blue = (uint8)(blue * 255.999f);
            this.alpha = (uint8)(alpha * 255.999f);
        }

        public bool equals (Colour colour) {
            bool does_red = red == (colour.red);
            bool does_green = green == (colour.green);
            bool does_blue = blue == (colour.blue);
            bool does_alpha = alpha == (colour.alpha);

            return (does_red && does_green && does_blue && does_alpha);
        }

        public void manipulate (float factor) {
            float r = (float)red * factor;
            float g = (float)green * factor;
            float b = (float)blue * factor;

            red = (uint8)r.clamp (0f, 255f);
            green = (uint8)g.clamp (0f, 255f);
            blue = (uint8)b.clamp (0f, 255f);
        }

        public string to_string () {
            string string_red = red.to_string ();
            string string_green = green.to_string ();
            string string_blue = blue.to_string ();
            string string_alpha = alpha.to_string ();

            return @"{ red: $(string_red), green: $(string_green), blue: $(string_blue), alpha: $(string_alpha) }";
        }
    }
}
