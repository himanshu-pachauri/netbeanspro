#include <stdio.h>
#include <iostream>
#include <gtk/gtk.h>
GtkWidget *window;
GtkWidget *button1;
GtkWidget *checkbutton1;
GtkWidget *checkbutton2;
GtkWidget *checkbutton3;
GtkWidget *switch1;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *layout1;

void checkbutton1_callback(GtkToggleButton *widget,gpointer data){
    
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(window)))
    {
        g_print("scince buttton get activated");
    }
    else{
        g_print("science buttton is diactivated");
    }

}
void checkbutton2_callback(GtkWidget *widget,gpointer data){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(window)))
    {
        g_print("commerce buttton get activated");
    }
    else{
        g_print("commerce buttton is diactivated");
    }
}

void checkbutton3_callback(GtkWidget *widget,gpointer data){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(window)))
    {
        g_print("arts buttton get activated");
    }
    else{
        g_print("arts buttton is diactivated");
    }}

int main(int argc,char **argv)
{
    int status;
    
    GtkBuilder *builder;
    gtk_init(&argc,&argv);
    builder=gtk_builder_new();
    status=gtk_builder_add_from_file(builder,"glade/ab.glade",NULL);
    if(status==0){
        fprintf(stderr,"glade file error");
        return 0;
    }
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    gtk_builder_connect_signals(builder,NULL);
    
    
  checkbutton1=GTK_WIDGET(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"checkbutton1")));
    gtk_builder_connect_signals(builder,NULL);
    
  checkbutton2=GTK_WIDGET(gtk_builder_get_object(builder,"checkbutton2"));
    gtk_builder_connect_signals(builder,NULL);
    
  checkbutton3=GTK_WIDGET(gtk_builder_get_object(builder,"checkbutton3"));
    gtk_builder_connect_signals(builder,NULL);
    
    switch1=GTK_WIDGET(gtk_builder_get_object(builder,"switch1"));
    gtk_builder_connect_signals(builder,NULL);
    
    label1=GTK_WIDGET(gtk_builder_get_object(builder,"label1"));
    gtk_builder_connect_signals(builder,NULL);
    
    
    
    //signal connects
    g_signal_connect(G_OBJECT(checkbutton1),"clicked",G_CALLBACK(checkbutton1_callback),NULL);
    g_signal_connect(G_OBJECT(checkbutton2),"clicked",G_CALLBACK(checkbutton2_callback),NULL);
    g_signal_connect(G_OBJECT(checkbutton3),"clicked",G_CALLBACK(checkbutton3_callback),NULL);
    
    g_object_unref(builder);
    gtk_widget_show(window);
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    gtk_main();
    




}
