#pragma once

#include <gtkmm.h>

// Item class for the list view
class MyItem : public Glib::Object
{
public:
    MyItem(const Glib::ustring &file_name, const Glib::ustring &file_path)
    {
        m_name = file_name;
        m_path = file_path;
    }
    Glib::ustring get_name() { return m_name; }
    Glib::ustring get_path() { return m_path; }

private:
    Glib::ustring m_name;
    Glib::ustring m_path;
};

// Main window class
class MyMediaPlayer : public Gtk::Window
{
public:
    MyMediaPlayer();
    virtual ~MyMediaPlayer();

private:
    // Child widgets
    Gtk::Video video;
    Gtk::Box main_box;
    Gtk::Button btnplay, btnprev, btnnext, btnstop, btnmode;
    Gtk::Label label_lyrics;
    Gtk::ColorDialogButton btncolor;

    Gtk::Expander expander_list;
    Gtk::ListView list_view;
    Gtk::Button btn_add, btn_remove, btn_clear, btn_load, btn_save;

    // Signal Handlers
    void btnplay_clicked();
    void btnprev_clicked();
    void btnnext_clicked();
    void btnstop_clicked();
    void btnmode_clicked();
    void btncolor_clicked();
    void btnadd_clicked();
    void btnremove_clicked();
    void btnclear_clicked();
    void btnload_clicked();
    void btnsave_clicked();

};
