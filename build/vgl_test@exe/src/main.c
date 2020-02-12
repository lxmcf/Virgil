/* main.c generated by valac 0.40.19, the Vala compiler
 * generated from main.vala, do not modify */



#include <glib.h>
#include <glib-object.h>
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL2_gfxPrimitives.h"
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL.h"


#define TYPE_VGL (vgl_get_type ())
#define VGL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_VGL, VGL))
#define VGL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_VGL, VGLClass))
#define IS_VGL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_VGL))
#define IS_VGL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_VGL))
#define VGL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_VGL, VGLClass))

typedef struct _VGL VGL;
typedef struct _VGLClass VGLClass;
typedef struct _VGLPrivate VGLPrivate;
enum  {
	VGL_0_PROPERTY,
	VGL_NUM_PROPERTIES
};
static GParamSpec* vgl_properties[VGL_NUM_PROPERTIES];
#define _SDL_DestroyWindow0(var) ((var == NULL) ? NULL : (var = (SDL_DestroyWindow (var), NULL)))
#define _SDL_DestroyRenderer0(var) ((var == NULL) ? NULL : (var = (SDL_DestroyRenderer (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _VGL {
	GObject parent_instance;
	VGLPrivate * priv;
};

struct _VGLClass {
	GObjectClass parent_class;
};

struct _VGLPrivate {
	gint timer;
	SDL_Window* window;
	SDL_Renderer* renderer;
};


static gpointer vgl_parent_class = NULL;

GType vgl_get_type (void) G_GNUC_CONST;
#define VGL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_VGL, VGLPrivate))
#define VGL_WINDOW_WIDTH 640
#define VGL_WINDOW_HEIGHT 360
#define VGL_REFRESH_DELAY 1000
void vgl_run (VGL* self);
static void vgl_initialise_video (VGL* self);
static void vgl_render (VGL* self);
static guint32 vgl_get_colour (VGL* self,
                        gint r,
                        gint g,
                        gint b,
                        gint a);
gint vgl_main (gchar** args,
               int args_length1);
VGL* vgl_new (void);
VGL* vgl_construct (GType object_type);
static void vgl_finalize (GObject * obj);


void
vgl_run (VGL* self)
{
#line 15 "/home/lxmcf/Documents/Projects/src/main.vala"
	g_return_if_fail (self != NULL);
#line 16 "/home/lxmcf/Documents/Projects/src/main.vala"
	vgl_initialise_video (self);
#line 18 "/home/lxmcf/Documents/Projects/src/main.vala"
	while (TRUE) {
#line 84 "main.c"
		gint _tmp0_;
		gint _tmp1_;
#line 18 "/home/lxmcf/Documents/Projects/src/main.vala"
		_tmp0_ = self->priv->timer;
#line 18 "/home/lxmcf/Documents/Projects/src/main.vala"
		if (!(_tmp0_ > 0)) {
#line 18 "/home/lxmcf/Documents/Projects/src/main.vala"
			break;
#line 93 "main.c"
		}
#line 19 "/home/lxmcf/Documents/Projects/src/main.vala"
		vgl_render (self);
#line 21 "/home/lxmcf/Documents/Projects/src/main.vala"
		SDL_Delay ((guint32) VGL_REFRESH_DELAY);
#line 23 "/home/lxmcf/Documents/Projects/src/main.vala"
		_tmp1_ = self->priv->timer;
#line 23 "/home/lxmcf/Documents/Projects/src/main.vala"
		self->priv->timer = _tmp1_ - 1;
#line 103 "main.c"
	}
}


static void
vgl_initialise_video (VGL* self)
{
	SDL_Window* _tmp0_;
	SDL_Window* _tmp1_;
	SDL_Renderer* _tmp2_;
#line 27 "/home/lxmcf/Documents/Projects/src/main.vala"
	g_return_if_fail (self != NULL);
#line 28 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp0_ = SDL_CreateWindow ("VGL (Vala Game Library)", (gint) SDL_WINDOWPOS_CENTERED_MASK, (gint) SDL_WINDOWPOS_CENTERED_MASK, VGL_WINDOW_WIDTH, VGL_WINDOW_HEIGHT, (guint32) SDL_WINDOW_SHOWN);
#line 28 "/home/lxmcf/Documents/Projects/src/main.vala"
	_SDL_DestroyWindow0 (self->priv->window);
#line 28 "/home/lxmcf/Documents/Projects/src/main.vala"
	self->priv->window = _tmp0_;
#line 29 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp1_ = self->priv->window;
#line 29 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp2_ = SDL_CreateRenderer (_tmp1_, -1, (guint32) (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
#line 29 "/home/lxmcf/Documents/Projects/src/main.vala"
	_SDL_DestroyRenderer0 (self->priv->renderer);
#line 29 "/home/lxmcf/Documents/Projects/src/main.vala"
	self->priv->renderer = _tmp2_;
#line 130 "main.c"
}


