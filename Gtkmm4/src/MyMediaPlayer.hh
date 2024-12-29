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
    static Glib::RefPtr<MyItem> create(const Glib::ustring &file_name, const Glib::ustring &file_path)
    {
        return Glib::RefPtr<MyItem>(new MyItem(file_name, file_path));
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
    Gtk::Box main_box, ctrl_box;
    Gtk::Button btnplay, btnprev, btnnext, btnstop, btnmode;
    Gtk::Label label_lyrics;
    Gtk::ColorDialogButton btncolor;
    Glib::RefPtr<Gtk::ColorDialog> color_dialog;

    Gtk::Expander expander_list;
    Gtk::Box list_box, ctrl_box2;
    Gtk::ListView list_view;
    Gtk::ScrolledWindow list_scroller;
    Gtk::Button btn_add, btn_remove, btn_clear, btn_load, btn_save;
    Glib::RefPtr<Gio::ListStore<MyItem>> media_list;
    Glib::RefPtr<Gtk::SingleSelection> media_selection;
    Glib::RefPtr<Gtk::SignalListItemFactory> media_factory;

    // Functions for the list view
    void setup_view(const Glib::RefPtr<Gtk::ListItem>& list_item);
    void bind_view(const Glib::RefPtr<Gtk::ListItem>& list_item);

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
