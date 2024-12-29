#include "MyMediaPlayer.hh"
#include <iostream>

MyMediaPlayer::MyMediaPlayer()
    : main_box(Gtk::Orientation::VERTICAL, 5),
    ctrl_box(Gtk::Orientation::HORIZONTAL, 5),
    list_box(Gtk::Orientation::VERTICAL, 5),
    ctrl_box2(Gtk::Orientation::HORIZONTAL, 5)
{
    // Initialize window
    set_title("My Media Player");
    set_icon_name("org.gtk.daleclack");
    set_default_size(300, 500);

    // Add video widget and label for lyrics
    video.set_size_request(300, 150);
    main_box.append(video);
    label_lyrics.set_use_markup(true);
    label_lyrics.set_markup("<span color='red' size='12pt'>No Media Playing...</span>");
    main_box.append(label_lyrics);

    // Create color dialog
    color_dialog = Gtk::ColorDialog::create();
    btncolor.set_dialog(color_dialog);

    // Update icons for widgets
    btnplay.set_icon_name("media-playback-start");
    btnprev.set_icon_name("media-skip-backward");
    btnnext.set_icon_name("media-skip-forward");
    btnstop.set_icon_name("media-playback-stop");
    btnmode.set_icon_name("media-playlist-repeat");
    ctrl_box.append(btnprev);
    ctrl_box.append(btnplay);
    ctrl_box.append(btnnext);
    ctrl_box.append(btnstop);
    ctrl_box.append(btnmode);
    ctrl_box.append(btncolor);
    ctrl_box.set_halign(Gtk::Align::CENTER);
    main_box.append(ctrl_box);

    // Add buttons for playlist management
    btn_add.set_icon_name("list-add");
    btn_remove.set_icon_name("list-remove");
    btn_load.set_icon_name("go-up");
    btn_save.set_icon_name("document-save");
    ctrl_box2.append(btn_add);
    ctrl_box2.append(btn_remove);
    ctrl_box2.append(btn_load);
    ctrl_box2.append(btn_save);
    ctrl_box2.set_halign(Gtk::Align::CENTER);
    list_box.append(ctrl_box2);

    // Create list store and list view for playlist
    media_list = Gio::ListStore<MyItem>::create();
    media_selection = Gtk::SingleSelection::create(media_list);
    media_factory = Gtk::SignalListItemFactory::create();
    media_factory->signal_setup().connect(sigc::mem_fun(*this, &MyMediaPlayer::setup_view));
    media_factory->signal_bind().connect(sigc::mem_fun(*this, &MyMediaPlayer::bind_view));
    list_view.set_model(media_selection);
    list_view.set_factory(media_factory);

    // Add list view to the playlist box
    list_scroller.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    list_scroller.set_child(list_view);
    list_box.append(list_scroller);
    list_scroller.set_vexpand(true);
    list_view.set_vexpand(true);

    // Add expander for playlist
    expander_list.set_label("Playlist");
    expander_list.set_vexpand(true);
    expander_list.set_child(list_box);
    main_box.append(expander_list);

    // Connect signals
    btnprev.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnprev_clicked));
    btnplay.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnplay_clicked));
    btnnext.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnnext_clicked));
    btnstop.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnstop_clicked));
    btnmode.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnmode_clicked));
    // btncolor.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btncolor_clicked));
    btn_add.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnadd_clicked));
    btn_remove.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnremove_clicked));
    btn_load.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnload_clicked));
    btn_save.signal_clicked().connect(sigc::mem_fun(*this, &MyMediaPlayer::btnsave_clicked));

    set_child(main_box);
}

MyMediaPlayer::~MyMediaPlayer()
{
}

void MyMediaPlayer::setup_view(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
    // Create a label for the list item
    auto label = Gtk::make_managed<Gtk::Label>("");
    list_item->set_child(*label);
}

void MyMediaPlayer::bind_view(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
    // Bind the label's text property to the item's titles
    auto pos = list_item->get_position();
    if (pos == GTK_INVALID_LIST_POSITION)
        return;
    auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
    auto item = media_list->get_item(pos);
    label->set_label(item->get_name());
    std::cout << item->get_name() << std::endl;
}

void MyMediaPlayer::btnprev_clicked()
{
}

void MyMediaPlayer::btnplay_clicked()
{
}

void MyMediaPlayer::btnnext_clicked()
{
}

void MyMediaPlayer::btnstop_clicked()
{
}

void MyMediaPlayer::btnmode_clicked()
{
}

void MyMediaPlayer::btncolor_clicked()
{
}

void MyMediaPlayer::btnadd_clicked()
{
    auto item1 = MyItem::create("test1", "test1.mp3");
    media_list->append(item1);
}

void MyMediaPlayer::btnremove_clicked()
{
}

void MyMediaPlayer::btnclear_clicked()
{
}

void MyMediaPlayer::btnload_clicked()
{
}

void MyMediaPlayer::btnsave_clicked()
{
}
