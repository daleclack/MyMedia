#pragma once

#include <gtkmm.h>

class MyMediaPlayer : public Gtk::Window
{
public:
    MyMediaPlayer();
    virtual ~MyMediaPlayer();

protected:
    //Signal handlers:
    // void on_button_clicked();

    // Gtk::Button m_button;
};
