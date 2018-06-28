/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 28 June, 2018, 3:36 PM
 */

#include <cstdlib>
#include <gtk/gtk.h>
#include <iostream>
#include <stdio.h>
using namespace std;
GtkWidget *window;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *label1;
    
void left_button_callback(){
    gtk_label_set_text(GTK_LABEL(label1),(const gchar *)"left_button_callback callled");

}    

void right_button_callback(){
   gtk_label_set_text(GTK_LABEL( label1),(const gchar *)"right_button_callback callled");
}
    
/*
 * 
 */
int main(int argc, char** argv) {
    int status;
    
    
    gtk_init(&argc,&argv);
    GtkBuilder *builder;
    builder=gtk_builder_new();
    status=gtk_builder_add_from_file(builder,"glade/ab.glade",NULL);
    if(status==0){
        fprintf(stderr,"glade file eror");
        return 0;
    }
    
    window=GTK_WIDGET(gtk_builder_get_object(builder,"mainwindow"));
    gtk_builder_connect_signals(builder,NULL);
    
    
    button1=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
    gtk_builder_connect_signals(builder,NULL);
    g_signal_connect(button1,"clicked",left_button_callback,NULL);
    
    button2=GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
    gtk_builder_connect_signals(builder,NULL);
    g_signal_connect(button2,"clicked",right_button_callback,NULL);
    button3=GTK_WIDGET(gtk_builder_get_object(builder,"button4"));
    gtk_builder_connect_signals(builder,NULL);
    g_signal_connect(button3,"clicked",gtk_main_quit,NULL);
    
    label1=GTK_WIDGET(gtk_builder_get_object(builder,"label1"));
    gtk_builder_connect_signals(builder,NULL);
    
    g_object_unref(G_OBJECT(builder));
    
    
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    gtk_widget_show_all(window);
    gtk_main();
    
    
    
}

