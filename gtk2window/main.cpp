/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 29 June, 2018, 11:54 AM
 */

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <gtk/gtk.h>

using namespace std;

GtkWidget *window;
GtkWidget *lin;
GtkWidget *win;
GtkWidget *apple;
GtkWidget *lbutton;
GtkWidget *llbl;
GtkWidget *wbutton;
GtkWidget *wlbl;
GtkWidget *abutton;
GtkWidget *albl;
//GtkBuilder *builder;



/*
 * 
 */
int main(int argc, char** argv) {
GtkBuilder *builder;
int status;
gtk_init(&argc,&argv);
builder=gtk_builder_new();
status =gtk_builder_add_from_file(builder,"glade/ab.glade",NULL);
if(status ==0){
    fprintf(stderr,"Glade file error");
    return 0;
}
window=GTK_WIDGET(gtk_builder_get_object(builder,"base"));
gtk_builder_connect_signals(builder,NULL);

lin=GTK_WIDGET(gtk_builder_get_object(builder,"linux"));
gtk_builder_connect_signals(builder,NULL);

win=GTK_WIDGET(gtk_builder_get_object(builder,"window"));
gtk_builder_connect_signals(builder,NULL);

lbutton=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
gtk_builder_connect_signals(builder,NULL);


g_object_unref(builder);
g_signal_connect(window,"destroy",gtk_main_quit,NULL);
gtk_widget_hide(win);
gtk_widget_hide(lin);
gtk_widget_show_all(window);

sleep(5);
g_print("1");
gtk_widget_show(win);
gtk_widget_hide(lin);
gtk_widget_show(window);
g_print("2");
sleep(5);

gtk_widget_hide(win);
gtk_widget_show(lin);
gtk_widget_show(window);
sleep(5);
g_print("3");
gtk_widget_show(window);

gtk_main();


    
    return 0;
}