static void
vgl_render (VGL* self)
{
	gint width = 0;
	gint height = 0;
	SDL_Window* _tmp0_;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gint16 x = 0;
	gint16 y = 0;
	guint32 colour = 0U;
	SDL_Renderer* _tmp3_;
	SDL_Renderer* _tmp4_;
	SDL_Renderer* _tmp5_;
#line 32 "/home/lxmcf/Documents/Projects/src/main.vala"
	g_return_if_fail (self != NULL);
#line 36 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp0_ = self->priv->window;
#line 36 "/home/lxmcf/Documents/Projects/src/main.vala"
	SDL_GetWindowSize (_tmp0_, &_tmp1_, &_tmp2_);
#line 36 "/home/lxmcf/Documents/Projects/src/main.vala"
	width = _tmp1_;
#line 36 "/home/lxmcf/Documents/Projects/src/main.vala"
	height = _tmp2_;
#line 38 "/home/lxmcf/Documents/Projects/src/main.vala"
	x = (gint16) (((gint16) width) / 2);
#line 39 "/home/lxmcf/Documents/Projects/src/main.vala"
	y = (gint16) (((gint16) height) / 2);
#line 41 "/home/lxmcf/Documents/Projects/src/main.vala"
	colour = G_MAXUINT32;
#line 43 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp3_ = self->priv->renderer;
#line 43 "/home/lxmcf/Documents/Projects/src/main.vala"
	boxColor (_tmp3_, (gint16) 0, (gint16) 0, (gint16) 640, (gint16) 360, vgl_get_colour (self, 0, 0, 0, 255));
#line 47 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp4_ = self->priv->renderer;
#line 47 "/home/lxmcf/Documents/Projects/src/main.vala"
	filledCircleColor (_tmp4_, x, y, (gint16) 100, colour);
#line 48 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp5_ = self->priv->renderer;
#line 48 "/home/lxmcf/Documents/Projects/src/main.vala"
	SDL_RenderPresent (_tmp5_);
#line 176 "main.c"
}


gint
vgl_main (gchar** args,
          int args_length1)
{
	gint result = 0;
	VGL* game = NULL;
	VGL* _tmp0_;
#line 52 "/home/lxmcf/Documents/Projects/src/main.vala"
	SDL_Init ((guint32) SDL_INIT_EVERYTHING);
#line 54 "/home/lxmcf/Documents/Projects/src/main.vala"
	_tmp0_ = vgl_new ();
#line 54 "/home/lxmcf/Documents/Projects/src/main.vala"
	game = _tmp0_;
#line 55 "/home/lxmcf/Documents/Projects/src/main.vala"
	vgl_run (game);
#line 57 "/home/lxmcf/Documents/Projects/src/main.vala"
	SDL_Quit ();
#line 59 "/home/lxmcf/Documents/Projects/src/main.vala"
	result = 0;
#line 59 "/home/lxmcf/Documents/Projects/src/main.vala"
	_g_object_unref0 (game);
#line 59 "/home/lxmcf/Documents/Projects/src/main.vala"
	return result;
#line 203 "main.c"
}


int
main (int argc,
      char ** argv)
{
#line 51 "/home/lxmcf/Documents/Projects/src/main.vala"
	return vgl_main (argv, argc);
#line 213 "main.c"
}


static guint32
vgl_get_colour (VGL* self,
                gint r,
                gint g,
                gint b,
                gint a)
{
	guint32 result = 0U;
	guint32 colour = 0U;
#line 62 "/home/lxmcf/Documents/Projects/src/main.vala"
	g_return_val_if_fail (self != NULL, 0U);
#line 63 "/home/lxmcf/Documents/Projects/src/main.vala"
	colour = (((((guint32) a) << 24) + (((guint32) r) << 16)) + (((guint32) g) << 8)) + ((guint32) b);
#line 65 "/home/lxmcf/Documents/Projects/src/main.vala"
	result = colour;
#line 65 "/home/lxmcf/Documents/Projects/src/main.vala"
	return result;
#line 234 "main.c"
}


VGL*
vgl_construct (GType object_type)
{
	VGL * self = NULL;
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	self = (VGL*) g_object_new (object_type, NULL);
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	return self;
#line 246 "main.c"
}


VGL*
vgl_new (void)
{
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	return vgl_construct (TYPE_VGL);
#line 255 "main.c"
}


static void
vgl_class_init (VGLClass * klass)
{
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	vgl_parent_class = g_type_class_peek_parent (klass);
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	g_type_class_add_private (klass, sizeof (VGLPrivate));
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	G_OBJECT_CLASS (klass)->finalize = vgl_finalize;
#line 268 "main.c"
}


static void
vgl_instance_init (VGL * self)
{
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	self->priv = VGL_GET_PRIVATE (self);
#line 10 "/home/lxmcf/Documents/Projects/src/main.vala"
	self->priv->timer = 10;
#line 279 "main.c"
}


static void
vgl_finalize (GObject * obj)
{
	VGL * self;
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_VGL, VGL);
#line 12 "/home/lxmcf/Documents/Projects/src/main.vala"
	_SDL_DestroyWindow0 (self->priv->window);
#line 13 "/home/lxmcf/Documents/Projects/src/main.vala"
	_SDL_DestroyRenderer0 (self->priv->renderer);
#line 4 "/home/lxmcf/Documents/Projects/src/main.vala"
	G_OBJECT_CLASS (vgl_parent_class)->finalize (obj);
#line 295 "main.c"
}


GType
vgl_get_type (void)
{
	static volatile gsize vgl_type_id__volatile = 0;
	if (g_once_init_enter (&vgl_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (VGLClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vgl_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (VGL), 0, (GInstanceInitFunc) vgl_instance_init, NULL };
		GType vgl_type_id;
		vgl_type_id = g_type_register_static (G_TYPE_OBJECT, "VGL", &g_define_type_info, 0);
		g_once_init_leave (&vgl_type_id__volatile, vgl_type_id);
	}
	return vgl_type_id__volatile;
}



