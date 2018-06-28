/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 28 June, 2018, 5:02 PM
 */

#include <cstdlib>
#include <gtk/gtk.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

/*
 * 
 */
GtkWidget *window;
GtkWidget *label1;
GtkWidget * button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *label2;

void button1_callback(){
    std::stringstream ss;
    ss<<std::rand();
    
    gtk_label_set_text((GtkLabel *)label2,(const gchar *)ss.str().c_str());
}


int main(int argc, char** argv) {
    int status;
    GtkBuilder *builder;
   
   
    gtk_init(&argc,&argv);
    builder=gtk_builder_new(); 
   status= gtk_builder_add_from_file(builder,"glade/ab.glade",NULL);
   if(status==0){
       fprintf(stderr,"glade file error found!!!");
       return 0;
   }
   window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
   gtk_builder_connect_signals(builder,NULL);
   
   label1=GTK_WIDGET(gtk_builder_get_object(builder,"label1"));
   gtk_builder_connect_signals(builder,NULL);
   
   button1=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
   gtk_builder_connect_signals(builder,NULL);
   
   button2=GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
   gtk_builder_connect_signals(builder,NULL);
   
   button3=GTK_WIDGET(gtk_builder_get_object(builder,"button3"));
   gtk_builder_connect_signals(builder,NULL);
   
   label2=GTK_WIDGET(gtk_builder_get_object(builder,"label2"));
   gtk_builder_connect_signals(builder,NULL);
   g_object_unref(builder);
   g_signal_connect(button3,"clicked",gtk_main_quit,NULL);
   
   g_signal_connect(button1,"clicked",button1_callback,NULL);
   g_signal_connect(window,"destroy",gtk_main_quit,NULL);
   gtk_widget_show_all(window);
   
   gtk_main();
   
   
    
    return 0;
}

