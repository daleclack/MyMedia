#include "MyMediaPlayer.hh"

int main(int argc, char **argv)
{
    // Create a new application instance and run it.
    auto app = Gtk::Application::create("org.gtk.daleclack");
    return app->make_window_and_run<MyMediaPlayer>(argc, argv);
}