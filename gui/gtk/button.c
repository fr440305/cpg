#include <gtk/gtk.h>

/* A callback function */
static void my_button_clicked(GtkWidget* w, gpointer data) {
	g_print("My button is pressed!\n");
}

int main(int argc, char** argv) {
	gtk_init(&argc, &argv);

	GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget* button = gtk_button_new_with_label("Click me!");

	g_signal_connect(
		window,
		"delete-event",
		G_CALLBACK(gtk_main_quit),
		NULL
	);
	g_signal_connect(
		button,
		"clicked",
		G_CALLBACK(my_button_clicked),
		//G_CALLBACK(gtk_main_quit),
		NULL
	);
	gtk_container_add(
		GTK_CONTAINER(window),
		button
	);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}

