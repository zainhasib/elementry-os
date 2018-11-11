#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include<stdlib.h>
#include<string.h>

GtkWidget *textField;
GtkWidget *view;
GtkWidget *window;
GtkWidget *grid;
GtkWidget *button;
GtkTextBuffer *buffer;
GtkTextIter iter;

static void print_hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}

void execute(char * cmd) {
    buffer = gtk_text_buffer_new (NULL);
    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 12);
    char *in = "$ : ";
    in = "$ : ";
    strcat(in, cmd);
    gtk_text_buffer_insert(buffer, &iter, in, strlen(cmd));
    gtk_text_view_set_buffer(GTK_TEXT_VIEW(view), buffer);
    g_print("%s\n", (char *)cmd);
}

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer data){
    if (event->keyval == GDK_KEY_Return){
            char * text;
            text = (char *)malloc(sizeof(char) * gtk_entry_get_text_length(GTK_ENTRY(textField)));
            text = (char *)gtk_entry_get_text(GTK_ENTRY(textField));
            //g_print("%s\n", (char *)text);
            execute(text);
            gtk_entry_set_text(GTK_ENTRY(textField), "");
        return TRUE;
    }
    return FALSE;
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    gsize length = 14;
    GtkTextBuffer *buffer;
    GtkTextIter iter;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Terminal");
    gtk_window_set_default_size (GTK_WINDOW (window), 1200, 800);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);

    textField = gtk_entry_new();
    gtk_entry_set_width_chars(GTK_ENTRY(textField), 120);
    g_signal_connect(textField, "key_release_event", G_CALLBACK(on_key_press), "data");
    button = gtk_button_new_with_label("Enter");

    grid = gtk_grid_new ();
    gtk_widget_get_vexpand(grid);

    gtk_container_add (GTK_CONTAINER (window), grid);

    gtk_grid_attach (GTK_GRID (grid), textField, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

    buffer = gtk_text_buffer_new (NULL);
    gtk_text_buffer_set_text(buffer, "dasdasdsa\n", -1);
    gtk_text_buffer_set_text(buffer, "$ : \n", -1);
    view = gtk_text_view_new_with_buffer (buffer);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(view), TRUE);
    //gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
    //gtk_text_buffer_insert(buffer, &iter, "Plain text\n", -1);
    gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (view), GTK_WRAP_WORD); 
    
    gtk_grid_attach (GTK_GRID (grid), view, 0, 1, 2, 2);

    gtk_widget_show_all (window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("zainhasib.google", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}