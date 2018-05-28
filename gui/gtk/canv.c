#include <gtk/gtk.h>

// decl:
gboolean on_draw(GtkWidget* w, cairo_t* cr, gpointer dat);


// def:
gboolean on_draw(GtkWidget* w, cairo_t* cr, gpointer dat) {
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

int main(int argc, char** argv) {
	gtk_init(&argc, &argv);

	GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget* canv = gtk_drawing_area_new();

	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(canv, "draw", G_CALLBACK(on_draw), NULL);
	gtk_container_add(GTK_CONTAINER(window), canv);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}

