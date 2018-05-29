#include <gtk/gtk.h>
#include <stdio.h>

gboolean draw_circle(GtkWidget* w, cairo_t* cr, gpointer dat);
gboolean draw_image(GtkWidget* w, cairo_t* cr, gpointer dat);

/* def: */
gboolean draw_circle(GtkWidget* w, cairo_t* cr, gpointer dat) {
	GtkStyleContext* ctx = gtk_widget_get_style_context(w);
	guint width = gtk_widget_get_allocated_width(w);
	guint height = gtk_widget_get_allocated_height(w);
	GdkRGBA color;

	gtk_render_background(ctx, cr, 0, 0, width, height);
	cairo_arc(
		cr,
		width/2.0, height/2.0,
		MIN(width, height)/2.0,
		0, 2 * G_PI
	);
	gtk_style_context_get_color(ctx, gtk_style_context_get_state(ctx), &color);
	gdk_cairo_set_source_rgba(cr, &color);
	cairo_fill(cr);
	return FALSE;
}

gboolean draw_image(GtkWidget* w, cairo_t* cr, gpointer dat) {
	GError* err = NULL;
	GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file("./avatar.png", &err);
	if (err) {
		printf("main:g_signal_connect:draw_image :: %s\n", err->message);
		g_error_free(err);
		return FALSE;
	}

	gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
	cairo_paint(cr);
	cairo_fill(cr);
	return FALSE;
}

int main(int argc, char** argv) {
	gtk_init(&argc, &argv);
	GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget* canv = gtk_drawing_area_new();

	/*gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);*/
	gtk_window_fullscreen(GTK_WINDOW(window));
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	/*g_signal_connect(canv, "draw", G_CALLBACK(draw_circle), NULL);*/
	g_signal_connect(canv, "draw", G_CALLBACK(draw_image), NULL);
	gtk_container_add(GTK_CONTAINER(window), canv);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}

