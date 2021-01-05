#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow()
        : m_label("I am a label")
        , m_btn("I am a button") {
        set_title("Test application");
        set_default_size(400, 400);

        m_btn.signal_clicked().connect([this]() {
            m_btn.set_label("I have been clicked");
            Glib::signal_timeout().connect_seconds([this]() -> bool {
                m_btn.set_label("I have timed out");
                return false;
            }, 1);
        });

        m_box.pack_start(m_label);
        m_box.pack_start(m_btn);

        m_box.show_all();

        add(m_box);
    }

private:
    Gtk::Box m_box;
    Gtk::Label m_label;
    Gtk::Button m_btn;
};

int main() {
    auto app = Gtk::Application::create("com.github.lorpus.gtktest");

    MainWindow window;
    window.show();

    return app->run(window);
}
