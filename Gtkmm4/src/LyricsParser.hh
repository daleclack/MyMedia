#pragma once

#include <gtkmm.h>
#include <map>

// Use map to store lyrics timestamp and lyric lines
typedef std::map<gint64, std::string> lyrics_map;

class LyricsParser
{
public:
    LyricsParser();
    void update_lyrics(Glib::ustring &filename);
    Glib::ustring get_lyric_line(gint64 timestamp);

private:
    Glib::ustring current_lyric_line;
};